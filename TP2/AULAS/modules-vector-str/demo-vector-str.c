#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "vector-str.h"
     
#define STR_MAX 100  

int main(){
	StrVec *vp = vecStrCreate();

	char s[STR_MAX];
	
	while( scanf( "%s", s) == 1 ){
		vecStrAdd( vp, s );
	}
	vecStrPrint( vp );
	vecStrSort( vp );
	vecStrPrint( vp );
	vecStrDelete( vp );
	return 0;
 }
