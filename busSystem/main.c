#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string.h>


#define FILENAME_SIZE 1024
#define MAX_LINE 2048



void start();

void showMenu();

bool Valid();

void availableBus();

void bookTickets();

void updateBus(char name[], int seatNumber, char filename[]);
void view_Tickets(int Bus_Num,int seat_Num, char Pass_Nam[]);

int main(){


    start();


    return 0;
}


void start(){

    printf("                                                       BUS TICKET RESERVATION SYSTEM\n                                                       Made by SHREEYA, HEMANT, SUMAN\n                                                        IIIT BHUBANESHWAR\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------PRESS ANY KEY TO CONTINUE-------------------------------------------------------------\n");
    getch();
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------\n");


    bool UserNameValid = Valid();
    if(UserNameValid==true){
        printf("\n");


        printf("----------------------------------------LOGIN IS SUCCESSFUL-------------------------------------------------\n");
        //printf("==============================WELCOME TO SHS BUS RESERVATION SYSTEM!!!======================================\n");
        //printf("------------------------------------------------------------------------------------------------------------\n");
        printf("Press any key to continue...\n");
        getch();

        printf("LOADING");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".");
        Sleep(500);


        showMenu();

    }
    else{
        printf("INVALID USERNAME/PASSWORD");
    }

}


//takes user input of user-name and password and checks if it's matching or not
bool Valid(){


    char pass[30];
    char name[30];
    printf("-----------------------------------------------LOGIN--------------------------------------------------------\n");
    printf("                    ENTER USERNAME :- ");
    gets(name);

    char nCheck[]={"suman"};
    char pCheck[]={"sahoo"};
    if(  strcmp(name, nCheck) ==0)
    {
        printf("\n");
        printf("                    ENTER PASSWORD :- ");
        gets(pass);

        Sleep(1000);
        if(strcmp(pass,pCheck)==0){
                return true;
        }
        else{
            return false;
        }

    }
    else{
        return false;
    }

}


//show menu and go to respective functions
void showMenu(){

    system("cls");

    printf("\n\nWELCOME TO SHS BUS RESERVATION SYSTEM\n");
    printf("1.\tView all available bus\n2.\tBook tickets\n3.\tCancel tickets\n4.\tView book tickets\n5.\tExit\n\n");

    int chooseOption;
    scanf("%d",&chooseOption);


    if (chooseOption==1){
            //printf("in the process of building");
            availableBus();
    }
    else if(chooseOption==2){
            printf("in the process of building");
            bookTickets();
    }
    else if (chooseOption==3){
            printf("in the process of building");
    }
    else if(chooseOption==4){
            int Bus_Num, seat_Num;
        char Pass_Nam[20];
        view_Tickets(Bus_Num, seat_Num, Pass_Nam);
    }
    else if (chooseOption==5){
            printf("thank you ");
    }
    else {
        printf("WRONG OPTION\n");
        showMenu();
    }

}


void availableBus(){

    printf("--------------------------------------SHS BUS RESERVATION SYSTEM--------------------------------------------\n\n");
    printf("Bus No.          Bus Name                 Destinations              Fare               Time\n");
    printf("606910          Puri Express                Puri                    50             08:00 to 10:00 (58 km)\n");
    printf("606911          Brahmapur Lines             Brahmapur               150            09:00 to 00:30 (164 km)\n");
    printf("606912          Cuttack Linear              Cuttack                 30             13:00 to 13:50 (34 km)\n");
    printf("606913          Balasore Express            Balasore                200            06:00 to 10:50 (207 km)\n");
    printf("606914          Rourkela Lines              Rourkela                500            22:00 to 06:00 (327 km)\n");
    printf("606915          Sambalpur Linear            Sambalpur               450            21:00 to 04:30 (319 km)\n");
    printf("605822          Kolkata Linear              Kolkata                 600            06:00 to 16:00 (450 km)\n");
    printf("604049          Hyderabad Express           Hyderabad               1200           16:00 to 12:00 (1024 km)\n");
    printf("605157          Ranchi Lines                Ranchi                  600            19:00 to 06:00 (506 km)\n");
    printf("607388          Nagpur Express              Nagpur                  1000           05:00 to 22:30 (840 km)\n\n");

    printf("press anything to return");
    getch();
    showMenu();


}

void view_Tickets(int Bus_Num, int seat_Num, char Pass_Nam[]){
     FILE *vbt;
       vbt = fopen("ViewTickets.txt","r");
        fscanf(vbt,"%d %d %s ",&Bus_Num, &seat_Num,Pass_Nam);
 printf("Bus Number     : %d\nSeat Number    : %d\nPassenger Name : %s\nDestination    : Bhubaneshwar to Puri\nTime           : 05:00\nFare           : 100\n\n",Bus_Num,seat_Num,Pass_Nam);
}
void bookTickets(){
    int num,i,j;
    char em[20] = {"Empty"};
    printf("========BUS RESERVATION SYSTEM==========\n");
    printf("Enter Bus no. :- ");
    scanf("%d",&num);
    printf("\n");




    char filename[FILENAME_SIZE];
    if (num==606910)
    strcpy(filename,"1.txt");
    else if (num==606911)
        strcpy(filename,"2.txt");

    else if (num==606912)
        strcpy(filename,"3.txt");
    else if (num==606913)
        strcpy(filename,"4.txt");
    else if (num==606914)
        strcpy(filename,"5.txt");
    else if (num==606915)
        strcpy(filename,"6.txt");
    else if (num==606916)
        strcpy(filename,"7.txt");
    else if (num==606917)
        strcpy(filename,"8.txt");
    else if (num==606918)
        strcpy(filename,"9.txt");
    else if (num==606919)
        strcpy(filename,"10.txt");

    FILE *fptr = fopen(filename,"r");


    //print the bus seats status
    for(int i=1; i<=32;i++){
        printf("%d.",i);

        for(int j=1;j<=6;j++){
            //char ch;
            // fscanf(fptr,"%[^\n ] ",ch);
            printf("%c",fgetc(fptr));
        }
        fgetc(fptr);
        // fgetc(fptr);
        //fgetc(fptr);
        printf("\n");
    }
    printf("\n");




    // int number =1;
    // for(i=0; i<6; i++){
    //     for(j=0; j<4; j++){
    //     printf("%d.%s    ",number,em);
    //     number++;
    //     }
    //     printf("\n");
    // }

    int AvTic = 20;
    printf("Available Tickets:--------> %d\n\n",AvTic);
    int num_Tic, seat_num, p_Mob_No, P_Trav_Date;
    char p_name[MAX_LINE];
    printf("Numbers Of Tickets you want to Book:--->");
    scanf("%d",&num_Tic);
    printf("\n");
    for(int m=1; m<=num_Tic; m++){
        printf("============Enter your details for Ticket no %d= \n",m);
        printf("Seat number:-------->");
        scanf("%d",&seat_num);
        printf("Passenger name:-------->");
        getchar();
        gets(p_name)
        printf("Passenger Mobile number:-------->");
        scanf("%d",&p_Mob_No);

        Sleep(300);
    }

    fclose(fptr);
    updateBus(p_name, seat_num,filename);


    Sleep(500);
    printf("ticket booked\n");

    printf("press any key to continue");
    getch();
    showMenu();
}


void updateBus(char name[], int seatNumber, char filename[]){

    FILE *file,*temp;



    char temp_filename[FILENAME_SIZE];

    char buffer[MAX_LINE];



    strcpy(temp_filename, "temp____");
    strcat(temp_filename, filename);

    file= fopen(filename,"r");
    temp = fopen(temp_filename,"w");


    if (file == NULL || temp == NULL)
    {
        printf("Error opening files(s).\n");
        return 1;
    }



    bool keep_reading = true;

    int current_line = 1;

    do{

        fgets(buffer, MAX_LINE, file);

        if (feof(file)) keep_reading = false;
        else if (current_line ==  seatNumber){
            fputs(name, temp);

        }
        else {
            fputs(buffer, temp);

        }

        current_line++;
    }while(keep_reading);


    fclose(file);
    fclose(temp);

    remove(filename);
    rename(temp_filename,filename);

}
