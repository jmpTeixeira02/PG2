#include <stdio.h>
#include <dirent.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "dirTree.h"
#include "binTree.h"
#include "hashTable.h"

static void arrRefPrint(RefArray *Ref){
   for (int i = 0; i < Ref->count; i++){
      printf("%s - %s\n", Ref->data[i]->name, Ref->data[i]->path);
   }
   return;
}

static void print(FileInfo *ref, void *none){
   printf("%s - %s\n", ref->name, ref->path);
} 

static void treeAdd(FileInfo *ref, void *rootPtr){
   //printf("\n%s\n", ref->name+ref->term+1);
   tAdd(rootPtr,ref->name+ref->term+1, ref);
}
static void hashAdd(FileInfo *ref, void *table){
   char* temp = strndup(ref->name, ref->term);
   hAdd(table, temp, ref);
}

int main(int argc, char *argv[])
{
   // Leitura argumentos 
   if (argc != 2){
      printf("Execução ./a.out <\"pasta\">");
      return 0;
   }
   char* path = argv[1];

   char* terms[] = {"out","a","c"};

   //Criação das estruturas
   StrShare *pathShare = strShareCreate();
   RefArray *origRef = refArrCreate();
   RefArray *sortRef = refArrCreate();
   RefArray *tempPtr = refArrCreate();
   termSetupTypes(terms,sizeof( terms ) / sizeof( char * ));
   scanDirTree(path,pathShare, origRef, sortRef);

   refArrSort(sortRef);

   TNode *tree = NULL; // Criar árvore
   HTable *table = hCreate(26);

   // Preencher árvore
   refArrScan(sortRef, treeAdd, &tree);
   
   // Preencher hashtable
   refArrScan(sortRef, hashAdd, table);

   char input;
   do{

      printf("\nIntroduza a opção que deseja\n");
      scanf(" %c", &input);
      char word[25];
      if (input == 't' || input == 's'){
         printf("Introduza a palavra a filtrar\n");
         scanf("%s", word);
      }
   
      switch(input){
         case 't':
            tempPtr = tSearch(tree, word);
            if (tempPtr == NULL)
               break;
            refArrScan(tempPtr, print, NULL);
            break;
         case 's':
            tempPtr = hSearch(table, word);
            if (tempPtr == NULL)
               break;
            refArrScan(tempPtr, print, NULL);
            break;
         case 'n':
            arrRefPrint(sortRef);
            break;
         case 'o':
            arrRefPrint(origRef);
            break;
         case 'q':
            refArrDelete(origRef);
            refArrDelete(sortRef);
            strShareDelete(pathShare);
            return 0;
            break;
      }
      while ((input = getchar()) != '\n' && input != EOF);
   } while (input != 'q');
   return 0;
}



