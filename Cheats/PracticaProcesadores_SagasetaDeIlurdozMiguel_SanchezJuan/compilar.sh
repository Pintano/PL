#!/bin/bash

# Script para compilar el parser

# Generar el parser con bison
bison -v -d parser.y

# Generar el escáner con flex
flex escaner.l

# Compilar el archivo generado por flex
gcc -c lex.yy.c

# Compilar el parser junto con el archivo generado por flex y otros archivos necesarios
gcc parser.tab.c lex.yy.o tablaSimbolos.c tablaCuadruplas.c -lfl -lm

# Limpiar archivos temporales generados por bison y flex
rm lex.yy.c parser.tab.c parser.tab.h
