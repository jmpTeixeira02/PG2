#include <stdio.h>
#include <dirent.h>
#include <string.h>

#include "dirTree.h"

static char* newPath(char* path, char* name){
    printf("AA");
    char* new_path;
    strcpy(new_path, path);
    strcat(new_path, "/");
    strcat(new_path, name);
    return new_path;
}

void scanDirTree( char *path, StrShare *pathShare, RefArray *origRef, RefArray *sortRef ){
    DIR *directory = opendir(path);
    if (directory == NULL)
        return;
    StrShareAdd(pathShare, path);
    struct dirent *de;
    while ( (de = readdir (directory)) != NULL){
        if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0)
            continue;
        //refArrAdd(origRef, fileInfoNew(path, de->d_name));
        //refArrAdd(sortRef, fileInfoNew(path, de->d_name));
        if (de->d_type == DT_DIR){
            char* new_path = newPath(path, de->d_name);
            scanDirTree(new_path, pathShare, origRef, sortRef);
        }
    }
    closedir(directory);
}

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
