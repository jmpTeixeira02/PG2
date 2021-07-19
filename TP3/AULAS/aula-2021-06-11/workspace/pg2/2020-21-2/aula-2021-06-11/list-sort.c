#include <stdio.h>
#include <stdlib.h>

typedef struct lNode {
	struct lNode *next;
	int data;
} LNode;

void lInsSort( LNode **hp, int v ){
	LNode *n = malloc( sizeof *n );
	n->data = v;
	LNode *p, *a;
	for( p = *hp; p != NULL && v > p->data; a = p, p = p->next )
		;
	n->next = p;
	if( p == *hp ) // ins cabeça
		*hp = n;
	else
		a->next = n;
}

void lPrint( LNode *h ){
	for( LNode *p = h; p != NULL; p = p->next ){
		printf( "%d\n", p->data );
	}
}

int lRemHead( LNode **hp, int *vp ){
	if( *hp == NULL )
		return 0;
	LNode *p = *hp;
	*vp = p->data;
	*hp = p->next;
	free( p );
	return 1;
}

int main(){
	LNode *head = NULL; // iniciar lista vazia
	int val;
	while( scanf( "%d", &val ) == 1 ){
		lInsSort( &head, val );
		putchar( '\n' );
		lPrint( head );
	}
	while( lRemHead( &head, &val ) ){
		printf( "%d\n", val );
	}
	return 0;
}


