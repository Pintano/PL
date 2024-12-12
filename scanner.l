
%{
/* need this for the call to atof() below */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definitions.h"
#include "programa.tab.h"
extern int yylineno;
%}


CIFRA                           [0-9]
LETRA                           [a-z]|[A-Z]
LETRA_O_CIFRA                   {LETRA}|{CIFRA}
IDENTIFICADOR_BOOLEANO          (?i:b){LETRA_O_CIFRA}*
IDENTIFICADOR                   {LETRA}{LETRA_O_CIFRA}*
LITERAL_ENTERO                  {CIFRA}+([eE](\+)?{CIFRA}+)?
LITERAL_REAL                    {CIFRA}+\.({CIFRA}+)?([eE](\+|\-)?{CIFRA}+)?|(\+|\-)?{CIFRA}+([eE](\-){CIFRA})+
VERDADERO                       (?i:verdadero)
FALSO                           (?i:falso)  
LITERAL_CARACTER                \"[^\"]*\"
LITERAL_CADENA                  \'([^\']|\/\')*\'
COMENTARIO                      \{([^}\/]|\/.)*\}
PRECONDICION                    \{(?i:prec)([^}\/]|\/.)*\}
POSTCONDICION                    \{(?i:post)([^}\/]|\/.)*\}
ASIGNACION                      :=
DELIMITADOR                     ;
SEPARADOR                       ,
ENTONCES                        ->
ELSE                            \[\]
RANGO                           \.\.
DECLARADOR_TIPO                 :
TIPO_BOOL                       (?i:booleano)
TIPO_ENTERO                     (?i:entero)
TIPO_REAL                       (?i:real)
TIPO_CADENA                     (?i:cadena)
TIPO_CARACTER                   (?i:caracter)
COMIENZO_ALGORITMO              (?i:algoritmo)
FIN_ALGORITMO                   (?i:falgoritmo)
COMIENZO_ACCION                 (?i:accion)
FIN_ACCION                      (?i:faccion)
COMIENZO_FUNCION                (?i:funcion)
FIN_FUNCION                     (?i:ffuncion)
COMIENZO_CONSTANTES             (?i:const)
FIN_CONSTANTES                  (?i:fconst)
COMIENZO_BUCLE_MIENTRAS         (?i:mientras)
FIN_BUCLE_MIENTRAS              (?i:fmientras)
COMIENZO_BUCLE_HACER            (?i:hacer)
HASTA                           (?i:hasta)
COMIENZO_BUCLE_PARA             (?i:para)
FIN_BUCLE_PARA                  (?i:fpara)
COMIENZO_SI                     (?i:si)
FIN_SI                          (?i:fsi)
COMIENZO_TIPO                   (?i:tipo)
FIN_TIPO                        (?i:ftipo)
COMIENZO_VAR                    (?i:var)
FIN_VAR                         (?i:fvar)
COMIENZO_TUPLA                  (?i:tupla)
FIN_TUPLA                       (?i:ftupla)
COMIENZO_TABLA                  (?i:tabla)
COMIENZO_INDICE                 \[
FIN_INDICE                      \]
MAYOR_IGUAL                     >=
MENOR_IGUAL                     <=
MENOR                           < 
MAYOR                           >
IGUAL                           =
OPERADOR_SUMA                   \+
OPERADOR_RESTA                  \-
OPERADOR_MULTIPLICACION         \*
OPERADORES_DIVISION             \/
OPERADORES_COCIENTE             (?i:div)
OPERADORES_RESTO                (?i:mod)
ENTRADA                         (?i:ent)
SALIDA                          (?i:sal)
ENTRADA_Y_SALIDA                (?i:e\/s)        
SALTO_LINEA                     [ \t\n]+ 
OPERADOR_BOOLEANO_O           (?i:o)
OPERADOR_BOOLEANO_Y           (?i:y)
CONTINUAR                       (?i:continuar) 
DECLARADOR_TIPO_TABLA           (?i:de) 
RETORNO                         (?i:dev)
NEGACION                        (?i:no)
REFERENCIA                      (?i:ref)
PUNTERO                         \.
COMIENZO_PARENTESIS             \(
FIN_PARENTESIS                  \)

%%

{VERDADERO}             { yylval.entero = ENUM_VERDADERO; return LITERAL_BOOLEANO; } 
{FALSO}                 { yylval.entero = ENUM_FALSO; return LITERAL_BOOLEANO; }  
{LITERAL_CARACTER}      { return LITERAL_CARACTER; }
{LITERAL_ENTERO}        { yylval.entero = atoi(yytext); return LITERAL_ENTERO; }
{LITERAL_REAL}          { yylval.real = strtod(yytext, NULL); return LITERAL_REAL; }
{OPERADOR_SUMA}         { yylval.entero = ENUM_SUMA; return OPERADORES_SUMA; }
{OPERADOR_RESTA}        { yylval.entero = ENUM_RESTA; return OPERADORES_SUMA; }
{LITERAL_CADENA}        { yylval.cadena = yytext; return LITERAL_CADENA; }
{COMIENZO_INDICE}       { return COMIENZO_INDICE; }
{FIN_INDICE}            { return FIN_INDICE; }
{IGUAL}                 { yylval.entero = ENUM_IGUAL; return IGUAL; }
{MAYOR_IGUAL}           { yylval.entero = ENUM_MAYORIGUAL; return COMPARADORES; }
{MENOR_IGUAL}           { yylval.entero = ENUM_MENORIGUAL; return COMPARADORES; }
{MENOR}                 { yylval.entero = ENUM_MAYOR; return COMPARADORES; }
{MAYOR}                 { yylval.entero = ENUM_MENOR; return COMPARADORES; }
{PRECONDICION}          { return PRECONDICION; }
{POSTCONDICION}         { return POSTCONDICION; }
{COMENTARIO}            { /* Ignorar comentarios */ }
{ASIGNACION}            {yylval.entero = ENUM_ASIGNACION; return ASIGNACION; }
{DELIMITADOR}           { return DELIMITADOR; }
{SEPARADOR}             { return SEPARADOR; }
{COMIENZO_PARENTESIS}   { return COMIENZO_PARENTESIS; }
{FIN_PARENTESIS}        { return FIN_PARENTESIS; }
{ENTONCES}              { return ENTONCES; }
{ELSE}                  { return ELSE; }
{RANGO}                 { return RANGO; }
{DECLARADOR_TIPO}       { return DECLARADOR_TIPO; }
{TIPO_BOOL}             { yylval.entero = ENUM_BOOLEANO; return TIPO; }          
{TIPO_ENTERO}           { yylval.entero = ENUM_ENTERO; return TIPO; }         
{TIPO_REAL}             { yylval.entero = ENUM_REAL; return TIPO; }
{TIPO_CADENA}           { yylval.entero = ENUM_CADENA; return TIPO; }          
{TIPO_CARACTER}         { yylval.entero = ENUM_CARACTER; return TIPO; }          
{COMIENZO_ALGORITMO}    { return COMIENZO_ALGORITMO; }
{FIN_ALGORITMO}         { return FIN_ALGORITMO; }
{COMIENZO_ACCION}       { return COMIENZO_ACCION; }
{FIN_ACCION}            { return FIN_ACCION; }
{COMIENZO_FUNCION}      { return COMIENZO_FUNCION; }
{FIN_FUNCION}           { return FIN_FUNCION; }
{COMIENZO_CONSTANTES}   { return COMIENZO_CONSTANTES; }
{FIN_CONSTANTES}        { return FIN_CONSTANTES; }
{COMIENZO_BUCLE_MIENTRAS}    { return COMIENZO_BUCLE_MIENTRAS; }
{COMIENZO_TABLA}        { return COMIENZO_TABLA; }
{FIN_BUCLE_MIENTRAS}    { return FIN_BUCLE_MIENTRAS; }
{COMIENZO_BUCLE_HACER}  { return COMIENZO_BUCLE_HACER; }
{HASTA}                 { return HASTA; }
{COMIENZO_BUCLE_PARA}   { return COMIENZO_BUCLE_PARA; }
{FIN_BUCLE_PARA}        { return FIN_BUCLE_PARA; }
{COMIENZO_SI}           { return COMIENZO_SI; }
{FIN_SI}                { return FIN_SI; }
{COMIENZO_TIPO}         { return COMIENZO_TIPO; }
{FIN_TIPO}              { return FIN_TIPO; }
{COMIENZO_VAR}          { return COMIENZO_VAR; }
{FIN_VAR}               { return FIN_VAR; }
{COMIENZO_TUPLA}        { return COMIENZO_TUPLA; }
{FIN_TUPLA}             { return FIN_TUPLA; }
{OPERADOR_MULTIPLICACION}         {yylval.entero = ENUM_MUL; return OPERADORES_MULTIPLICACION; }
{OPERADORES_DIVISION}             {yylval.entero = ENUM_DIV; return OPERADORES_MULTIPLICACION; }
{OPERADORES_COCIENTE}             {yylval.entero = ENUM_COC; return OPERADORES_MULTIPLICACION; }
{OPERADORES_RESTO}                {yylval.entero = ENUM_RESTO; return OPERADORES_MULTIPLICACION; }
{ENTRADA}                        { yylval.entero = ENUM_ENTRADA; return ENTRADA_SALIDA; }
{SALIDA}                          { yylval.entero = ENUM_SALIDA; return ENTRADA_SALIDA; }
{ENTRADA_Y_SALIDA}                { yylval.entero = ENUM_E_S; return ENTRADA_SALIDA; }
{OPERADOR_BOOLEANO_O}           { yylval.entero = ENUM_O; return OPERADORES_BOOLEANOS; }
{OPERADOR_BOOLEANO_Y}           { yylval.entero = ENUM_Y; return OPERADORES_BOOLEANOS; }
{CONTINUAR}             { return CONTINUAR; }
{DECLARADOR_TIPO_TABLA} { return DECLARADOR_TIPO_TABLA; }
{RETORNO}               { return RETORNO; }
{NEGACION}              { return NEGACION; }
{REFERENCIA}            { return REFERENCIA; }
{IDENTIFICADOR_BOOLEANO}         { yylval.cadena = strdup(yytext); return IDENTIFICADOR_BOOLEANO; }
{IDENTIFICADOR} { yylval.cadena = strdup(yytext); return IDENTIFICADOR; }
{PUNTERO}               { return PUNTERO; }
\n                      { ++yylineno; }
{SALTO_LINEA}           {/* eat up whitespace */}
.           {
            
            }


%%

