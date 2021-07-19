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
	if( v < (*rp)->data )
		tAdd( &(*rp)->left, v );
	else
		tAdd( &(*rp)->right, v );
}

int main(){
	TNode *root = NULL;
	tAdd( &root, 20 );
	tAdd( &root, 60 );
	tAdd( &root, 10 );
	tAdd( &root, 30 );
	tAdd( &root, 50 );
	tAdd( &root, 70 );
	tAdd( &root, 40 );
	
	tPrintIndent( root, 0 );
	return 0;
}
