#include <stdio.h>
#include "ex1_func.h"

void zerosarray(Set A, Set B){
    for (int i=0 ; i < BITMAP_PARTS ; ++i ){
        A[i]=0;
        B[i]=0;
    }
    return;
}

void showarrays(Set A, Set B)
{
    printf("A\n");
    setShow(A);
    printf("B\n");
    setShow(B);
}

void setfunc(char cmd, Set set, int Value, Set A)
{
    if (cmd == 'r')
        setRemove(set, Value);
    else if (cmd == 'p')
        setPlace(set, Value);
    else if (cmd == 'u')
        setUnion(A, set);
    else if (cmd == 'i')
        setIntersect(A, set);
}

void helpcase(char cmd, int val, Set A, Set B, char set)
{
    if (set == 'A')
        setfunc(cmd, A, val,A);
    else if (set == 'B')
        setfunc(cmd, B, val,A);

}

int main()
{
    Set A,B;
    zerosarray(A,B);
    char cmd = 'a', conj;
    int val;
    while (cmd != 'q')
    {
        printf("Escreva o comando ");
        scanf(" %c", &cmd);
      
        if (cmd == 'p' || cmd == 'r')
            scanf(" %c %d", &conj, &val);
        else if (cmd == 'u' || cmd == 'i')
            scanf(" %c", &conj);
        else if (cmd == 's')
            showarrays(A,B);
        else if (cmd == 'q')
            return 0;
        helpcase(cmd, val, A, B, conj);
    }
    return 0;
}