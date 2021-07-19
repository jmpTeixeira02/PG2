#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct hLNode{
	struct hLNode *next;
	char *data;
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

char *hLSearch( HLNode *l, char *data ){
	for( HLNode *p = l; p != NULL; p = p->next ){
		if( strcmp( p->data, data ) == 0 )
			return p->data;
	}
	return NULL;
}

HLNode *hLAdd( HLNode *l, char *data ){
	HLNode *n = malloc( sizeof *n );
	n->data = strdup( data );
	n->next = l;
	return n;
}

void hLPrint( HLNode *l ){
	for( HLNode *p = l; p != NULL; p = p->next ){
		printf( "%s ", p->data );
	}
	putchar( '\n' );
}

static int hash( HTable *ht, char *data ){
	unsigned s = 0;
	for( int i = 0; data[i] != 0; ++i )
		s += data[i] << ( i % (sizeof (int) * CHAR_BIT) );
	return s % ht->size;
}

char *hSearch( HTable *ht, char *data ){ // ret. NULL se não existe
	int i = hash( ht, data );
	return hLSearch( ht->table[i], data );
}

void hAdd( HTable *ht, char *data ){
	int i = hash( ht, data );
	char *found = hLSearch( ht->table[i], data );
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
	char val[30];
	while( scanf( "%s", val ) == 1 && strcmp( val, "." ) != 0){
		hAdd( ht, val );
		putchar( '\n' );
		hPrintDebug( ht );
		putchar( '\n' );
	}
	
	while( scanf( "%s", val ) == 1 ){
		char *p = hSearch( ht, val );
		if( p != NULL )
			printf( "O valor \"%s\" existe", val );
		else
			printf( "O valor \"%s\" não existe", val );
	}
	return 0;
}
	
	
	
