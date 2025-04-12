%{
#include "listaSimbolos.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
Lista tablaSimb;
int contCadenas=1;

extern char *yytext;
extern int yylineno;
extern int yylex();
void imprimirTablaS();
int perteneceTablaS(char * c);
void insertaTablaIdentificador(char * c, Tipo t);
int esConstante(char * c);
void insertaTablaString(char * c, Tipo t, int contCadenas);
void yyerror();
void imprimeEnsamblador();
int registrosOcupados[10];
char * obtenerReg();
char * concatena(char * a, char * b);

%}

%code requires{
	#include "listaCodigo.h"
}

%union{
char *lexema;
ListaC codigo;
}

%type <codigo> expression

%token <lexema> STR ID NUM
%token VAR CONST IF ELSE WHILE PRINT READ SEPARADOR COMA PLUSOP MINUSOP MULOP DIVOP ASIG LPAREN RPAREN LLLAVE RLLAVE INTERR DPUNTOS 

%right ASIG
%left PLUSOP MINUSOP
%left MULOP DIVOP
%left INTERR DPUNTOS
%left UMINUS

%expect 1
%%

program 		: 	{tablaSimb=creaLS();} ID LPAREN RPAREN LLLAVE declarations statement_list RLLAVE {imprimirTablaS(); imprimeEnsamblador();liberaLS(tablaSimb); }
				;

declarations 	: 	declarations VAR tipo var_list SEPARADOR                      	
       			| 	declarations CONST tipo const_list SEPARADOR                  
    		    |   %empty                                                             	
				;	
tipo            : 	NUM                                                              
                ;

var_list		:  	ID 																{if (!perteneceTablaS($1)) insertaTablaIdentificador($1,VARIABLE); else printf("Error en linea %d : %s ya declarada \n",yylineno,$1);}
				| 	var_list COMA ID 												{if (!perteneceTablaS($3)) insertaTablaIdentificador($3,VARIABLE); else printf("Error en linea %d : %s ya declarada \n",yylineno,$3);}
				;
		
const_list 		: 	ID ASIG expression 												{if (!perteneceTablaS($1)) insertaTablaIdentificador($1,CONSTANTE); else printf("Error en linea %d : %s ya declarada \n",yylineno,$1);}
				| 	const_list COMA ID ASIG expression 								{if (!perteneceTablaS($3)) insertaTablaIdentificador($3,CONSTANTE); else printf("Error en linea %d : %s ya declarada \n",yylineno,$3);}
				;

statement_list  :  	statement_list statement                                       
                |   %empty                                                               
                ;				

statement 		: 	ID ASIG expression SEPARADOR 								   {if (!perteneceTablaS($1)) printf("Error en linea %d : %s no declarada \n",yylineno,$1);
																					else if (esConstante($1)) printf("Error en linea %d : %s es constante\n", yylineno, $1);}
                |  	LLLAVE statement_list RLLAVE                                   
                |  	IF LPAREN expression RPAREN statement ELSE statement           
                |  	IF LPAREN expression RPAREN statement                          
                |  	WHILE LPAREN expression RPAREN statement                       
                |  	PRINT LPAREN print_list RPAREN SEPARADOR                       
                | 	READ LPAREN read_list RPAREN SEPARADOR                         
                ;

print_list      : 	print_item                                                     
                | 	print_list COMA print_item                                    
                ;

print_item 		: 	expression
				|   STR 															{insertaTablaString($1,CADENA,contCadenas++);}
				;

read_list   	: 	ID 															    {if (!perteneceTablaS($1)) printf("Error en linea %d : %s no declarada \n", yylineno,$1);
																					else if (esConstante($1)) printf("Error en linea %d : %s es constante\n", yylineno, $1);}
				| read_list COMA ID 												{if (!perteneceTablaS($3)) printf("Error en linea %d : %s no declarada \n", yylineno, $3);
																					else if (esConstante($3)) printf("Error en linea %d : %s es constante\n", yylineno, $3);}
				;

expression		: 	expression PLUSOP expression              						{}                      
                | 	expression MINUSOP expression                 {}                  
                | 	expression MULOP expression                     {}                
                |	expression DIVOP expression                                     
                | 	LPAREN expression INTERR expression DPUNTOS expression RPAREN   {}
                | 	MINUSOP expression %prec UMINUS                                   {}          
                | 	LPAREN expression RPAREN                                        {}
				| 	ID 																{if (!perteneceTablaS($1)) printf("Error en linea %d : %s no declarada \n", yylineno, $1); 
																																								$$ = creaLC();
																																								Operacion oper;
																																								oper.op = "lw";
																																								oper.res = obtenerReg();
																																								oper.arg1 = concatena("_",$1);
																																								oper.arg2 = NULL;
																																								insertaLC($$,finalLC($$),oper);
																																								guardaResLC($$,oper.res); }
				| 	NUM             												{$$ = creaLC();
																					 Operacion oper;
																					 oper.op = "li";
																					 oper.res = obtenerReg();
																					 oper.arg1 = $1;
																					 oper.arg2 = NULL;
																					 insertaLC($$,finalLC($$),oper);
																					 guardaResLC($$,oper.res);}                                        
				;

%%


void yyerror() {
    printf("Error sintactico en token %s y linea %d\n", yytext, yylineno);
}


void imprimirTablaS() {
	//printf("Imprimiendo lista de %d simbolos\n",longitudLS(tablaSimb));
  	PosicionLista p = inicioLS(tablaSimb);
  	while (p != finalLS(tablaSimb)) {
    		Simbolo aux = recuperaLS(tablaSimb,p);
    		char *tipo;
    		switch (aux.tipo) {
        		case VARIABLE:
            			tipo = "variable";
           		break;
        		case CONSTANTE:
            			tipo = "constante";
            		break;
				case CADENA:
						tipo = "cadena";
					break;
        		default:
            		tipo = "otro";
    		}
    		//printf("%s es %s\n",aux.nombre,tipo);    
    		p = siguienteLS(tablaSimb,p);
  	}
}

int perteneceTablaS(char * c) {
	PosicionLista p = buscaLS(tablaSimb, c);
	return (p != finalLS(tablaSimb));
}

void insertaTablaIdentificador(char * c, Tipo t) {
	Simbolo aux;
	aux.nombre = c;
	aux.tipo = t;
	aux.valor = 0;
	//printf("El tipo es %d\n", aux.tipo);
	//printf("Insertando variable %s en la tabla de simbolos\n", c);
	if(t == CONSTANTE) {
	  	insertaLS(tablaSimb, finalLS(tablaSimb), aux);
	} else if (t == VARIABLE) {
		insertaLS(tablaSimb, finalLS(tablaSimb), aux);
	}
}

int esConstante(char * c) {
	PosicionLista p = buscaLS(tablaSimb, c);
	int cte = 0;
	if(p!= finalLS(tablaSimb)){
		Simbolo aux = recuperaLS(tablaSimb,p);
		if(aux.tipo == CONSTANTE)
			cte = 1;
	}
	
	return cte;
}

void insertaTablaString(char * c, Tipo t, int contCadenas) {
	/*Simbolo aux;
	sprintf(aux.nombre, "str%d",contCadenas);
	aux.tipo = t;
	// aux.valor = c;
	printf("Insertando cadena str%d -> (%s) en la tabla de simbolos\n", contCadenas, c);*/
	Simbolo aux;
	aux.nombre = c;
	aux.tipo = t;
	aux.valor = contCadenas;
	contCadenas++;
	insertaLS(tablaSimb, finalLS(tablaSimb), aux);
}

void imprimeEnsamblador(){
	printf("##################\n");
	printf("# Seccion de datos\n");
	printf("\t.data\n\n");
	PosicionLista p = inicioLS(tablaSimb);
	//Primero imprimimos las cadenas
	while(p!=finalLS(tablaSimb)){
		Simbolo aux = recuperaLS(tablaSimb,p);
		if(aux.tipo == CADENA){
			printf("srt%d: \n\t.asciiz %s \n",aux.valor,aux.nombre);
		}
		p = siguienteLS(tablaSimb,p);
	}

	//Imprimo variables y constantes
	p = inicioLS(tablaSimb);
	while(p!=finalLS(tablaSimb)){
		Simbolo aux = recuperaLS(tablaSimb,p);
		if(aux.tipo == VARIABLE || aux.tipo == CONSTANTE){
			printf("_%s: \n\t.word 0 \n",aux.nombre);
		} 
		p = siguienteLS(tablaSimb,p);
	}

}

char * obtenerReg(){
	char * registros[10] = {"$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8", "$t9"};
	// Algoritmo de búsqueda:
	int i = 0;
	while(i < 9 && registrosOcupados[i]){
		i++;
	}

	if(!registrosOcupados[i]){
		registrosOcupados[i] = 1;
	}

	return registros[i];

}

char * concatena(char * a, char * b){
	int tamanoBuffer = strlen(a) + strlen(b) + 1; //malloc(sizeof(char)*34); //32 del tamaño del ID + "/0" + "_"
	char * buffer = malloc(tamanoBuffer * sizeof(char));
	sprintf(buffer, "%s%s", a, b);
	return buffer;
}
