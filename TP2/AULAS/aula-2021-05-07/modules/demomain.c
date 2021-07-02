#include <stdio.h>

int countArr( void *arr, int size, int elemSize, int (*check)( void *elem, void *context ), void *context );

int isGreaterInt( void *elem, void *context ){
	return *(int *)elem > *(int *)context ;
}

int isMultInt( void *elem, void *context ){
	return *(int *)elem % *(int *)context == 0;
}

int main(){
	int x[] = { 1, 2, 3, 10, 20, 30, 0, -1, -2, -3, -4, -5, -40, -51 };
	int context = 0;
	int r1 = countArr( x, sizeof x / sizeof *x, sizeof *x, isGreaterInt, &context );
	context = 10;
	int r2 = countArr( x, sizeof x / sizeof *x, sizeof *x, isGreaterInt, &context );
	context = 2;
	int r3 = countArr( x, sizeof x / sizeof *x, sizeof *x, isMultInt, &context );
	context = 10;
	int r4 = countArr( x, sizeof x / sizeof *x, sizeof *x, isMultInt, &context );
	printf( "%d %d %d %d\n", r1, r2, r3, r4 );
	return 0;
}


