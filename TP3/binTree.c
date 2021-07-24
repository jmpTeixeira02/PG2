#include "binTree.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

RefArray *tSearch( TNode *root, char *termin){
    if (root == NULL){
        return NULL;
    }
    int compare = strcmp(termin, root->termin);

    if (compare > 0)
        return tSearch(root->right, termin); 
    else if (compare < 0)
        return tSearch(root->left, termin); 
    else
        return root->refArr;
}

void tAdd( TNode **rootPtr, char *termin, FileInfo *ref ){
    if (strcmp(termin, "") == 0)
        return;

    // Se node não existir, criar
    if (*rootPtr == NULL){
        TNode *node = malloc( sizeof *node );
		node->left = node->right = NULL;
        strcpy(node->termin, termin);
        RefArray *arr = refArrCreate();
        refArrAdd(arr, ref);
        node->refArr= arr;
		*rootPtr = node;
        return;
    }
    
    int compare = strcmp (termin, (*rootPtr)->termin);
    if (compare < 0)
        tAdd(&(*rootPtr)->left, termin, ref);
    else if (compare > 0)
        tAdd(&(*rootPtr)->right, termin, ref);
    else
        refArrAdd((*rootPtr)->refArr, ref);
    return;
}

static TNode *treeToSortedList( TNode *r, TNode *link ){
    TNode * p;
    if( r == NULL ) return link;
    p = treeToSortedList( r->left, r );
    r->left = NULL;
    r->right = treeToSortedList( r->right, link );
    return p;
}

static TNode *sortedListToBalancedTree( TNode **listRoot, int n) {
    if( n == 0 )
        return NULL;
    TNode *leftChild = sortedListToBalancedTree(listRoot, n/2);
    TNode *parent = *listRoot;
    parent->left = leftChild;
    *listRoot = (*listRoot)->right;
    parent->right = sortedListToBalancedTree(listRoot, n-(n/2 + 1) );
    return parent;
}

static int tCount( TNode *r ){
	if( r == NULL )
		return 0;
	return 1 + tCount( r->left ) + tCount( r->right );
}

void tBalance( TNode **rootPtr ){
    *rootPtr = treeToSortedList( *rootPtr, NULL );
	*rootPtr = sortedListToBalancedTree( &(*rootPtr), tCount(*rootPtr) );
}

void tFree( TNode *root ){
    if (root == NULL)
        return;
    tFree(root->left);
    tFree(root->right);
    free(root);
}
