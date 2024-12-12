
%{
/* need this for the call to atof() below */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

%}


CIFRA                           [0-9]
LETRA                           [a-z]|[A-Z]
LETRA_O_CIFRA                   {LETRA}|{CIFRA}
IDENTIFICADOR                   {LETRA}{LETRA_O_CIFRA}*
LITERAL_ENTERO                  (\+|\-)?{CIFRA}+([eE](\+)?{CIFRA}+)?
LITERAL_REAL                    (\+|\-)?{CIFRA}+\.({CIFRA}+)?([eE](\+|\-)?{CIFRA}+)?|(\+|\-)?{CIFRA}+([eE](\-){CIFRA})+
LITERAL_BOOLEANO                (?i:verdadero|falso)
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
TIPO                            (?i:booleano|entero|real|cadena|caracter)
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
COMPARADORES                    >=|<=|<|>
IGUAL                           =
OPERADORES_SUMA                 \+|\-
OPERADORES_MULTIPLICACION       (?i:\*|\/|div|mod)
SIMBOLO                         _
ENTRADA_SALIDA                  (?i:ent|sal|e\/s)          
SALTO_LINEA                     [ \t\n]+ 
OPERADORES_BOOLEANOS            (?i:o|y)
CONTINUAR                       (?i:continuar) 
DECLARADOR_TIPO_TABLA           (?i:de) 
RETORNO                         (?i:dev)
NEGACION                        (?i:no)
REFERENCIA                      (?i:ref)
PUNTERO                         \.
COMIENZO_PARENTESIS             \(
FIN_PARENTESIS                  \)

%%

{LITERAL_BOOLEANO}      {
                        printf( "Literal booleano: %s\n", yytext );
                }
{LITERAL_CARACTER}      {
                        printf( "Literal caracter: %s\n", yytext );
                }
{LITERAL_ENTERO}        {
                        int entero_value = atoi(yytext);
                        double float_value = strtod(yytext, NULL);
                        printf( "Literal entero: %d, su cadena de texto es: %s\n", (int)float_value , yytext);
                }
{LITERAL_REAL}          {
                        double real_value = strtod(yytext, NULL);         
                        printf( "Literal real: %lf, su cadena de texto es: %s\n", real_value, yytext );
                }  
{OPERADORES_SUMA}    {
                        printf( "Detectado operador suma o resta: %s\n", yytext );
                }
{LITERAL_CADENA}        {
                        printf( "Literal cadena: %s\n", yytext );
                }  
{COMIENZO_INDICE}        {
                        printf( "Inicio indice: %s\n", yytext );
                }
{FIN_INDICE}        {
                        printf( "Fin indice: %s\n", yytext );
                }
{IGUAL}        {
                        printf( "Igual: %s\n", yytext );
                }
{COMPARADORES}        {
                        printf( "Comparador: %s\n", yytext );
                }


{PRECONDICION}            {
                        printf( "Precondicion: %s\n", yytext );
                }
{POSTCONDICION}            {
                        printf( "Postcondicion: %s\n", yytext );
                }
{COMENTARIO}            {
                        printf( "Comentario: %s\n", yytext );
                }
{ASIGNACION}    {
                        printf( "Detectado operador asignación: %s\n", yytext );
                }
{DELIMITADOR}    {
                        printf( "Detectado operador delimitador: %s\n", yytext );
                }
{SEPARADOR}    {
                        printf( "Detectado operador separador: %s\n", yytext );
                }
{COMIENZO_PARENTESIS}    {
                        printf( "Detectado comienzo parentesis: %s\n", yytext );
                }
{FIN_PARENTESIS}    {
                        printf( "Detectado fin parentesis: %s\n", yytext );
                }              
{ENTONCES}    {
                        printf( "Detectado operador entonces: %s\n", yytext );
                }
{ELSE}    {
                        printf( "Detectado operador else: %s\n", yytext );
                }
{RANGO}    {
                        printf( "Detectado operador rango: %s\n", yytext );
                }
{DECLARADOR_TIPO}    {
                        printf( "Detectado operador declarador de tipo: %s\n", yytext );
                }
{TIPO}          {
                        printf( "Detectado operador tipo: %s\n", yytext );
                }
{COMIENZO_ALGORITMO}            {
                        printf( "Detectado operador comienzo algoritmo: %s\n", yytext );
                }
{FIN_ALGORITMO}         {
                        printf( "Detectado operador fin algoritmo: %s\n", yytext );
                }
{COMIENZO_ACCION}    {
                        printf( "Detectado operador comienzo accion: %s\n", yytext );
                }
{FIN_ACCION}    {
                        printf( "Detectado operador fin accion: %s\n", yytext );
                }
{COMIENZO_FUNCION}    {
                        printf( "Detectado operador comienzo funcion: %s\n", yytext );
                }
{FIN_FUNCION}    {
                        printf( "Detectado operador fin funcion: %s\n", yytext );
                }
{COMIENZO_CONSTANTES}    {
                        printf( "Detectado operador comienzo constantes: %s\n", yytext );
                }
{FIN_CONSTANTES}    {
                        printf( "Detectado operador fin constantes: %s\n", yytext );
                }
{COMIENZO_BUCLE_MIENTRAS}    {
                        printf( "Detectado operador comienzo mientras: %s\n", yytext );
                }
{COMIENZO_TABLA}    {
                        printf( "Detectado comienzo de tabla: %s\n", yytext );
                }
{FIN_BUCLE_MIENTRAS}    {
                        printf( "Detectado operador fin mientras: %s\n", yytext );
                }
{COMIENZO_BUCLE_HACER}    {
                        printf( "Detectado operador comienzo hacer: %s\n", yytext );
                }
{HASTA}    {
                        printf( "Detectado operador hasta: %s\n", yytext );
                }
{COMIENZO_BUCLE_PARA}    {
                        printf( "Detectado operador comienzo para: %s\n", yytext );
                }
{FIN_BUCLE_PARA}    {
                        printf( "Detectado operador fin para: %s\n", yytext );
                }
{COMIENZO_SI}    {
                        printf( "Detectado operador comienzo si: %s\n", yytext );
                }
{FIN_SI}    {
                        printf( "Detectado operador fin si: %s\n", yytext );
                }
{COMIENZO_TIPO}    {
                        printf( "Detectado operador comienzo tipo: %s\n", yytext );
                }
{FIN_TIPO}    {
                        printf( "Detectado operador fin tipo: %s\n", yytext );
                }
{COMIENZO_VAR}    {
                        printf( "Detectado operador comienzo var: %s\n", yytext );
                }
{FIN_VAR}    {
                        printf( "Detectado operador fin var: %s\n", yytext );
                }
{COMIENZO_TUPLA}    {
                        printf( "Detectado operador comienzo tupla: %s\n", yytext );
                }
{FIN_TUPLA}    {
                        printf( "Detectado operador fin tupla: %s\n", yytext );
                }

{OPERADORES_MULTIPLICACION}    {
                        printf( "Detectado operador multiplicacion o division: %s\n", yytext );
                }
{SIMBOLO}    {
                        printf( "Detectado simbolo: %s\n", yytext );
                }
{ENTRADA_SALIDA}    {
                        printf( "Detectado operador entrada salida: %s\n", yytext );
                }
{OPERADORES_BOOLEANOS}    {
                        printf( "Detectado operador booleano: %s\n", yytext );
                }
{CONTINUAR}    {
                        printf( "Detectado operador continuar: %s\n", yytext );
                }
{DECLARADOR_TIPO_TABLA}    {
                        printf( "Detectado operador declarador tipo tabla: %s\n", yytext );
                }
{RETORNO}    {
                        printf( "Detectado operador de retorno: %s\n", yytext );
                }
{NEGACION}    {
                        printf( "Detectado operador negacion: %s\n", yytext );
                }
{REFERENCIA}    {
                        printf( "Detectado operador referencia: %s\n", yytext );
                }
{IDENTIFICADOR}         {
                        printf("Identificador encontrado: %s\n",yytext);
                }
{PUNTERO}         {
                        printf("Puntero encontrado: %s\n",yytext);
                }

{SALTO_LINEA}         /* eat up whitespace */

.           {
            
            }

%%

int main( int argc, char **argv )
    {
    ++argv, --argc;  /* skip over program name */
    if ( argc > 0 )
            yyin = fopen( argv[0], "r" );
    else
            yyin = stdin;

    yylex();
    }
