#include <stdio.h>
#include <stdlib.h>

typedef struct hLNode{
	struct hLNode *next;
	int data;
} HLNode;

typedef struct {
	HLNode **table;
	int size;
} HTable;

HTable *hCreate( int size ){
	HTable *r = malloc( sizeof *r );
	r->table = calloc( size, sizeof(HLNode *) ); // contém ponteiros NULL
	r->size = size;
	return r;
}

int *hLSearch( HLNode *l, int data ){
	for( HLNode *p = l; p != NULL; p = p->next ){
		if( p->data == data )
			return &p->data;
	}
	return NULL;
}

HLNode *hLAdd( HLNode *l, int data ){
	HLNode *n = malloc( sizeof *n );
	n->data = data;
	n->next = l;
	return n;
}

void hLPrint( HLNode *l ){
	for( HLNode *p = l; p != NULL; p = p->next ){
		printf( "%d ", p->data );
	}
	putchar( '\n' );
}

int hash( HTable *ht, int data ){
	return data % ht->size;
}

int *hSearch( HTable *ht, int data ){ // ret. NULL se não existe
	int i = hash( ht, data );
	return hLSearch( ht->table[i], data );
}

void hAdd( HTable *ht, int data ){
	int i = hash( ht, data );
	int *found = hLSearch( ht->table[i], data );
	if( found == NULL ){
		ht->table[i] = hLAdd( ht->table[i], data );
	}
}

void hPrintDebug( HTable *ht ){
	for( int i = 0; i < ht->size; ++i ){
		if( ht->table[i] == NULL )
			continue;
		printf( "[%d] ", i );
		hLPrint( ht->table[i] );
	}
}

int main(){
	HTable *ht = hCreate( 100 );
	int val;
	while( scanf( "%d", &val ) == 1 ){
		hAdd( ht, val );
		putchar( '\n' );
		hPrintDebug( ht );
		putchar( '\n' );
	}
	scanf( "%*s" );
	
	while( scanf( "%d", &val ) == 1 ){
		int *p = hSearch( ht, val );
		if( p != NULL )
			printf( "O valor %d existe", val );
		else
			printf( "O valor %d não existe", val );
	}
	return 0;
}
	
	
	
