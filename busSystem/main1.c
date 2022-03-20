#include <stdlib.h>
#include <stdio.h>

int main(){

    FILE *p = fopen("2.txt","r");
    char ch;
    //printf("%([^\n ]) ", fscanf(p,"%([^\n ]) ",ch));
    gets(fscanf(p,"%([^\n ]) ",ch));
    return 0;
}