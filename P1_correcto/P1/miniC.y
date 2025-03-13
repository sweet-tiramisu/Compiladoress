%{
#include <stdio.h>
extern char *yytext;
extern int yylineno;
extern int yylex();
int main();
void yyerror();
%}

%token VAR CONST INT IF ELSE WHILE PRINT READ ID ENTERO CADENA SEPARADOR COMMA PLUSOP MINUSOP MULOP DIVOP ASSIGNOP LPAREN RPAREN LLLAVE RLLAVE INTERR DPUNTOS

%%

program         :  ID LPAREN RPAREN LLLAVE declarations statement_list RLLAVE {printf("Aplica program -> ID () { declarations statement_list } \n");}
declarations    :  declarations VAR tipo var_list SEPARADOR                       {printf("Aplica declarations -> declarations VAR tipo var_list ; \n");}
                |  declarations CONST tipo const_list SEPARADOR                   {printf("Aplica declarations -> declarations CONST tippo const_list ; } \n");}
                |                                                                 {printf("Aplica declarations -> lambda \n");}
                ;
tipo            :  INT                                                              {printf("Aplica tipo -> ENTERO \n");}
                ;
var_list        :  ID                                                             {printf("Aplica var_list -> ID \n");}
                |  var_list COMMA ID                                              {printf("Aplica var_list -> var_list , ID \n");}
                ;
const_list      :  ID ASSIGNOP expression                                         {printf("Aplica const_list -> ID = expression \n");}
                |  const_list COMMA ID ASSIGNOP expression                        {printf("Aplica const_list , ID = expression \n");}
                ;
statement_list  :  statement_list statement                                       {printf("Aplica statement_list -> statement_list statement \n");}
                |                                                                 {printf("Aplica statement_list -> lambda } \n");}
                ;
statement       :  ID ASSIGNOP expression SEPARADOR                               {printf("Aplica statement -> ID = expression ; \n");}
                |  LLLAVE statement_list RLLAVE                                   {printf("Aplica statement -> { statement_list } \n");}
                |  IF LPAREN expression RPAREN statement ELSE statement           {printf("Aplica statement -> IF ( expression ) statement ELSE statement } \n");}
                |  IF LPAREN expression RPAREN statement                          {printf("Aplica statement -> IF ( expression ) statement } \n");}
                |  WHILE LPAREN expression RPAREN statement                       {printf("Aplica statement -> WHILE ( expression ) statement \n");}
                |  PRINT LPAREN print_list RPAREN SEPARADOR                       {printf("Aplica statement -> PRINT ( print_list ) ; \n");}
                |  READ LPAREN read_list RPAREN SEPARADOR                         {printf("Aplica statement -> READ ( read_list ) ; \n");}
                ;
print_list      :  print_item                                                     {printf("Aplica print_list -> print_item \n");}
                |  print_list COMMA print_item                                    {printf("Aplica print_list -> print_list , print_item \n");}
                ;
print_item      :  expression                                                     {printf("Aplica print_item -> expression \n");}
                |  CADENA                                                         {printf("Aplica print_item -> CADENA \n");}
                ;
read_list       :  ID                                                             {printf("Aplica read_list -> ID \n");}
                | read_list COMMA ID                                              {printf("Aplica read_list -> read_list , ID \n");}
                ;
expression      : expression PLUSOP expression                                    {printf("Aplica expression -> expression + expression \n");}
                | expression MINUSOP expression                                   {printf("Aplica expression -> expression - expression \n");}
                | expression MULOP expression                                     {printf("Aplica expression -> expression * expression \n");}
                | expression DIVOP expression                                     {printf("Aplica expression -> expression / expression \n");}
                | LPAREN expression INTERR expression DPUNTOS expression RPAREN   {printf("Aplica expression -> ( expression ? expression : expression ) \n");}
                | MINUSOP expression                                              {printf("Aplica expression -> - expression \n");}
                | LPAREN expression RPAREN                                        {printf("Aplica expression -> ( expression ) \n");}
                | ID                                                              {printf("Aplica expression -> ID \n");}
                | ENTERO                                                          {printf("Aplica expression -> NUM \n");}
                ;

%%



void yyerror() {
    printf("Error sintactico en token %s y linea %d\n", yytext, yylineno);
}