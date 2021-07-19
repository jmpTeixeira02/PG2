#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hashTable.h"


static int hash( HTable *ht, char *data){
    unsigned s = 0;
	for( int i = 0; data[i] != 0; ++i )
		s += data[i] << ( i % (sizeof (int) * CHAR_BIT) );
	return s % ht->size;
}

HTable *hCreate( int size ){
    HTable *table = malloc(sizeof *table);
    // Meter os ponteiros da hash table com NULL
    table->table = calloc(size, sizeof(LNode *));
    table->size = size;
    return table;
}

void hAdd( HTable *ht, char *name, FileInfo *ref ){
}

RefArray *hSearch( HTable *ht, char * name){
    for(int i = 0; i < ht->size; i++){
        
    }
}