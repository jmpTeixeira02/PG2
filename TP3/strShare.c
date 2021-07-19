#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "strShare.h"

#define BLOCK_SIZE 8

StrShare *strShareCreate(void){
    // Criar variavel
    StrShare *data = malloc(sizeof *data);
    if( data == NULL ){
		fprintf( stderr, "Erro, malloc falhou alojamento de StrShare\n" );
		exit( -1 );
	}
    data->space = data->count = 0;
    data-> data = NULL;
    return data;
}

char *StrShareAdd(StrShare *share, char *str){
    // Se a estrutura começar a ficar cheia, aumentar o espaço
    if (share->space == share->count){
        // Criar espaço para novos elementos
        share->data = realloc(share->data, (share->space += BLOCK_SIZE) * sizeof *share->data);
        if( share->data == NULL ){
            fprintf( stderr, "Erro, malloc falhou alojamento de StrShare\n" );
            exit( -1 );
	    }
    }
    return share->data[share->count++] = strdup(str);
}

void strShareDelete( StrShare *share ){
    for (int i = 0; i < share->count; i++){
        free (share->data[i]);
    }
    free(share->data);
    free(share);
}
