
%{
#include <math.h>
#include "parser.tab.h"
%}
%option case-insensitive


/* Identificadores */
CIFRA	[0-9]
CARACTER [a-z0-9/(){}\[\] ,_;.:-]
LITERAL_ENTERO_J [+-]?{CIFRA}{CIFRA}*([eE]{CIFRA}{CIFRA}*)?
LITERAL_REAL_J    [+-]?{CIFRA}{CIFRA}*(\.{CIFRA}{CIFRA}*)?([eE]{CIFRA}{CIFRA}*)?
LITERAL_BOOLEANO_J verdadero|falso
LITERAL_CARACTER_J    \"{CARACTER}\"
LITERAL_CADENA_J  \'{CARACTER}*\'
LITERAL_NUMERICO_J    {LITERAL_ENTERO_J}|{LITERAL_REAL_J}

COMENTARIO_J \{([^\}]|\/\})*\}
ALGORITMO_J algoritmo
ACCION_J accion
FACCION_J faccion
FUNCION_J funcion
FFUNCION_J ffuncion
FALGORITMO_J falgoritmo
CONST_J const
CONTINUAR_J continuar
DE_J de
DEV_J dev
DIV_J div
ENT_J ent
ENTRADA_SALIDA_J e\/s
FALSO_J falso
FCONST_J fconst
FMIENTRAS_J fmientras
FPARA_J fpara
FSI_J fsi
FTIPO_J ftipo
FTUPLA_J ftupla
FVAR_J fvar
HACER_J hacer
HASTA_J hasta
MIENTRAS_J mientras
MOD_J \%
NO_J no
PARA_J para
SAL_J sal
SI_J si
TABLA_J tabla
TIPO_J tipo
TUPLA_J tupla
VAR_J var
VERDADERO_J verdadero
COMA_J ,
PUNTOPUNTO_J \.\.
DOSPUNTOS_J :
DOSPUNTOSIGUAL_J :=
ID_J ([a-z]|[A-Z])[a-zA-Z0-9]*
PUNTOCOMA_J ;
CORCHETECERRAR_J \]
MAS_J \+
MENOS_J \-
POR_J \*
ENTRE_J \/
PARENTESISABRIR_J \(
PARENTESISCERRAR_J  \)
MENOR_J \<
MAYOR_J \>
IGUAL_J \=
DISTINTO_J \<\>
MAYOR_IGUAL_J \>\=
MENOR_IGUAL_J \<\=
FLECHA_J \-\>
ENTERO_J entero
REAL_J real
BOOLEANO_J booleano
CARACTER_J caracter
STRING_J cadena
ID_A_J [a-zA-Z0-9]*
ID_B_J [bB][a-zA-Z0-9]*
O_J OR
Y_J AND
CORCHETEABRIR_J \[
PUNTO_J \.
REF_J ref
NEG_J \-
ELSE_J \[\]


%%
{ELSE_J} {return ELSE;}
{CORCHETECERRAR_J} {return CORCHETECERRAR;}
{CORCHETEABRIR_J} {return CORCHETEABRIR;}
{LITERAL_ENTERO_J} {return LITERAL_ENTERO;}
{LITERAL_REAL_J} {return LITERAL_REAL;}
{LITERAL_BOOLEANO_J} {return LITERAL_BOOLEANO;}
{LITERAL_CARACTER_J} {return LITERAL_CARACTER;}
{COMENTARIO_J} {return COMENTARIO;}
{ALGORITMO_J} {return ALGORITMO;}
{ACCION_J} {return ACCION;}
{FACCION_J} {return FACCION;}
{FUNCION_J} {return FUNCION;}
{FFUNCION_J} {return FFUNCION;}
{FALGORITMO_J} {return FALGORITMO;}
{CONST_J} {return CONST;}
{CONTINUAR_J} {return CONTINUAR;}
{DE_J} {return DE;}
{DEV_J} {return DEV;}
{DIV_J} {return DIV;}
{ENT_J} {return ENT;}
{ENTRADA_SALIDA_J} {return ENTRADA_SALIDA;}

{FCONST_J} {return FCONST;}
{FMIENTRAS_J} {return FMIENTRAS;}
{FPARA_J} {return FPARA;}
{FSI_J} {return FSI;}
{FTIPO_J} {return FTIPO;}
{FTUPLA_J} {return FTUPLA;}
{FVAR_J} {return FVAR;}
{HACER_J} {return HACER;}
{HASTA_J} {return HASTA;}
{MIENTRAS_J} {return MIENTRAS;}
{MOD_J} {return MOD;}
{NO_J} {return NO;}
{PARA_J} {return PARA;}
{SAL_J} {return SAL;}
{SI_J} {return SI;}
{TABLA_J} {return TABLA;}
{TIPO_J} {return TIPO;}
{TUPLA_J} {return TUPLA;}
{VAR_J} {return VAR;}
{COMA_J} {return COMA;}
{PUNTOPUNTO_J} {return PUNTOPUNTO;}
{DOSPUNTOS_J} {return DOSPUNTOS;}
{DOSPUNTOSIGUAL_J} {return DOSPUNTOSIGUAL;}
{PUNTOCOMA_J} {return PUNTOCOMA;}
{MAS_J} {return MAS;}
{MENOS_J} {return MENOS;}
{POR_J} {return POR;}
{ENTRE_J} {return ENTRE;}
{PARENTESISABRIR_J} {return PARENTESISABRIR;}
{PARENTESISCERRAR_J} {return PARENTESISCERRAR;}

{MENOR_J} {yylval.oprel = MENOR_ENUM;
	return OPREL;}
{MAYOR_J} {yylval.oprel = MAYOR_ENUM;
	return OPREL;}
{IGUAL_J} {yylval.oprel = IGUAL_ENUM;
	return OPREL;}
{DISTINTO_J} {yylval.oprel = DISTINTO_ENUM;
	return OPREL;}
{MAYOR_IGUAL_J} {yylval.oprel = MAYOR_IGUAL_ENUM;
	return OPREL;}
{MENOR_IGUAL_J} {yylval.oprel = MENOR_IGUAL_ENUM;
	return OPREL;}
{FLECHA_J} {return FLECHA;}
{ENTERO_J} {
    yylval.tipoBase = ENTERO_ENUM;
    return TIPOBASE;
    }
{REAL_J} {
    yylval.tipoBase = REAL_ENUM;
    return TIPOBASE;
    }
{BOOLEANO_J} {
    yylval.tipoBase = BOOLEANO_ENUM;
    return TIPOBASE;
    }
{CARACTER_J} {
    yylval.tipoBase = CARACTER_ENUM;
    return TIPOBASE;
    }
{STRING_J} {
    yylval.tipoBase = STRING_ENUM;
    return TIPOBASE;
    }
{O_J} {return O;}
{Y_J} {return Y;}
{REF_J} {return REF;}
{ID_B_J} {
    strcpy(yylval.cadena,strdup(yytext));
    return ID_B;
    }
{ID_A_J} {
    strcpy(yylval.cadena,strdup(yytext));
    return ID_A;
    }
{PUNTO_J} {return PUNTO;}


%%
