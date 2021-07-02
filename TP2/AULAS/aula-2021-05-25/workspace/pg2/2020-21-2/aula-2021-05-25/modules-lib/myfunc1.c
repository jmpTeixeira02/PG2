#include <stdio.h>

#include "myfunc1.h"

static int auxfunc( int a, int b ){
	St_ab s = { a, b };
	return myfunc2( s );
}

int myfunc1( int a, int b ){
	return auxfunc( a, b );
}
