%s COMENT

%{
#include "miniC.tab.h"
#include "listaCodigo.h"
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
int                                         return NUM;
if                                          return IF;
else                                        return ELSE;
while                                       return WHILE;
print                                       return PRINT;
read                                        return READ;

[ \n\t\r]+                                  ;

({letra}|_)({letra}|{digito}|_){0,30}       {yylval.lexema=strdup(yytext);return ID;}
{entero}                                    return comprobar_entero();

\"([^"]|{escape})*\"                        {yylval.lexema=strdup(yytext);return STR;}



"//"(.*)[\n]                                ;

"/*"                                        {BEGIN COMENT; yymore();}
<COMENT>[*]+[/]                             {BEGIN 0;}
<COMENT>[^*]*                               yymore();
<COMENT>[*]+[^/*]*                          yymore();


";"                                         return SEPARADOR;
","                                         return COMA;
"+"                                         return PLUSOP;
"-"                                         return MINUSOP;
"*"                                         return MULOP;
"/"                                         return DIVOP;
"="                                         return ASIG;
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
    if(atoll(yytext) < 2147483648)
        return NUM;
    printf("ERROR: Entero fuera de rango en la linea %d\n", yylineno);
    return NUM;
}