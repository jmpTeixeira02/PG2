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
    array->space = 0;
    array->count = 0;
    array->data = NULL;
    return array;
}

// Deixar por fazer
void refArrDelete( RefArray *ra){
    for (int i = 0; i < ra->count; i++){
        free (ra->data[i]);
    }
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
    // Se tiverem o mesmo nome, ordenar por ditoria
    printf("%d %d\n", data1->term, data2->term);
    //if (strcmp(data1->name, data2->name) == 0)
        //return strcmp(data1->path,data2->path);
    //return strcmp((data2->name),(data1->name));
    return 0;
}

void refArrSort( RefArray *ra ){
    qsort(ra, ra->count, sizeof(*ra), compare);
}

void refArrScan( RefArray *ra, void (*act)(FileInfo *fi, void *param),void *actParam ){
    for (int i = 0; i < ra->count; i++)
        act(ra->data[i], actParam);
}

/* int main(){

    FileInfo *teste1 = fileInfoNew("DEF", "teste1");
    FileInfo *teste8 = fileInfoNew("ABC", "teste8");
    FileInfo *teste9 = fileInfoNew("ABC", "teste9");
    FileInfo *teste2 = fileInfoNew("DEF", "teste2");
    FileInfo *teste3 = fileInfoNew("DEF", "teste3");
    FileInfo *teste4 = fileInfoNew("ABC", "teste4");
    FileInfo *teste5 = fileInfoNew("ABC", "teste5");
    FileInfo *teste6 = fileInfoNew("ABC", "teste6");
    FileInfo *teste7 = fileInfoNew("ABC", "teste7");


    RefArray *teste = refArrCreate();
    refArrAdd(teste, teste2);
    refArrAdd(teste, teste4);
    refArrAdd(teste, teste3);
    refArrAdd(teste, teste1);
    refArrAdd(teste, teste5);
    refArrAdd(teste, teste6);
    refArrAdd(teste, teste7);
    refArrAdd(teste, teste8);
    refArrAdd(teste, teste9);
    for (int i = 0; i < 9; i++)
        printf("%d %d %s %s\n", teste->count, teste->space,(teste->data[i])->path ,teste->data[i]->name);
    refArrSort(teste);
    for (int i = 0; i < 9; i++)
        printf("%d %d %s %s\n", teste->count, teste->space,(teste->data[i])->path ,teste->data[i]->name);
    return 0;
} */