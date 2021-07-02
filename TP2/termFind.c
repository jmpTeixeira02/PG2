#include <stdio.h>
#include <string.h>

static char** gTerms;
static int nTerms;

void termSetupTypes( char* terms[], int numTerms ){
    gTerms = terms;
    nTerms = numTerms;
}

int termFind(char *str){
    int lasttermindex = 0;
    int lastindex = 0;
    for (int i = 0; str[i] != '\n' && str[i] != '\0'; i++){
        if (str[i] == '.')
        lasttermindex = i;
        lastindex = i + 1;
    }
    for (int i = 0; i < nTerms; i++){
        int res = strcmp(&str[lasttermindex+1],gTerms[i]);
        if (res == 0)
            return lasttermindex;
    }
    return lastindex;
}
