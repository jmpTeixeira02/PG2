#ifndef _FILEINFO_H_
#define _FILEINFO_H_

#include "termFind.h"

typedef struct {
    char *path; // string partilhada – localização do ficheiro
    char *name; // string alojada dinamicamente – nome completo
    int term; // posição da terminação no nome
} FileInfo;

FileInfo *fileInfoNew( char *sharedPath, char *name );
void fileInfoDelete( FileInfo *info );

#endif
