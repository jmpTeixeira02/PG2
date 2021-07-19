#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "refArray.h"

#define BLOCK_SIZE 8


// Deixar por fazer
RefArray *refArrCreate( void ){
    RefArray *array = malloc(sizeof *array);
    if (array == NULL){
        fprintf( stderr, "Erro, malloc falhou alojamento de StrShare\n" );
		exit( -1 );
    }
    array->space = array->count = 0;
    array->data = NULL;
    return array;
}

// Deixar por fazer
void refArrDelete( RefArray *ra){
    for (int i = 0; i < ra->count; i++)
        fileInfoDelete(ra->data[i]);
    free(ra->data);
    free(ra);
}

// Deixar por fazer
void refArrAdd( RefArray *ra, FileInfo *ref ){
    if (ra->space == ra->count){
        // Criar espaço para novos elementos
        ra->data = realloc(ra->data, (ra->space += BLOCK_SIZE) * sizeof *ra->data);
        if( ra->data == NULL ){
            fprintf( stderr, "Erro, malloc falhou alojamento de StrShare\n" );
            exit( -1 );
	    }
    }
    ra->data[ra->count++] = ref;
}


static int compare( const void *e1, const void *e2 ){ 
    const FileInfo *data1 = *(const FileInfo **)e1;
    const FileInfo *data2 = *(const FileInfo **)e2;
    //Se tiverem o mesmo nome, ordenar por ditoria
    if (strcmp(data1->name, data2->name) == 0)
        return strcmp(data1->path,data2->path);
    return strcmp((data1->name),(data2->name));
}

void refArrSort( RefArray *ra ){
    qsort(ra->data, ra->count, sizeof(FileInfo*), compare);
}

void refArrScan( RefArray *ra, void (*act)(FileInfo *fi, void *param),void *actParam ){
    for (int i = 0; i < ra->count; i++)
        act(ra->data[i], actParam);
}
