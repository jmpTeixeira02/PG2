#include <stdio.h>
#include <dirent.h>
#include <stdbool.h>

#include "dirTree.h"


void test(StrShare *pathShare, RefArray *origRef, RefArray *sortRef ){
   printf("\n\n----PATHSHARE----\n\n");

   for (int i = 0; i < pathShare->count; i++){
      printf("%s\n", pathShare->data[i]);
   }

   printf("\n\n---ORIGREF----\n\n");

   for (int i = 0; i < origRef->count; i++){
      printf("%s\n", origRef->data[i]->name);
   }

   //refArrSort(sortRef);

   printf("\n\n---SORTREF----\n\n");

   for (int i = 0; i < sortRef->count; i++){
      printf("%s\n", sortRef->data[i]->name);
   }
}

bool inputRead(char input, char** word)
{
   if (input == 't' || input == 's'){
      scanf("%s", *word);
      return true;
   }
   else if (input == 'o' || input == 'n' || input == 'q')
      return true;
   return false;
}

int main(int argc, char *argv[])
{
   if (argc != 2){
      printf("Execução ./a.out <\"pasta\">");
      return 0;
   }
   char* path = argv[1];
   //leitura das diretorias e preenchimento da estrutura de dados
   StrShare *pathShare = strShareCreate();
   RefArray *origRef = refArrCreate();
   RefArray *sortRef = refArrCreate();

   scanDirTree(path,pathShare, origRef, sortRef);
   char input;
   char *word;

   do{
      printf("Introduza a opção que deseja\n");
      input = getchar();
   } while (!inputRead(input, &word));
   
   //printf("%c, %s", input, word);

   switch(input){
      case 't':
         break;
      case 's':
         break;
      case 'n':
         break;
      case 'o':
         break ;
      case 'q':
         refArrDelete(origRef);
         refArrDelete(sortRef);
         strShareDelete(pathShare);
         return 0;
   }


   //test(pathShare, origRef, sortRef);
   
   return 0;
}



