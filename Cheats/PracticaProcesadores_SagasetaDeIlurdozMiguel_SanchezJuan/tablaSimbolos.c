#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tablaSimbolos.h"

Tabla tablaSimbolos;

void iniciar_tabla(){
	tablaSimbolos.sigPos = 0;
};

int insertar_simbolo(char nombreSimbolo[100]){
	Simbolo nuevoSimbolo = crear_simbolo(nombreSimbolo);
	tablaSimbolos.simbolos[tablaSimbolos.sigPos] = nuevoSimbolo;
	tablaSimbolos.sigPos++;
	return nuevoSimbolo.clave;
	
};
Simbolo crear_simbolo(char nombreSimbolo[100]){
	Simbolo nuevoSimbolo;
	strcpy(nuevoSimbolo.nombre,nombreSimbolo);
	nuevoSimbolo.tipo = -1;
	nuevoSimbolo.clave = tablaSimbolos.sigPos;
	return nuevoSimbolo;
};

void actualiza_tipo_simbolo(int clave, int tipo){
	tablaSimbolos.simbolos[clave].tipo = tipo;
};

int obtener_tipo_simbolo(char nombreSimbolo[100]){
	for (int i = 0; i< 100; i++){
		if(strcmp(nombreSimbolo,tablaSimbolos.simbolos[i].nombre) ==0){
			return tablaSimbolos.simbolos[i].tipo;
		}
	}
}

int obtener_clave_simbolo(char nombreSimbolo[100]){
	for (int i = 0; i< 100; i++){
		if(strcmp(nombreSimbolo,tablaSimbolos.simbolos[i].nombre) ==0){
			return i;
		}
	}
}

int insertar_variable_temporal(){
	char nombreSimbolo[100];
	sprintf(nombreSimbolo,"T%d", tablaSimbolos.sigPos);
	Simbolo nuevoSimbolo = crear_simbolo(nombreSimbolo);
	tablaSimbolos.simbolos[tablaSimbolos.sigPos] = nuevoSimbolo;
	tablaSimbolos.sigPos++;
	return nuevoSimbolo.clave;
}


void imprimir_tabla_simbolos() {
	char *enumerados[] = {"+(ent)","-(ent)","*(ent)","/(ent)","+(real)","-(real)","*(real)","/(real)",":=","div","mod","intToReal","OR","AND","NULO","GOTO","=",">","<","<=",">=","!=","=TRUE","Lit_entero","Lit_real","Lit_bool","Entero","Real","Booleano","Caracter","String","Verdadero","Falso"};
	FILE *archivo = fopen("tablaSimbolos.txt", "w");
	
	// Imprimir encabezado
	fprintf(archivo, "Nombre\t\t\tTipo\t\tClave\n");

	for (int i = 0; i < tablaSimbolos.sigPos; ++i) {
        fprintf(archivo, "%s\t\t\t%s\t\t%d\n",
                tablaSimbolos.simbolos[i].nombre,
                enumerados[tablaSimbolos.simbolos[i].tipo],
                tablaSimbolos.simbolos[i].clave);
    
	}
}
