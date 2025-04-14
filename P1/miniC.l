%s COMENT

%{
#include "miniC.tab.h"
#include "listaCodigo.h"
void error_lexico();

%}
digito              [0-9]
letra               [a-zA-Z]
entero              {digito}+
escape              (\\\"|\\\\)
%option             yylineno

%%

"/*"                                        {BEGIN COMENT;}
<COMENT>[*]+[/]                             {BEGIN 0;}
<COMENT>[^*]*                               ;
<COMENT>[*]+[^/*]*                          ;
"//"(.*)[\n]                                ;
[ \n\t\r]+                                  ;

var                                         return VAR;
const                                       return CONST;
int                                         return NUM;
if                                          return IF;
else                                        return ELSE;
while                                       return WHILE;
print                                       return PRINT;
read                                        return READ;


({letra}|_)({letra}|{digito}|_){0,30}       {yylval.lexema=strdup(yytext);return ID;}
{entero}                                    {yylval.lexema=strdup(yytext); if(atoll(yytext) > 2147483648) printf("ERROR: Entero fuera de rango en la linea %d\n", yylineno); return NUM; }

\"([^"]|{escape})*\"                        {yylval.lexema=strdup(yytext);return STR;}


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
