#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "write.h"
#include "color.h"
#include "rank.h"
#include <string.h>

extern int menu;
extern int totalmoves;
extern time_t seconds;
extern int remainline;
extern int thirdPage;
extern int firstPage;
extern int secondPage;
extern int topIndex;
extern char arrayOfGame[12][12];

int main()
{
    undoIndex = 0;
    for (int i = 0; i < 60; i++)
    {
        for (int j = 0; j < 2; j++)
            undoRedo[i][j] = 0;
    }
    topIndex = 0;
    player1.score = 0;
    player1.numofmoves = 0;
    player2.score = 0;
    player2.numofmoves = 0;
    player3.score = 0;
    player3.numofmoves = 0;
    firstPage = 0;
    secondPage = 0;
    thirdPage = 0;
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            arrayOfGame[i][j] = 0;
        }
    }
    dotsandboxs();
    printf("\n\n\n\n\t\t\t\t\t welcome to our project \n\n ");
    printf("\t\t\t\t\t put 1.New Game\n\n ");
    printf("\t\t\t\t\t put 2.Load game\n\n ");
    printf("\t\t\t\t\t put 3.top 10 \n\n ");
    printf("\t\t\t\t\t put 4.esc \n\n ");
    printf("\t\t\t\t\t enter your choice \n\n ");
    checkScan(4, &firstPage);
    system("cls");
    if (firstPage == 4)
        return 0;
    if (firstPage == 3)
    {
        getRank();
        printf("\n\n\n\n1-Main Menu\n2-Exit\n\n");
        menu = 0;
        checkScan(2, &menu);
        if (menu == 1)
        {
            system("cls");
            main();
        }
        return 0;
    }
    if (firstPage == 1)
    {
        system("cls");
        dotsandboxs;
        guide();
        printf("\n\n\n\n\n\n\t\t\t\t\t put 1.Easy Game \n\n ");
        printf("\t\t\t\t\t put 2.Hard game\n\n ");
        printf("\t\t\t\t\t enter your choice \n\n ");
        checkScan(2, &secondPage);
        system("cls");

        system("cls");
        printf("\n\n\n\n\n\t\t\t\t\t put 1.one player \n\n ");
        printf("\t\t\t\t\t put 2.two player\n\n ");
        printf("\t\t\t\t\t enter your choice \n\n ");
        checkScan(2, &thirdPage);
        system("cls");
    }
    if (thirdPage == 1)
    {
        printf("\n\n\n\n\n\t\t\t\t\t First Player Name:");
        player1.nameLength = input(player1.name, 100);
        player1.nameLength = input(player1.name, 100);
        system("cls");
    }
    else if (thirdPage == 2)
    {
        printf("\n\n\n\n\n\t\t\t\t\t First Player Name:");
        player1.nameLength = input(player1.name, 100);
        player1.nameLength = input(player1.name, 100);

        printf("\n\n\t\t\t\t\t Second Player Name:");
        player2.nameLength = input(player2.name, 100);
        system("cls");
    }
    typeOfGame();
    return 0;
}
