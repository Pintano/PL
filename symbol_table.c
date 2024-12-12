// symbol_table.c
#include "symbol_table.h"

SymbolCategory sc;
SymbolValue sv;
Symbol symbol;
TABLE symbol_table;

void emptyTable(){
    symbol_table.sig = 0;
}

SymbolValue initializeSymbolValue() {
    SymbolValue value;

    value.entero = 0;
    value.real = 0.0;
    value.booleano = false;
    value.caracter = '\0';
    value.cadena[0] = '\0';  

    return value;
}

int insertSymbolVar(char *name) {
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
    strncpy(symbol_table.simbolos[sigant].data.variable.name, name, sizeof(symbol_table.simbolos[sigant].data.variable.name) - 1);
    symbol_table.simbolos[sigant].data.variable.name[sizeof(symbol_table.simbolos[sigant].data.variable.name) - 1] = '\0';
    symbol_table.simbolos[sigant].type = -1;
    symbol_table.simbolos[sigant].key = sigant;
    symbol_table.simbolos[sigant].category = VARIABLE;
    symbol_table.sig++;
    
    return symbol_table.simbolos[sigant].key;
}

int insertSymbolConst(char *name, SymbolValue value) {
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
    strncpy(symbol_table.simbolos[sigant].data.constant.name, name, sizeof(symbol_table.simbolos[sigant].data.constant.name) - 1);
    symbol_table.simbolos[sigant].data.constant.name[sizeof(symbol_table.simbolos[sigant].data.constant.name) - 1] = '\0';
    symbol_table.simbolos[sigant].type = -1;
    symbol_table.simbolos[sigant].key = sigant;
    symbol_table.simbolos[sigant].data.constant.value = value;
    symbol_table.simbolos[sigant].category = CONSTANT;
    symbol_table.sig++;
    return symbol_table.simbolos[sigant].key;
}

int insertSymbolLit(SymbolValue value) {
    if (symbol_table.sig >= 100) {
        printf("No se pueden insertar más símbolos.\n");
        return -1;
    }
    printf("Insertando símbolo literal\n");
    int sigant = symbol_table.sig;
    symbol_table.simbolos[sigant].data.literal.value = value;
    symbol_table.simbolos[sigant].type = -1;
    symbol_table.simbolos[sigant].category = LITERAL;
    symbol_table.simbolos[sigant].key = sigant;

    symbol_table.sig++;
    return symbol_table.simbolos[sigant].key;
}

void changeSymbol(int key, int type) {
    symbol_table.simbolos[key].type = type;
}

int get_SymbolVarConst_Key(char name[100]) {
    for (int i = 0; i < 100; ++i) {
        if(symbol_table.simbolos[i].category == VARIABLE){
            if(strcmp(symbol_table.simbolos[i].data.variable.name, name) == 0){
                return i;
            }
        }else if(symbol_table.simbolos[i].category == CONSTANT){
            if(strcmp(symbol_table.simbolos[i].data.constant.name, name) == 0){
                return i;
            }
        }
    }
    return -1;
}

int get_SymbolVarConst_Type(char name[100]) {
    for (int i = 0; i < 100; ++i) {
        if(symbol_table.simbolos[i].category == VARIABLE){
            if(strcmp(symbol_table.simbolos[i].data.variable.name, name) == 0){
                return symbol_table.simbolos[i].type;
            }
        }else if(symbol_table.simbolos[i].category == CONSTANT){
            if(strcmp(symbol_table.simbolos[i].data.constant.name, name) == 0){
                return symbol_table.simbolos[i].type;
            }
        }
    }
    return -1;
}

int get_SymbolLit_Key(SymbolValue value) {
    for (int i = 0; i < 100; ++i) {
        if(symbol_table.simbolos[i].category == LITERAL){
            if(symbol_table.simbolos[i].data.literal.value.entero == value.entero){
                return i;
            }else if(symbol_table.simbolos[i].data.literal.value.real == value.real){
                return i;
            }else if(symbol_table.simbolos[i].data.literal.value.booleano == value.booleano){
                return i;
            }else if(symbol_table.simbolos[i].data.literal.value.caracter == value.caracter){
                return i;
            }else if(strcmp(symbol_table.simbolos[i].data.literal.value.cadena, value.cadena) == 0){
                return i;
            }
        }
    }
    return -1;
}

int get_SymbolLit_Type(SymbolValue value) {
    for (int i = 0; i < 100; ++i) {
        if(symbol_table.simbolos[i].category == LITERAL){
            if(symbol_table.simbolos[i].data.literal.value.entero == value.entero){
                return symbol_table.simbolos[i].type;
            }else if(symbol_table.simbolos[i].data.literal.value.real == value.real){
                return symbol_table.simbolos[i].type;
            }else if(symbol_table.simbolos[i].data.literal.value.booleano == value.booleano){
                return symbol_table.simbolos[i].type;
            }else if(symbol_table.simbolos[i].data.literal.value.caracter == value.caracter){
                return symbol_table.simbolos[i].type;
            }else if(strcmp(symbol_table.simbolos[i].data.literal.value.cadena, value.cadena) == 0){
                return symbol_table.simbolos[i].type;
            }
        }
    }
    return -1;
}

Symbol new_SymbolVar(char name[100]) { //supuestamente yasta
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

    strncpy(newSymb.data.variable.name, name, sizeof(newSymb.data.variable.name) - 1);
    newSymb.data.variable.name[sizeof(newSymb.data.variable.name) - 1] = '\0';
    newSymb.type = -1;
    newSymb.key = symbol_table.sig;
    newSymb.category = VARIABLE;

    return newSymb;
}

Symbol new_SymbolLit(SymbolValue value) { //mirar lo del tipo
    Symbol newSymb;

    // Depuración: Verifica el nombre antes de crear el nuevo símbolo
    // printf("Creando nuevo símbolo: %s\n", name);
    printf("Creando nuevo símbolo literal\n");

    newSymb.data.literal.value = value;
    newSymb.type = -1;
    newSymb.key = symbol_table.sig;
    newSymb.category = LITERAL;

    return newSymb;
}

Symbol new_SymbolConst(char name[100], SymbolValue value) { //mirar lo del tipo
    Symbol newSymb;

    // Depuración: Verifica el nombre antes de crear el nuevo símbolo
    printf("Creando nueva constante: %s\n", name);

    strncpy(newSymb.data.constant.name, name, sizeof(newSymb.data.constant.name) - 1);
    newSymb.data.constant.name[sizeof(newSymb.data.constant.name) - 1] = '\0';
    newSymb.type = -1;
    newSymb.key = symbol_table.sig;
    newSymb.data.literal.value = value;
    newSymb.category = CONSTANT;

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

    Symbol newSymb = new_SymbolVar(name);
    symbol_table.simbolos[symbol_table.sig] = newSymb;
    symbol_table.sig++;
    return newSymb.key;
}

bool existSymbolVarConst(char name[100]){
    for (int i = 0; i < symbol_table.sig; ++i) {
        if (strcmp(symbol_table.simbolos[i].data.variable.name, name) == 0){
            return true;
        }
        else if (strcmp(symbol_table.simbolos[i].data.constant.name, name) == 0){
            return true;
        }
	}
	return false;
}

bool existLiteral(SymbolValue value){ //CREO QUE ESTO VA A DAR MUCHOS PROBLEMAS
    for (int i = 0; i < symbol_table.sig; ++i) {
        if(symbol_table.simbolos[i].category == LITERAL){
            if (symbol_table.simbolos[i].data.literal.value.entero == value.entero){
                return true;
            }
            else if (symbol_table.simbolos[i].data.literal.value.real == value.real){
                return true;
            }
            else if (symbol_table.simbolos[i].data.literal.value.booleano == value.booleano){
                return true;
            }
            else if (symbol_table.simbolos[i].data.literal.value.caracter == value.caracter){
                return true;
            }
            else if (strcmp(symbol_table.simbolos[i].data.literal.value.cadena, value.cadena) == 0){
                return true;
            }
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

void printSymbolTable() {
    printf("Tabla de Símbolos:\n");
    printf("---------------------------------------------------------\n");
    printf("| Key  | Categoría  | Nombre       | Tipo       | Valor       |\n");
    printf("---------------------------------------------------------\n");

    for (int i = 0; i < symbol_table.sig; i++) {
        Symbol *s = &symbol_table.simbolos[i];
        printf("| %-4d | ", s->key);

        switch (s->category) {
            case VARIABLE:
                printf("Variable    | %-11s | %-10s | %-10s |\n",
                       s->data.variable.name,
                       getTypeName(s->type),
                       "N/A");
                break;
            case LITERAL:
                printf("Literal     | N/A         | %-10s | ",
                       getTypeName(s->type));
                switch (s->type) {
                    case ENUM_ENTERO: printf("%d", s->data.literal.value.entero); break;
                    case ENUM_REAL: printf("%.2f", s->data.literal.value.real); break;
                    case ENUM_BOOLEANO: printf(s->data.literal.value.booleano ? "TRUE" : "FALSE"); break;
                    case ENUM_CARACTER: printf("%c", s->data.literal.value.caracter); break;
                    case ENUM_CADENA: printf("%s", s->data.literal.value.cadena); break;
                    default: printf("UNKNOWN");
                }
                printf(" |\n");
                break;
            case CONSTANT:
                printf("Constante   | %-11s | %-10s | ",
                       s->data.constant.name,
                       getTypeName(s->type));
                switch (s->type) {
                    case ENUM_ENTERO: printf("%d", s->data.constant.value.entero); break;
                    case ENUM_REAL: printf("%.2f", s->data.constant.value.real); break;
                    case ENUM_BOOLEANO: printf(s->data.constant.value.booleano ? "TRUE" : "FALSE"); break;
                    case ENUM_CARACTER: printf("%c", s->data.constant.value.caracter); break;
                    case ENUM_CADENA: printf("%s", s->data.constant.value.cadena); break;
                    default: printf("UNKNOWN");
                }
                printf(" |\n");
                break;
        }
    }

    printf("---------------------------------------------------------\n");
}
