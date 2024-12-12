/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "programa.y"

    #include <stdio.h>
    #include <stdlib.h>
    extern FILE *yyin;  // Declaración de yyin para Flex
    extern int yylex();
    void yyerror(const char *s);
    #include "symbol_table.h"
    #include "definitions.h"
    #include "cuadruple_table.h"


#line 83 "programa.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "programa.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LITERAL_CARACTER = 3,           /* LITERAL_CARACTER  */
  YYSYMBOL_ASIGNACION = 4,                 /* ASIGNACION  */
  YYSYMBOL_DELIMITADOR = 5,                /* DELIMITADOR  */
  YYSYMBOL_SEPARADOR = 6,                  /* SEPARADOR  */
  YYSYMBOL_COMIENZO_ALGORITMO = 7,         /* COMIENZO_ALGORITMO  */
  YYSYMBOL_FIN_ALGORITMO = 8,              /* FIN_ALGORITMO  */
  YYSYMBOL_COMIENZO_PARENTESIS = 9,        /* COMIENZO_PARENTESIS  */
  YYSYMBOL_FIN_PARENTESIS = 10,            /* FIN_PARENTESIS  */
  YYSYMBOL_COMIENZO_ACCION = 11,           /* COMIENZO_ACCION  */
  YYSYMBOL_FIN_ACCION = 12,                /* FIN_ACCION  */
  YYSYMBOL_COMIENZO_FUNCION = 13,          /* COMIENZO_FUNCION  */
  YYSYMBOL_FIN_FUNCION = 14,               /* FIN_FUNCION  */
  YYSYMBOL_COMIENZO_CONSTANTES = 15,       /* COMIENZO_CONSTANTES  */
  YYSYMBOL_FIN_CONSTANTES = 16,            /* FIN_CONSTANTES  */
  YYSYMBOL_COMIENZO_BUCLE_MIENTRAS = 17,   /* COMIENZO_BUCLE_MIENTRAS  */
  YYSYMBOL_FIN_BUCLE_MIENTRAS = 18,        /* FIN_BUCLE_MIENTRAS  */
  YYSYMBOL_COMIENZO_BUCLE_HACER = 19,      /* COMIENZO_BUCLE_HACER  */
  YYSYMBOL_HASTA = 20,                     /* HASTA  */
  YYSYMBOL_COMIENZO_BUCLE_PARA = 21,       /* COMIENZO_BUCLE_PARA  */
  YYSYMBOL_FIN_BUCLE_PARA = 22,            /* FIN_BUCLE_PARA  */
  YYSYMBOL_COMIENZO_VAR = 23,              /* COMIENZO_VAR  */
  YYSYMBOL_FIN_VAR = 24,                   /* FIN_VAR  */
  YYSYMBOL_DECLARADOR_TIPO = 25,           /* DECLARADOR_TIPO  */
  YYSYMBOL_COMIENZO_SI = 26,               /* COMIENZO_SI  */
  YYSYMBOL_FIN_SI = 27,                    /* FIN_SI  */
  YYSYMBOL_ENTONCES = 28,                  /* ENTONCES  */
  YYSYMBOL_ELSE = 29,                      /* ELSE  */
  YYSYMBOL_RETORNO = 30,                   /* RETORNO  */
  YYSYMBOL_NEGACION = 31,                  /* NEGACION  */
  YYSYMBOL_PRECONDICION = 32,              /* PRECONDICION  */
  YYSYMBOL_POSTCONDICION = 33,             /* POSTCONDICION  */
  YYSYMBOL_COMIENZO_TIPO = 34,             /* COMIENZO_TIPO  */
  YYSYMBOL_FIN_TIPO = 35,                  /* FIN_TIPO  */
  YYSYMBOL_COMIENZO_TUPLA = 36,            /* COMIENZO_TUPLA  */
  YYSYMBOL_FIN_TUPLA = 37,                 /* FIN_TUPLA  */
  YYSYMBOL_COMIENZO_TABLA = 38,            /* COMIENZO_TABLA  */
  YYSYMBOL_RANGO = 39,                     /* RANGO  */
  YYSYMBOL_DECLARADOR_TIPO_TABLA = 40,     /* DECLARADOR_TIPO_TABLA  */
  YYSYMBOL_COMIENZO_INDICE = 41,           /* COMIENZO_INDICE  */
  YYSYMBOL_FIN_INDICE = 42,                /* FIN_INDICE  */
  YYSYMBOL_REFERENCIA = 43,                /* REFERENCIA  */
  YYSYMBOL_PUNTERO = 44,                   /* PUNTERO  */
  YYSYMBOL_CONTINUAR = 45,                 /* CONTINUAR  */
  YYSYMBOL_LITERAL_REAL = 46,              /* LITERAL_REAL  */
  YYSYMBOL_LITERAL_CADENA = 47,            /* LITERAL_CADENA  */
  YYSYMBOL_IDENTIFICADOR_BOOLEANO = 48,    /* IDENTIFICADOR_BOOLEANO  */
  YYSYMBOL_IDENTIFICADOR = 49,             /* IDENTIFICADOR  */
  YYSYMBOL_LITERAL_ENTERO = 50,            /* LITERAL_ENTERO  */
  YYSYMBOL_OPERADORES_MULTIPLICACION = 51, /* OPERADORES_MULTIPLICACION  */
  YYSYMBOL_OPERADORES_SUMA = 52,           /* OPERADORES_SUMA  */
  YYSYMBOL_LITERAL_BOOLEANO = 53,          /* LITERAL_BOOLEANO  */
  YYSYMBOL_IGUAL = 54,                     /* IGUAL  */
  YYSYMBOL_COMPARADORES = 55,              /* COMPARADORES  */
  YYSYMBOL_TIPO = 56,                      /* TIPO  */
  YYSYMBOL_ENTRADA_SALIDA = 57,            /* ENTRADA_SALIDA  */
  YYSYMBOL_OPERADORES_BOOLEANOS = 58,      /* OPERADORES_BOOLEANOS  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_desc_algoritmo = 60,            /* desc_algoritmo  */
  YYSYMBOL_cabecera_alg = 61,              /* cabecera_alg  */
  YYSYMBOL_bloque_alg = 62,                /* bloque_alg  */
  YYSYMBOL_decl_globales = 63,             /* decl_globales  */
  YYSYMBOL_decl_a_f = 64,                  /* decl_a_f  */
  YYSYMBOL_bloque = 65,                    /* bloque  */
  YYSYMBOL_declaraciones = 66,             /* declaraciones  */
  YYSYMBOL_declaracion_tipo = 67,          /* declaracion_tipo  */
  YYSYMBOL_declaracion_const = 68,         /* declaracion_const  */
  YYSYMBOL_declaracion_var = 69,           /* declaracion_var  */
  YYSYMBOL_lista_d_tipo = 70,              /* lista_d_tipo  */
  YYSYMBOL_d_tipo = 71,                    /* d_tipo  */
  YYSYMBOL_expresion_t = 72,               /* expresion_t  */
  YYSYMBOL_lista_campos = 73,              /* lista_campos  */
  YYSYMBOL_lista_d_cte = 74,               /* lista_d_cte  */
  YYSYMBOL_literal = 75,                   /* literal  */
  YYSYMBOL_lista_d_var = 76,               /* lista_d_var  */
  YYSYMBOL_lista_id = 77,                  /* lista_id  */
  YYSYMBOL_decl_ent_sal = 78,              /* decl_ent_sal  */
  YYSYMBOL_expresion = 79,                 /* expresion  */
  YYSYMBOL_exp_a = 80,                     /* exp_a  */
  YYSYMBOL_literal_numerico = 81,          /* literal_numerico  */
  YYSYMBOL_exp_b = 82,                     /* exp_b  */
  YYSYMBOL_m = 83,                         /* m  */
  YYSYMBOL_operando = 84,                  /* operando  */
  YYSYMBOL_operando_b = 85,                /* operando_b  */
  YYSYMBOL_instrucciones = 86,             /* instrucciones  */
  YYSYMBOL_instruccion = 87,               /* instruccion  */
  YYSYMBOL_asignacion = 88,                /* asignacion  */
  YYSYMBOL_alternativa = 89,               /* alternativa  */
  YYSYMBOL_lista_opciones = 90,            /* lista_opciones  */
  YYSYMBOL_iteracion = 91,                 /* iteracion  */
  YYSYMBOL_it_cota_exp = 92,               /* it_cota_exp  */
  YYSYMBOL_it_cota_fija = 93,              /* it_cota_fija  */
  YYSYMBOL_accion_d = 94,                  /* accion_d  */
  YYSYMBOL_funcion_d = 95,                 /* funcion_d  */
  YYSYMBOL_a_cabecera = 96,                /* a_cabecera  */
  YYSYMBOL_f_cabecera = 97,                /* f_cabecera  */
  YYSYMBOL_d_par_form = 98,                /* d_par_form  */
  YYSYMBOL_d_p_form = 99,                  /* d_p_form  */
  YYSYMBOL_accion_ll = 100,                /* accion_ll  */
  YYSYMBOL_funcion_ll = 101,               /* funcion_ll  */
  YYSYMBOL_l_ll = 102                      /* l_ll  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   249

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  219

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   313


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    70,    70,    74,    78,    82,    83,    84,    88,    89,
      90,    94,    98,    99,   100,   101,   105,   110,   114,   118,
     119,   123,   124,   128,   129,   130,   131,   139,   140,   144,
     145,   149,   150,   154,   155,   156,   157,   158,   163,   172,
     176,   186,   196,   207,   220,   221,   226,   227,   228,   232,
     256,   281,   284,   287,   290,   306,   308,   312,   329,   334,
     341,   343,   349,   355,   361,   366,   370,   371,   372,   376,
     383,   384,   388,   389,   390,   391,   392,   396,   416,   429,
     433,   434,   438,   439,   443,   447,   451,   455,   459,   463,
     467,   468,   472,   476,   480,   484,   485
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "LITERAL_CARACTER",
  "ASIGNACION", "DELIMITADOR", "SEPARADOR", "COMIENZO_ALGORITMO",
  "FIN_ALGORITMO", "COMIENZO_PARENTESIS", "FIN_PARENTESIS",
  "COMIENZO_ACCION", "FIN_ACCION", "COMIENZO_FUNCION", "FIN_FUNCION",
  "COMIENZO_CONSTANTES", "FIN_CONSTANTES", "COMIENZO_BUCLE_MIENTRAS",
  "FIN_BUCLE_MIENTRAS", "COMIENZO_BUCLE_HACER", "HASTA",
  "COMIENZO_BUCLE_PARA", "FIN_BUCLE_PARA", "COMIENZO_VAR", "FIN_VAR",
  "DECLARADOR_TIPO", "COMIENZO_SI", "FIN_SI", "ENTONCES", "ELSE",
  "RETORNO", "NEGACION", "PRECONDICION", "POSTCONDICION", "COMIENZO_TIPO",
  "FIN_TIPO", "COMIENZO_TUPLA", "FIN_TUPLA", "COMIENZO_TABLA", "RANGO",
  "DECLARADOR_TIPO_TABLA", "COMIENZO_INDICE", "FIN_INDICE", "REFERENCIA",
  "PUNTERO", "CONTINUAR", "LITERAL_REAL", "LITERAL_CADENA",
  "IDENTIFICADOR_BOOLEANO", "IDENTIFICADOR", "LITERAL_ENTERO",
  "OPERADORES_MULTIPLICACION", "OPERADORES_SUMA", "LITERAL_BOOLEANO",
  "IGUAL", "COMPARADORES", "TIPO", "ENTRADA_SALIDA",
  "OPERADORES_BOOLEANOS", "$accept", "desc_algoritmo", "cabecera_alg",
  "bloque_alg", "decl_globales", "decl_a_f", "bloque", "declaraciones",
  "declaracion_tipo", "declaracion_const", "declaracion_var",
  "lista_d_tipo", "d_tipo", "expresion_t", "lista_campos", "lista_d_cte",
  "literal", "lista_d_var", "lista_id", "decl_ent_sal", "expresion",
  "exp_a", "literal_numerico", "exp_b", "m", "operando", "operando_b",
  "instrucciones", "instruccion", "asignacion", "alternativa",
  "lista_opciones", "iteracion", "it_cota_exp", "it_cota_fija", "accion_d",
  "funcion_d", "a_cabecera", "f_cabecera", "d_par_form", "d_p_form",
  "accion_ll", "funcion_ll", "l_ll", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-116)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-48)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,   -11,    42,    41,  -116,    10,    20,    31,     9,    18,
      10,    10,    17,    76,    44,    50,   123,    87,    29,   158,
       9,     9,     9,    58,    65,    66,    18,    18,  -116,  -116,
      11,   114,   102,   121,   124,   126,   110,   117,  -116,  -116,
     137,    90,   137,  -116,  -116,   140,    43,   149,  -116,   162,
    -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,   164,
       9,   173,     9,   123,   156,  -116,  -116,  -116,  -116,  -116,
    -116,  -116,   188,  -116,  -116,   137,   137,   153,   169,   102,
    -116,    21,  -116,     4,  -116,  -116,   205,   174,   142,   147,
    -116,   154,    69,  -116,  -116,  -116,   123,   123,   209,   102,
     206,    62,   212,    -6,   137,     4,   137,  -116,   168,   137,
     158,   161,   207,   123,   190,   165,  -116,    20,   142,    27,
       8,   146,   196,   186,   128,  -116,   137,     4,  -116,   175,
      31,   128,   137,   137,     4,     4,  -116,  -116,  -116,  -116,
     219,   158,   137,   158,    22,   215,   147,    46,  -116,    89,
    -116,   123,   217,   223,  -116,   220,   137,   123,  -116,  -116,
    -116,   102,  -116,   192,   222,    27,  -116,  -116,  -116,  -116,
    -116,   175,   137,   123,   211,    -3,   204,   137,  -116,  -116,
     210,   229,   161,   208,     5,  -116,   231,   128,  -116,   146,
    -116,  -116,   137,   137,   213,  -116,   102,  -116,  -116,   102,
    -116,   153,   195,    74,    54,  -116,  -116,   234,  -116,   201,
     158,   158,  -116,   102,   221,   204,  -116,  -116,  -116
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     7,    32,    20,    15,    10,
       7,     7,     0,     0,     0,     0,    39,     0,     0,     0,
      15,    15,    15,     0,     0,     0,    10,    10,     5,     6,
       0,     0,     0,     0,    43,    42,     0,     0,     2,     4,
       0,     0,     0,    72,    69,    65,     0,     0,    11,    71,
      73,    74,    75,    83,    82,    76,    12,    13,    14,     0,
      15,     0,    15,    39,     0,     8,     9,    35,    37,    34,
      36,    33,     0,    17,    28,     0,     0,    30,     0,     0,
      56,    65,    55,     0,    60,    26,     0,     0,    27,    46,
      53,    47,    52,    59,    48,    16,     0,     0,     0,     0,
      65,     0,     0,     0,     0,     0,     0,    68,     0,     0,
       0,    91,     0,    39,     0,    44,     3,    32,     0,    46,
      47,    58,     0,     0,     0,    25,     0,     0,    65,    54,
      20,     0,     0,     0,     0,     0,    64,    41,    40,    18,
       0,     0,     0,     0,    96,     0,    77,     0,    66,    78,
      70,     0,     0,     0,    86,     0,     0,    39,    31,    51,
      63,     0,    21,     0,     0,     0,    19,    24,    62,    61,
      50,    49,     0,    39,     0,     0,    81,     0,    93,    67,
       0,     0,    91,     0,     0,    45,     0,     0,    94,    57,
      38,    84,     0,     0,     0,    95,     0,    88,    90,     0,
      87,    30,     0,     0,     0,    79,    92,     0,    29,     0,
       0,     0,    89,     0,     0,    81,    22,    85,    80
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,  -116,  -116,   194,   182,   -26,   141,   155,   159,
    -116,   112,   -78,  -115,    45,   127,  -116,   -58,   -86,  -116,
     -36,   -60,  -116,   -68,  -116,   -19,   -16,  -108,  -116,  -116,
    -116,    30,  -116,  -116,  -116,  -116,  -116,  -116,  -116,    67,
    -116,  -116,  -116,  -114
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     8,    17,     9,    25,    18,    19,    20,    21,
      22,    15,    86,    87,   123,    13,    72,    36,    37,    64,
      88,    89,    90,    91,   172,    92,    93,    48,    49,    50,
      51,   194,    52,    53,    54,    26,    27,    60,    62,   152,
     153,    55,    94,   145
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      46,   125,   150,    47,   101,   115,   103,   120,   121,   163,
     137,   138,   164,   127,    67,   119,   167,   192,   160,   200,
       1,   140,   143,   129,     6,     6,   -23,   -23,   177,    23,
     126,    24,    16,   174,   112,   176,   114,   159,     3,   118,
     118,   149,     4,     7,     7,   146,     5,   105,   132,   133,
      80,   132,   133,   128,    82,   155,    83,    68,    69,   132,
     133,    70,    39,   195,    71,   180,   136,   165,   144,    12,
     147,    30,   202,   118,   170,   171,   132,   133,   134,   135,
      14,   141,   211,   186,   106,    33,   107,   108,   179,   148,
     144,    46,    31,   210,    47,    38,   168,   169,    32,   185,
     132,   133,   214,   215,   189,    74,   175,    59,   132,   133,
     106,    75,   107,   108,    61,   190,   132,   133,   206,    73,
     184,   207,    46,    63,    46,    47,    95,    47,   132,   133,
      96,    74,    97,    76,    98,   216,   118,    75,    77,   102,
      78,   144,    99,   -47,   -47,    79,    75,   136,    80,   104,
      44,    81,    82,   109,    83,    84,   203,   204,    85,    76,
      10,    56,    57,    58,    11,    10,    10,   110,    76,    11,
      11,    34,    35,   111,    80,    40,    44,   100,    82,    41,
      83,    84,   113,    80,    42,    44,   100,    82,   116,    83,
      84,    46,    46,   117,    47,    47,   132,   133,   134,   135,
     -47,   -47,   122,    43,    28,    29,    44,    45,    65,    66,
     124,   130,   136,   131,   139,   126,   142,   128,   151,   154,
     156,   161,   157,   162,   173,   178,   134,   181,   182,   191,
     183,   187,   188,   193,   197,   196,   201,   209,   199,   212,
     205,   213,   166,   217,   158,   218,   208,     0,     0,   198
};

static const yytype_int16 yycheck[] =
{
      19,    79,   110,    19,    40,    63,    42,    75,    76,   124,
      96,    97,   126,     9,     3,    75,   131,    20,    10,    14,
       7,    99,    28,    83,    15,    15,     5,     6,     6,    11,
       9,    13,    23,   141,    60,   143,    62,    10,    49,    75,
      76,   109,     0,    34,    34,   105,     5,     4,    54,    55,
      46,    54,    55,    49,    50,   113,    52,    46,    47,    54,
      55,    50,    33,   177,    53,   151,    58,   127,   104,    49,
     106,    54,   187,   109,   134,   135,    54,    55,    51,    52,
      49,    19,    28,   161,    41,    35,    43,    44,    42,   108,
     126,   110,    16,    19,   110,     8,   132,   133,    54,   157,
      54,    55,   210,   211,   172,     3,   142,    49,    54,    55,
      41,     9,    43,    44,    49,   173,    54,    55,   196,     5,
     156,   199,   141,    57,   143,   141,     5,   143,    54,    55,
       6,     3,     6,    31,    24,   213,   172,     9,    36,    49,
      38,   177,    25,    54,    55,    43,     9,    58,    46,     9,
      48,    49,    50,     4,    52,    53,   192,   193,    56,    31,
       5,    20,    21,    22,     5,    10,    11,     5,    31,    10,
      11,    48,    49,     9,    46,    17,    48,    49,    50,    21,
      52,    53,     9,    46,    26,    48,    49,    50,    32,    52,
      53,   210,   211,     5,   210,   211,    54,    55,    51,    52,
      54,    55,    49,    45,    10,    11,    48,    49,    26,    27,
      41,     6,    58,    39,     5,     9,     4,    49,    57,    12,
      30,    25,    57,    37,     5,    10,    51,    10,     5,    18,
      10,    39,    10,    29,     5,    25,     5,    42,    30,     5,
      27,    40,   130,    22,   117,   215,   201,    -1,    -1,   182
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    60,    49,     0,     5,    15,    34,    61,    63,
      67,    68,    49,    74,    49,    70,    23,    62,    65,    66,
      67,    68,    69,    11,    13,    64,    94,    95,    63,    63,
      54,    16,    54,    35,    48,    49,    76,    77,     8,    33,
      17,    21,    26,    45,    48,    49,    84,    85,    86,    87,
      88,    89,    91,    92,    93,   100,    66,    66,    66,    49,
      96,    49,    97,    57,    78,    64,    64,     3,    46,    47,
      50,    53,    75,     5,     3,     9,    31,    36,    38,    43,
      46,    49,    50,    52,    53,    56,    71,    72,    79,    80,
      81,    82,    84,    85,   101,     5,     6,     6,    24,    25,
      49,    79,    49,    79,     9,     4,    41,    43,    44,     4,
       5,     9,    65,     9,    65,    76,    32,     5,    79,    80,
      82,    82,    49,    73,    41,    71,     9,     9,    49,    80,
       6,    39,    54,    55,    51,    52,    58,    77,    77,     5,
      71,    19,     4,    28,    79,   102,    80,    79,    84,    82,
      86,    57,    98,    99,    12,    76,    30,    57,    74,    10,
      10,    25,    37,    72,   102,    80,    70,    72,    79,    79,
      80,    80,    83,     5,    86,    79,    86,     6,    10,    42,
      77,    10,     5,    10,    79,    76,    71,    39,    10,    82,
      76,    18,    20,    29,    90,   102,    25,     5,    98,    30,
      14,     5,    72,    79,    79,    27,    71,    71,    73,    42,
      19,    28,     5,    40,    86,    86,    71,    22,    90
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    61,    62,    63,    63,    63,    64,    64,
      64,    65,    66,    66,    66,    66,    67,    68,    69,    70,
      70,    71,    71,    71,    71,    71,    71,    72,    72,    73,
      73,    74,    74,    75,    75,    75,    75,    75,    76,    76,
      77,    77,    77,    77,    78,    78,    79,    79,    79,    80,
      80,    80,    80,    80,    80,    81,    81,    82,    82,    82,
      82,    82,    82,    82,    83,    84,    84,    84,    84,    85,
      86,    86,    87,    87,    87,    87,    87,    88,    88,    89,
      90,    90,    91,    91,    92,    93,    94,    95,    96,    97,
      98,    98,    99,   100,   101,   102,   102
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     4,     2,     2,     2,     0,     2,     2,
       0,     2,     2,     2,     2,     0,     4,     4,     4,     5,
       0,     3,     8,     1,     3,     2,     1,     1,     1,     5,
       0,     5,     0,     1,     1,     1,     1,     1,     5,     0,
       3,     3,     1,     1,     2,     4,     1,     1,     1,     3,
       3,     3,     1,     1,     2,     1,     1,     4,     2,     1,
       1,     3,     3,     3,     0,     1,     3,     4,     2,     1,
       3,     1,     1,     1,     1,     1,     1,     3,     3,     6,
       5,     0,     1,     1,     5,     9,     4,     6,     5,     7,
       3,     0,     4,     4,     4,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* desc_algoritmo: COMIENZO_ALGORITMO IDENTIFICADOR DELIMITADOR cabecera_alg bloque_alg FIN_ALGORITMO  */
#line 70 "programa.y"
                                                                                       { printf("Programa reconocido correctamente.\n"); }
#line 1333 "programa.tab.c"
    break;

  case 3: /* cabecera_alg: decl_globales decl_a_f decl_ent_sal PRECONDICION  */
#line 74 "programa.y"
                                                     {}
#line 1339 "programa.tab.c"
    break;

  case 4: /* bloque_alg: bloque POSTCONDICION  */
#line 78 "programa.y"
                         {}
#line 1345 "programa.tab.c"
    break;

  case 5: /* decl_globales: declaracion_tipo decl_globales  */
#line 82 "programa.y"
                                   {}
#line 1351 "programa.tab.c"
    break;

  case 6: /* decl_globales: declaracion_const decl_globales  */
#line 83 "programa.y"
                                      {}
#line 1357 "programa.tab.c"
    break;

  case 7: /* decl_globales: %empty  */
#line 84 "programa.y"
                {}
#line 1363 "programa.tab.c"
    break;

  case 8: /* decl_a_f: accion_d decl_a_f  */
#line 88 "programa.y"
                      {}
#line 1369 "programa.tab.c"
    break;

  case 9: /* decl_a_f: funcion_d decl_a_f  */
#line 89 "programa.y"
                         {}
#line 1375 "programa.tab.c"
    break;

  case 10: /* decl_a_f: %empty  */
#line 90 "programa.y"
                {}
#line 1381 "programa.tab.c"
    break;

  case 11: /* bloque: declaraciones instrucciones  */
#line 94 "programa.y"
                                {}
#line 1387 "programa.tab.c"
    break;

  case 12: /* declaraciones: declaracion_tipo declaraciones  */
#line 98 "programa.y"
                                   {}
#line 1393 "programa.tab.c"
    break;

  case 13: /* declaraciones: declaracion_const declaraciones  */
#line 99 "programa.y"
                                      {}
#line 1399 "programa.tab.c"
    break;

  case 14: /* declaraciones: declaracion_var declaraciones  */
#line 100 "programa.y"
                                    {}
#line 1405 "programa.tab.c"
    break;

  case 15: /* declaraciones: %empty  */
#line 101 "programa.y"
                {}
#line 1411 "programa.tab.c"
    break;

  case 16: /* declaracion_tipo: COMIENZO_TIPO lista_d_tipo FIN_TIPO DELIMITADOR  */
#line 105 "programa.y"
                                                    {
    }
#line 1418 "programa.tab.c"
    break;

  case 17: /* declaracion_const: COMIENZO_CONSTANTES lista_d_cte FIN_CONSTANTES DELIMITADOR  */
#line 110 "programa.y"
                                                               {}
#line 1424 "programa.tab.c"
    break;

  case 18: /* declaracion_var: COMIENZO_VAR lista_d_var FIN_VAR DELIMITADOR  */
#line 114 "programa.y"
                                                 {}
#line 1430 "programa.tab.c"
    break;

  case 19: /* lista_d_tipo: IDENTIFICADOR IGUAL d_tipo SEPARADOR lista_d_tipo  */
#line 118 "programa.y"
                                                      {}
#line 1436 "programa.tab.c"
    break;

  case 20: /* lista_d_tipo: %empty  */
#line 119 "programa.y"
                {}
#line 1442 "programa.tab.c"
    break;

  case 21: /* d_tipo: COMIENZO_TUPLA lista_campos FIN_TUPLA  */
#line 123 "programa.y"
                                          {}
#line 1448 "programa.tab.c"
    break;

  case 22: /* d_tipo: COMIENZO_TABLA COMIENZO_INDICE expresion_t RANGO expresion_t FIN_INDICE DECLARADOR_TIPO_TABLA d_tipo  */
#line 124 "programa.y"
                                                                                                           {}
#line 1454 "programa.tab.c"
    break;

  case 23: /* d_tipo: IDENTIFICADOR  */
#line 128 "programa.y"
                  {}
#line 1460 "programa.tab.c"
    break;

  case 24: /* d_tipo: expresion_t RANGO expresion_t  */
#line 129 "programa.y"
                                    {}
#line 1466 "programa.tab.c"
    break;

  case 25: /* d_tipo: REFERENCIA d_tipo  */
#line 130 "programa.y"
                        {}
#line 1472 "programa.tab.c"
    break;

  case 26: /* d_tipo: TIPO  */
#line 131 "programa.y"
           {
        printf("Entra tipo\n");
        (yyval.type) = (yyvsp[0].entero);
        printf("Sale tipo\n");
    }
#line 1482 "programa.tab.c"
    break;

  case 27: /* expresion_t: expresion  */
#line 139 "programa.y"
              {}
#line 1488 "programa.tab.c"
    break;

  case 28: /* expresion_t: LITERAL_CARACTER  */
#line 140 "programa.y"
                       {}
#line 1494 "programa.tab.c"
    break;

  case 29: /* lista_campos: IDENTIFICADOR DECLARADOR_TIPO d_tipo DELIMITADOR lista_campos  */
#line 144 "programa.y"
                                                                  {}
#line 1500 "programa.tab.c"
    break;

  case 30: /* lista_campos: %empty  */
#line 145 "programa.y"
                {}
#line 1506 "programa.tab.c"
    break;

  case 31: /* lista_d_cte: IDENTIFICADOR IGUAL literal DELIMITADOR lista_d_cte  */
#line 149 "programa.y"
                                                        {}
#line 1512 "programa.tab.c"
    break;

  case 32: /* lista_d_cte: %empty  */
#line 150 "programa.y"
                {}
#line 1518 "programa.tab.c"
    break;

  case 33: /* literal: LITERAL_BOOLEANO  */
#line 154 "programa.y"
                     {}
#line 1524 "programa.tab.c"
    break;

  case 34: /* literal: LITERAL_CADENA  */
#line 155 "programa.y"
                     {}
#line 1530 "programa.tab.c"
    break;

  case 35: /* literal: LITERAL_CARACTER  */
#line 156 "programa.y"
                       {}
#line 1536 "programa.tab.c"
    break;

  case 36: /* literal: LITERAL_ENTERO  */
#line 157 "programa.y"
                     {}
#line 1542 "programa.tab.c"
    break;

  case 37: /* literal: LITERAL_REAL  */
#line 158 "programa.y"
                   {}
#line 1548 "programa.tab.c"
    break;

  case 38: /* lista_d_var: lista_id DECLARADOR_TIPO d_tipo DELIMITADOR lista_d_var  */
#line 163 "programa.y"
                                                            {
        for(int i = 0; i < (yyvsp[-4].listaId).sig; i++){
            changeSymbol((yyvsp[-4].listaId).keys[i], (yyvsp[-2].type));
            (yyval.listaId).keys[i] = (yyvsp[-4].listaId).keys[i];
        }
        (yyval.listaId).sig = (yyvsp[-4].listaId).sig;
        printCuadrupleTable();
        printSymbolTable();
    }
#line 1562 "programa.tab.c"
    break;

  case 39: /* lista_d_var: %empty  */
#line 172 "programa.y"
                {}
#line 1568 "programa.tab.c"
    break;

  case 40: /* lista_id: IDENTIFICADOR SEPARADOR lista_id  */
#line 176 "programa.y"
                                     {
        if(!existSymbolVarConst((yyvsp[-2].cadena))){
            (yyvsp[0].listaId).keys[(yyvsp[0].listaId).sig] = insertSymbolVar((yyvsp[-2].cadena));
            (yyvsp[0].listaId).sig++;
        }
        else{
            yyerror("Declarando identificador repetido.");
        }
        (yyval.listaId) = (yyvsp[0].listaId);
    }
#line 1583 "programa.tab.c"
    break;

  case 41: /* lista_id: IDENTIFICADOR_BOOLEANO SEPARADOR lista_id  */
#line 186 "programa.y"
                                                {
        if(!existSymbolVarConst((yyvsp[-2].cadena))){
            (yyvsp[0].listaId).keys[(yyvsp[0].listaId).sig] = insertSymbolVar((yyvsp[-2].cadena));
            (yyvsp[0].listaId).sig++;  
        }
        else{
            yyerror("Declarando identificador repetido.");
        }
        (yyval.listaId) = (yyvsp[0].listaId);
    }
#line 1598 "programa.tab.c"
    break;

  case 42: /* lista_id: IDENTIFICADOR  */
#line 196 "programa.y"
                    {
        if(!existSymbolVarConst((yyvsp[0].cadena))){
            (yyval.listaId).keys[0] = insertSymbolVar((yyvsp[0].cadena));
            (yyval.listaId).sig = 1;
        }
        else{
            yyerror("Declarando identificador repetido.");
            (yyval.listaId).sig = 0;
        }
        
    }
#line 1614 "programa.tab.c"
    break;

  case 43: /* lista_id: IDENTIFICADOR_BOOLEANO  */
#line 207 "programa.y"
                             {
        if(!existSymbolVarConst((yyvsp[0].cadena))){
            (yyval.listaId).keys[0] = insertSymbolVar((yyvsp[0].cadena));
            (yyval.listaId).sig = 1;
        }
        else{
            yyerror("Declarando identificador repetido.");
            (yyval.listaId).sig = 0;
        }
    }
#line 1629 "programa.tab.c"
    break;

  case 44: /* decl_ent_sal: ENTRADA_SALIDA lista_d_var  */
#line 220 "programa.y"
                               {}
#line 1635 "programa.tab.c"
    break;

  case 45: /* decl_ent_sal: ENTRADA_SALIDA lista_d_var ENTRADA_SALIDA lista_d_var  */
#line 221 "programa.y"
                                                           {}
#line 1641 "programa.tab.c"
    break;

  case 46: /* expresion: exp_a  */
#line 226 "programa.y"
          {}
#line 1647 "programa.tab.c"
    break;

  case 47: /* expresion: exp_b  */
#line 227 "programa.y"
            {}
#line 1653 "programa.tab.c"
    break;

  case 48: /* expresion: funcion_ll  */
#line 228 "programa.y"
                 {}
#line 1659 "programa.tab.c"
    break;

  case 49: /* exp_a: exp_a OPERADORES_SUMA exp_a  */
#line 232 "programa.y"
                                {
        int T = insert_temp();
        (yyval.expresion).place = T;
        if ((yyvsp[-2].expresion).type == (yyvsp[0].expresion).type){
            changeSymbol(T, (yyvsp[-2].expresion).type);
            gen((yyvsp[-1].entero), (yyvsp[-2].expresion).place, (yyvsp[0].expresion).place, T);
            (yyval.expresion).type = (yyvsp[-2].expresion).type;
        }
        else{
            if ((yyvsp[-2].expresion).type == ENUM_REAL && (yyvsp[0].expresion).type == ENUM_ENTERO){
                changeSymbol(T, (yyvsp[-2].expresion).type);
                gen(INT_TO_REAL,(yyvsp[0].expresion).place,NULO,T);
                gen((yyvsp[-1].entero), (yyvsp[-2].expresion).place, (yyvsp[0].expresion).place,  T);
                (yyval.expresion).type = (yyvsp[-2].expresion).type;
            }
            else{
                changeSymbol(T, (yyvsp[0].expresion).type);
                gen(INT_TO_REAL,(yyvsp[-2].expresion).place,NULO,T);
                gen((yyvsp[-1].entero), (yyvsp[-2].expresion).place, (yyvsp[0].expresion).place,  T);
                (yyval.expresion).type = (yyvsp[0].expresion).type;
            }

        }
    }
#line 1688 "programa.tab.c"
    break;

  case 50: /* exp_a: exp_a OPERADORES_MULTIPLICACION exp_a  */
#line 256 "programa.y"
                                            {
        int T = insert_temp();
        (yyval.expresion).place = T;
        if ((yyvsp[-2].expresion).type == (yyvsp[0].expresion).type){
            changeSymbol(T, (yyvsp[-2].expresion).type);
            gen((yyvsp[-1].entero), (yyvsp[-2].expresion).place, (yyvsp[0].expresion).place, T);
            (yyval.expresion).type = (yyvsp[-2].expresion).type;
        }
        else{
            if ((yyvsp[-2].expresion).type == ENUM_REAL && (yyvsp[0].expresion).type == ENUM_ENTERO){
                changeSymbol(T, (yyvsp[-2].expresion).type);
                gen(INT_TO_REAL,(yyvsp[0].expresion).place,NULO,T);
                gen((yyvsp[-1].entero), (yyvsp[-2].expresion).place, (yyvsp[0].expresion).place,  T);
                (yyval.expresion).type = (yyvsp[-2].expresion).type;
            }
            else{
                changeSymbol(T, (yyvsp[0].expresion).type);
                gen(INT_TO_REAL,(yyvsp[-2].expresion).place,NULO,T);
                gen((yyvsp[-1].entero), (yyvsp[-2].expresion).place, (yyvsp[0].expresion).place,  T);
                (yyval.expresion).type = (yyvsp[0].expresion).type;
            }

        }

    }
#line 1718 "programa.tab.c"
    break;

  case 51: /* exp_a: COMIENZO_PARENTESIS exp_a FIN_PARENTESIS  */
#line 281 "programa.y"
                                               {
        (yyval.expresion) = (yyvsp[-1].expresion);
    }
#line 1726 "programa.tab.c"
    break;

  case 52: /* exp_a: operando  */
#line 284 "programa.y"
               {
        (yyval.expresion) = (yyvsp[0].expresion);
    }
#line 1734 "programa.tab.c"
    break;

  case 53: /* exp_a: literal_numerico  */
#line 287 "programa.y"
                       {
        (yyval.expresion) = (yyvsp[0].expresion);
    }
#line 1742 "programa.tab.c"
    break;

  case 54: /* exp_a: OPERADORES_SUMA exp_a  */
#line 290 "programa.y"
                            {
        if((yyvsp[-1].entero) == ENUM_RESTA){
            printf("Cambio SImbolo\n");
            int T = insert_temp();
            (yyval.expresion).place = T;
            gen((yyvsp[-1].entero),(yyvsp[0].expresion).place,NULO,T);
            (yyval.expresion).type = (yyvsp[0].expresion).type;
           
        }
        else if((yyvsp[-1].entero) == ENUM_SUMA){
            (yyval.expresion) = (yyvsp[0].expresion);
        }
    }
#line 1760 "programa.tab.c"
    break;

  case 55: /* literal_numerico: LITERAL_ENTERO  */
#line 306 "programa.y"
                   {
    }
#line 1767 "programa.tab.c"
    break;

  case 56: /* literal_numerico: LITERAL_REAL  */
#line 308 "programa.y"
                   {}
#line 1773 "programa.tab.c"
    break;

  case 57: /* exp_b: exp_b OPERADORES_BOOLEANOS m exp_b  */
#line 312 "programa.y"
                                      {
        printf("Entra expb operandores expb\n");
        if( (yyvsp[-2].entero) == ENUM_O){
            backpatch((yyvsp[-3].expresion_bool).FL, (yyvsp[-1].param).quad);
            (yyval.expresion_bool).TL = merge((yyvsp[-3].expresion_bool).TL, (yyvsp[0].expresion_bool).TL);
            (yyval.expresion_bool).FL = (yyvsp[0].expresion_bool).FL;
        }
        else if((yyvsp[-2].entero) == ENUM_Y ){
            backpatch((yyvsp[-3].expresion_bool).TL, (yyvsp[-1].param).quad);
            (yyval.expresion_bool).FL = merge((yyvsp[-3].expresion_bool).FL, (yyvsp[0].expresion_bool).FL);
            (yyval.expresion_bool).TL = (yyvsp[0].expresion_bool).TL;
        }
        else{
            // Error en operador booleano
            yyerror("Operador booleano incorrecto");
        }
    }
#line 1795 "programa.tab.c"
    break;

  case 58: /* exp_b: NEGACION exp_b  */
#line 329 "programa.y"
                     {
        printf("Entra negacion booleana\n");
        (yyval.expresion_bool).TL = (yyvsp[0].expresion_bool).FL;
        (yyval.expresion_bool).FL = (yyvsp[0].expresion_bool).TL;
    }
#line 1805 "programa.tab.c"
    break;

  case 59: /* exp_b: operando_b  */
#line 334 "programa.y"
                 {
        printf("Entra operando booleano\n");
        (yyval.expresion_bool).TL = makelistWithData(table.nextQuad);
        (yyval.expresion_bool).FL = makelistWithData(table.nextQuad + 1);
        gen(ENUM_VERDADERO,(yyvsp[0].expresion).place,NULO,NULO);
        gen(GOTO,NULO,NULO,NULO);
    }
#line 1817 "programa.tab.c"
    break;

  case 60: /* exp_b: LITERAL_BOOLEANO  */
#line 341 "programa.y"
                       {
    }
#line 1824 "programa.tab.c"
    break;

  case 61: /* exp_b: expresion COMPARADORES expresion  */
#line 343 "programa.y"
                                       {
        (yyval.expresion_bool).TL = makelistWithData(table.nextQuad);
        (yyval.expresion_bool).FL = makelistWithData(table.nextQuad + 1);
        gen((yyvsp[-1].entero),(yyvsp[-2].expresion).place,(yyvsp[0].expresion).place,NULO);
        gen(GOTO,NULO,NULO,NULO);
    }
#line 1835 "programa.tab.c"
    break;

  case 62: /* exp_b: expresion IGUAL expresion  */
#line 349 "programa.y"
                                {
        (yyval.expresion_bool).TL = makelistWithData(table.nextQuad);
        (yyval.expresion_bool).FL = makelistWithData(table.nextQuad + 1);
        gen((yyvsp[-1].entero),(yyvsp[-2].expresion).place,(yyvsp[0].expresion).place,NULO);
        gen(GOTO,NULO,NULO,NULO);
    }
#line 1846 "programa.tab.c"
    break;

  case 63: /* exp_b: COMIENZO_PARENTESIS exp_b FIN_PARENTESIS  */
#line 355 "programa.y"
                                               {
        (yyval.expresion_bool).TL = (yyvsp[-1].expresion_bool).TL;
        (yyval.expresion_bool).FL = (yyvsp[-1].expresion_bool).FL;
    }
#line 1855 "programa.tab.c"
    break;

  case 64: /* m: %empty  */
#line 361 "programa.y"
             {
    (yyval.param).quad = table.nextQuad;
}
#line 1863 "programa.tab.c"
    break;

  case 65: /* operando: IDENTIFICADOR  */
#line 366 "programa.y"
                  {
        (yyval.expresion).type = get_SymbolVarConst_Type((yyvsp[0].cadena));
        (yyval.expresion).place = get_SymbolVarConst_Key((yyvsp[0].cadena));
    }
#line 1872 "programa.tab.c"
    break;

  case 66: /* operando: operando PUNTERO operando  */
#line 370 "programa.y"
                                {}
#line 1878 "programa.tab.c"
    break;

  case 67: /* operando: operando COMIENZO_INDICE expresion FIN_INDICE  */
#line 371 "programa.y"
                                                    {}
#line 1884 "programa.tab.c"
    break;

  case 68: /* operando: operando REFERENCIA  */
#line 372 "programa.y"
                          {}
#line 1890 "programa.tab.c"
    break;

  case 69: /* operando_b: IDENTIFICADOR_BOOLEANO  */
#line 376 "programa.y"
                           {
        (yyval.expresion).type = get_SymbolVarConst_Type((yyvsp[0].cadena));
        (yyval.expresion).place = get_SymbolVarConst_Key((yyvsp[0].cadena));
    }
#line 1899 "programa.tab.c"
    break;

  case 70: /* instrucciones: instruccion DELIMITADOR instrucciones  */
#line 383 "programa.y"
                                          {}
#line 1905 "programa.tab.c"
    break;

  case 71: /* instrucciones: instruccion  */
#line 384 "programa.y"
                  {}
#line 1911 "programa.tab.c"
    break;

  case 72: /* instruccion: CONTINUAR  */
#line 388 "programa.y"
              {}
#line 1917 "programa.tab.c"
    break;

  case 73: /* instruccion: asignacion  */
#line 389 "programa.y"
                 {}
#line 1923 "programa.tab.c"
    break;

  case 74: /* instruccion: alternativa  */
#line 390 "programa.y"
                  {}
#line 1929 "programa.tab.c"
    break;

  case 75: /* instruccion: iteracion  */
#line 391 "programa.y"
                {}
#line 1935 "programa.tab.c"
    break;

  case 76: /* instruccion: accion_ll  */
#line 392 "programa.y"
                {}
#line 1941 "programa.tab.c"
    break;

  case 77: /* asignacion: operando ASIGNACION exp_a  */
#line 396 "programa.y"
                              {
        printf("Asigna\n");
        if ((yyvsp[-2].expresion).type == (yyvsp[0].expresion).type) {
            gen(ENUM_ASIGNACION, (yyvsp[0].expresion).place, NULO, (yyvsp[-2].expresion).place);
            printCuadrupleTable();
            printSymbolTable();
        } 
        else if ((yyvsp[-2].expresion).type == ENUM_REAL && (yyvsp[0].expresion).type == ENUM_ENTERO) {
            int T = insert_temp();
            gen(INT_TO_REAL, (yyvsp[0].expresion).place, NULO, T);
            gen(ENUM_ASIGNACION, T, NULO, (yyvsp[-2].expresion).place);
            printCuadrupleTable();
            printSymbolTable();
        } 
        else {
            // Error en tipos incompatibles
            yyerror("Tipos incompatibles en la asignación.");
        }
       
    }
#line 1966 "programa.tab.c"
    break;

  case 78: /* asignacion: operando_b ASIGNACION exp_b  */
#line 416 "programa.y"
                                  {
        printf("Entra asignacion bool\n");
        backpatch((yyvsp[0].expresion_bool).FL, table.nextQuad);
        gen(ENUM_ASIGNACION,ENUM_FALSO,NULO,(yyvsp[-2].expresion).place);
        gen(GOTO,NULO,NULO,table.nextQuad+2);
        backpatch((yyvsp[0].expresion_bool).TL,table.nextQuad);
        gen(ENUM_ASIGNACION,ENUM_VERDADERO,NULO,(yyvsp[-2].expresion).place);
        printCuadrupleTable();
        printSymbolTable();
    }
#line 1981 "programa.tab.c"
    break;

  case 79: /* alternativa: COMIENZO_SI expresion ENTONCES instrucciones lista_opciones FIN_SI  */
#line 429 "programa.y"
                                                                       {}
#line 1987 "programa.tab.c"
    break;

  case 80: /* lista_opciones: ELSE expresion ENTONCES instrucciones lista_opciones  */
#line 433 "programa.y"
                                                         {}
#line 1993 "programa.tab.c"
    break;

  case 81: /* lista_opciones: %empty  */
#line 434 "programa.y"
                {}
#line 1999 "programa.tab.c"
    break;

  case 82: /* iteracion: it_cota_fija  */
#line 438 "programa.y"
                 {}
#line 2005 "programa.tab.c"
    break;

  case 83: /* iteracion: it_cota_exp  */
#line 439 "programa.y"
                 {}
#line 2011 "programa.tab.c"
    break;

  case 84: /* it_cota_exp: COMIENZO_BUCLE_MIENTRAS expresion COMIENZO_BUCLE_HACER instrucciones FIN_BUCLE_MIENTRAS  */
#line 443 "programa.y"
                                                                                           {}
#line 2017 "programa.tab.c"
    break;

  case 85: /* it_cota_fija: COMIENZO_BUCLE_PARA IDENTIFICADOR ASIGNACION expresion HASTA expresion COMIENZO_BUCLE_HACER instrucciones FIN_BUCLE_PARA  */
#line 447 "programa.y"
                                                                                                                             {}
#line 2023 "programa.tab.c"
    break;

  case 86: /* accion_d: COMIENZO_ACCION a_cabecera bloque FIN_ACCION  */
#line 451 "programa.y"
                                                 {}
#line 2029 "programa.tab.c"
    break;

  case 87: /* funcion_d: COMIENZO_FUNCION f_cabecera bloque RETORNO expresion FIN_FUNCION  */
#line 455 "programa.y"
                                                                     {}
#line 2035 "programa.tab.c"
    break;

  case 88: /* a_cabecera: IDENTIFICADOR COMIENZO_PARENTESIS d_par_form FIN_PARENTESIS DELIMITADOR  */
#line 459 "programa.y"
                                                                            {}
#line 2041 "programa.tab.c"
    break;

  case 89: /* f_cabecera: IDENTIFICADOR COMIENZO_PARENTESIS lista_d_var FIN_PARENTESIS RETORNO d_tipo DELIMITADOR  */
#line 463 "programa.y"
                                                                                            {}
#line 2047 "programa.tab.c"
    break;

  case 90: /* d_par_form: d_p_form DELIMITADOR d_par_form  */
#line 467 "programa.y"
                                    {}
#line 2053 "programa.tab.c"
    break;

  case 91: /* d_par_form: %empty  */
#line 468 "programa.y"
                {}
#line 2059 "programa.tab.c"
    break;

  case 92: /* d_p_form: ENTRADA_SALIDA lista_id DECLARADOR_TIPO d_tipo  */
#line 472 "programa.y"
                                                   {}
#line 2065 "programa.tab.c"
    break;

  case 93: /* accion_ll: IDENTIFICADOR COMIENZO_PARENTESIS l_ll FIN_PARENTESIS  */
#line 476 "programa.y"
                                                          {}
#line 2071 "programa.tab.c"
    break;

  case 94: /* funcion_ll: IDENTIFICADOR COMIENZO_PARENTESIS l_ll FIN_PARENTESIS  */
#line 480 "programa.y"
                                                          {}
#line 2077 "programa.tab.c"
    break;

  case 95: /* l_ll: expresion SEPARADOR l_ll  */
#line 484 "programa.y"
                             {}
#line 2083 "programa.tab.c"
    break;

  case 96: /* l_ll: expresion  */
#line 485 "programa.y"
                {}
#line 2089 "programa.tab.c"
    break;


#line 2093 "programa.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 490 "programa.y"


extern int yylineno; // Asegúrate de incluir esto si estás contando líneas
extern char *yytext;

/* Manejo de errores */
void yyerror(const char *s) {
    fprintf(stderr, "Error en línea %d: %s '%s'\n", yylineno, s, yytext);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <archivo_entrada>\n", argv[0]);
        return 1;
    }

    FILE *archivo = fopen(argv[1], "r");
    if (!archivo) {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Asigna el archivo a yyin para que Flex lo use
    yyin = archivo;

    printf("Procesando el archivo: %s\n", argv[1]);
    yyparse();

    fclose(archivo);
    return 0;
}
