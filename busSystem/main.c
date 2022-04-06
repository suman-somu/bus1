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
void cancelTickets();
int howManyEmpty(char filename[]);
void updateViewTickets(int busNum, int seatNo);
void LogInSucc();

int main(){

    startup();
    LogInSucc();

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


void LogInSucc(){
 bool UserNameValid = Valid();
    if(UserNameValid==true){
        printf("\n");
        printf("LOADING");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".");
        Sleep(500);
        system("cls");
        printf("----------------------------------------LOGIN IS SUCCESSFUL-------------------------------------------------\n");
        printf("----------------Press any key to go to main menu...--------------\n");
        getch();

        showMenu();
    }
    else{
         printf("\n");
        printf("LOADING");
        Sleep(300);
        printf(".");
        Sleep(300);
        printf(".");
        Sleep(300);
        printf(".");
        Sleep(300);
        printf("\nINVALID USERNAME/PASSWORD\n\n\n");
        printf("press 1 to exit\npress any key to try again\n");
        int ch;
        ch = getch();
        if(ch==1){
            exit(0);
        }
        else{
            LogInSucc();
        }
    }
}


//takes user input of user-name and password and checks if it's matching or not
bool Valid(){


    char pass[30];
    char name[30];
    printf("-----------------------------------------------LOGIN--------------------------------------------------------\n");
    printf("                    ENTER USERNAME :- ");
    scanf(" %[^\n]%*c", name);

    char nCheck[30]={"suman"};
    char pCheck[30]={"sahoo"};
    char ch1;
    int i;
    if(  strcmp(name, nCheck) ==0)
    {
        printf("\n");
        printf("                    ENTER PASSWORD :- ");
        //gets(pass);

        for(i=0; i<30; i++)
        {
            ch1=getch();
            pass[i]=ch1;

            if(ch1!=13)      //13 is ASCII of Enter key
                printf("*");
            if(ch1 == 13)
                break;
        }
        pass[i]='\0';


        printf("\n");
        Sleep(1000);
        if(strcmp(pass,pCheck)==0){
                return true;
        }
        else{
            return false;
        }
        printf("\n");
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
            availableBus();
    }
    else if(chooseOption==2){
            bookTickets();
    }
    else if (chooseOption==3){
            cancelTickets();
    }
    else if(chooseOption==4){
            view_Tickets();
    }
    else if (chooseOption==5){
            printf("******Thank You for using this system****** ");
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
        //printf("Total fare is 50\n");
        strcpy(filename,"1.txt");
    }
    else if (Bus_Num==200) {
        //printf("Total fare is 150\n");
        strcpy(filename,"2.txt");
    }
    else if (Bus_Num==300) {
        //printf("Total fare is 30\n");
        strcpy(filename,"3.txt");
    }
    else if (Bus_Num==400){
        //printf("Total fare is 200\n");
        strcpy(filename,"4.txt");
    }
    else if (Bus_Num==500) {
       //printf("Total fare is 500\n");
       strcpy(filename,"5.txt");
    }
    else if (Bus_Num==600) {
        //printf("Total fare is 400\n");
        strcpy(filename,"6.txt");
    }
    else if (Bus_Num==700) {
        //printf("Total fare is 600\n");
        strcpy(filename,"7.txt");
    }
    else if (Bus_Num==800){
        //printf("Total fare is 1200\n");
        strcpy(filename,"8.txt");
    }
    else if (Bus_Num==900){
        //printf("Total fare is 600\n");
        strcpy(filename,"9.txt");
    }
    else if (Bus_Num==1000){
        //printf("Total fare is 1000\n");
        strcpy(filename,"10.txt");
    }
    else{
        printf("No bus found\n");
        printf("\npress any key to go back\n");
        getch();
        showMenu();
    }

    printBus(filename);
    printf("enter seat number = ");
    scanf("%d",&seat_number);


    deleteTicket(filename, seat_number);
    updateViewTickets(Bus_Num,seat_number);


    printf("\n\n\nYour Tickets has been CANCELLED\n\n\n");
    if (Bus_Num==100){
        printf("Total fare is 50\n");       
    }
    else if (Bus_Num==200) {
        printf("Total fare is 150\n");
    }
    else if (Bus_Num==300) {
        printf("Total fare is 30\n");
    }
    else if (Bus_Num==400){
        printf("Total fare is 200\n");
    }
    else if (Bus_Num==500) {
       printf("Total fare is 500\n");
    }
    else if (Bus_Num==600) {
        printf("Total fare is 400\n");
    }
    else if (Bus_Num==700) {
        printf("Total fare is 600\n");
    }
    else if (Bus_Num==800){
        printf("Total fare is 1200\n");
    }
    else if (Bus_Num==900){
        printf("Total fare is 600\n");
    }
    else if (Bus_Num==1000){
        printf("Total fare is 1000\n");
    }
    printf("\n\n\nTotal Amount Will be refund\n\n");
    printf("press anything to continue");
    getch();
    showMenu();

}

void updateViewTickets(int busNumber, int seat_number){

    char main_file[FILENAME_SIZE];
    char temp_file[FILENAME_SIZE];


    strcpy(main_file,"ViewTickets.txt");

    strcpy(temp_file,"temp__");
    strcat(temp_file,main_file);

    

    FILE *fp = fopen(main_file,"r");
    FILE *temp = fopen(temp_file,"w");


    bool keepLoop;
    if(feof(fp)){
        keepLoop = false;
    }
    else {
        keepLoop = true;
    }

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
            printf("CHECK1 ");
            continue;
        }
        else {
            printf("CHECK ");
            fprintf(temp,"%d %d %s %s %c",busNo,seatNo,name,name1,'\n');
        }

        
        if(feof(fp)){
            keepLoop = false;
        }


    }
    printf("CHECK 2");

    fclose(temp);
    fclose(fp);

    remove(main_file);
    rename(temp_file,main_file);

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
    printf("100            Puri Express                Puri                    100            08:00 to 10:00 (58 km)\n");
    printf("200            Brahmapur Lines             Brahmapur               150            09:00 to 00:30 (164 km)\n");
    printf("300            Cuttack Linear              Cuttack                 50             13:00 to 13:50 (34 km)\n");
    printf("400            Balasore Express            Balasore                200            06:00 to 10:50 (207 km)\n");
    printf("500            Rourkela Lines              Rourkela                500            22:00 to 06:00 (327 km)\n");
    printf("600            Sambalpur Linear            Sambalpur               450            21:00 to 04:30 (319 km)\n");
    printf("700            Kolkata Linear              Kolkata                 600            06:00 to 16:00 (450 km)\n");
    printf("800            Hyderabad Express           Hyderabad               1200           16:00 to 12:00 (1024 km)\n");
    printf("900            Ranchi Lines                Ranchi                  600            19:00 to 06:00 (506 km)\n");
    printf("1000           Nagpur Express              Nagpur                  1000           05:00 to 22:30 (840 km)\n\n");

    printf("press any key to return to main menu");
    getch();
    showMenu();

}


void view_Tickets(){
    int Bus_Num,seat_Num;

    char Pass_Nam[MAX_LINE];


    FILE *vbt1;
    vbt1 = fopen("ViewTickets.txt","r");
    int count = 0;
    char c1 = fgetc(vbt1);
    while(c1 != EOF){
        if(c1==' ' ){
            //cnt++;
            //printf("%5s"," ");
        }
        //printf("%c",c1);
        c1 = fgetc(vbt1);

        count++;
    }

    fclose(vbt1);
    if( count == 0){
        printf("\n\nNo Tickets Booked Till Now\n\n");

    }else {

        FILE *vbt;
        vbt = fopen("ViewTickets.txt","r");


        printf("\n\nBN = Bus Number\nSN = Seat Number\nPN = Passenger Number\n\n");
        printf("BN %5s SN %5s PN\n"," "," "," ");
        //loop through the file and print it
        char c = fgetc(vbt);
        while(c != EOF){
            if(c==' ' ){
                //cnt++;
                printf("%5s"," ");
            }
            printf("%c",c);
            c = fgetc(vbt);


        }
        fclose(vbt);
    }


    printf("\n\nenter any key to return to menu");
    getch();

    showMenu();
}

//function used to book new tickets
void bookTickets(){
    int Bus_Num;
    printf("========SHS BUS RESERVATION SYSTEM==========\n");
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

        printf("\npress any key to go back\n");
        getch();
        showMenu();
    }

    printBus(filename);

    int AvTic = 20;
    //howManyEmpty(filename);

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
        printf("Passenger FULL name:-------->");
        getchar();
        gets(Pass_Nam);


        updateBus(Pass_Nam, Seat_Num, filename);

        char yes,ch = 'y';
        printf("Confirm(y/n) : ");
        scanf("%c",&yes);
        if(ch==yes){
            printf("ticket booked\n");

            if (Bus_Num==100){
                printf("Each seat fare is 50\n");
                //strcpy(filename,"1.txt");
            }
            else if (Bus_Num==200) {
                printf("Each seat fare is 150\n");
                //strcpy(filename,"2.txt");
            }
            else if (Bus_Num==300) {
                printf("Each seat fare is 30\n");
                //strcpy(filename,"3.txt");
            }
            else if (Bus_Num==400){
                printf("Each seat fare is 200\n");
                //strcpy(filename,"4.txt");
            }
            else if (Bus_Num==500) {
                printf("Each seat fare is 500\n");
                //strcpy(filename,"5.txt");
            }
            else if (Bus_Num==600) {
                printf("Each seat fare is 400\n");
                //strcpy(filename,"6.txt");
            }
            else if (Bus_Num==700) {
                printf("Each seat fare is 600\n");
                //strcpy(filename,"7.txt");
            }
            else if (Bus_Num==800){
                printf("Each seat fare is 1200\n");
                //strcpy(filename,"8.txt");
            }
            else if (Bus_Num==900){
                printf("Each seat fare is 600\n");
                //strcpy(filename,"9.txt");
            }
            else if (Bus_Num==1000){
                printf("Each seat fare is 1000\n");
                //strcpy(filename,"10.txt");
            }


            FILE *vbt = fopen("ViewTickets.txt","a");
            fprintf(vbt, "\n%d %d %s ",Bus_Num,Seat_Num, Pass_Nam);
            fclose(vbt);
        }else{
            printf("Your ticket has not been booked\n");
        }


        Sleep(300);
    }

    Sleep(500);
    printf("----------------------press any key to go back to main menu-----------------------------");


    getch();
    showMenu();
}

int howManyEmpty(char filename[]){


    FILE *file = fopen(filename,"r");
    char buffer[16];
    char check[16]="empty";
    bool keep_reading = true;

    int count = 0;

    //loop through the file and check each line to find "empty" and increment the count variable
    while(keep_reading){

        fgets(buffer, 16, file);
        printf("%s",buffer);

        if (feof(file)){
            printf("first out");
            keep_reading = false;

        }
        if (strcmp(buffer,check)==0){
            count++;
            printf("second");
        }


    }
    fclose(file);
    return count;

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


//what is the difference bet pointer function and declaring the pointer fnc
