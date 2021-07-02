#ifndef _VECTOR_STR_H_
#define _VECTOR_STR_H_

typedef struct{
	int space;
	int size;
	char **data;
} StrVec;
     
StrVec *vecStrCreate( void );
void vecStrAdd( StrVec *v, char *s );
void vecStrSort( StrVec *v );
void vecStrPrint( StrVec *v );
void vecStrDelete( StrVec *v );

#endif
