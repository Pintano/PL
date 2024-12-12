#include <stdio.h>
#include <stdlib.h>

#include "tablaCuadruplas.h"
#include "tablaSimbolos.h"

TablaCuadruplas tablaCuadruplas;


void iniciar_tabla_cuadruplas(){
	tablaCuadruplas.sigPos = 0;
};

void gen(int oper1, int operando, int oper2, int resultado){
	tablaCuadruplas.cuadruplas[tablaCuadruplas.sigPos].operando1 = oper1;
	tablaCuadruplas.cuadruplas[tablaCuadruplas.sigPos].operando2 = oper2;
	tablaCuadruplas.cuadruplas[tablaCuadruplas.sigPos].operador = operando;
	tablaCuadruplas.cuadruplas[tablaCuadruplas.sigPos].resultado = resultado;
	tablaCuadruplas.sigPos++;
}

void imprimirTablaCuadruplas() {
	char *enumerados[] = {"+(ent)","-(ent)","*(ent)","/(ent)","+(real)","-(real)","*(real)","/(real)",":=","div","mod","intToReal","OR","AND","NULO","GOTO","=",">","<","<=",">=","!=","=TRUE","Lit_entero","Lit_real","Lit_bool","Entero","Real","Booleano","Caracter","String","Verdadero","Falso"};
	FILE *archivo = fopen("tablaCuadruplas.txt", "w");
	
	// Imprimir encabezado
	fprintf(archivo, "sigPos\t\tOperador\tOperando1\tOperando2\tResultado\n");

	for (int i = 0; i < tablaCuadruplas.sigPos; ++i) {
		if(tablaCuadruplas.cuadruplas[i].operando1 == 8888 && tablaCuadruplas.cuadruplas[i].operando2 != 8888 ){
			fprintf(archivo, "%d\t\t%s\t\t%s\t\t%s\t\t%d\n",
		i, enumerados[tablaCuadruplas.cuadruplas[i].operador],
		"Nulo",
		tablaSimbolos.simbolos[tablaCuadruplas.cuadruplas[i].operando2].nombre,
		tablaCuadruplas.cuadruplas[i].resultado);
		} else if (tablaCuadruplas.cuadruplas[i].operando1 != 8888 && tablaCuadruplas.cuadruplas[i].operando2 == 8888 ){
	fprintf(archivo, "%d\t\t%s\t\t%s\t\t%s\t\t%d\n",
		i, enumerados[tablaCuadruplas.cuadruplas[i].operador],
		tablaSimbolos.simbolos[tablaCuadruplas.cuadruplas[i].operando1].nombre,
		"Nulo",
		tablaCuadruplas.cuadruplas[i].resultado);
		} else if (tablaCuadruplas.cuadruplas[i].operando1 == 8888 && tablaCuadruplas.cuadruplas[i].operando2 == 8888 ){
			fprintf(archivo, "%d\t\t%s\t\t%s\t\t%s\t\t%d\n",
		i, enumerados[tablaCuadruplas.cuadruplas[i].operador],
		"Nulo",
		"Nulo",
		tablaCuadruplas.cuadruplas[i].resultado);
		}else{
			fprintf(archivo, "%d\t\t%s\t\t%s\t\t%s\t\t%d\n",
		i, enumerados[tablaCuadruplas.cuadruplas[i].operador],
		tablaSimbolos.simbolos[tablaCuadruplas.cuadruplas[i].operando1].nombre,
		tablaSimbolos.simbolos[tablaCuadruplas.cuadruplas[i].operando2].nombre,
		tablaCuadruplas.cuadruplas[i].resultado);
		}
	}
}

void merge(int lista1[100],int longLista1,int lista2[100],int longLista2,int* listaSalida){
	for (int i =0 ; i <longLista1; i++){
		listaSalida[i] = lista1[i];
	}
	for (int i = longLista1; i < longLista1+longLista2; i++){
		listaSalida[i] = lista2[i-longLista1];
	}
}

int makelist(int numero){
	return numero;
}

void backpatch(int* lista,int longLista,int salto){
	for (int i = 0; i < longLista; i++){
		if(tablaCuadruplas.cuadruplas[lista[i]].resultado ==-1){
			tablaCuadruplas.cuadruplas[lista[i]].resultado = salto;
		}
	}
}

void igualar_listas(int listadestino[100],int listafuente[100],int longLista){
	for (int i = 0; i < longLista; i++) {
        listadestino[i] = listafuente[i];
    }
}

bool esVacio(int longitud){
	return longitud == 0;
}
