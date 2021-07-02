#include <stdio.h>
#include "ex1_func.h"


void setPlace(Set set, unsigned value)
{
    int index = value / (sizet_long);
    value %= sizet_long;
    set[index] |= 1ul << value;
    return;
}

void setUnion(Set set1, Set set2)
{
    for (int i = 0; i < BITMAP_PARTS; i++)
        set1[i] |= set2[i];
    return;
}

void setRemove(Set set, unsigned value)
{
    int index = value / (sizet_long);
    value %= sizet_long;
    set[index] &= 1ul << value;
    return;
}

void setIntersect(Set set1, Set set2)
{
    for (int i = 0; i < BITMAP_PARTS; i++)
        set1[i] &= set2[i];
    return;
}

void setShow(Set set)
{
    for (int i = 0; i < BITMAP_PARTS ; i++)
    {
        for (int j = 0; j < sizet_long; j++)
        {
            unsigned long byte = (set[i] >> j) & 1;
            if (byte == 1)
                printf("Indice %d, bit %d \n", i, j);
        }
    }
    printf("\b\b\b\n");
    return;
}