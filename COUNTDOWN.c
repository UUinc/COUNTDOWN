//COUNTDOWN Inspired by the movie : COUNTDOWN Movie
#include <stdio.h>
#include <conio.h>

typedef struct
{   
    int yrs;
    int day;
    int hrs;
    int min;
    int sec;
    int done;

} Timer;

//Global Variables
Timer timer;

//Function Declaration
int Random(int n);
void DeathDay(int age);
void DisplayCounter();
void Countdown();

int main()
{
    int age, error;

    do
    {
        printf("Your Age : ");
        fflush(stdin);
        error = !scanf("%d",&age);
        error = error || age < 1 || age > 200 ? 1 : 0;
        if(error)
            printf("\n--Incorrect age!--\n\n");
    } while (error);

    DeathDay(age);

    while(!timer.done)
    {
        system("cls");
        DisplayCounter();
        Countdown();
        sleep(1);
    }
    
    return 0;
}

int Random(int n)
{
    time_t t;
	    
    srand((unsigned) time(&t));

    return rand() % n;
}

void DeathDay(int age)
{
    timer.done = 0;

    if(age > 99)
        timer.yrs = Random(5);
    else if(age > 15)
        timer.yrs = Random(50);
    else
    {
        timer.yrs = 10;
        timer.yrs += Random(100);
    }
        
    timer.day = Random(99);
    timer.hrs = Random(23);
    timer.min = Random(59);
    timer.sec = Random(59);
}

void DisplayCounter()
{
    printf("\n---------------COUNTDOWN---------------\n\n");
    printf("\t\t%d yrs\n\n",timer.yrs);
    printf("\t\t%d day\n\n",timer.day);
    printf("\t\t%d hrs\n\n",timer.hrs);
    printf("\t\t%d min\n\n",timer.min);
    printf("\t\t%d sec\n\n",timer.sec);
    printf("----------------------------------------");
}

void Countdown()
{
    if(timer.sec > 0)
        timer.sec--;
    else
    {
        timer.sec = 59;
        if(timer.min > 0)
            timer.min--;
        else
        {
            timer.min = 59;
            if(timer.hrs > 0)
                timer.hrs--;
            else
            {
                timer.hrs = 23;
                if(timer.day > 0)
                    timer.day--;
                else
                {
                    timer.day = 99;
                    if(timer.yrs > 0)
                        timer.yrs--;
                    else
                    {
                        printf("\n\t\tR.I.P\n");
                        timer.done = 1;
                    }
                }
            }
        }
    }
}