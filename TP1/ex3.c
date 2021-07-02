#include <dirent.h>
#include "ex2.h"
#include <stdlib.h>
#include <stdio.h>


#define MAX_FILE_NAME 256
#define MAX_ITEMS 16

#ifndef DT_DIR
# define DT_UNKNOWN	0
# define DT_FIFO	1
# define DT_CHR		2
# define DT_DIR		4
# define DT_BLK		6
# define DT_REG		8
# define DT_LNK		10
# define DT_SOCK	12
# define DT_WHT		14
#endif

enum ItemType { T_FILE, T_DIRECTORY }; 

typedef struct {  
    enum ItemType type;
    char filename[MAX_FILE_NAME];
    int term;
} Item;

int loadDirList( Item list[], size_t size, char *path ){
    DIR* d = opendir(path);
    struct dirent * de;
    char* terms[] = {"c","h","a"};
    int termsize = sizeof( terms ) / sizeof( char * );
    int i = 0;
    while( ( de = readdir( d ) ) != NULL )
    {
        if (de->d_type == DT_DIR || de->d_type == DT_REG)
        {
            if (i > size)
                return i;
            list[i].type = de->d_type;
            strcpy(list[i].filename, de->d_name);
            list[i].term = findTerm(list[i].filename, terms, termsize);
            i++;
        }
    }
    return i;
}

int compare( const void *e1, const void *e2 ){ 
    const Item *item1 = e1;
    const Item *item2 = e2;
    if (item1->type == item2->type)
        return strcmp(item1->filename, item2->filename);
    return item2->type - item1->type;
}

int compareaux( const void *e1, const void *e2 ){ 
    const Item *item1 = *(const Item **)e1;
    const Item *item2 = *(const Item **)e2;
    // Se tiverem o mesmo termo
    if (strcmp((item1->filename+item1->term), (item2->filename+item2->term)) == 0)
        return strcmp(item1->filename, item2->filename);    
    return strcmp(item2->filename, item1->filename);
}

// Primeiro Ficheiro, diretoria. Nome completo alfabéticamente crescente
void sortList( Item list[], size_t num)
{
    printf("\n");
    qsort(list, num, sizeof(Item), compare);
    for (int i = 0; i < num; i++){
        char *str;
        if (list[i].type == DT_DIR)
            str = "Dir";
        else
            str = "File";
        printf("%s\t[%s]\n",list[i].filename, str);
    }   
}
       

void sortAuxList( Item *auxList[], size_t num )
{
    printf("\n");
    qsort(auxList, num, sizeof(*auxList), compareaux);
    for (int i = 0; i < num; i++)
        printf("%s\n",auxList[i]->filename);
}
//size of ponteiro para struct
// fazer igualar o auxlist a list no main


int main()
{
    char input;
    int sizelist;
    int work = 1;
    Item list[MAX_ITEMS];
    sizelist = loadDirList(list, MAX_ITEMS, "teste");

    Item *auxlist[MAX_ITEMS];
    int sizeaux = 0;
    for (int i = 0; i < MAX_ITEMS; i++){
        if (list[i].type == DT_REG)
            auxlist[sizeaux++] = &list[i];
    }   
    //printf("%d", sizelist);
    //printf("%d",sizeaux);
    printf("Introduza o input: ");
    while (work == 1)
    {
        scanf(" %c",&input);
        if (input == 'l')
            sortList(list,sizelist);

        else if (input == 'f')
        {
            Item *auxlist[MAX_ITEMS];
            int sizeaux = 0;
            for (int i = 0; i < MAX_ITEMS; i++){
            if (list[i].type == DT_REG)
                auxlist[sizeaux++] = &list[i];
            }   
            sortAuxList(auxlist, sizeaux);
        }
        else if (input == 'q')
            return 0;
        printf("\nIntroduza o input\n");
    }
    return 0;
}