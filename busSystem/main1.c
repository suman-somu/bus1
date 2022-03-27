int main(){

   startup();

    bool UserNameValid = Valid();
    if(UserNameValid==true)
    {
        printf("----------------------------------------LOGIN IS SUCCESSFUL-------------------------------------------------\n");
        printf("----------------Press any key to go to main menu...--------------\n");
        getch();

        showMenu();

    }
    else
    {
        printf("INVALID USERNAME/PASSWORD");
        return 0;
    }

    int chooseOption = 0;
    while (chooseOption != 5)
    {

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
            printf("WRONG OPTION\nENTER CORRECT OPTION\n\npress anything to continue");
            getch();
            showMenu();
        }
    }
    return 0;
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