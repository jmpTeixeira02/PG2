#include <stdio.h>
#include <dirent.h>

#include "dirTree.h"

int main()
{
    //leitura das diretorias e preenchimento da estrutura de dados
    StrShare *pathShare = strShareCreate();
    RefArray *origRef = refArrCreate();
    RefArray *sortRef = refArrCreate();
    scanDirTree("TESTE",pathShare, origRef, sortRef);
    printf("\n\n----PATHSHARE----\n\n");

    for (int i = 0; i < pathShare->count; i++){
       printf("%s\n", pathShare->data[i]);
    }

    printf("\n\n---ORIGREF----\n\n");

    for (int i = 0; i < origRef->count; i++){
       printf("%s\n", origRef->data[i]->name);
    }
}



