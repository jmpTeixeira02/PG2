#include <stdio.h> 


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

int main(){
	TNode n10 = { NULL, NULL, 10 };
	TNode n30 = { NULL, NULL, 30 };
	TNode n20 = { &n10, &n30, 20 };
	TNode n50 = { NULL, NULL, 50 };
	TNode n70 = { NULL, NULL, 70 };
	TNode n60 = { &n50, &n70, 60 };
	TNode n40 = { &n20, &n60, 40 };
	tPrintIndent( &n40, 0 );
	return 0;
}
