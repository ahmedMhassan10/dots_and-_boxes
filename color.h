#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED
#include "rank.h"

int thirdPage;

int checkScan(int maxN,int *choice)//checks if the scaned thing is a number not a letter or a symbol
{
    int x;
    char z[100];
    while (1)
    {
        if(maxN==1 ||maxN==2 || maxN==4 ||maxN==3)
        {
            scanf("%d",&x);
            if(x<=maxN && x>0)
            {
                *choice=x;
                return 0;
            }
            else
            {
                fgets(z,100,stdin);
                printf("Invalid input\n");
                continue;
            }
        }
        else if(maxN==5 ||  maxN==11)
        {
            scanf("%d",&x);
            if(x<=maxN && x>0)
            {
                *choice=x;
                return 0;
            }else{
                fgets(z,100,stdin);
                printf("Invalid input\n");
                continue;
            }
        }
    }
}

void dotsandboxs()//to print dots and boxes large
{

    printf("\t\t  _      ____  _________  ____          __     _        _          ___    ____       ____\n");
    printf("\t\t | \\    /    \\     |     |             /  \\   | \\    | | \\        |   \\  /    \\ \\  /|      \n ");
    printf("\t\t |  |  |      |    |     |____        /____\\  |  \\   | |  |       |___/ |      | \\/ |____ \n");
    printf("\t\t |  |  |      |    |          |      |      | |   \\  | |  |       |   \\ |      | /\\      |\n");
    printf("\t\t |_/    \\____/     |      ____|      |      | |    \\_| |_/        |___/  \\____/ /  \\ ____|\n\n");

}
void guide()
{
    printf("\t\t\t\t\t\t<< game guide >>\n");
    printf("\t\t\t\t-To play enter the index of the place you want your line to be\n");
    printf("\t\t\t\t-if a person completes all four sides of a unit square gets a point\n");
    printf("\t\t\t\t-it is only valid to select from the in game menu instead of entering number of row\n\n");
}

#endif // COLOR_H_INCLUDED
