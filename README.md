bison -d -v programa.y


CONECTAR FLEX Y BISON
bison -d programa.y
flex scanner.l
gcc -o parser programa.tab.c lex.yy.c -lfl
./parser


int main( int argc, char **argv )
    {
    ++argv, --argc;  /* skip over program name */
    if ( argc > 0 )
            yyin = fopen( argv[0], "r" );
    else
            yyin = stdin;

    yylex();
    }
#   P L  
 