#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING 30

typedef struct lNode {
	struct lNode *next;
	char *data;
} LNode;

void lInsSort( LNode **hp, char *v ){
	LNode *n = malloc( sizeof *n );
	n->data = strdup( v ); // strcpy( malloc( strlen( v ) + 1 ), v );
	LNode *p, *a;
	for( p = *hp; p != NULL && strcmp( v, p->data ) > 0 ; a = p, p = p->next )
		;
	n->next = p;
	if( p == *hp ) // ins cabeça
		*hp = n;
	else
		a->next = n;
}

void lPrint( LNode *h ){
	for( LNode *p = h; p != NULL; p = p->next ){
		printf( "%s\n", p->data );
	}
}

int lRemHead( LNode **hp, char *vp ){
	if( *hp == NULL )
		return 0;
	LNode *p = *hp;
	strcpy( vp, p->data );
	*hp = p->next;
	free( p->data );
	free( p );
	return 1;
}


int main(){
	LNode *head = NULL; // iniciar lista vazia
	char val[MAX_STRING];
	while( scanf( "%s", val ) == 1 ){
		lInsSort( &head, val );
		putchar( '\n' );
		lPrint( head );
	}
	while( lRemHead( &head, val ) ){
		printf( "%s\n", val );
	}
	return 0;
}


