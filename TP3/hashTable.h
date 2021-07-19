#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include "refArray.h"

typedef struct lNode{
    struct lNode *next; // ponteiro de ligação
    char *name; // string, aloj. dinâmico – nome representado
    RefArray *refArr; // referencias associadas
} LNode;

typedef struct {
int size; // dimensão da tabela
LNode **table; // array de ponteiros alojado dinamicamente
} HTable;


HTable *hCreate( int size );
void hAdd( HTable *ht, char *name, FileInfo *ref );
RefArray *hSearch( HTable *ht, char * name);
void hFree( HTable *ht );

#endif