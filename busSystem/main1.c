#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string.h>


int main(){

    FILE *fp = fopen("ViewTickets1.txt","r");

    int n = getw(*fp);
    printf("%d",n);
     n = getw(*fp);
    printf("%d",n);


    return 0;
}