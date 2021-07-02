#include <stdio.h>

int countArr( void *arr, int size, int elemSize, int (*check)( void *elem, void *context ), void *context ){
	int res = 0;
	char *p = arr;
	for( int i = 0; i < size; ++i ){
		res += check( p + i * elemSize, context ); // &arr[i] 
	}
	return res;
}
