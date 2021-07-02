
#include "myfunc2.h"

static int auxfunc( St_ab data ){
	return data.a + data.b;
}

int myfunc2( St_ab data ){
	return auxfunc( data );
}
