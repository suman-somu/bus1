#include <stdio.h>
#include <stdlib.h>


struct date {
    int dd;
    int mm;
    int yyyy;
};
typedef struct date D;

int main()
{

    D d1,d2,r;

    printf("\nenter the first date in dd mm yyyy format =");
    scanf(" %d %d %d",&(d1.dd),&(d1.mm),&(d1.yyyy));
    printf("\nenter the second date in dd mm yyyy format =");
    scanf(" %d %d %d",&(d2.dd),&(d2.mm),&(d2.yyyy));


    if(d1.yyyy < d2.yyyy){
            
        int temp = d1.yyyy;
        d1.yyyy = d2.yyyy;
        d2.yyyy= temp;

        temp = d1.mm;
        d1.mm= d2.mm;
        d2.mm= temp;

        temp = d1.dd;
        d1.dd= d2.dd;
        d2.dd = temp;

    }else if(d1.yyyy == d2.yyyy){
        if(d1.mm == d2.mm ){
            if(d1.dd < d2.dd){
                int temp = d1.yyyy;
                d1.yyyy = d2.yyyy;
                d2.yyyy= temp;

                temp = d1.mm;
                d1.mm= d2.mm;
                d2.mm= temp;

                temp = d1.dd;
                d1.dd= d2.dd;
                d2.dd = temp;
            }
        }
        
        if(d1.mm < d2.mm ){
            int temp = d1.yyyy;
            d1.yyyy = d2.yyyy;
            d2.yyyy= temp;

            temp = d1.mm;
            d1.mm= d2.mm;
            d2.mm= temp;

            temp = d1.dd;
            d1.dd= d2.dd;
            d2.dd = temp;
        }
    }

    r.yyyy = d1.yyyy - d2.yyyy;
    r.mm = d1.mm - d2.mm ;
    r.dd = d1.dd - d2.dd;



    if(r.dd < 0){
        r.dd += 30;
        r.mm -= 1;
    }

    if(r.mm <0 ){
        r.mm +=12;
        r.yyyy -= 1;
    }

    // if(r.yyyy <0 ){
    //     r.yyyy *= -1;
    // }

    printf("\n\nthe difference between the two dates in dd mm yyyy, is = %d %d %d ",r.dd,r.mm,r.yyyy);
    return 0;
}
