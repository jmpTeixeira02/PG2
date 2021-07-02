#include <stdio.h>
#include <stdlib.h>

typedef struct lNode {
	struct lNode *next;
	int data;
} LNode;

void lInsTail( LNode **hp, LNode **tp, int v ){
	LNode *n = malloc( sizeof *n );
	n->data = v;
	n->next = NULL;
	if( *hp == NULL )
		*hp = n;
	else
		(*tp)->next = n;
	*tp = n;
}

int lRemHead( LNode **hp, LNode **tp, int *vp ){
	if( *hp == NULL )
		return 0;
	LNode *p = *hp;
	*vp = p->data;
	*hp = p->next; 
	if( *hp == NULL )
		*tp = NULL;
	free( p );
	return 1;
}

int main(){
	LNode *head = NULL; // iniciar lista vazia
	LNode *tail = NULL; // iniciar lista vazia
	int val;
	while( scanf( "%d", &val ) == 1 ){
		lInsTail( &head, &tail, val );
	}
	while( lRemHead( &head, &tail, &val ) ){
		printf( "%d\n", val );
	}
	return 0;
}


