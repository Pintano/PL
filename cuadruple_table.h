// cuadruple_table.h
#ifndef CUADRUPLE_TABLE_H
#define CUADRUPLE_TABLE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "definitions.h"

typedef struct Cuadruple {
    int operador;
    int operando1;
    int operando2;
    int resultado;
} Cuadruple;

typedef struct Table{
    int nextQuad;
    Cuadruple cuadruple[100];
}Table;

extern Table table;

void gen(int operator, int operando1, int operando2, int resultado);
void backpatch(IntList list, int jump);
IntList merge(IntList trueList, IntList falseList);
IntList makelist();
IntList makelistWithData(int nextquad);
void printCuadrupleTable();

#endif