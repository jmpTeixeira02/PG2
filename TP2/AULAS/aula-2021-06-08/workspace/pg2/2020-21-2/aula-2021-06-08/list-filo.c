#include <stdio.h>
#include <stdlib.h>

typedef struct lNode {
	struct lNode *next;
	int data;
} LNode;

void lInsHead( LNode **hp, int v ){
	LNode *n = malloc( sizeof *n );
	n->data = v;
	n->next = *hp;
	*hp = n;
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
		lInsHead( &head, val );
	}
	while( lRemHead( &head, &val ) ){
		printf( "%d\n", val );
	}
	return 0;
}


