#ifndef TABLA_CUAPLAS_H
#define TABLA_CUADRUPLAS_H

#include <stdio.h>
#include <stdbool.h>

typedef enum operadores{
	SUMA_ENTERO = 0,
	RESTA_ENTERO,
	MULT_ENTERO,
	DIV_ENTERO,
	SUMA_REAL,
	RESTA_REAL,
	MULT_REAL,
	DIV_REAL,
	ASIGNACION_ENUM,
	DIV_ENUM,
	MODULO,
	INT_TO_REAL,
	OR_ENUM,
	AND_ENUM,
	NULO = 8888,
	SALTO = 15
}Operadores;

typedef enum operadores_booleanos{
	IGUAL_ENUM =16,
	MAYOR_ENUM,
	MENOR_ENUM,
	MENOR_IGUAL_ENUM,
	MAYOR_IGUAL_ENUM,
	DISTINTO_ENUM,
	IGUAL_A_VERDADERO
}Operadores_booleanos;

typedef enum literales{
	LITERAL_ENTERO_ENUM = 23,
	LITERAL_REAL_ENUM,
	LITERAL_BOOLEANO_ENUM

}literales;


typedef struct Cuadrupla{
	int operador;
	int operando1;
	int operando2;
	int resultado;
}Cuadrupla;

typedef struct TablaCuadruplas{
	int sigPos;
	Cuadrupla cuadruplas[100];
}TablaCuadruplas;

extern TablaCuadruplas tablaCuadruplas;

void iniciar_tabla_cuadruplas();
void gen(int,int,int,int);
void merge(int*,int,int*,int,int*);
int makelist();
void backpatch(int*,int,int);
void igualar_listas(int*,int*,int);
void imprimirTablaCuadruplas();
bool esVacio(int);
#endif
