#include <stdio.h>

#include "myfunc1.h"

static int v1;
int v2 = 10;
int v3;
static int v4 = 20;

static int auxfunc( int a, int b ){
	St_ab s = { a, b };
	return myfunc2( s );
}

int myfunc1( int a, int b ){
	++v1;
	printf( "myfunc1, v1: %d\n", v1 );
	return auxfunc( a, b );
}
