#include <stdio.h>
#include <math.h>

int main(){
	double x;
	while( scanf( "%lf", &x ) == 1 ){
		printf( "sin( %lf ) = %lf\n", x, sin( x ) );
	}
	return 0;
}
