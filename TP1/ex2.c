#include <stdio.h>
#include "ex2.h"

int main()
{
    char *str = "prog.o";
    char* terms[] = {"c","h"};
    int termsize = sizeof( terms ) / sizeof( char * );
    printf("%d", findTerm(str,terms, termsize));
}
