#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileInfo.h"

FileInfo *fileInfoNew( char *sharedPath, char *name ){
    FileInfo *file = malloc(sizeof *file);
    if (file == NULL){
        fprintf( stderr, "Erro, malloc falhou alojamento de StrShare\n" );
		exit( -1 );
    }
    file->path = sharedPath;
    memcpy(file->name, name, strlen(name)+1);
    file->term = termFind(name);
    return file;
}

void fileInfoDelete( FileInfo *info ){
    free(info->name);
    free(info);
}
