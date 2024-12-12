/* Juan Sánchez Albardíaz y Miguel Sagaseta de Ilúrdoz Sánchez */

%{
  #include <math.h>
  #include <stdio.h>
  extern FILE* yyin;
  int yylex (void);
  void yyerror (char const *);
%}

%code requires{

	#include "tablaSimbolos.h"
	#include "tablaCuadruplas.h"
	
	typedef struct TipoListaEnt{
		int siguiente;
		int claves[100];
	}TipoListaEnt;
	
	typedef struct TipoInstrucciones{
		int siguiente;
		int next[100];
	}TipoInstrucciones;
	
	typedef struct TipoListaChar{
		int siguiente;
		char* array[100];
	}TipoListaChar;
	
	typedef struct TipoBooleano{
		int verdadero[100];
		int falso[100];
		int sigVerdadero;
		int sigFalso;
		int place;
		int nextQuad;
	}TipoBooleano;
	
	typedef struct TipoExpresion{
		int place;
		int type;
		int nextQuad;
	}TipoExpresion;

	typedef struct tipoM{
		int nextQuad;
	}TipoM;

	
}


%union{
	TipoListaEnt listaID;
	TipoListaChar listaNombres;
	TipoBooleano booleano;
	TipoExpresion expresion;
	TipoInstrucciones instruccion;
	Tipos tipos;
	int entero;
	int oprel;
	int tipoBase;
	TipoM variableM;
	char cadena[100];
}


%token LITERAL_ENTERO LITERAL_REAL LITERAL_BOOLEANO LITERAL_CARACTER LITERAL_CADENA LITERAL_NUMERICO COMENTARIO ALGORITMO ACCION FACCION FUNCION FFUNCION FALGORITMO CONST CONTINUAR DE DEV ENT ENTRADA_SALIDA FALSO FCONST FMIENTRAS FPARA FSI FTIPO FTUPLA FVAR HACER HASTA MIENTRAS MOD NO  PARA  SAL SI TABLA TIPO TUPLA VAR VERDADERO COMA PUNTOPUNTO DOSPUNTOS DOSPUNTOSIGUAL PUNTOCOMA IGUAL  CORCHETECERRAR MAS MENOS POR ENTRE PARENTESISABRIR PARENTESISCERRAR  FLECHA ELSE


%left MAS MENOS O
%left POR ENTRE DIV MOD
%left Y 

%left CORCHETEABRIR PUNTO REF

%type <listaID> lista_id
%type <listaID> lista_d_var
%type <instruccion> instrucciones
%type <instruccion> lista_opciones
%type <instruccion> it_cota_exp
%type <instruccion> it_cota_fija
%type <instruccion> alternativa
%token <cadena> ID_A
%token <cadena> ID_B
%type <expresion> operando_a
%type <expresion> operando_b
%type <entero> d_tipo
%token <entero> OPREL
%token <entero> TIPOBASE
%type <expresion> exp_a
%type <booleano> exp_b
%type <expresion> expresion
%type <expresion> asignacion
%type <variableM> M
%type <listaID> N
%type <instruccion> instruccion


%% /* The grammar follows. */

desc_algoritmo:
    ALGORITMO ID_A PUNTOCOMA cabecera_alg bloque_alg FALGORITMO PUNTO {}
| ALGORITMO ID_B PUNTOCOMA cabecera_alg bloque_alg FALGORITMO PUNTO {}
    ;
cabecera_alg:
    decl_globales decl_a_f decl_ent_sal COMENTARIO {}
    ;
bloque_alg:
    bloque COMENTARIO {}
    ;
decl_globales:
    declaracion_tipo decl_globales {}
| declaracion_const decl_globales {}
| %empty
;
decl_a_f:
    accion_d decl_a_f {}
| funcion_d decl_a_f {}
|%empty
;
bloque:
    declaraciones instrucciones {}
;
declaraciones:
    declaracion_tipo declaraciones {}
| declaracion_const declaraciones {}
| declaracion_var declaraciones {}
| %empty
;
/* Declaraciones */
declaracion_tipo:
    TIPO lista_d_tipo FTIPO PUNTOCOMA {}
;
declaracion_const:
    CONST lista_d_cte FCONST PUNTOCOMA {}
;
declaracion_var:
    VAR lista_d_var FVAR PUNTOCOMA {}
;
/* Declaraciones de tipos */
lista_d_tipo:
    ID_A IGUAL d_tipo PUNTOCOMA lista_d_tipo {}
| ID_B IGUAL d_tipo PUNTOCOMA lista_d_tipo {}
| %empty
;
d_tipo:
    TUPLA lista_campos FTUPLA {}
| TABLA CORCHETEABRIR expresion_t PUNTOPUNTO expresion_t CORCHETECERRAR DE d_tipo {}
| ID_A {}
| ID_B {}
| expresion_t PUNTOPUNTO expresion_t {}
| REF d_tipo {}
| TIPOBASE	{
			$$ = $1;
			}
;
expresion_t:
    expresion {}
| LITERAL_CARACTER {}
;
lista_campos:
    ID_A DOSPUNTOS d_tipo PUNTOCOMA lista_campos
| ID_B DOSPUNTOS d_tipo PUNTOCOMA lista_campos
| %empty
;
/* Declaraciones de constantes y variables */
lista_d_cte:
    ID_A IGUAL LITERAL_ENTERO PUNTOCOMA lista_d_cte
| ID_A IGUAL LITERAL_REAL PUNTOCOMA lista_d_cte
| ID_A IGUAL LITERAL_BOOLEANO PUNTOCOMA lista_d_cte
| ID_A IGUAL LITERAL_CADENA PUNTOCOMA lista_d_cte
| ID_A IGUAL LITERAL_NUMERICO PUNTOCOMA lista_d_cte
| ID_A IGUAL LITERAL_CARACTER PUNTOCOMA lista_d_cte

| ID_B IGUAL LITERAL_ENTERO PUNTOCOMA lista_d_cte
| ID_B IGUAL LITERAL_REAL PUNTOCOMA lista_d_cte
| ID_B IGUAL LITERAL_BOOLEANO PUNTOCOMA lista_d_cte
| ID_B IGUAL LITERAL_CADENA PUNTOCOMA lista_d_cte
| ID_B IGUAL LITERAL_NUMERICO PUNTOCOMA lista_d_cte
| ID_B IGUAL LITERAL_CARACTER PUNTOCOMA lista_d_cte
| %empty
;
lista_d_var:
    lista_id DOSPUNTOS d_tipo PUNTOCOMA lista_d_var 	{
						for (int i = 0; i < $1.siguiente; i++){
    							actualiza_tipo_simbolo($1.claves[i],$3);
							$$.claves[i] = $1.claves[i];
						}
						$$.siguiente = $1.siguiente;
    						}
| %empty {}
;
lista_id:
    ID_A COMA lista_id	{
    			$3.claves[$3.siguiente] = insertar_simbolo($1);
    			$3.siguiente++;
    			$$ = $3;
			}
| ID_A	{ 
	$$.claves[0] = insertar_simbolo($1);
	$$.siguiente = 1;
	}
	
| ID_B	{ 
	$$.claves[0] = insertar_simbolo($1);
	$$.siguiente = 1;
	}
	
| ID_B COMA lista_id	{
    			$3.claves[$3.siguiente] = insertar_simbolo($1);
    			$3.siguiente++;
    			$$ = $3;
			}
;
decl_ent_sal:
    decl_ent
| decl_ent decl_sal
| decl_sal
;
decl_ent:
    ENT lista_d_var
;
decl_sal:
    SAL lista_d_var
;
/* Expresiones */


exp_a:
    exp_a MAS exp_a {
    			int T = insertar_variable_temporal();
    			$$.place = T;
    			if($1.type == ENTERO_ENUM && $3.type == ENTERO_ENUM){
				actualiza_tipo_simbolo(T, ENTERO_ENUM);
				gen($1.place,SUMA_ENTERO,$3.place,T);
				$$.type = ENTERO_ENUM;
			}
			else if($1.type == ENTERO_ENUM && $3.type == REAL_ENUM){
				actualiza_tipo_simbolo(T, REAL_ENUM);
				gen($1.place,INT_TO_REAL,NULO,T);
				gen(T,SUMA_REAL,$3.place,T);
				$$.type = REAL_ENUM;
			}
			else if($1.type == REAL_ENUM && $3.type == ENTERO_ENUM){
				actualiza_tipo_simbolo(T, REAL_ENUM);
				gen($3.place,INT_TO_REAL,NULO,T);
				gen(T,SUMA_REAL,$1.place,T);
				$$.type = REAL_ENUM;
			}
			else if($1.type == REAL_ENUM && $3.type == REAL_ENUM){
				actualiza_tipo_simbolo(T, REAL_ENUM);
				gen($1.place,SUMA_REAL,$3.place,T);
				$$.type = REAL_ENUM;
			}
		}
    			
| exp_a MENOS exp_a {
    			int T = insertar_variable_temporal();
    			$$.place = T;
    			if($1.type == ENTERO_ENUM && $3.type == ENTERO_ENUM){
				actualiza_tipo_simbolo(T, ENTERO_ENUM);
				gen($1.place,RESTA_ENTERO,$3.place,T);
				$$.type = ENTERO_ENUM;
			}
			else if($1.type == ENTERO_ENUM && $3.type == REAL_ENUM){
				actualiza_tipo_simbolo(T, REAL_ENUM);
				gen($1.place,INT_TO_REAL,NULO,T);
				gen(T,RESTA_REAL,$3.place,T);
				$$.type = REAL_ENUM;
			}
			else if($1.type == REAL_ENUM && $3.type == ENTERO_ENUM){
				actualiza_tipo_simbolo(T, REAL_ENUM);
				gen($3.place,INT_TO_REAL,NULO,T);
				gen(T,RESTA_REAL,$1.place,T);
				$$.type = REAL_ENUM;
			}
			else if($1.type == REAL_ENUM && $3.type == REAL_ENUM){
				actualiza_tipo_simbolo(T, REAL_ENUM);
				gen($1.place,RESTA_REAL,$3.place,T);
				$$.type = REAL_ENUM;
			}
		}
| exp_a POR exp_a {
    			int T = insertar_variable_temporal();
    			$$.place = T;
    			if($1.type == ENTERO_ENUM && $3.type == ENTERO_ENUM){
				actualiza_tipo_simbolo(T, ENTERO_ENUM);
				gen($1.place,MULT_ENTERO,$3.place,T);
				$$.type = ENTERO_ENUM;
			}
			else if($1.type == ENTERO_ENUM && $3.type == REAL_ENUM){
				actualiza_tipo_simbolo(T, REAL_ENUM);
				gen($1.place,INT_TO_REAL,NULO,T);
				gen(T,MULT_REAL,$3.place,T);
				$$.type = REAL_ENUM;
			}
			else if($1.type == REAL_ENUM && $3.type == ENTERO_ENUM){
				actualiza_tipo_simbolo(T, REAL_ENUM);
				gen($3.place,INT_TO_REAL,NULO,T);
				gen(T,MULT_REAL,$1.place,T);
				$$.type = REAL_ENUM;
			}
			else if($1.type == REAL_ENUM && $3.type == REAL_ENUM){
				actualiza_tipo_simbolo(T, REAL_ENUM);
				gen($1.place,MULT_REAL,$3.place,T);
				$$.type = REAL_ENUM;
			}
		}
| exp_a ENTRE exp_a {
    			int T = insertar_variable_temporal();
    			$$.place = T;
    			if($1.type == ENTERO_ENUM && $3.type == ENTERO_ENUM){
				actualiza_tipo_simbolo(T, ENTERO_ENUM);
				gen($1.place,DIV_ENTERO,$3.place,T);
				$$.type = ENTERO_ENUM;
			}
			else if($1.type == ENTERO_ENUM && $3.type == REAL_ENUM){
				actualiza_tipo_simbolo(T, REAL_ENUM);
				gen($1.place,INT_TO_REAL,NULO,T);
				gen(T,DIV_REAL,$3.place,T);
				$$.type = REAL_ENUM;
			}
			else if($1.type == REAL_ENUM && $3.type == ENTERO_ENUM){
				actualiza_tipo_simbolo(T, REAL_ENUM);
				gen($3.place,INT_TO_REAL,NULO,T);
				gen(T,DIV_REAL,$1.place,T);
				$$.type = REAL_ENUM;
			}
			else if($1.type == REAL_ENUM && $3.type == REAL_ENUM){
				actualiza_tipo_simbolo(T, REAL_ENUM);
				gen($1.place,DIV_REAL,$3.place,T);
				$$.type = REAL_ENUM;
			}
		}
| exp_a MOD exp_a {
    			int T = insertar_variable_temporal();
    			$$.place = T;
    			if($1.type == ENTERO_ENUM && $3.type == ENTERO_ENUM){
				actualiza_tipo_simbolo(T, ENTERO_ENUM);
				gen($1.place,MODULO,$3.place,T);
				$$.type = ENTERO_ENUM;
			}
			else if($1.type == ENTERO_ENUM && $3.type == REAL_ENUM){
				yyerror("Operación incorrecta");
			}
			else if($1.type == REAL_ENUM && $3.type == ENTERO_ENUM){
				yyerror("Operación incorrecta");
			}
			else if($1.type == REAL_ENUM && $3.type == REAL_ENUM){
				yyerror("Operación incorrecta");
			}
		}
| exp_a DIV exp_a {
    			int T = insertar_variable_temporal();
    			$$.place = T;
    			if($1.type == ENTERO_ENUM && $3.type == ENTERO_ENUM){
				actualiza_tipo_simbolo(T, ENTERO_ENUM);
				gen($1.place,DIV_ENUM,$3.place,T);
				$$.type = ENTERO_ENUM;
			}
			else if($1.type == ENTERO_ENUM && $3.type == REAL_ENUM){
				yyerror("Operación incorrecta");
			}
			else if($1.type == REAL_ENUM && $3.type == ENTERO_ENUM){
				yyerror("Operación incorrecta");
			}
			else if($1.type == REAL_ENUM && $3.type == REAL_ENUM){
				yyerror("Operación incorrecta");
			}
		}
| PARENTESISABRIR exp_a PARENTESISCERRAR {
					$$.type = $2.type;
					$$.place = $2.place;
					}
| operando_a {$$ = $1;}
| LITERAL_NUMERICO {}
| LITERAL_ENTERO {
			$$.type = ENTERO_ENUM;
			char nombreLiteral[100];
			sprintf(nombreLiteral,"L.E.%d", tablaSimbolos.sigPos);
			$$.place = insertar_simbolo(nombreLiteral);
			
		}
| LITERAL_REAL {}
| MENOS exp_a {}
;
exp_b:
    exp_b O M exp_b {
    			backpatch($1.falso,$1.sigFalso,$3.nextQuad);
    			merge($1.verdadero,$1.sigVerdadero,$4.verdadero,$4.sigFalso,$$.verdadero);
    			igualar_listas($$.falso,$4.falso,$4.sigFalso);
    			$$.sigFalso = $4.sigFalso;
    		}
| exp_b Y M exp_b {
				backpatch($1.verdadero,$1.sigVerdadero,$3.nextQuad);
    			merge($1.falso,$1.sigFalso,$4.falso,$4.sigFalso,$$.falso);
    			igualar_listas($$.verdadero,$4.verdadero,$4.sigVerdadero);
    			$$.sigVerdadero = $4.sigVerdadero;
		}	
| NO exp_b {
		igualar_listas($$.verdadero,$2.falso,$2.sigFalso);
		$$.sigVerdadero = $2.sigFalso;
		igualar_listas($$.falso,$2.verdadero,$2.sigVerdadero);
		$$.sigFalso = $2.sigVerdadero;
}
| operando_b {
		$$.verdadero[0] = makelist(tablaCuadruplas.sigPos);
		$$.falso[0] = makelist(tablaCuadruplas.sigPos +1);
		$$.sigVerdadero = 1;
		$$.sigFalso = 1;
		gen($1.place,IGUAL_A_VERDADERO,NULO,-1);
		gen(NULO,SALTO,NULO,-1);
}
| VERDADERO {}
| FALSO {}
| expresion OPREL expresion {
				$$.verdadero[0] = makelist(tablaCuadruplas.sigPos);
				$$.falso[0] = makelist(tablaCuadruplas.sigPos +1);
				$$.sigVerdadero = 1;
				$$.sigFalso = 1;
				gen($1.place,$2,$3.place,-1);
				gen(NULO,SALTO,NULO,-1);
}
| PARENTESISABRIR exp_b PARENTESISCERRAR {
						igualar_listas($$.verdadero,$2.verdadero,$2.sigVerdadero);
						$$.sigVerdadero = $2.sigVerdadero;
						igualar_listas($$.falso,$2.falso,$2.sigFalso);
						$$.sigFalso = $2.sigFalso;
}
;

expresion:
    exp_a {
    		$$.type = $1.type;
    		$$.place = $1.place;
    	}
| exp_b {}
| funcion_ll {}
;
operando_a:
    ID_A {
    		$$.type = obtener_tipo_simbolo($1);
    		$$.place = obtener_clave_simbolo($1);
    		}
| operando_a PUNTO operando_a {}
| operando_a CORCHETEABRIR expresion CORCHETECERRAR {}
| operando_a REF {}
;
operando_b:
    ID_B {
			$$.type = obtener_tipo_simbolo($1);
    		$$.place = obtener_clave_simbolo($1);
    }
| operando_b PUNTO operando_b {}
| operando_b CORCHETEABRIR expresion CORCHETECERRAR {}
| operando_b REF {}
;
/* Instrucciones */
instrucciones:
    instruccion PUNTOCOMA instrucciones {}
| instruccion {}
;
instruccion:
    CONTINUAR {}
| asignacion {
				$$.siguiente = makelist(0);
				}
| alternativa {}
| iteracion {}
| accion_ll {}
;

asignacion:
    operando_a DOSPUNTOSIGUAL  expresion {
    						if ($1.type == $3.type){
    							gen($3.place,ASIGNACION_ENUM,NULO,$1.place);
    						} else if ($1.type == REAL_ENUM && $3.type == ENTERO_ENUM){
    							gen($3.place,INT_TO_REAL,NULO,$1.place);
    							gen($3.place,ASIGNACION_ENUM,NULO,$1.place);
    						} else if ($1.type == ENTERO_ENUM && $3.type == REAL_ENUM){
    							gen($3.place,ASIGNACION_ENUM,NULO,$1.place);
    						} else {yyerror("Se ha producido un error");}
    					}
| operando_b DOSPUNTOSIGUAL exp_b
								{
									backpatch($3.falso,$3.sigFalso,tablaCuadruplas.sigPos);
								    gen(NULO,VERDADERO_ENUM,NULO,$1.place);
									gen(NULO,SALTO,NULO,tablaCuadruplas.sigPos +2);
									backpatch($3.verdadero,$3.sigVerdadero,tablaCuadruplas.sigPos);
									gen(NULO,FALSO_ENUM,NULO,$1.place);
								}
;
alternativa:
    SI exp_b FLECHA M instrucciones M lista_opciones FSI
							{
    							backpatch($2.verdadero,$2.sigVerdadero,$4.nextQuad);
    							if (!esVacio($7.siguiente)){
    								backpatch($2.falso,$2.sigFalso,$6.nextQuad);
    							}
    							if(!esVacio($5.siguiente)){
									int listaVacia[100];
									merge($2.falso,$2.sigFalso,$5.next,$5.siguiente,listaVacia);
									int sigListaVacia = $2.sigFalso + $5.siguiente;
									merge(listaVacia,sigListaVacia,$7.next,$7.siguiente,$$.next);
									$$.siguiente = sigListaVacia + $7.siguiente +1;
    							}else{
									int listaVacia[100];
									int listaVacia2[100];
									merge($2.falso,$2.sigFalso,$5.next,$5.siguiente,listaVacia);
									int sigListaVacia = $2.sigFalso + $5.siguiente;
									merge(listaVacia,sigListaVacia,listaVacia2,0,$$.next);
									$$.siguiente = sigListaVacia +1;
									gen(NULO,SALTO,NULO,-1);
    							}
    						}
;
lista_opciones:
    ELSE exp_b FLECHA M instrucciones M lista_opciones
							{
    							backpatch($2.verdadero,$2.sigVerdadero,$4.nextQuad);
    							if (!esVacio($7.siguiente)){
    								backpatch($2.falso,$2.sigFalso,$6.nextQuad);
    							}
    							if(!esVacio($5.siguiente)){
									int listaVacia[100];
									merge($2.falso,$2.sigFalso,$5.next,$5.siguiente,listaVacia);
									int sigListaVacia = $2.sigFalso + $5.siguiente;
									merge(listaVacia,sigListaVacia,$7.next,$7.siguiente,$$.next);
									$$.siguiente = sigListaVacia + $7.siguiente +1;
    							}else{
									int listaVacia[100];
									int listaVacia2[100];
									merge($2.falso,$2.sigFalso,$5.next,$5.siguiente,listaVacia);
									int sigListaVacia = $2.sigFalso + $5.siguiente;
									merge(listaVacia,sigListaVacia,listaVacia2,0,$$.next);
									$$.siguiente = sigListaVacia +1;
									gen(NULO,SALTO,NULO,-1);
    							}
    						}
| %empty {}
;
iteracion:
    it_cota_fija {}
| it_cota_exp {}
;
it_cota_exp:
    MIENTRAS M exp_b HACER M instrucciones FMIENTRAS {
    							backpatch($3.verdadero,$3.sigVerdadero,$5.nextQuad);
    							if (!esVacio($6.siguiente)){
    								backpatch($6.next,$6.siguiente,$2.nextQuad);
    							}else{
    								gen(NULO,SALTO,NULO,$2.nextQuad);
    							}
    							igualar_listas($$.next,$3.falso,$3.sigFalso);
    							$$.siguiente = $3.sigFalso;
    						}

it_cota_fija:
    PARA ID_A DOSPUNTOSIGUAL expresion HASTA expresion N HACER M instrucciones FPARA{
								backpatch($10.next,$10.siguiente,tablaCuadruplas.sigPos);
								gen(obtener_clave_simbolo($2),SUMA_ENTERO,LITERAL_ENTERO_ENUM,obtener_clave_simbolo($2));
								gen(NULO,SALTO,NULO,tablaCuadruplas.sigPos +2);
								backpatch($7.claves,$7.siguiente,tablaCuadruplas.sigPos);
								gen(NULO,ASIGNACION_ENUM,$4.place,obtener_clave_simbolo($2));
								gen(obtener_clave_simbolo($2),MENOR_ENUM,$6.place,$9.nextQuad);
								$$.next[0] = makelist(tablaCuadruplas.sigPos);
								$$.siguiente = 1;
								gen(NULO,SALTO,NULO,-1);
		}
| PARA ID_B DOSPUNTOSIGUAL expresion HASTA expresion N HACER M instrucciones FPARA{
								backpatch($10.next,$10.siguiente,tablaCuadruplas.sigPos);
								gen(obtener_clave_simbolo($2),SUMA_ENTERO,LITERAL_ENTERO_ENUM,obtener_clave_simbolo($2));
								gen(NULO,SALTO,NULO,tablaCuadruplas.sigPos +2);
								backpatch($7.claves,$7.siguiente,tablaCuadruplas.sigPos);
								gen(NULO,ASIGNACION_ENUM,$4.place,obtener_clave_simbolo($2));
								gen(obtener_clave_simbolo($2),MENOR_ENUM,$6.place,$9.nextQuad);
								$$.next[0] = makelist(tablaCuadruplas.sigPos);
								$$.siguiente = 1;
								gen(NULO,SALTO,NULO,-1);
		}
;
/* Acciones y funciones */
accion_d:
    ACCION a_cabecera bloque FACCION
;
funcion_d:
    FUNCION f_cabecera bloque DEV expresion FFUNCION
;
a_cabecera:
    ID_A PARENTESISABRIR d_par_form PARENTESISCERRAR PUNTOCOMA
| ID_B PARENTESISABRIR d_par_form PARENTESISCERRAR PUNTOCOMA
;
f_cabecera:
    ID_A PARENTESISABRIR lista_d_var PARENTESISCERRAR DEV d_tipo PUNTOCOMA
| ID_B PARENTESISABRIR lista_d_var PARENTESISCERRAR DEV d_tipo PUNTOCOMA
;
d_par_form:
    d_p_form PUNTOCOMA d_par_form
| %empty
;
d_p_form:
    ENT lista_id DOSPUNTOS d_tipo
| SAL lista_id DOSPUNTOS d_tipo
| ENTRADA_SALIDA lista_id DOSPUNTOS d_tipo
;
accion_ll:
    ID_A PARENTESISABRIR l_ll PARENTESISCERRAR
| ID_B PARENTESISABRIR l_ll PARENTESISCERRAR
;
funcion_ll:
    ID_A PARENTESISABRIR l_ll PARENTESISCERRAR
| ID_B PARENTESISABRIR l_ll PARENTESISCERRAR
;
l_ll:
    expresion COMA l_ll
| expresion
;
M:
%empty {$$.nextQuad = tablaCuadruplas.sigPos;}

N:
%empty {
	$$.claves[0] = makelist(tablaCuadruplas.sigPos);
	$$.siguiente = 1;
	gen(NULO,SALTO,NULO,-1);
}

%%
#include <ctype.h>
#include <stdlib.h>


int main( int argc, char **argv )
	{
	iniciar_tabla();
	iniciar_tabla_cuadruplas();
	++argv, --argc;  /* skip over program name */
	if ( argc > 0 )
		yyin = fopen( argv[0], "r" );
	else
		yyin = stdin;

	yyparse();
	imprimir_tabla_simbolos();
	imprimirTablaCuadruplas();
	}

#include <stdio.h>
void yyerror (char const *s)
{
  fprintf (stderr, "%s\n", s);
}

