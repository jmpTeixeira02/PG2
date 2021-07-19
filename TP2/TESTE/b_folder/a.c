#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char *path = "batatas";
    char * name = "ads";
    char *new_path = malloc(sizeof *new_path);
    strcpy(new_path, path);
    strcat(new_path, "/");
    strcat(new_path, name);
    return 0;
}
