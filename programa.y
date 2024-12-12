
%{
    #include <stdio.h>
    #include <stdlib.h>
    extern FILE *yyin;  // Declaración de yyin para Flex
    extern int yylex();
    void yyerror(const char *s);
    #include "symbol_table.h"
    #include "definitions.h"
    #include "cuadruple_table.h"

%}

%union {
    TipoExp expresion;
    TipoBool expresion_bool;
    IdList listaId;
    int entero;
    float real;
    char* cadena;
    enum type type;
    TipoM param;
}

/* Declaración de tokens que vienen del scanner (Flex) */
%token LITERAL_CARACTER
%token ASIGNACION  
%token DELIMITADOR SEPARADOR COMIENZO_ALGORITMO FIN_ALGORITMO
%token COMIENZO_PARENTESIS FIN_PARENTESIS
%token COMIENZO_ACCION FIN_ACCION COMIENZO_FUNCION FIN_FUNCION
%token COMIENZO_CONSTANTES FIN_CONSTANTES
%token COMIENZO_BUCLE_MIENTRAS FIN_BUCLE_MIENTRAS
%token COMIENZO_BUCLE_HACER HASTA
%token COMIENZO_BUCLE_PARA FIN_BUCLE_PARA
%token COMIENZO_VAR FIN_VAR
%token DECLARADOR_TIPO
%token COMIENZO_SI FIN_SI
%token ENTONCES ELSE
%token RETORNO NEGACION
%token PRECONDICION POSTCONDICION
%token COMIENZO_TIPO FIN_TIPO
%token COMIENZO_TUPLA FIN_TUPLA
%token COMIENZO_TABLA RANGO DECLARADOR_TIPO_TABLA
%token COMIENZO_INDICE FIN_INDICE
%token REFERENCIA PUNTERO
%token CONTINUAR 

%token <real> LITERAL_REAL
%token <cadena> LITERAL_CADENA IDENTIFICADOR_BOOLEANO IDENTIFICADOR 
%token <entero> LITERAL_ENTERO OPERADORES_MULTIPLICACION 
OPERADORES_SUMA LITERAL_BOOLEANO IGUAL COMPARADORES 
TIPO ENTRADA_SALIDA OPERADORES_BOOLEANOS

%type <listaId> lista_id
%type <listaId> lista_d_var
%type <type> d_tipo
%type <expresion_bool> exp_b 
%type <expresion> exp_a operando operando_b asignacion literal_numerico expresion
%type <param> m

%left REFERENCIA PUNTERO COMIENZO_INDICE
%left COMPARADORES IGUAL
%left OPERADORES_BOOLEANOS
%right NEGACION
%left OPERADORES_SUMA
%left OPERADORES_MULTIPLICACION
%%

desc_algoritmo: 
    COMIENZO_ALGORITMO IDENTIFICADOR DELIMITADOR cabecera_alg bloque_alg FIN_ALGORITMO { printf("Programa reconocido correctamente.\n"); }
    ;

cabecera_alg:
    decl_globales decl_a_f decl_ent_sal PRECONDICION {}
    ;

bloque_alg:
    bloque POSTCONDICION {}
    ;

decl_globales:
    declaracion_tipo decl_globales {}
    | declaracion_const decl_globales {}
    | /*vacio*/ {}
    ;

decl_a_f:
    accion_d decl_a_f {}
    | funcion_d decl_a_f {}
    | /*vacio*/ {}
    ;

bloque:
    declaraciones instrucciones {}
    ;

declaraciones:
    declaracion_tipo declaraciones {}
    | declaracion_const declaraciones {}
    | declaracion_var declaraciones {}
    | /*vacio*/ {}
    ;

declaracion_tipo: 
    COMIENZO_TIPO lista_d_tipo FIN_TIPO DELIMITADOR {
    }
    ;

declaracion_const: 
    COMIENZO_CONSTANTES lista_d_cte FIN_CONSTANTES DELIMITADOR {}
    ;

declaracion_var: 
    COMIENZO_VAR lista_d_var FIN_VAR DELIMITADOR {}
    ;

lista_d_tipo:
    IDENTIFICADOR IGUAL d_tipo SEPARADOR lista_d_tipo {}
    | /*vacio*/ {}
    ;

d_tipo: 
    COMIENZO_TUPLA lista_campos FIN_TUPLA {}
    | COMIENZO_TABLA COMIENZO_INDICE expresion_t RANGO expresion_t FIN_INDICE DECLARADOR_TIPO_TABLA d_tipo {}
    ;

d_tipo:
    IDENTIFICADOR {}
    | expresion_t RANGO expresion_t {}
    | REFERENCIA d_tipo {}
    | TIPO {
        printf("Entra tipo\n");
        $$ = $1;
        printf("Sale tipo\n");
    }
    ;

expresion_t:
    expresion {}
    | LITERAL_CARACTER {}
    ;

lista_campos: 
    IDENTIFICADOR DECLARADOR_TIPO d_tipo DELIMITADOR lista_campos {}
    | /*vacio*/ {}
    ;

lista_d_cte:
    IDENTIFICADOR IGUAL literal DELIMITADOR lista_d_cte {}
    | /*vacio*/ {}
    ;

literal: 
    LITERAL_BOOLEANO {}
    | LITERAL_CADENA {}
    | LITERAL_CARACTER {}
    | LITERAL_ENTERO {}
    | LITERAL_REAL {}
    ;


lista_d_var : 
    lista_id DECLARADOR_TIPO d_tipo DELIMITADOR lista_d_var {
        for(int i = 0; i < $1.sig; i++){
            changeSymbol($1.keys[i], $3);
            $$.keys[i] = $1.keys[i];
        }
        $$.sig = $1.sig;
        printCuadrupleTable();
        printSymbolTable();
    }
    | /*vacio*/ {}
    ;

lista_id:
    IDENTIFICADOR SEPARADOR lista_id {
        if(!existSymbol($1)){
            $3.keys[$3.sig] = insertSymbol($1);
            $3.sig++;
        }
        else{
            yyerror("Declarando identificador repetido.");
        }
        $$ = $3;
    }
    | IDENTIFICADOR_BOOLEANO SEPARADOR lista_id {
        if(!existSymbol($1)){
            $3.keys[$3.sig] = insertSymbol($1);
            $3.sig++;  
        }
        else{
            yyerror("Declarando identificador repetido.");
        }
        $$ = $3;
    }
    | IDENTIFICADOR {
        if(!existSymbol($1)){
            $$.keys[0] = insertSymbol($1);
            $$.sig = 1;
        }
        else{
            yyerror("Declarando identificador repetido.");
            $$.sig = 0;
        }
        
    }
    | IDENTIFICADOR_BOOLEANO {
        if(!existSymbol($1)){
            $$.keys[0] = insertSymbol($1);
            $$.sig = 1;
        }
        else{
            yyerror("Declarando identificador repetido.");
            $$.sig = 0;
        }
    }
    ;

decl_ent_sal:
    ENTRADA_SALIDA lista_d_var {}
    | ENTRADA_SALIDA lista_d_var ENTRADA_SALIDA lista_d_var{}
    ;
    

expresion : 
    exp_a {}
    | exp_b {}
    | funcion_ll {}
    ;

exp_a :
    exp_a OPERADORES_SUMA exp_a {
        int T = insert_temp();
        $$.place = T;
        if ($1.type == $3.type){
            changeSymbol(T, $1.type);
            gen($2, $1.place, $3.place, T);
            $$.type = $1.type;
        }
        else{
            if ($1.type == ENUM_REAL && $3.type == ENUM_ENTERO){
                changeSymbol(T, $1.type);
                gen(INT_TO_REAL,$3.place,NULO,T);
                gen($2, $1.place, $3.place,  T);
                $$.type = $1.type;
            }
            else{
                changeSymbol(T, $3.type);
                gen(INT_TO_REAL,$1.place,NULO,T);
                gen($2, $1.place, $3.place,  T);
                $$.type = $3.type;
            }

        }
    }
    | exp_a OPERADORES_MULTIPLICACION exp_a {
        int T = insert_temp();
        $$.place = T;
        if ($1.type == $3.type){
            changeSymbol(T, $1.type);
            gen($2, $1.place, $3.place, T);
            $$.type = $1.type;
        }
        else{
            if ($1.type == ENUM_REAL && $3.type == ENUM_ENTERO){
                changeSymbol(T, $1.type);
                gen(INT_TO_REAL,$3.place,NULO,T);
                gen($2, $1.place, $3.place,  T);
                $$.type = $1.type;
            }
            else{
                changeSymbol(T, $3.type);
                gen(INT_TO_REAL,$1.place,NULO,T);
                gen($2, $1.place, $3.place,  T);
                $$.type = $3.type;
            }

        }

    }
    | COMIENZO_PARENTESIS exp_a FIN_PARENTESIS {
        $$ = $2;
    }
    | operando {
        $$ = $1;
    }
    | literal_numerico {
        $$ = $1;
    }
    | OPERADORES_SUMA exp_a {
        if($1 == ENUM_RESTA){
            printf("Cambio SImbolo\n");
            int T = insert_temp();
            $$.place = T;
            gen($1,$2.place,NULO,T);
            $$.type = $2.type;
           
        }
        else if($1 == ENUM_SUMA){
            $$ = $2;
        }
    }
    ;

literal_numerico:
    LITERAL_ENTERO {
    }
    | LITERAL_REAL {}
    ;

exp_b:
    exp_b OPERADORES_BOOLEANOS m exp_b{
        printf("Entra expb operandores expb\n");
        if( $2 == ENUM_O){
            backpatch($1.FL, $3.quad);
            $$.TL = merge($1.TL, $4.TL);
            $$.FL = $4.FL;
        }
        else if($2 == ENUM_Y ){
            backpatch($1.TL, $3.quad);
            $$.FL = merge($1.FL, $4.FL);
            $$.TL = $4.TL;
        }
        else{
            // Error en operador booleano
            yyerror("Operador booleano incorrecto");
        }
    }
    | NEGACION exp_b {
        printf("Entra negacion booleana\n");
        $$.TL = $2.FL;
        $$.FL = $2.TL;
    }
    | operando_b {
        printf("Entra operando booleano\n");
        $$.TL = makelistWithData(table.nextQuad);
        $$.FL = makelistWithData(table.nextQuad + 1);
        gen(ENUM_VERDADERO,$1.place,NULO,NULO);
        gen(GOTO,NULO,NULO,NULO);
    }
    | LITERAL_BOOLEANO {
    }
    | expresion COMPARADORES expresion {
        $$.TL = makelistWithData(table.nextQuad);
        $$.FL = makelistWithData(table.nextQuad + 1);
        gen($2,$1.place,$3.place,NULO);
        gen(GOTO,NULO,NULO,NULO);
    }
    | expresion IGUAL expresion {
        $$.TL = makelistWithData(table.nextQuad);
        $$.FL = makelistWithData(table.nextQuad + 1);
        gen($2,$1.place,$3.place,NULO);
        gen(GOTO,NULO,NULO,NULO);
    }
    | COMIENZO_PARENTESIS exp_b FIN_PARENTESIS {
        $$.TL = $2.TL;
        $$.FL = $2.FL;
    }
    ;

m: /*vacio*/ {
    $$.quad = table.nextQuad;
};

operando:
    IDENTIFICADOR {
        $$.type = get_Symbol_Type($1);
        $$.place = get_Symbol_Key($1);
    }
    | operando PUNTERO operando {}
    | operando COMIENZO_INDICE expresion FIN_INDICE {}
    | operando REFERENCIA {}
    ;

operando_b:
    IDENTIFICADOR_BOOLEANO {
        $$.type = get_Symbol_Type($1);
        $$.place = get_Symbol_Key($1);
    }
    ;

instrucciones: 
    instruccion DELIMITADOR instrucciones {}
    | instruccion {}
    ;

instruccion:
    CONTINUAR {}
    | asignacion {}
    | alternativa {}
    | iteracion {}
    | accion_ll {}
    ;

asignacion: 
    operando ASIGNACION exp_a {
        printf("Asigna\n");
        if ($1.type == $3.type) {
            gen(ENUM_ASIGNACION, $3.place, NULO, $1.place);
            printCuadrupleTable();
            printSymbolTable();
        } 
        else if ($1.type == ENUM_REAL && $3.type == ENUM_ENTERO) {
            int T = insert_temp();
            gen(INT_TO_REAL, $3.place, NULO, T);
            gen(ENUM_ASIGNACION, T, NULO, $1.place);
            printCuadrupleTable();
            printSymbolTable();
        } 
        else {
            // Error en tipos incompatibles
            yyerror("Tipos incompatibles en la asignación.");
        }
       
    }
    | operando_b ASIGNACION exp_b {
        printf("Entra asignacion bool\n");
        backpatch($3.FL, table.nextQuad);
        gen(ENUM_ASIGNACION,ENUM_FALSO,NULO,$1.place);
        gen(GOTO,NULO,NULO,table.nextQuad+2);
        backpatch($3.TL,table.nextQuad);
        gen(ENUM_ASIGNACION,ENUM_VERDADERO,NULO,$1.place);
        printCuadrupleTable();
        printSymbolTable();
    }
    ;

alternativa:
    COMIENZO_SI expresion ENTONCES instrucciones lista_opciones FIN_SI {}
    ;

lista_opciones:
    ELSE expresion ENTONCES instrucciones lista_opciones {}
    | /*vacio*/ {}
    ;

iteracion:
    it_cota_fija {}
    |it_cota_exp {}
    ;

it_cota_exp:
    COMIENZO_BUCLE_MIENTRAS expresion COMIENZO_BUCLE_HACER instrucciones FIN_BUCLE_MIENTRAS{}
    ;

it_cota_fija:
    COMIENZO_BUCLE_PARA IDENTIFICADOR ASIGNACION expresion HASTA expresion COMIENZO_BUCLE_HACER instrucciones FIN_BUCLE_PARA {}
    ;

accion_d:
    COMIENZO_ACCION a_cabecera bloque FIN_ACCION {}
    ;

funcion_d:
    COMIENZO_FUNCION f_cabecera bloque RETORNO expresion FIN_FUNCION {}
    ;

a_cabecera:
    IDENTIFICADOR COMIENZO_PARENTESIS d_par_form FIN_PARENTESIS DELIMITADOR {}
    ;

f_cabecera:
    IDENTIFICADOR COMIENZO_PARENTESIS lista_d_var FIN_PARENTESIS RETORNO d_tipo DELIMITADOR {}
    ;

d_par_form:
    d_p_form DELIMITADOR d_par_form {}
    | /*vacio*/ {}
    ;

d_p_form: 
    ENTRADA_SALIDA lista_id DECLARADOR_TIPO d_tipo {}
    ;

accion_ll :
    IDENTIFICADOR COMIENZO_PARENTESIS l_ll FIN_PARENTESIS {}
    ;

funcion_ll :
    IDENTIFICADOR COMIENZO_PARENTESIS l_ll FIN_PARENTESIS {}
    ;

l_ll :
    expresion SEPARADOR l_ll {}
    | expresion {}
    ;



%%

extern int yylineno; // Asegúrate de incluir esto si estás contando líneas
extern char *yytext;

/* Manejo de errores */
void yyerror(const char *s) {
    fprintf(stderr, "Error en línea %d: %s '%s'\n", yylineno, s, yytext);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <archivo_entrada>\n", argv[0]);
        return 1;
    }

    FILE *archivo = fopen(argv[1], "r");
    if (!archivo) {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Asigna el archivo a yyin para que Flex lo use
    yyin = archivo;

    printf("Procesando el archivo: %s\n", argv[1]);
    yyparse();

    fclose(archivo);
    return 0;
}