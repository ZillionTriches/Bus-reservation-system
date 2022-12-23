#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<unistd.h>
#include "splash.h"
#include "login.h"
#include "database.h"
#include "H_database.h"


void menu(void);
void ticketbook(void);
void seatselect(void);
void payment (void);
int fare(int a, int b);

int p, d;

int main(void)
{
    splashscreen();
    sleep(5);
    system("CLS");
    Log_reg();
    menu();

    return 0;
}

void menu(void)
{
    int a;
    while(a!=3)
    {
        printf("1. Book a ticket for an upcoming trip.\n");
        printf("2. Look at your Travel History so far.\n");
        printf("3. Exit\n\n");
        printf("Enter the 1/2/3 based on your selection below\n");
        scanf("%d", &a);


        switch(a)
        {
        case 1:
            printf("\n _________________________________________\n");
            printf("  Booking a ticket has never been easier  ");
            printf("\n -----------------------------------------\n");
            printf("Select your Pick-up, destination and Bus seat.\n\n");
            ticketbook();
            a = 3;
            break;

        case 2:
            printf("\n_______________________\n");
            printf(" Your Travel History is: ");
            printf("\n-----------------------\n");
            readhis();
            a = 3;
            break;
        case 3:
            printf("\n\nThank You!!");
            break;

        default:
            printf("\nPlease Enter a valid option!");
            break;
        }
    }

}
void ticketbook(void)
{
    int f;
    printf("\nEnter your pickup location from the option below: \n");
    printf("1. Mirpur\n");
    printf("2. Uttara\n");
    printf("3. Banani\n");
    printf("4. Gulshan\n");
    printf("5. Bashundhara\n");
    printf("6. Badda\n");
    printf("7. Mohammadpur\n");
    printf("8. Dhanmondi\n");
    printf("\nEnter your choice: ");
    scanf("%d", &p);

    printf("\nEnter your destination from the option below: \n");
    printf("1. Mirpur\n");
    printf("2. Uttara\n");
    printf("3. Banani\n");
    printf("4. Gulshan\n");
    printf("5. Bashundhara\n");
    printf("6. Badda\n");
    printf("7. Mohammadpur\n");
    printf("8. Dhanmondi\n");
    printf("\nEnter your choice: ");
    scanf("%d", &d);

    f = fare(p, d);
    add_info(p, d);
    printf("Your Fare is: %dtk\n", f);
    payment();

    printf("Select your Bus seat: \n");

    seatselect();
    system("CLS");
    printf("\n------------------------\n");
    printf(" Thank you Travel Again!!");
    printf("\n------------------------\n");

}

void seatselect(void)
{
    int i, j, count, n, v;
    int b[40];

    get_info(b);

    while(1)
    {
        count = 0;

        for(i=0; i<10; i++)
        {
            for(j=0; j<4; j++)
            {
                if(b[count] == 0)
                    printf("%d. Available\t\t", count+1);
                else
                    printf("%d. Booked\t\t", count+1);
                count++;
            }
            printf("\n\n");

        }
        printf("\nEnter the seat number of your choice: ");
        scanf("%d", &n);

        v = seatbook(n);
        if(v==10)

                printf("\nSeat unavailable\n");
        else
            {
                printf("\nSeat Booked\n");
                break;
            }

    }
}

int fare(int p, int d)
{
    int z = p - d;

    if(z < 0)
        z = z * -1;

    switch(z)
    {
    case 0:
        return 0;

    case 1:
    case 2:
        return 30;
        break;

    case 3:
    case 4:
        return 40;

    case 5:
    case 6:
        return 50;

    case 7:
    case 8:
        return 60;

    default:
        return 60;
    }
}

void payment(void)
{
    int n, flag = 1;
    char number[11], pin[5];

    while(flag==1)
    {


        printf("\nPlease select your preferred payment option\n");
        printf("1. Bkash\n");
        printf("2. Cash\n");
        printf("3. Visa Card\n");
        scanf("%d", &n);

        switch(n)
        {
        case 1:
            printf("Enter Bkash number: ");
            scanf("%s", number);
            printf("Enter PIN: ");
            scanf("%s", pin);

            printf("Payment Successful\n");
            flag = 0;
            break;

        case 2:
            printf("Pay to your nearest ticket collection point: ");
            flag = 0;
            break;

        case 3:
            printf("Unavailable now\nPlease select one of the other two options.");

        default:
            continue;
            break;
        }
    }
    system("CLS");
}

