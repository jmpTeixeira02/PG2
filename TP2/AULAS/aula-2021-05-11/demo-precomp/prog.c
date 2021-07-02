
#include "header.h"

#define MAX_SIZE 30
#define N_ELEMS 100

#define A_LENGTH( a ) ( sizeof a / sizeof *a )

#define A_INIT( a ) do{ \
	for( int i = 0; i < A_LENGTH( a ); ++i ){ \
		a[i] = 0; \
	} \
}while( 0 )

int main(){
	char data[N_ELEMS][MAX_SIZE];
	int x = 0, n;
	int y = MY_ARR_SIZE;
	int ai[1000];
	
	if( x ) 
		A_INIT( ai );
	else
		printf( "array não iniciado\n" );
	
	n = A_LENGTH( data );
	
	for( int i = 0; i < N_ELEMS; ++i ){
		// ...
	}
	
	if( x < MAX_SIZE ){
		// ...
	}
	
	return 0;
}
