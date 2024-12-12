
// symbol_table.h
#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
typedef struct Symbol {
    char name[100];         // Nombre del símbolo (ej. nombre de variable)
    int type;           // Tipo de dato del símbolo
    int key;          
} Symbol;

typedef struct table{
    int sig;
    Symbol simbolos[100];
}TABLE;

extern TABLE symbol_table;
Symbol new_Symbol(char name[100]);
void emptyTable();
int insertSymbol(char *name);
void changeSymbol(int key, int type);
bool existSymbol(char name[100]);
int insert_temp();
void printSymbolTable();
int get_Symbol_Key(char name[100]);
int get_Symbol_Type(char name[100]);
#endif
