#ifndef _REFARRAY_H_
#define _REFARRAY_H_

#include "fileInfo.h"

typedef struct {
    int space; // quantidade de elementos alojados para o array data
    int count; // quantidade de elementos preenchidos
    FileInfo **data; // array de ponteiros
} RefArray;

RefArray *refArrCreate( void );
void refArrDelete( RefArray *ra);
void refArrAdd( RefArray *ra, FileInfo *ref );
void refArrSort( RefArray *ra );
void refArrScan( RefArray *ra, void (*act)(FileInfo *fi, void *param),void *actParam );

#endif
