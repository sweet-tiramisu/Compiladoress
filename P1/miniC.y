%{
#include "listaSimbolos.h"
#include "listaCodigo.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
Lista tablaSimb;
int contCadenas=1;
int contadorEtiquetas = 1;

extern char *yytext;
extern int yylineno;
extern int yylex();
extern int errores;
void imprimirTablaS();
int perteneceTablaS(char * c);
void insertaTablaIdentificador(char * c, Tipo t);
int esConstante(char * c);
void insertaTablaString(char * c, Tipo t, int contCadenas);
void yyerror();
void imprimeLS();
char * registros[10] = {"$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$t8", "$t9"};
int registrosOcupados[10] = {0};
char * obtenerReg();
char * concatena(char * a, char * b);
void liberarReg(char * reg);
void imprimirLC(ListaC codigo);
char * obtenerEtiqueta();
char * concatenaNumero (char * a, int num);

%}

%code requires {
	#include "listaCodigo.h"
}

%union{
char *lexema;
ListaC codigo;
}

%type <codigo> expression statement statement_list print_item print_list read_list declarations const_list

%token <lexema> STR ID NUM
%token VAR CONST IF ELSE WHILE PRINT READ SEPARADOR COMA PLUSOP MINUSOP MULOP DIVOP ASIG LPAREN RPAREN LLLAVE RLLAVE INTERR DPUNTOS 

%right ASIG
%left PLUSOP MINUSOP
%left MULOP DIVOP
%left INTERR DPUNTOS
%left UMINUS

%expect 1
%%

program 		: 	{tablaSimb=creaLS();} ID LPAREN RPAREN LLLAVE declarations statement_list RLLAVE {/*imprimirTablaS();*/ concatenaLC($6,$7); imprimeLS(); imprimirLC($6); liberaLS(tablaSimb); liberaLC($6); liberaLC($7);}
				;

declarations 	: 	declarations VAR tipo var_list SEPARADOR                      	{$$ = $1;}
       			| 	declarations CONST tipo const_list SEPARADOR                  	{$$ = $1;
																					concatenaLC($$,$4);
																					liberaLC($4);
																					}
    		    |   %empty                                                          {$$ = creaLC();} 	
				;	
tipo            : 	NUM                                                              
                ;

var_list		:  	ID 																{if (!perteneceTablaS($1)) insertaTablaIdentificador($1,VARIABLE); else printf("Error en linea %d : %s ya declarada \n",yylineno,$1);}
				| 	var_list COMA ID 												{if (!perteneceTablaS($3)) insertaTablaIdentificador($3,VARIABLE); else printf("Error en linea %d : %s ya declarada \n",yylineno,$3);}
				;
		
const_list 		: 	ID ASIG expression 												{if (!perteneceTablaS($1)) insertaTablaIdentificador($1,CONSTANTE); else printf("Error en linea %d : %s ya declarada \n",yylineno,$1);
																					 $$ = $3;
																					 Operacion oper;
																					 oper.op = "sw";
																					 oper.res = recuperaResLC($3);
																					 oper.arg1 = concatena("_",$1);
																					 oper.arg2 = NULL;
																					 insertaLC($$,finalLC($$),oper);
																					 liberarReg(oper.res);
																					}
				| 	const_list COMA ID ASIG expression 								{if (!perteneceTablaS($3)) insertaTablaIdentificador($3,CONSTANTE); else printf("Error en linea %d : %s ya declarada \n",yylineno,$3);
																					 $$ = $1;
																					 concatenaLC($$,$5);
																					 Operacion oper;
																					 oper.op = "sw";
																					 oper.res = recuperaResLC($5);
																					 oper.arg1 = concatena("_",$3);
																					 oper.arg2 = NULL;
																					 insertaLC($$,finalLC($$),oper);
																					 liberarReg(oper.res);
																					}
				;

statement_list  :  	statement_list statement                                        {$$ = $1;
																					 concatenaLC($$,$2);
																					 liberaLC($2);
																					}
                |   %empty 															{$$ = creaLC();}                                                           
                ;				

statement 		: 	ID ASIG expression SEPARADOR 								   {if (!perteneceTablaS($1)) printf("Error en linea %d : %s no declarada \n",yylineno,$1); 
																					else if (esConstante($1)) printf("Error en linea %d : %s es constante\n", yylineno, $1);
																					$$ = $3;
																					Operacion oper;
																					oper.op = "sw";
																					oper.res = recuperaResLC($3);
																					oper.arg1 = concatena("_",$1);
																					oper.arg2 = NULL;
																					insertaLC($$,finalLC($$),oper);
																					liberarReg(oper.res);
																					//guardaResLC($$,oper.res); 

																					/*imprimirLC($3);*/}
                |  	LLLAVE statement_list RLLAVE                                   {$$ = $2;}
                |  	IF LPAREN expression RPAREN statement ELSE statement           {$$ = $3;
																					Operacion oper;
																					oper.op = "beqz";
																					oper.res = recuperaResLC($3);
																					oper.arg1 = obtenerEtiqueta();
																					oper.arg2 = NULL;
																					insertaLC($$,finalLC($$),oper);
																					concatenaLC($$,$5);
																					liberaLC($5);

																					Operacion operacion2;
																					operacion2.op = "b";
																					operacion2.res = obtenerEtiqueta();//recuperaResLC($3);
																					operacion2.arg1 = NULL;//obtenerEtiqueta();
																					operacion2.arg2 = NULL;
																					insertaLC($$,finalLC($$),operacion2);
																					
																					
																					Operacion operacion3;
																					operacion3.op = "etiqueta";
																					operacion3.res = oper.arg1;
																					operacion3.arg1 = NULL;
																					operacion3.arg2 = NULL;
																					insertaLC($$,finalLC($$),operacion3);
																					liberarReg(recuperaResLC($$));
																					concatenaLC($$,$7);
																					liberaLC($7);

																					Operacion operacion4;
																					operacion4.op = "etiqueta";
																					operacion4.res = operacion2.res;
																					operacion4.arg1 = NULL;
																					operacion4.arg2 = NULL;
																					insertaLC($$,finalLC($$),operacion4);
																					liberarReg(recuperaResLC($3));

																						
																					}
                |  	IF LPAREN expression RPAREN statement                          {$$ = $3;
																					Operacion oper;
																					oper.op = "beqz";
																					oper.res = recuperaResLC($3);
																					oper.arg1 = obtenerEtiqueta();
																					oper.arg2 = NULL;
																					insertaLC($$,finalLC($$),oper);
																					concatenaLC($$,$5);
																					liberaLC($5);

																					Operacion operacion2;
																					operacion2.op = "etiqueta";
																					operacion2.res = oper.arg1;
																					operacion2.arg1 = NULL;
																					operacion2.arg2 = NULL;
																					insertaLC($$,finalLC($$),operacion2);
																					liberarReg(recuperaResLC($$));
																					}
                |  	WHILE LPAREN expression RPAREN statement                       {$$ = creaLC();
																					Operacion oper;
																					oper.op = "etiqueta";
																					oper.res = obtenerEtiqueta();
																					oper.arg1 = NULL;
																					oper.arg2 = NULL;
																					insertaLC($$,finalLC($$),oper);

																					concatenaLC($$,$3);
																				
																					Operacion operacion2;
																					operacion2.op = "beqz";
																					operacion2.res = recuperaResLC($3);
																					operacion2.arg1 = obtenerEtiqueta();
																					operacion2.arg2 = NULL;
																					insertaLC($$,finalLC($$),operacion2);
																					//liberaLC($3);

																					concatenaLC($$,$5);																					
																					liberaLC($5);																																																													
																					
																					Operacion operacion3;
																					operacion3.op = "b";
																					operacion3.res = oper.res;
																					operacion3.arg1 = NULL;
																					operacion3.arg2 = NULL;
																					//printf("insertando la b");
																					insertaLC($$,finalLC($$),operacion3);
																																										
																					Operacion operacion4;
																					operacion4.op = "etiqueta";
																					operacion4.res = operacion2.arg1;
																					operacion4.arg1 = NULL;
																					operacion4.arg2 = NULL;
																					insertaLC($$,finalLC($$),operacion4);
																					liberarReg(recuperaResLC($3));
																					
																				   }
                |  	PRINT LPAREN print_list RPAREN SEPARADOR                       {$$ = $3;}																				
                | 	READ LPAREN read_list RPAREN SEPARADOR                         {$$ = $3;}
                ;

print_list      : 	print_item                                                     {$$ = $1;}
                | 	print_list COMA print_item                                     {$$ = $1; concatenaLC($$,$3);}
                ;

print_item 		: 	expression													   {$$ = $1;
																					 Operacion oper;
																					 oper.op = "move";
																					 oper.res = "$a0";
																					 oper.arg1 = recuperaResLC($1);
																					 oper.arg2 = NULL;
																					 insertaLC($$,finalLC($$),oper);
																					 //guardaResLC($$,operacion2.res); 

																					 Operacion operacion2;
																					 operacion2.op = "li";
																					 operacion2.res = "$v0";
																					 operacion2.arg1 = "1";
																					 operacion2.arg2 = NULL;
																					 insertaLC($$,finalLC($$),operacion2);
																					 //guardaResLC($$,operacion1.res); 
																					 																					 
																					 Operacion syscall;			
																					 syscall.op = "syscall";
																					 syscall.res = NULL;
																					 syscall.arg1 = NULL;
																					 syscall.arg2 = NULL;
																					 insertaLC($$,finalLC($$),syscall);
																					 //guardaResLC($$,syscall.res); 
																					 liberarReg(recuperaResLC($1));
																					}
				|   STR 															{insertaTablaString($1,CADENA,contCadenas);
																					 $$ = creaLC();
																					 Operacion operacion1;
																					 operacion1.op = "la";
																					 operacion1.res = "$a0";
																					 operacion1.arg1 = concatenaNumero("$str", contCadenas++);
																					 operacion1.arg2 = NULL;
																					 insertaLC($$,finalLC($$),operacion1);
																					 //guardaResLC($$,operacion1.res); 

																					 Operacion operacion2;
																					 operacion2.op = "li";
																					 operacion2.res = "$v0";
																					 operacion2.arg1 = "4";
																					 operacion2.arg2 = NULL;
																					 insertaLC($$,finalLC($$),operacion2);
																					 //guardaResLC($$,operacion2.res); 
																					 
																					 																					 Operacion syscall;			
																					 syscall.op = "syscall";
																					 syscall.res = NULL;
																					 syscall.arg1 = NULL;
																					 syscall.arg2 = NULL;
																					 insertaLC($$,finalLC($$),syscall);
																					 //guardaResLC($$,syscall.res); 
																					}
				;

read_list   	: 	ID 															    {if (!perteneceTablaS($1)) printf("Error en linea %d : %s no declarada \n", yylineno,$1);
																					else if (esConstante($1)) printf("Error en linea %d : %s es constante\n", yylineno, $1);
																					 $$ = creaLC();
																					 Operacion operacion1;
																					 operacion1.op = "li";
																					 operacion1.res = "$v0";
																					 operacion1.arg1 = "5";
																					 operacion1.arg2 = NULL;
																					 insertaLC($$,finalLC($$),operacion1);
																					 //guardaResLC($$,operacion1.res); 
																					 
																					 Operacion syscall;			
																					 syscall.op = "syscall";
																					 syscall.res = NULL;
																					 syscall.arg1 = NULL;
																					 syscall.arg2 = NULL;
																					 insertaLC($$,finalLC($$),syscall);
																					 //guardaResLC($$,syscall.res); 
																					 
																					 Operacion operacion2;
																					 operacion2.op = "sw";
																					 operacion2.res = "$v0";
																					 operacion2.arg1 = concatena("_", $1);
																					 operacion2.arg2 = NULL;
																					 insertaLC($$,finalLC($$),operacion2);
																					 //guardaResLC($$,operacion2.res); 

																					 
																					}
				| 	read_list COMA ID 												{if (!perteneceTablaS($3)) printf("Error en linea %d : %s no declarada \n", yylineno, $3);
																					else if (esConstante($3)) printf("Error en linea %d : %s es constante\n", yylineno, $3);
																					 $$ = $1;
																					 Operacion operacion1;
																					 operacion1.op = "li";
																					 operacion1.res = "$v0";
																					 operacion1.arg1 = "5";
																					 operacion1.arg2 = NULL;
																					 insertaLC($$,finalLC($$),operacion1);
																					 //guardaResLC($$,operacion1.res); 
																					 
																					 Operacion syscall;			
																					 syscall.op = "syscall";
																					 syscall.res = NULL;
																					 syscall.arg1 = NULL;
																					 syscall.arg2 = NULL;
																					 insertaLC($$,finalLC($$),syscall);
																					 //guardaResLC($$,syscall.res); 
																					 
																					 Operacion operacion2;
																					 operacion2.op = "sw";
																					 operacion2.res = "$v0";
																					 operacion2.arg1 = concatena("_", $3);
																					 operacion2.arg2 = NULL;
																					 insertaLC($$,finalLC($$),operacion2);
																					 //guardaResLC($$,operacion2.res); 
																					}
				;

expression		: 	expression PLUSOP expression              						{ $$ = $1; concatenaLC($$,$3);
																					  Operacion oper; oper.op = "add"; oper.res = obtenerReg();
																					  oper.arg1 = recuperaResLC($1); oper.arg2 = recuperaResLC($3);
																					  insertaLC($$,finalLC($$),oper); guardaResLC($$,oper.res); 
																					  liberarReg(oper.arg1); liberarReg(oper.arg2); liberaLC($3);
																					}                    
                | 	expression MINUSOP expression                 					{ $$ = $1; concatenaLC($$,$3);
																					  Operacion oper; oper.op = "sub"; oper.res = obtenerReg();
																					  oper.arg1 = recuperaResLC($1); oper.arg2 = recuperaResLC($3);
																					  insertaLC($$,finalLC($$),oper); guardaResLC($$,oper.res); 
																					  liberarReg(oper.arg1); liberarReg(oper.arg2); liberaLC($3);
																					}                  
                | 	expression MULOP expression                     				{ $$ = $1; concatenaLC($$,$3);
																					  Operacion oper; oper.op = "mul"; oper.res = obtenerReg();
																					  oper.arg1 = recuperaResLC($1); oper.arg2 = recuperaResLC($3);
																					  insertaLC($$,finalLC($$),oper); guardaResLC($$,oper.res); 
																					  liberarReg(oper.arg1); liberarReg(oper.arg2); liberaLC($3);
																					}                
                |	expression DIVOP expression                                     { $$ = $1; concatenaLC($$,$3);
																					  Operacion oper; oper.op = "div"; oper.res = obtenerReg();
																					  oper.arg1 = recuperaResLC($1); oper.arg2 = recuperaResLC($3);
																					  insertaLC($$,finalLC($$),oper); guardaResLC($$,oper.res); 
																					  liberarReg(oper.arg1); liberarReg(oper.arg2); liberaLC($3);
																					}
                | 	LPAREN expression INTERR expression DPUNTOS expression RPAREN   {}
                | 	MINUSOP expression %prec UMINUS                                 {$$ = $2;
																					 Operacion oper;
																					 oper.op = "neg";
																					 oper.res = recuperaResLC($2);
																					 oper.arg1 = recuperaResLC($2);
																					 oper.arg2 = NULL;
																					 insertaLC($$,finalLC($$),oper);
																					 guardaResLC($$,oper.res);}          
                | 	LPAREN expression RPAREN                                        {$$ = $2;}																					
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
	
	insertaLS(tablaSimb, finalLS(tablaSimb), aux);
	
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

void imprimeLS(){	// .data del programa
	printf("##################\n");
	printf("# Seccion de datos\n");
	printf("\t.data\n\n");
	PosicionLista p = inicioLS(tablaSimb);
	//Primero imprimimos las cadenas
	while(p!=finalLS(tablaSimb)){
		Simbolo aux = recuperaLS(tablaSimb,p);
		if(aux.tipo == CADENA){
			printf("str%d: \n\t.asciiz %s \n",aux.valor,aux.nombre);
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
	// Algoritmo de búsqueda:
	int i = 0;
	while(i < 10 && registrosOcupados[i]){
		i++;
	}

	if(!registrosOcupados[i]){
		registrosOcupados[i] = 1;
	}

	return registros[i];

}

char * concatena(char * a, char * b){
	/*int tamanoBuffer = strlen(a) + strlen(b) + 1; //malloc(sizeof(char)*34); //32 del tamaño del ID + "/0" + "_"
	char * buffer = malloc(tamanoBuffer * sizeof(char));
	sprintf(buffer, "%s%s", a, b);
	return buffer;*/
	char buffer[40];
	sprintf(buffer, "%s%s", a, b);
	return strdup(buffer);
}

char * concatenaNumero (char * a, int num){
	char buffer[32];
	sprintf(buffer, "%s%d", a, num);
	return strdup(buffer);
}

void liberarReg(char * reg) {
    if (reg == NULL) return;

    char * numero = &reg[2];				// tomo el dígito del registro: "$t7" -> 7
    int nuevoRegistro = atoi(numero);		
	 if (nuevoRegistro >= 0 && nuevoRegistro < 10) 
		registrosOcupados[nuevoRegistro] = 0;	// libero el reg seleccionado
}

void imprimirLC(ListaC codigo) {
	printf("###################\n");
	printf("# Seccion de codigo\n");
	printf("\t.text\n");
	printf("\t.globl main\n");
	printf("main:\n");
	PosicionListaC p = inicioLC(codigo);
	while (p != finalLC(codigo)) {
		Operacion oper = recuperaLC(codigo,p);
		if(strcmp(oper.op, "etiqueta") == 0){
			 printf("%s: \n", oper.res);
		}else{
			printf("\t%s",oper.op);
			if (oper.res) printf(" %s",oper.res);
			if (oper.arg1) printf(", %s",oper.arg1);
			if (oper.arg2) printf(", %s",oper.arg2);
			printf("\n");
		}
		
		p = siguienteLC(codigo,p);
	}
	printf("\n");
	printf("##############\n");
	printf("# Fin\n");
	printf("\tli $v0, 10\n");
	printf("\tsyscall\n");
	
}

char *obtenerEtiqueta() {
	char aux[32];
	sprintf(aux,"$l%d",contadorEtiquetas++);
	return strdup(aux);
}