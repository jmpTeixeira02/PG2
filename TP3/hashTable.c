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

static RefArray *hLSearch( LNode *l, char *name ){
	for(LNode *p = l; p != NULL; p = p->next){
		if( strcmp( p->name, name ) == 0 )
			return p->refArr;
	}
	return NULL;
}

RefArray *hSearch( HTable *ht, char * name){
    int i = hash (ht, name);
    return hLSearch (ht->table[i], name);
}

static LNode *hLAdd( LNode *l, char *name, FileInfo *ref){
	LNode *n = malloc(sizeof *n);
	n->name = strdup(name);
	n->next = l;
    RefArray *arr = refArrCreate();
    refArrAdd(arr, ref);
    n->refArr=arr;
	return n;
}

void hAdd( HTable *ht, char *name, FileInfo *ref ){
    int i = hash (ht, name);
    RefArray* found = hLSearch(ht->table[i], name);
    // Ainda não existir
    if (found == NULL)
        ht->table[i] = hLAdd(ht->table[i], name, ref);
    else
        refArrAdd(ht->table[i]->refArr, ref);
}


void hFree( HTable *ht ){
    for (int i = 0; i < ht->size; i++)
        free(ht->table[i]);
    free(ht->table);
    free(ht);
}