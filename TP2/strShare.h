#ifndef _STRSHARE_H_
#define _STRSHARE_H_

typedef struct {
    int space; // quantidade de elementos alojados para o array data
    int count; // quantidade de elementos preenchidos
    char **data; // array de ponteiros para as strings existentes
} StrShare;


StrShare *strShareCreate(void);
char *StrShareAdd(StrShare *share, char *str);
void strShareDelete( StrShare *share );

#endif