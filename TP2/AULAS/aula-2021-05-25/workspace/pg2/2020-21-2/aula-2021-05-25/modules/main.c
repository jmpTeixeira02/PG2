#include <stdio.h>

#include "myfunc1.h"

#include "myfunc2.h"

int v1;
int v2;
extern int v3;
extern int v5;

int main(){
	int x = 0, y = 0;
	St_ab z = { 111, 222 };
	v1 = v3;
	printf( "main, v1: %d\n", v1 );
	x = myfunc1( 10, 20 );
	printf( "main, v1: %d\n", v1 );
	y = myfunc2( z );
	printf( "%d %d\n", x, y );
}
