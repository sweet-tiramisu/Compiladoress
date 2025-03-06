%s COMENT

%{
#include "lexico1.h"
int comprobar_entero();
void error_lexico();

%}
digito              [0-9]
letra               [a-zA-Z]
entero              {digito}+
escape              (\\\"|\\\\)
%option             yylineno

%%

var                                         return VAR;
const                                       return CONST;
int                                         return INT;
if                                          return IF;
else                                        return ELSE;
while                                       return WHILE;
print                                       return PRINT;
read                                        return READ;

[ \n\t]+                                    ;

({letra}|_)({letra}|{digito}|_){0,30}       return ID;
{entero}                                    return comprobar_entero();

\"([^"]|{escape})*\"                        return CADENA;



"//"(.*)[\n]                                ;

"/*"                                        {BEGIN COMENT; yymore();}
<COMENT>[*]+[/]                             {BEGIN 0;}
<COMENT>[^*]*                               yymore();
<COMENT>[*]+[^/*]*                          yymore();


";"                                         return SEPARADOR;
","                                         return COMMA;
"+"                                         return PLUSOP;
"-"                                         return MINUSOP;
"*"                                         return MULOP;
"/"                                         return DIVOP;
"="                                         return ASSIGNOP;
"("                                         return LPAREN;		
")"                                         return RPAREN;
"{"                                         return LLLAVE;
"}"                                         return RLLAVE;
"?"                                         return INTERR;
":"                                         return DPUNTOS;

[^\n\t]                                     error_lexico();


%%

void error_lexico() {
    printf("Carácter no reconocido en la linea %d: %s\n", yylineno, yytext);
}

int comprobar_entero() {
    if(atoll(yytext) < 2147483648 && atoll(yytext) > -2147483648)
        return ENTERO;
    printf("ERROR: Entero fuera de rango en la linea %d\n", yylineno);
    return ERROR_TOKEN;
}

int main(){
    int i;
    while(i = yylex()){
        /*if(i != ERROR_TOKEN)
            printf(" TOKEN %d %s\n",i,yytext);*/
    }
    printf("FIN ANALISIS LEXICO\n");

}
