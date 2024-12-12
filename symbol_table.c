// symbol_table.c
#include "symbol_table.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "definitions.h"
TABLE symbol_table;

void emptyTable() {
    symbol_table.sig = 0;
}

int insertSymbol(char *name) {
    if (name == NULL) {
        printf("Error: El nombre proporcionado es nulo.\n");
        return -1;
    }

    if (strlen(name) == 0) {
        printf("Error: El nombre proporcionado está vacío.\n");
        return -1;
    }

    int sigant = symbol_table.sig;
    if (symbol_table.sig == 100) {
        printf("No se puede insertar más símbolos\n");
        return -1;
    }

    // Depuración: Verifica el nombre antes de insertar
    printf("Insertando símbolo: %s\n", name);

    strncpy(symbol_table.simbolos[sigant].name, name, sizeof(symbol_table.simbolos[sigant].name) - 1);
    symbol_table.simbolos[sigant].name[sizeof(symbol_table.simbolos[sigant].name) - 1] = '\0';
    symbol_table.simbolos[sigant].type = -1;
    symbol_table.simbolos[sigant].key = sigant;
    symbol_table.sig++;

    return symbol_table.simbolos[sigant].key;
}

void changeSymbol(int key, int type) {
    symbol_table.simbolos[key].type = type;
}

int get_Symbol_Key(char name[100]) {
    for (int i = 0; i < 100; ++i) {
        if (strcmp(symbol_table.simbolos[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int get_Symbol_Type(char name[100]) {
    for (int i = 0; i < 100; ++i) {
        if (strcmp(symbol_table.simbolos[i].name, name) == 0) {
            return symbol_table.simbolos[i].type;
        }
    }
    return -1;
}

Symbol new_Symbol(char name[100]) {
    Symbol newSymb;

    if (name == NULL) {
        printf("Error: El nombre proporcionado es nulo.\n");
        newSymb.key = -1;
        return newSymb;
    }

    if (strlen(name) == 0) {
        printf("Error: El nombre proporcionado está vacío.\n");
        newSymb.key = -1;
        return newSymb;
    }

    // Depuración: Verifica el nombre antes de crear el nuevo símbolo
    printf("Creando nuevo símbolo: %s\n", name);

    strncpy(newSymb.name, name, sizeof(newSymb.name) - 1);
    newSymb.name[sizeof(newSymb.name) - 1] = '\0';
    newSymb.type = -1;
    newSymb.key = symbol_table.sig;

    return newSymb;
}

int insert_temp() {
    if (symbol_table.sig >= 100) {
        printf("No se puede insertar más símbolos temporales\n");
        return -1;
    }
    char name[100];
    sprintf(name, "temp%d", symbol_table.sig);

    // Depuración: Verifica el nombre temporal antes de insertarlo
    printf("Creando símbolo temporal: %s\n", name);

    Symbol newSymb = new_Symbol(name);
    symbol_table.simbolos[symbol_table.sig] = newSymb;
    symbol_table.sig++;
    return newSymb.key;
}

bool existSymbol(char name[100]){
    for (int i = 0; i < symbol_table.sig; ++i) {
        if (strcmp(symbol_table.simbolos[i].name, name) == 0){
            return true;
        }
	}
	return false;
}

const char* getTypeName(int type) {
    switch (type) {
        case ENUM_ENTERO: return "ENTERO";
        case ENUM_REAL: return "REAL";
        case ENUM_BOOLEANO: return "BOOLEANO";
        case ENUM_CARACTER: return "CARACTER";
        case ENUM_CADENA: return "CADENA";
        default: return "UNKNOWN";
    }
}
void printSymbolTable(){
    printf("Tabla de Símbolos:\n");
    printf("-----------------------------\n");
    printf("| Key  | Nombre       | Tipo       |\n");
    printf("-----------------------------\n");

    for (int i = 0; i < symbol_table.sig; i++) {
        Symbol s = symbol_table.simbolos[i];
        printf("| %-4d | %-11s | %-10s |\n", s.key, s.name, getTypeName(s.type));
    }

    printf("-----------------------------\n");
}
