#include <stdio.h>
#include <string.h>

int findTerm( char *str, char *terms[], int numTerms )
{
    int lasttermindex = 0;
    int lastindex = 0;
    for (int i = 0; str[i] != '\n' && str[i] != '\0'; i++)
    {
        if (str[i] == '.')
            lasttermindex = i;
        lastindex = i + 1;
    }
    for (int i = 0; i < numTerms; i++)
    {
        int res = strcmp(&str[lasttermindex+1],terms[i]);
        if (res == 0)
            return lasttermindex;
    }
    return lastindex;
}

/* int main()
{
    char *str = "prog.o";
    char* terms[] = {"c","h"};
    int termsize = sizeof( terms ) / sizeof( char * );
    printf("%d", findTerm(str,terms, termsize));

} */
