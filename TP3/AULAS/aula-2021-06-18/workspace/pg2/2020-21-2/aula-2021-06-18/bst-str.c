#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

typedef struct tNode{
	struct tNode *left, *right;
	char *data;
} TNode;

void tPrint( TNode *r ){
	if( r == NULL )
		return;
	tPrint( r->left );
	printf( "%s\n", r->data );
	tPrint( r->right );
}

void tPrintIndent( TNode *r, int h ){
	if( r == NULL )
		return;
	tPrintIndent( r->left, h + 1 );
	for( int i = 0; i < h; ++i )
		printf( "   " );
	printf( "%s\n", r->data );
	tPrintIndent( r->right, h + 1 );
}

void tAdd( TNode **rp, char *v ){
	printf("\n\n%p\n", *rp);
	if( *rp == NULL ){
		printf("\nNEW NODE\n\n");
		TNode *n = malloc( sizeof *n );
		n->data = strdup(v);
		n->left = n->right = NULL;
		*rp = n;
		return;
	}
	int c = strcmp( v,  (*rp)->data );
	if( c == 0 ){
		// processar caso de valor repetido
	}
	else if( c < 0 )
		tAdd( &(*rp)->left, v );
	else
		tAdd( &(*rp)->right, v );
}

TNode *tSearch( TNode *r, char *v ){
	if( r == NULL ){
		return NULL;
	}
	int c = strcmp( v,  r->data );
	if( c == 0 ){
		return r;
	}
	if( c < 0 ){
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
	char val[30];
	while( scanf( "%s", val ) == 1 && strcmp( val, "." ) != 0 ){
		tAdd( &root, val );
		putchar( '\n' );
		tPrintIndent( root, 0 );
		putchar( '\n' );
	}
	
	root = treeToSortedList( root, NULL );
	root = sortedListToBalancedTree( &root, tCount( root ) );
	putchar( '\n' );
	tPrintIndent( root, 0 );
	putchar( '\n' );

	while( scanf( "%s", val ) == 1 ){
		TNode *p = tSearch( root, val );
		if( p != NULL )
			printf( "O valor %s existe", val );
		else
			printf( "O valor %s não existe", val );
	}
	return 0;
}

