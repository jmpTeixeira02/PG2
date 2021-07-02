#include <stdio.h>
#include <string.h>
#include <stdlib.h>
     
#define BLOCK_SIZE 8
#define STR_MAX 100  

int cmpStrPtr( const void *e1,const void *e2 ){
	return  strcmp( *( char **)e1, *( char **)e2 );
}

int main(){

	int space = 0;
	int size = 0;
	char **data = NULL;
	
	char v[STR_MAX];
	while( scanf( "%s", v ) == 1 ){
		if( size == space ){
			data = realloc( data, ( space += BLOCK_SIZE ) * sizeof *data );
			if( data == NULL ){
				fprintf( stderr, "Erro, realloc falhou alojamento\n" );
				return -1;
			}
		}
		
		data[size++] = strcpy( malloc(strlen( v ) + 1 ), v );
		
	}

	for( int i = 0; i < size; ++i ){
		printf( "%s\n", data[i] );
	}
	putchar( '\n' );
	
	qsort( data, size, sizeof *data, cmpStrPtr ); 
	
	for( int i = 0; i < size; ++i ){
		printf( "%s\n", data[i] );
	}
	putchar( '\n' );
	
	for( int i = 0; i < size; ++i ){
		free( data[i] );
	}
	free( data );
	return 0;
 }
