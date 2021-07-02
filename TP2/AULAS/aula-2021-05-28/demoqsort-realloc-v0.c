#include <stdio.h>
#include <stdlib.h>
       

int cmpInt( const void *e1,const void *e2 ){
	return *(const int *)e1 - *(const int *)e2;
}

int main(){
	int n;
	int *b = malloc( sizeof *b );
	if( b == NULL ){
		fprintf( stderr, "Erro, malloc falhou alojamento\n" );
		return -1;
	}
	int i;
	int v;
	for( i = 0; scanf( "%d", &v ) == 1; ++i ){
		b = realloc( b, ( i + 1 ) * sizeof *b );
		if( b == NULL ){
			fprintf( stderr, "Erro, realloc falhou alojamento\n" );
			return -1;
		}
		b[i] = v;
	}
	for( int j = 0; j < i; ++j ){
		printf( "%d ", b[j] );
	}
	putchar( '\n' );
	
	qsort( b, i, sizeof *b, cmpInt ); 
	
	for( int j = 0; j < i; ++j ){
		printf( "%d ", b[j] );
	}
	putchar( '\n' );
	free( b );
	return 0;
 }
