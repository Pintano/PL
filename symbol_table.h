
// symbol_table.h
#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "definitions.h"

// typedef struct Symbol {
//     char name[100];         // Nombre del símbolo (ej. nombre de variable)
//     int type;           // Tipo de dato del símbolo
//     int key;        
// } Symbol;

// Categorías de símbolos
typedef enum SymbolCategory {
    VARIABLE = 30,
    LITERAL,
    CONSTANT
} SymbolCategory;

// Valor genérico para literales y constantes
typedef union SymbolValue {
    int entero;
    float real;
    bool booleano;
    char caracter;
    char cadena[100];
} SymbolValue;

// Estructura de símbolo
typedef struct Symbol {
    int key;   
    int type;               
    SymbolCategory category;  

    union {
        struct {
            char name[100];
        } variable;

        struct {
            SymbolValue value;  
        } literal;

        struct {
            char name[100];         
            SymbolValue value;  
        } constant;
    } data;
} Symbol;


typedef struct table{
    int sig;
    Symbol simbolos[100];
}TABLE;


extern TABLE symbol_table;
// Symbol new_Symbol(char name[100]);
void emptyTable();

SymbolValue initializeSymbolValue();
// int insertSymbol(char *name);
int insertSymbolVar(char *name);
int insertSymbolConst(char *name, SymbolValue value);
int insertSymbolLit(SymbolValue value);

void changeSymbol(int key, int type);

int get_SymbolVarConst_Key(char name[100]);
int get_SymbolVarConst_Type(char name[100]);

int get_SymbolLit_Key(SymbolValue value);
int get_SymbolLit_Type(SymbolValue value);

Symbol new_SymbolVar(char name[100]);
Symbol new_SymbolLit(SymbolValue value);
Symbol new_SymbolConst(char name[100], SymbolValue value);

int insert_temp();
// bool existSymbol(char name[100]);
bool existSymbolVarConst(char name[100]);
bool existLiteral(SymbolValue value);

void printSymbolTable();

#endif
