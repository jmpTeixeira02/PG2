#include <stdio.h>

int main()
{


int *a;
int *b;
char input;

scanf(" %c", &input);

if (input == 'a')
    *a = 10;
if (*a == 10)
    printf("\n%d\n", *a);
return 0;
}