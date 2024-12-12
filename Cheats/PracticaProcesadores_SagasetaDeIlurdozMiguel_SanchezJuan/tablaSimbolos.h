#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

#include <stdio.h>
#include <stdbool.h>

typedef enum Tipos{
	ENTERO_ENUM = 26,
	REAL_ENUM,
	BOOLEANO_ENUM,
	CARACTER_ENUM,
	STRING_ENUM,
	VERDADERO_ENUM,
	FALSO_ENUM
}Tipos;

typedef struct simbolo{
	char nombre[100];
	int tipo;
	int clave;
}Simbolo;

typedef struct tabla{
	int sigPos;
	Simbolo simbolos[100];
}Tabla;

extern Tabla tablaSimbolos;

void iniciar_tabla();
int insertar_simbolo(char*);
Simbolo crear_simbolo(char*);
void actualiza_tipo_simbolo(int, int);
int obtener_tipo_simbolo(char*);
int obtener_clave_simbolo(char*);
int insertar_variable_temporal();
void imprimir_tabla_simbolos();


#endif
