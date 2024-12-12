#ifndef DEFINICIONES_H
#define DEFINICIONES_H

typedef enum type {
    ENUM_ENTERO,
    ENUM_REAL,
    ENUM_BOOLEANO,
    ENUM_CARACTER,
    ENUM_CADENA
} type;

typedef enum comparator {
    ENUM_MAYORIGUAL = 5,
    ENUM_MENORIGUAL,
    ENUM_IGUAL,
    ENUM_MENOR,
    ENUM_MAYOR
    //ENUM_DISTINTO
} comparator;

typedef enum suma_resta {
    ENUM_SUMA = 10,
    ENUM_RESTA
} suma_resta;

typedef enum mul_div {
    ENUM_MUL =12,
    ENUM_DIV,
    ENUM_COC,
    ENUM_RESTO
} mul_div;

typedef enum entrada_salida {
    ENUM_ENTRADA = 16,
    ENUM_SALIDA,
    ENUM_E_S
} entrada_salida;

typedef enum o_y {
    ENUM_O = 19,
    ENUM_Y
} o_y;

typedef enum booleano {
    ENUM_VERDADERO = 21,
    ENUM_FALSO
} booleano;

typedef enum operadores_extra {
    INT_TO_REAL = 23,
    ENUM_ASIGNACION,
    GOTO,
    NULO = -1
} operadores_extra;

typedef struct IdList{
    int sig;
    int keys[100];
}IdList;

typedef struct TipoExp{
    int place;
    int type;
    int nextQuad;
}TipoExp;

typedef struct IntList{
    int list[100];
    int listSize;
} IntList;

typedef struct TipoBool{
    IntList TL;
    IntList FL;
    int nextQuad;
}TipoBool;

typedef struct TipoM{
    int quad;
}TipoM;

#endif
