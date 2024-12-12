/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PROGRAMA_TAB_H_INCLUDED
# define YY_YY_PROGRAMA_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    LITERAL_CARACTER = 258,        /* LITERAL_CARACTER  */
    ASIGNACION = 259,              /* ASIGNACION  */
    DELIMITADOR = 260,             /* DELIMITADOR  */
    SEPARADOR = 261,               /* SEPARADOR  */
    COMIENZO_ALGORITMO = 262,      /* COMIENZO_ALGORITMO  */
    FIN_ALGORITMO = 263,           /* FIN_ALGORITMO  */
    COMIENZO_PARENTESIS = 264,     /* COMIENZO_PARENTESIS  */
    FIN_PARENTESIS = 265,          /* FIN_PARENTESIS  */
    COMIENZO_ACCION = 266,         /* COMIENZO_ACCION  */
    FIN_ACCION = 267,              /* FIN_ACCION  */
    COMIENZO_FUNCION = 268,        /* COMIENZO_FUNCION  */
    FIN_FUNCION = 269,             /* FIN_FUNCION  */
    COMIENZO_CONSTANTES = 270,     /* COMIENZO_CONSTANTES  */
    FIN_CONSTANTES = 271,          /* FIN_CONSTANTES  */
    COMIENZO_BUCLE_MIENTRAS = 272, /* COMIENZO_BUCLE_MIENTRAS  */
    FIN_BUCLE_MIENTRAS = 273,      /* FIN_BUCLE_MIENTRAS  */
    COMIENZO_BUCLE_HACER = 274,    /* COMIENZO_BUCLE_HACER  */
    HASTA = 275,                   /* HASTA  */
    COMIENZO_BUCLE_PARA = 276,     /* COMIENZO_BUCLE_PARA  */
    FIN_BUCLE_PARA = 277,          /* FIN_BUCLE_PARA  */
    COMIENZO_VAR = 278,            /* COMIENZO_VAR  */
    FIN_VAR = 279,                 /* FIN_VAR  */
    DECLARADOR_TIPO = 280,         /* DECLARADOR_TIPO  */
    COMIENZO_SI = 281,             /* COMIENZO_SI  */
    FIN_SI = 282,                  /* FIN_SI  */
    ENTONCES = 283,                /* ENTONCES  */
    ELSE = 284,                    /* ELSE  */
    RETORNO = 285,                 /* RETORNO  */
    NEGACION = 286,                /* NEGACION  */
    PRECONDICION = 287,            /* PRECONDICION  */
    POSTCONDICION = 288,           /* POSTCONDICION  */
    COMIENZO_TIPO = 289,           /* COMIENZO_TIPO  */
    FIN_TIPO = 290,                /* FIN_TIPO  */
    COMIENZO_TUPLA = 291,          /* COMIENZO_TUPLA  */
    FIN_TUPLA = 292,               /* FIN_TUPLA  */
    COMIENZO_TABLA = 293,          /* COMIENZO_TABLA  */
    RANGO = 294,                   /* RANGO  */
    DECLARADOR_TIPO_TABLA = 295,   /* DECLARADOR_TIPO_TABLA  */
    COMIENZO_INDICE = 296,         /* COMIENZO_INDICE  */
    FIN_INDICE = 297,              /* FIN_INDICE  */
    REFERENCIA = 298,              /* REFERENCIA  */
    PUNTERO = 299,                 /* PUNTERO  */
    CONTINUAR = 300,               /* CONTINUAR  */
    LITERAL_REAL = 301,            /* LITERAL_REAL  */
    LITERAL_CADENA = 302,          /* LITERAL_CADENA  */
    IDENTIFICADOR_BOOLEANO = 303,  /* IDENTIFICADOR_BOOLEANO  */
    IDENTIFICADOR = 304,           /* IDENTIFICADOR  */
    LITERAL_ENTERO = 305,          /* LITERAL_ENTERO  */
    OPERADORES_MULTIPLICACION = 306, /* OPERADORES_MULTIPLICACION  */
    OPERADORES_SUMA = 307,         /* OPERADORES_SUMA  */
    LITERAL_BOOLEANO = 308,        /* LITERAL_BOOLEANO  */
    IGUAL = 309,                   /* IGUAL  */
    COMPARADORES = 310,            /* COMPARADORES  */
    TIPO = 311,                    /* TIPO  */
    ENTRADA_SALIDA = 312,          /* ENTRADA_SALIDA  */
    OPERADORES_BOOLEANOS = 313     /* OPERADORES_BOOLEANOS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "programa.y"

    TipoExp expresion;
    TipoBool expresion_bool;
    IdList listaId;
    int entero;
    float real;
    char* cadena;
    enum type type;
    TipoM param;

#line 133 "programa.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PROGRAMA_TAB_H_INCLUDED  */
