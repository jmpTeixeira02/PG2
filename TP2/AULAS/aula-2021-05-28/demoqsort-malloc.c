#include <stdio.h>
#include <stdlib.h>
       

int cmpInt( const void *e1,const void *e2 ){
	return *(const int *)e1 - *(const int *)e2;
}

int main(){
	printf( "Quantidade de elementos a alojar?\n");
	int n;
	scanf( "%d", &n );
	int *b = malloc( n * sizeof *b );
	if( b == NULL ){
		fprintf( stderr, "Erro, malloc falhou alojamento\n" );
		return -1;
	}
	int i;
	for( i = 0; i < n && scanf( "%d", &b[i] ) == 1; ++i )
		;
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
