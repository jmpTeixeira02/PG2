#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "vector-str.h"

#define BLOCK_SIZE 8

static int cmpStrPtr( const void *e1,const void *e2 ){
	return  strcmp( *( char **)e1, *( char **)e2 );
}

StrVec *vecStrCreate( void ){
	StrVec *v = malloc( sizeof *v );
	if( v == NULL ){
		fprintf( stderr, "Erro, malloc falhou alojamento de StrVec\n" );
		exit( -1 );
	}
	v->size = v->space = 0;
	v->data = NULL;
	return v;
}

void vecStrAdd( StrVec *v, char *s ){
	if( v->size == v->space ){
		v->data = realloc( v->data, ( v->space += BLOCK_SIZE ) * sizeof *v->data );
		if( v->data == NULL ){
			fprintf( stderr, "Erro, realloc falhou alojamento\n" );
			exit( -1 );
		}
	}
	v->data[v->size++] = strdup( s ); // strcpy( malloc( strlen( s ) + 1 ), s );
}

void vecStrSort( StrVec *v ){
	qsort( v->data, v->size, sizeof *v->data, cmpStrPtr );
}

void vecStrPrint( StrVec *v ){
	for( int i = 0; i < v->size; ++i ){
		printf( "%s\n", v->data[i] );
	}
}

void vecStrDelete( StrVec *v ){
	for( int i = 0; i < v->size; ++i ){
		free( v->data[i] );
	}
	free( v->data );
	free( v );
}


