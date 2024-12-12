// cuadruple_table.c
#include "cuadruple_table.h"
#include "definitions.h"
Table table;

void gen(int operator, int operando1, int operando2, int resultado){
    if(table.nextQuad == 100){
        printf("No se puede insertar más cuadruplos\n");
        return;
    }
    table.cuadruple[table.nextQuad].operador = operator;
    table.cuadruple[table.nextQuad].operando1 = operando1;
    table.cuadruple[table.nextQuad].operando2 = operando2;
    table.cuadruple[table.nextQuad].resultado = resultado;
    table.nextQuad++;
}

void backpatch(IntList list, int jump){
    for(int i = 0;i < list.listSize; i++){
        if(table.cuadruple[list.list[i]].resultado == -1){
            table.cuadruple[list.list[i]].resultado = jump;
        }
    }
}

IntList merge(IntList trueList, IntList falseList){
   IntList finalList;
    for(int i = 0; i < trueList.listSize; i++){
        finalList.list[i] = trueList.list[i];
    }
    for(int i = 0; i < falseList.listSize; i++){
        finalList.list[falseList.listSize + i] = falseList.list[i];
    }
}

IntList makelist(){
   IntList list;
   list.listSize = 0;
   return list;
}

IntList makelistWithData(int nextquad) {
    IntList list;             
    list.listSize = 1;        
    list.list[0] = nextquad;  
    return list;              
}

// Función auxiliar para convertir el operador en una cadena
const char* getOperatorName(int operador) {
    switch (operador) {
        case ENUM_MAYORIGUAL: return ">=";
        case ENUM_MENORIGUAL: return "<=";
        case ENUM_IGUAL: return "==";
        case ENUM_MENOR: return "<";
        case ENUM_MAYOR: return ">";
        case ENUM_SUMA: return "+";
        case ENUM_RESTA: return "-";
        case ENUM_MUL: return "*";
        case ENUM_DIV: return "/";
        case ENUM_COC: return "div";
        case ENUM_RESTO: return "mod";
        case ENUM_ENTRADA: return "INPUT";
        case ENUM_SALIDA: return "OUTPUT";
        case ENUM_E_S: return "I/O";
        case ENUM_O: return "OR";
        case ENUM_Y: return "AND";
        case ENUM_VERDADERO: return "TRUE";
        case ENUM_FALSO: return "FALSE";
        case NULO: return "NULL";
        case INT_TO_REAL: return "INT->REAL";
        case ENUM_ASIGNACION: return ":=";
        case GOTO: return "GOTO";
        default: return "UNKNOWN";
    }
}

// Función para imprimir la tabla de cuádruplos
void printCuadrupleTable() {
    printf("Tabla de Cuádruplas:\n");
    printf("------------------------------------------------\n");
    printf("| #  | Operador   | Operando1 | Operando2 | Resultado |\n");
    printf("------------------------------------------------\n");

    for (int i = 0; i < table.nextQuad; i++) {
        Cuadruple c = table.cuadruple[i];
        printf("| %-3d | %-10s | %-9d | %-9d | %-9d |\n",
               i,
               getOperatorName(c.operador),
               c.operando1,
               c.operando2,
               c.resultado);
    }

    printf("------------------------------------------------\n");
}