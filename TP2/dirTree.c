#include <stdio.h>
#include <dirent.h>
#include <string.h>

#include "dirTree.h"

static char* newPath(char* path, char* name){
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
        if (de->d_type == DT_REG){
            refArrAdd(origRef, fileInfoNew(path, de->d_name));
            refArrAdd(sortRef, fileInfoNew(path, de->d_name));
        }
        else if (de->d_type == DT_DIR){
            char* new_path = newPath(path, de->d_name);
            scanDirTree(new_path, pathShare, origRef, sortRef);
        }
    }
    closedir(directory);
}
