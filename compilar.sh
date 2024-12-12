#!/bin/bash
echo "<Inicio de bison y flex>"
    #Bison
    bison -d -v -t programa.y #el -t habrá que quitarlo

    #Flex
    flex scanner.l

    #Modulos
    gcc -c symbol_table.c
    gcc -c cuadruple_table.c

    # Compilar el archivo generado por flex
    gcc -c lex.yy.c

    # Compilar el parser junto con el archivo generado por flex y otros archivos necesarios
    gcc programa.tab.c lex.yy.o symbol_table.o cuadruple_table.o  -lfl -lm -o parserPrueba

echo "<Fin>"