#include <stdio.h> 
#include <stdlib.h> 


typedef struct tNode{
	struct tNode *left, *right;
	int data;
} TNode;

void tPrint( TNode *r ){
	if( r == NULL )
		return;
	tPrint( r->left );
	printf( "%d\n", r->data );
	tPrint( r->right );
}

void tPrintIndent( TNode *r, int h ){
	if( r == NULL )
		return;
	tPrintIndent( r->left, h + 1 );
	for( int i = 0; i < h; ++i )
		printf( "   " );
	printf( "%d\n", r->data );
	tPrintIndent( r->right, h + 1 );
}

void tAdd( TNode **rp, int v ){
	if( *rp == NULL ){
		TNode *n = malloc( sizeof *n );
		n->data = v;
		n->left = n->right = NULL;
		*rp = n;
		return;
	}
	if( v == (*rp)->data ){
		// processar caso de valore repetido
	}
	else if( v < (*rp)->data )
		tAdd( &(*rp)->left, v );
	else
		tAdd( &(*rp)->right, v );
}

TNode *tSearch( TNode *r, int v ){
	if( r == NULL ){
		return NULL;
	}
	if( v == r->data ){
		return r;
	}
	if( v < r->data ){
		return tSearch( r->left, v );
	}
	return tSearch( r->right, v );
}

TNode *treeToSortedList( TNode *r, TNode *link ){
	TNode * p;
	if( r == NULL ) return link;
	p = treeToSortedList( r->left, r );
	r->left = NULL;
	r->right = treeToSortedList( r->right, link );
	return p;
}

TNode *sortedListToBalancedTree(TNode **listRoot, int n) {
	if( n == 0 )
		return NULL;
	TNode *leftChild = sortedListToBalancedTree(listRoot, n/2);
	TNode *parent = *listRoot;
	parent->left = leftChild;
	*listRoot = (*listRoot)->right;
	parent->right = sortedListToBalancedTree(listRoot, n-(n/2 + 1) );
	return parent;
}

int tCount( TNode *r ){
	if( r == NULL )
		return 0;
	return 1 + tCount( r->left ) + tCount( r->right );
}

int main(){
	TNode *root = NULL; // iniciar árvore vazia
	int val;
	while( scanf( "%d", &val ) == 1 ){
		tAdd( &root, val );
		putchar( '\n' );
		tPrintIndent( root, 0 );
		putchar( '\n' );
	}
	scanf( "%*s" );
	
	root = treeToSortedList( root, NULL );
	root = sortedListToBalancedTree( &root, tCount( root ) );
	putchar( '\n' );
	tPrintIndent( root, 0 );
	putchar( '\n' );

	while( scanf( "%d", &val ) == 1 ){
		TNode *p = tSearch( root, val );
		if( p != NULL )
			printf( "O valor %d existe", val );
		else
			printf( "O valor %d não existe", val );
	}
	return 0;
}

