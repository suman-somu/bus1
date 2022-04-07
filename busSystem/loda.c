


int main(int seatNumber){

    char main[25];
    strcpy(main,"inventory.txt");

    char temp[25];
    strcpy(temp,"temp_main");

    FILE *f1 = fopen(main,"r");
    FILE *f2 = fopen(temp,"w");


    int current_line =1;
    bool keep_reading = true;
    do{

        char buffer[5];
        fgets(buffer, 5, f1);

        
        

        if (feof(f1)){
            keep_reading = false;
        }
        
        if (current_line ==  seatNumber){.2

            int num;
            scanf("%d",num);
            fprintf(num, f2);
            fputc('\n',f2);

        }
        else {
            int num;
            fscanf("%d",num);
            fprintf(num,f2);
            fputc('\n',f2)
        }


        current_line++;

    }while(keep_reading);


    fclose(f1);
    fclose(f2);

    return 0;
}