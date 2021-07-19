#include <stdio.h>
#include <dirent.h>
#include <stdbool.h>
#include <string.h>

#include "dirTree.h"

static void arrRefPrint(RefArray *Ref){
   for (int i = 0; i < Ref->count; i++){
      printf("%s - %s\n", Ref->data[i]->name, Ref->data[i]->path);
   }
   return;
}

int main(int argc, char *argv[])
{
   // Leitura argumentos 
   if (argc != 2){
      printf("Execução ./a.out <\"pasta\">");
      return 0;
   }
   char* path = argv[1];


   //Criação das estruturas
   StrShare *pathShare = strShareCreate();
   RefArray *origRef = refArrCreate();
   RefArray *sortRef = refArrCreate();
   char* terms[] = {"a","c","out"};
   termSetupTypes(terms,sizeof( terms ) / sizeof( char * ));
   scanDirTree(path,pathShare, origRef, sortRef);

   refArrSort(sortRef);


   char input;
   do{

      printf("\nIntroduza a opção que deseja\n");

      char input;
      scanf(" %c", &input);
      char word[25];
      if (input == 't' || input == 's'){
         printf("Introduza a palavra a filtrar\n");
         scanf("%s", word);
      }
   
      switch(input){
         case 't':
            for (int i = 0; i < sortRef->count; i++){
               if (strcmp(sortRef->data[i]->name+sortRef->data[i]->term+1, word) == 0)
                  printf("%s - %s\n", sortRef->data[i]->name, sortRef->data[i]->path);
            }
            break;
         case 's':
            for (int i = 0; i < sortRef->count; i++){
               if (strncmp(sortRef->data[i]->name, word, sortRef->data[i]->term) == 0)
                  printf("%s - %s\n", sortRef->data[i]->name, sortRef->data[i]->path);
            }
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



