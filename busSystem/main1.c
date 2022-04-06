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



void updateViewTickets(int busNumber, int seat_number){

    char temp_file[FILENAME_SIZE];

    strcpy(temp_file,"temp__");
    strcat(temp_file,"ViewTickets.txt");

    FILE *fp = fopen("ViewTickets.txt","r");
    FILE *temp = fopen(temp_file,"w");

    bool keepLoop = true;
    printf("CHECK 1 ");
    while(keepLoop){
        printf("check ");
        char buffer[MAX_LINE];
        int busNo,seatNo;
        char name[MAX_LINE];
        char name1[MAX_LINE];
        fscanf(fp,"%d %d %s %s",&busNo,&seatNo,&name,&name1);
        fgets(buffer,MAX_LINE,fp);
        printf("%s",buffer);
        if(busNo==busNumber && seat_number==seatNo){
            continue;
        }
        else {
            fprintf(temp,"%d %d %s %s %c",busNo,seatNo,name,name1,'\n');
        }

        
        if(feof(fp)){
            keepLoop = false;
        }


    }
    printf("CHECK 2");

    fclose(temp);
    fclose(fp);
}