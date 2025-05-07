%s COMENT

%{
#include "miniC.tab.h"
#include "listaCodigo.h"
int contaErrorLexico=0;

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
do                                          return DO;
for                                         return FOR;


({letra}|_)({letra}|{digito}|_){0,30}       {yylval.lexema=strdup(yytext); if(yyleng>32){printf("ERROR: Identificador %s, excede la longitud máxima en la linea %d\n",yytext, yylineno); contaErrorLexico++;} return ID;}
{entero}                                    {yylval.lexema=strdup(yytext); if(atoll(yytext) > 2147483648){printf("ERROR: Entero fuera de rango en la linea %d\n", yylineno); contaErrorLexico++;} return NUM;}

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
"<"                                         return MENOR;
">"                                         return MAYOR;
">="                                        return MAYORIGUAL;
"<="                                        return MENORIGUAL;
"=="                                        return IGUALIGUAL;
"!="                                        return NOIGUAL;

[^/*$_=(){};,+\-a-zA-Z0-9 \n\t\r]           {printf("Error lexico en la cadena %s en linea %d\n",yytext, yylineno); contaErrorLexico++;}



%%
