#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string.h>


#define FILENAME_SIZE 1024
#define MAX_LINE 30


void showMenu();
bool Valid();
void availableBus();
void bookTickets();
void updateBus(char name[], int seatNumber, char filename[]);
void view_Tickets();
void printBus(char filename[]);
void startup();
void deleteTicket(char filename[], int seatNo);

int main(){

    startup();

    bool UserNameValid = Valid();
    if(UserNameValid==true){
        printf("\n");

        // printf("LOADING");
        // Sleep(500);
        // printf(".");
        // Sleep(500);
        // printf(".");
        // Sleep(500);
        // printf(".");
        // Sleep(500);
        printf("----------------------------------------LOGIN IS SUCCESSFUL-------------------------------------------------\n");
        //printf("==============================WELCOME TO SHS BUS RESERVATION SYSTEM!!!======================================\n");
        //printf("------------------------------------------------------------------------------------------------------------\n");
        printf("----------------Press any key to go to main menu...--------------\n");
        getch();

        showMenu();

    }
    else{
        printf("INVALID USERNAME/PASSWORD");
    }

    return 0;
}


void startup()
{

    printf("                                                       BUS TICKET RESERVATION SYSTEM\n                                                       Made by SHREEYA, HEMANT, SUMAN\n                                                        IIIT BHUBANESHWAR\n");
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("---------------------------------------------------------PRESS ANY KEY TO CONTINUE-------------------------------------------------------------\n");
    getch();
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
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
            //printf("in the process of building");
            bookTickets();
    }
    else if (chooseOption==3){
            printf("in the process of building");
            cancelTickets();
    }
    else if(chooseOption==4){
            view_Tickets();
    }
    else if (chooseOption==5){
            printf("thank you ");
    }
    else {
        printf("WRONG OPTION\nENTER CORRECT OPTION\n\npress anything to continue");
        getch();
        showMenu();
    }

}


void cancelTickets(){


    //AVAILABLE TICKETS TO CANCEL, WHICH WILL BE FOUND FROM ViewTickets.txt



    int Bus_Num,seat_number;
    printf("========BUS RESERVATION SYSTEM==========\n");
    printf("\nTICKET CANCELLATION\n");
    printf("Enter Bus no. :- ");
    scanf("%d",&Bus_Num);
    printf("\n");


    char filename[FILENAME_SIZE];
    if (Bus_Num==100){
        printf("Total fare is 50\n");
        strcpy(filename,"1.txt");
    }
    else if (Bus_Num==200) {
        printf("Total fare is 150\n");
        strcpy(filename,"2.txt");
    }
    else if (Bus_Num==300) {
        printf("Total fare is 30\n");
        strcpy(filename,"3.txt");
    }
    else if (Bus_Num==400){
        printf("Total fare is 200\n");
        strcpy(filename,"4.txt");
    }
    else if (Bus_Num==500) {
       printf("Total fare is 500\n");
       strcpy(filename,"5.txt");
    }
    else if (Bus_Num==600) {
        printf("Total fare is 400\n");
        strcpy(filename,"6.txt");
    }
    else if (Bus_Num==700) {
        printf("Total fare is 600\n");
        strcpy(filename,"7.txt");
    }
    else if (Bus_Num==800){
        printf("Total fare is 1200\n");
        strcpy(filename,"8.txt");
    }
    else if (Bus_Num==900){
        printf("Total fare is 600\n");
        strcpy(filename,"9.txt");
    }
    else if (Bus_Num==1000){
        printf("Total fare is 1000\n");
        strcpy(filename,"10.txt");
    }
    else{
        printf("No bus found\n");
    }

    printBus(filename);

    printf("enter seat number = ");
    scanf("%d",&seat_number);

    deleteTicket(filename, seat_number);

    printf("DELETED\n");
    printf("press anything to continue");
    getch();
    showMenu();


}

//support function of cancelTickets()
void deleteTicket(char filename[], int seat_number){
    FILE *file,*temp;

    char name[MAX_LINE] = "empty";

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

        if (feof(file)){
            keep_reading = false;
            fputs(buffer, temp);
        } 
        else if (current_line ==  seat_number){
            fputs(name, temp);
            fputc('$',temp);
            fputc('\n',temp);
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


void availableBus(){

    printf("--------------------------------------SHS BUS RESERVATION SYSTEM--------------------------------------------\n\n");
    printf("Bus No.          Bus Name                 Destinations              Fare               Time\n");
    printf("100            Puri Express                Puri                    50             08:00 to 10:00 (58 km)\n");
    printf("200            Brahmapur Lines             Brahmapur               150            09:00 to 00:30 (164 km)\n");
    printf("300            Cuttack Linear              Cuttack                 30             13:00 to 13:50 (34 km)\n");
    printf("400            Balasore Express            Balasore                200            06:00 to 10:50 (207 km)\n");
    printf("500            Rourkela Lines              Rourkela                500            22:00 to 06:00 (327 km)\n");
    printf("600            Sambalpur Linear            Sambalpur               450            21:00 to 04:30 (319 km)\n");
    printf("700            Kolkata Linear              Kolkata                 600            06:00 to 16:00 (450 km)\n");
    printf("800            Hyderabad Express           Hyderabad               1200           16:00 to 12:00 (1024 km)\n");
    printf("900            Ranchi Lines                Ranchi                  600            19:00 to 06:00 (506 km)\n");
    printf("1000           Nagpur Express              Nagpur                  1000           05:00 to 22:30 (840 km)\n\n");

    printf("press anything to return");
    getch();
    showMenu();


}


void view_Tickets(){
    int Bus_Num;
    int seat_Num;
    char Pass_Nam[MAX_LINE];

    FILE *vbt;
    vbt = fopen("ViewTickets.txt","r");


    bool willContinue = true;

    while(willContinue){

        if(feof(vbt)){
            willContinue = false;
        }


        fscanf(vbt," %d %d %s ",&Bus_Num, &seat_Num,&Pass_Nam);
        if(Bus_Num==606910){
            printf("Bus Number     : %d\nSeat Number    : %d\nPassenger Name : %s\nDestination    : Bhubaneshwar to Puri\nTime           : 08:00 to 10:00 (58 km)\nFare           : 50\n\n",Bus_Num,seat_Num,Pass_Nam);
        }
        else if(Bus_Num==606911){
            printf("Bus Number     : %d\nSeat Number    : %d\nPassenger Name : %s\nDestination    : Bhubaneshwar to Brahmapur\nTime           : 09:00 to 00:30 (164 km)\nFare           : 150\n\n",Bus_Num,seat_Num,Pass_Nam);
        }
        else if(Bus_Num==606912){
            printf("Bus Number     : %d\nSeat Number    : %d\nPassenger Name : %s\nDestination    : Bhubaneshwar to  Cuttack\nTime           : 13:00 to 13:50 (34 km)\nFare           : 30\n\n",Bus_Num,seat_Num,Pass_Nam);
        }
        else if(Bus_Num==606913){
            printf("Bus Number     : %d\nSeat Number    : %d\nPassenger Name : %s\nDestination    : Bhubaneshwar to Balasore\nTime           : 06:00 to 10:50 (207 km)\nFare           : 200\n\n",Bus_Num,seat_Num,Pass_Nam);
        }
        else if(Bus_Num==606914){
            printf("Bus Number     : %d\nSeat Number    : %d\nPassenger Name : %s\nDestination    : Bhubaneshwar to Rourkela\nTime           : 22:00 to 06:00 (327 km)\nFare           : 500\n\n",Bus_Num,seat_Num,Pass_Nam);
        }
        else if(Bus_Num==606915){
            printf("Bus Number     : %d\nSeat Number    : %d\nPassenger Name : %s\nDestination    : Bhubaneshwar to Sambalpur\nTime           : 21:00 to 04:30 (319 km)\nFare           : 450\n\n",Bus_Num,seat_Num,Pass_Nam);
        }
        else if(Bus_Num==605822){
            printf("Bus Number     : %d\nSeat Number    : %d\nPassenger Name : %s\nDestination    : Bhubaneshwar to Kolkata\nTime           : 06:00 to 16:00 (450 km)\nFare           : 600\n\n",Bus_Num,seat_Num,Pass_Nam);
        }
        else if(Bus_Num==604049){
            printf("Bus Number     : %d\nSeat Number    : %d\nPassenger Name : %s\nDestination    : Bhubaneshwar to Hyderabad\nTime           : 16:00 to 12:00 (1024 km)\nFare           : 1200\n\n",Bus_Num,seat_Num,Pass_Nam);
        }
        else if(Bus_Num==605157){
            printf("Bus Number     : %d\nSeat Number    : %d\nPassenger Name : %s\nDestination    : Bhubaneshwar to Ranchi\nTime           : 19:00 to 06:00 (506 km)\nFare           : 600\n\n",Bus_Num,seat_Num,Pass_Nam);
        }
        else if(Bus_Num==607388){
            printf("Bus Number     : %d\nSeat Number    : %d\nPassenger Name : %s\nDestination    : Bhubaneshwar to Nagpur\nTime           : 05:00 to 22:30 (840 km)\nFare           : 1000\n\n",Bus_Num,seat_Num,Pass_Nam);
        }

        fgetc(vbt);
        fgetc(vbt);
        fgetc(vbt);
    }

    

    printf("enter any key to return to menu");
    getch();

    fclose(vbt);

    showMenu();
}

//function used to book new tickets
void bookTickets(){
    int Bus_Num,i,j;
    printf("========BUS RESERVATION SYSTEM==========\n");
    printf("Enter Bus no. :- ");
    scanf("%d",&Bus_Num);
    printf("\n");

    char filename[FILENAME_SIZE];
    if (Bus_Num==100){
        printf("Total fare is 50\n");
        strcpy(filename,"1.txt");
    }
    else if (Bus_Num==200) {
        printf("Total fare is 150\n");
        strcpy(filename,"2.txt");
    }
    else if (Bus_Num==300) {
        printf("Total fare is 30\n");
        strcpy(filename,"3.txt");
    }
    else if (Bus_Num==400){
        printf("Total fare is 200\n");
        strcpy(filename,"4.txt");
    }
    else if (Bus_Num==500) {
       printf("Total fare is 500\n");
       strcpy(filename,"5.txt");
    }
    else if (Bus_Num==600) {
        printf("Total fare is 400\n");
        strcpy(filename,"6.txt");
    }
    else if (Bus_Num==700) {
        printf("Total fare is 600\n");
        strcpy(filename,"7.txt");
    }
    else if (Bus_Num==800){
        printf("Total fare is 1200\n");
        strcpy(filename,"8.txt");
    }
    else if (Bus_Num==900){
        printf("Total fare is 600\n");
        strcpy(filename,"9.txt");
    }
    else if (Bus_Num==1000){
        printf("Total fare is 1000\n");
        strcpy(filename,"10.txt");
    }
    else{
        printf("No bus found\n");
    }

    printBus(filename);

    int AvTic = 20;
    printf("Available Tickets:--------> %d\n\n",AvTic);
    int num_Tic,Seat_Num;
    char Pass_Nam[20];
    printf("Numbers Of Tickets you want to Book:--->");
    scanf("%d",&num_Tic);
    printf("\n");
    for(int m=1; m<=num_Tic; m++){
        printf("============Enter your details for Ticket no %d= \n",m);
        printf("Seat number:-------->");
        scanf("%d",&Seat_Num);
        printf("Passenger name:-------->");
        getchar();
        gets(Pass_Nam);


        updateBus(Pass_Nam, Seat_Num, filename);

        char yes,ch = 'y';
        printf("Confirm(y/n) : ");
        scanf("%c",&yes);
        if(ch==yes){
            printf("ticket booked\n");
            FILE *vbt = fopen("ViewTickets.txt","a");
            fprintf(vbt, "\n%d %d %s ",Bus_Num,Seat_Num, Pass_Nam);
            fclose(vbt);
        }else{
            printf("Your ticket has not been booked\n");
        }


        Sleep(300);
    }


    //printf("%s\n",Pass_Nam);



    Sleep(500);
    printf("----------------------press any key to go back to main menu-----------------------------");





    getch();
    showMenu();
}

//support function of bookTickets()
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

        if (feof(file)){
            keep_reading = false;
            fputs(buffer, temp);
        } 
        else if (current_line ==  seatNumber){
            fputs(name, temp);
            fputc('$',temp);
            fputc('\n',temp);

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

//used to print the seats status of a particular bus file
void printBus(char filename[]){

    FILE *fptr = fopen(filename,"r");

    char c = 'a';
    //print the bus seats status
    for(int i=1 ; !feof(fptr) ; i++){
        printf("%d.",i);

        for(int j=1;;j++){
            //char ch;
            // fscanf(fptr,"%[^\n ] ",ch);
            c = fgetc(fptr);
            if(c == '$' || c == NULL){
                break;
            }

            printf("%c",c);

        }
        c = fgetc(fptr);
        // fgetc(fptr);
        //fgetc(fptr);
        printf("\n");
    }
    printf("\n");
    fclose(fptr);

}
