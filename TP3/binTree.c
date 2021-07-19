#include "binTree.h"
#include <stdlib.h>
#include <string.h>

RefArray *tSearch( TNode *root, char *termin){
    if (root == NULL){
        return NULL;
    }
    else if (strcmp(root->termin, termin) > 0)
        return tSearch(root->right, termin); 
    else if (strcmp(root->termin, termin) < 0)
        return tSearch(root->left, termin); 
    else
        return root->refArr;
}
void tAdd( TNode **rootPtr, char *termin, FileInfo *ref ){

    if (tSearch(rootPtr, termin) != NULL)
        return; // Term já existe

    // Se a árvore ainda não existir, criar uma
    else if (*rootPtr == NULL){
        TNode *node = malloc( sizeof *node );
		node->left = node->right = NULL;
        strcpy(node->termin, termin);
		*rootPtr = node;
		return;
    }

    if (strcmp(&(*rootPtr)->termin, termin) < 0)
        tAdd(&(*rootPtr)->left, termin, ref);
    else if (strcmp(&(*rootPtr)->termin, termin) > 0)
        tAdd(&(*rootPtr)->right, termin, ref);
    
}

void tFree( TNode *root ){
    if (root == NULL)
        return;
    tFree(root->left);
    tFree(root->right);
    free(root);
}
