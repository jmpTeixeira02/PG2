#include <stdio.h>

#include "myfunc1.h"

#include "myfunc2.h"



int main(){
	int x, y;
	St_ab z = { 111, 222 };
	x = myfunc1( 10, 20 );
	y = myfunc2( z );
	printf( "%d %d\n", x, y );
}
