#include <stdio.h>
#include <stdlib.h>
     
#define BLOCK_SIZE 8  

int cmpInt( const void *e1,const void *e2 ){
	return *(const int *)e1 - *(const int *)e2;
}

int main(){

	int space = 0;
	int size = 0;
	int *data = NULL;
	int v;
	while( scanf( "%d", &v ) == 1 ){
		if( size == space ){
			data = realloc( data, ( space += BLOCK_SIZE ) * sizeof *data );
			if( data == NULL ){
				fprintf( stderr, "Erro, realloc falhou alojamento\n" );
				return -1;
			}
		}
		data[size++] = v;
	}

	for( int i = 0; i < size; ++i ){
		printf( "%d ", data[i] );
	}
	putchar( '\n' );
	
	qsort( data, size, sizeof *data, cmpInt ); 
	
	for( int i = 0; i < size; ++i ){
		printf( "%d ", data[i] );
	}
	putchar( '\n' );
	free( data );
	return 0;
 }
