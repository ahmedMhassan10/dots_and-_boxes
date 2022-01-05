#ifndef WRITE_H_INCLUDED
#define WRITE_H_INCLUDED
#include <time.h>
#include "rank.h"
#include <string.h>

int menu = 0;
int help = 0;
int undoRedo[60][2] = {0};
int undoIndex = 0;
int undoCounter = 0;
int thirdPage;
int secondPage;
int firstPage;
int score1 = 0, score3 = 0;
int re = 0;
char arrayOfGame[12][12] = {0};
typedef struct build
{
    char name[100];
    int nameLength;
    int score;
    int color;
    int numofmoves;
    int topIndex;

} build;
build player1 = {"", 0, 0, 0, 0};
build player2 = {"bb", 0, 0, 0, 0};
build player3 = {"Computer", 0, 0, 0, 0};
int input(char arr[], int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n' && i < n)
    {
        arr[i++] = ch;
    }
    arr[i] = '\0';
    return i;
}

int totalmoves = 1;
int remainline = 0;
time_t seconds;

void timeDifferance(time_t seconds)
{
    time_t second;
    second = time(NULL);
    time_t time = second - seconds;
    time_t minutes = time / 60;
    time %= 60;
    printf("\x1b[33m"
           "\nTotal Time ( %d:%d )\n"
           "\x1b[0m",
           (int)minutes, (int)time);
}
void write(int n, char a[12][12])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        printf("\t\t  ");
        for (j = 0; j < n; j++)
        {
            if (a[i][j] == 'A')
            {

                printf("\x1b[34m"
                       "% c  "
                       "\x1b[0m",
                       a[i][j]);
            }
            else if (a[i][j] == 'B')
            {
                printf("\x1b[31m"
                       "% c  "
                       "\x1b[0m",
                       a[i][j]);
            }
            else
            {
                printf("% c  ", a[i][j]);
            }
        }
        printf("\n");
    }
    printf("\x1b[33m"
           "\nRemaining lines= %d\n\n"
           "\x1b[0m",
           remainline);
    if (thirdPage == 2)
    {
        printf("\x1b[34m"
               "\n%s`s number of moves :%d\t"
               "\x1b[31m"
               " %s`s number of moves :%d\n"
               "\x1b[0m",
               player1.name, player1.numofmoves, player2.name, player2.numofmoves);
        printf("\x1b[34m"
               "\n%s score :%d\t\t"
               "\x1b[31m"
               "    %s score :%d\n"
               "\x1b[0m",
               player1.name, player1.score, player2.name, player2.score);
        timeDifferance(seconds);
        printf("\x1b[33m"
               "\nUndo-->(1,1) \t Redo-->(2,2) \t Main Menu-->(3,3) \t Save-->(4,4)\n"
               "\x1b[0m");
        if (totalmoves % 2 == 1)
        {
            printf("\x1b[34m"
                   "\n%s`s turn\n"
                   "\x1b[0m",
                   player1.name);
        }
        else
        {
            printf("\x1b[31m"
                   "\n%s`s turn\n"
                   "\x1b[0m",
                   player2.name);
        }
    }
    else
    {
        printf("\x1b[34m"
               "\n%s`s number of moves :%d\t"
               "\x1b[31m"
               " %s`s number of moves :%d\n"
               "\x1b[0m",
               player1.name, player1.numofmoves, player3.name, player3.numofmoves);
        if (thirdPage == 1)
        {
            printf("\x1b[34m"
                   "\n%s score :%d\t\t"
                   "\x1b[31m"
                   "    %s score :%d\n"
                   "\x1b[0m",
                   player1.name, player1.score, player3.name, player3.score);
            timeDifferance(seconds);
            printf("\x1b[33m"
                   "\nUndo-->(1,1) \t Redo-->(2,2) \t Main Menu-->(3,3) \t Save-->(4,4)\n"
                   "\x1b[0m");
            if (totalmoves % 2 == 1)
            {
                printf("\x1b[34m"
                       "\n%s`s turn\n"
                       "\x1b[0m",
                       player1.name);
            }
            else
            {
                printf("\x1b[31m"
                       "\n%s`s turn\n"
                       "\x1b[0m",
                       player3.name);
            }
        }
    }
}
void leadboard(int siz)
{
    int i, j;
    for (i = 1; i < 12; i += 2)
    {
        for (j = 1; j < 12; j += 2)
        {
            arrayOfGame[i][j] = 254;
        }
    }
    arrayOfGame[0][1] = '1';
    arrayOfGame[0][2] = '2';
    arrayOfGame[0][3] = '3';
    arrayOfGame[0][4] = '4';
    arrayOfGame[0][5] = '5';
    arrayOfGame[0][6] = '6';
    arrayOfGame[0][7] = '7';
    arrayOfGame[0][8] = '8';
    arrayOfGame[0][9] = '9';
    arrayOfGame[0][10] = 'a';
    arrayOfGame[0][11] = 'b';
    arrayOfGame[0][12] = 'c';
    arrayOfGame[1][0] = '1';
    arrayOfGame[2][0] = '2';
    arrayOfGame[3][0] = '3';
    arrayOfGame[4][0] = '4';
    arrayOfGame[5][0] = '5';
    arrayOfGame[6][0] = '6';
    arrayOfGame[7][0] = '7';
    arrayOfGame[8][0] = '8';
    arrayOfGame[9][0] = '9';
    arrayOfGame[10][0] = 'a';
    arrayOfGame[11][0] = 'b';
    arrayOfGame[12][0] = 'c';
    write(siz, arrayOfGame);
    return;
}
int checkComplete(int siz)
{
    int counter = 0;
    for (int i = 2; i < siz; i += 2)
    {
        for (int j = 2; j < siz; j += 2)
        {
            if (arrayOfGame[i - 1][j] != 0 && arrayOfGame[i + 1][j] != 0 && arrayOfGame[i][j - 1] != 0 && arrayOfGame[i][j + 1] != 0 && arrayOfGame[i][j] == 0)
            {
                if (totalmoves % 2 == 1)
                {
                    arrayOfGame[i][j] = 'A';
                }
                else
                {
                    arrayOfGame[i][j] = 'B';
                }
                counter++;
            }
        }
    }
    return counter;
}
int checkComplete2(int siz)
{
    int counter = 0;
    for (int i = 2; i < siz; i += 2)
    {
        for (int j = 2; j < siz; j += 2)
        {
            if (arrayOfGame[i - 1][j] != 0 && arrayOfGame[i + 1][j] != 0 && arrayOfGame[i][j - 1] != 0 && arrayOfGame[i][j + 1] != 0 && arrayOfGame[i][j] == 0)
            {
                if (totalmoves % 2 == 0)
                {
                    arrayOfGame[i][j] = 'A';
                }
                else
                {
                    arrayOfGame[i][j] = 'B';
                }
                counter++;
            }
        }
    }
    return counter;
}
int playerOne(int siz)
{
    player1.numofmoves++;
    int counte = 0;
    counte = checkComplete(siz);
    score1 = player1.score;
    player1.score += counte;
    if (counte != 0)
        totalmoves++;
    return counte;
}
void playertwo(int siz)
{
    player2.numofmoves++;
    int counte = 0;
    counte = checkComplete(siz);
    player2.score += counte;
    if (counte != 0)
        totalmoves++;
}
int playerthree(int siz)
{
    player3.numofmoves++;
    int counte = 0;
    counte = checkComplete(siz);
    player3.score += counte;
    if (counte != 0)
        totalmoves++;
    return counte;
}
int antiCheckComplete(int siz)
{
    int counter = 0;
    for (int i = 2; i < siz; i += 2)
    {
        for (int j = 2; j < siz; j += 2)
        {
            if (arrayOfGame[i][j] != 0 && ((arrayOfGame[i - 1][j] == 0) || arrayOfGame[i + 1][j] == 0 || arrayOfGame[i][j - 1] == 0 || arrayOfGame[i][j + 1] == 0))
            {
                if (arrayOfGame[i][j] == 'A')
                {
                    arrayOfGame[i][j] = 0;
                    player1.score--;
                    counter++;
                }
                else if (thirdPage == 2 && arrayOfGame[i][j] == 'B')
                {
                    arrayOfGame[i][j] = 0;
                    player2.score--;
                    counter++;
                }
                else if (thirdPage == 1 && arrayOfGame[i][j] == 'B')
                {
                    arrayOfGame[i][j] = 0;
                    player3.score--;
                    counter++;
                }
            }
        }
    }
    return counter;
}
void undo(int siz)
{
    int k = 0;
    arrayOfGame[undoRedo[--undoIndex][0]][undoRedo[undoIndex][1]] = 0;
    k = antiCheckComplete(siz);
    if (k > 0)
        totalmoves--;
    if (totalmoves % 2 == 0)
    {
        player1.numofmoves--;
    }
    else
    {
        if (thirdPage == 2)
        {
            player2.numofmoves--;
        }
        else
        {
            player3.numofmoves--;
        }
    }
    totalmoves--;
    remainline++;
}
void redo(int siz)
{
    remainline--;
    totalmoves++;
    if (undoRedo[undoIndex][0] % 2 == 0)
    {
        arrayOfGame[undoRedo[undoIndex][0]][undoRedo[undoIndex][1]] = 179;
    }
    else
    {
        arrayOfGame[undoRedo[undoIndex][0]][undoRedo[undoIndex][1]] = 196;
    }
    undoIndex++;
    if (totalmoves % 2 == 0)
    {
        player1.numofmoves++;
        int counte = 0;
        counte = checkComplete2(siz);
        player1.score += counte;
        if (counte != 0)
            totalmoves++;
    }
    else
    {
        player2.numofmoves++;
        int counte = 0;
        counte = checkComplete2(siz);
        player2.score += counte;
        if (counte != 0)
            totalmoves++;
    }
}
void save1(int fileNum)
{
    FILE *s;
    if (fileNum == 1)
    {
        s = fopen("game1.bin", "wb");
        remove(s);
        s = fopen("game1.bin", "wb");
    }
    else if (fileNum == 2)
    {
        s = fopen("game2.bin", "wb");
        remove(s);
        s = fopen("game2.bin", "wb");
    }
    else if (fileNum == 3)
    {
        s = fopen("game3.bin", "wb");
        remove(s);
        s = fopen("game3.bin", "wb");
    }
    fprintf(s, "%d\n", secondPage);
    fprintf(s, "%d\n", thirdPage);
    fprintf(s, "%d\n", remainline);
    fprintf(s, "%d\n", totalmoves);
    fprintf(s, "%d\n", player1.numofmoves);
    fprintf(s, "%d\n", player1.score);
    fprintf(s, "%s\n", player1.name);
    /* fprintf(s,"%s\n",player1.color);*/
    fprintf(s, "%d\n", player2.numofmoves);
    fprintf(s, "%d\n", player2.score);
    fprintf(s, "%s\n", player2.name);
    /* fprintf(s,"%s\n",player2.color);*/
    fprintf(s, "%d\n", player3.numofmoves);
    fprintf(s, "%d\n", player3.score);
    fprintf(s, "%s\n", player3.name);
    /* fprintf(s,"%s\n",player3.color);*/
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            fprintf(s, "%c\n", arrayOfGame[i][j]);
        }
    }
    fclose(s);
}
int game(int numOfRow, int numOfColumn, int siz)
{
    if (numOfRow == 4 && numOfColumn == 4)
    {
        printf("save as \n1-game1 \n2-game2\n3-game3\n");
        int fileNum;
        checkScan(3, &fileNum);
        save1(fileNum);
    }
    else if (numOfRow == 1 && numOfColumn == 1 && undoIndex > 0)
    {
        undoCounter++;
        undo(siz);
        system("cls");
        write(siz, arrayOfGame);
    }
    else if (numOfRow == 2 && numOfColumn == 2 && undoCounter > 0 && undoRedo[undoIndex][0] != 0 && undoRedo[undoIndex][1] != 0)
    {
        redo(siz);
        undoCounter--;
        system("cls");
        write(siz, arrayOfGame);
    }
    else if (numOfRow < siz && numOfColumn < siz && arrayOfGame[numOfRow][numOfColumn] == 0 && !(numOfColumn % 2 == 0 && numOfRow % 2 == 0))
    {
        undoCounter = 0;
        undoRedo[undoIndex][0] = numOfRow;
        undoRedo[undoIndex++][1] = numOfColumn;
        if (numOfRow % 2 == 0)
        {
            arrayOfGame[numOfRow][numOfColumn] = 179;
        }
        else
        {
            arrayOfGame[numOfRow][numOfColumn] = 196;
        }

        if (totalmoves % 2 == 1)
        {
            playerOne(siz);
        }
        else
        {
            playertwo(siz);
        }
        remainline--;
        totalmoves++;
        system("cls");
        write(siz, arrayOfGame);
    }
    else
    {
        printf("\n");
        printf("Error try again\n");
        printf("Write the needed row :\t");
        checkScan(siz - 1, &numOfRow);
        printf("\n");
        printf("Write the needed column :\t");
        checkScan(siz - 1, &numOfColumn);
        game(numOfRow, numOfColumn, siz);
    }
}
int gameOfcomputer(int numOfRow, int numOfColumn, int siz)
{
    if (numOfRow == 4 && numOfColumn == 4)
    {
        printf("save as \n1-game1 \n2-game2\n3-game3\n");
        int fileNum;
        checkScan(3, &fileNum);
        save1(fileNum);
    }
    else if (numOfRow == 1 && numOfColumn == 1 && undoIndex > 0)
    {
        if (score1 != 0)
        {
            undoCounter += 1;
            undo(siz);
            score1 = 0;
            system("cls");
            write(siz, arrayOfGame);
        }
        else if (score3 != 0)
        {
            undoCounter += 2 * score3 + 1;
            for (int i = 0; i < score3 + 2; i++)
            {
                undo(siz);
            }
            score3 = 0;
            system("cls");
            write(siz, arrayOfGame);
        }
        else
        {
            undoCounter += 2;
            undo(siz);
            undo(siz);
            system("cls");
            write(siz, arrayOfGame);
        }
        help = 1;
    }
    else if (numOfRow == 2 && numOfColumn == 2)
    {
        if (help == 0 && undoRedo[undoIndex][0] == 0)
        {
            printf("\n");
            printf("Error try again\n");
            printf("Write the needed row :\t");
            checkScan(siz - 1, &numOfRow);
            printf("\n");
            printf("Write the needed column :\t");
            checkScan(siz - 1, &numOfColumn);
            gameOfcomputer(numOfRow, numOfColumn, siz);
        }
        else
        {
            redo(siz);
            undoCounter--;
            system("cls");
            write(siz, arrayOfGame);
        }
    }
    else if (numOfRow < siz && numOfColumn < siz && arrayOfGame[numOfRow][numOfColumn] == 0 && !(numOfColumn % 2 == 0 && numOfRow % 2 == 0))
    {

        undoRedo[undoIndex][0] = numOfRow;
        undoRedo[undoIndex++][1] = numOfColumn;
        help = 0;
        if (numOfRow % 2 == 0)
        {
            arrayOfGame[numOfRow][numOfColumn] = 179;
        }
        else
        {
            arrayOfGame[numOfRow][numOfColumn] = 196;
        }

        if (totalmoves % 2 == 1)
        {
            score1 = playerOne(siz);
        }
        else
        {
            score3 += playerthree(siz);
        }
        undoCounter = 0;
        remainline--;
        totalmoves++;
        system("cls");
        write(siz, arrayOfGame);
    }
    else
    {
        printf("\n");
        printf("Error try again\n");
        printf("Write the needed row :\t");
        checkScan(siz - 1, &numOfRow);
        printf("\n");
        printf("Write the needed column :\t");
        checkScan(siz - 1, &numOfColumn);
        gameOfcomputer(numOfRow, numOfColumn, siz);
    }
    return 1;
}

void load(int fileNum, int *second, int *third, int *remain, int *total, int *oneMoves, int *onescore, char oneName[100], /* char onecolor[10],*/ int *twoMoves, int *twoscore, char twoName[100], /*char twocolor[10],*/ int *threeMoves, int *threescore, char threeName[100], /*char threecolor[10]*/ char arr[12][12])
{
    FILE *s;
    if (fileNum == 1)
    {
        s = fopen("game1.bin", "rb");
    }
    else if (fileNum == 2)
    {
        s = fopen("game2.bin", "rb");
    }
    else if (fileNum == 3)
    {
        s = fopen("game3.bin", "rb");
    }

    fscanf(s, "%d\n", second);
    fscanf(s, "%d\n", third);
    fscanf(s, "%d\n", remain);
    fscanf(s, "%d\n", total);
    fscanf(s, "%d\n", oneMoves);
    fscanf(s, "%d\n", onescore);
    fscanf(s, "%s\n", oneName);
    /* fscanf(s,"%s\n",onecolor);*/
    fscanf(s, "%d\n", twoMoves);
    fscanf(s, "%d\n", twoscore);
    fscanf(s, "%s\n", twoName);
    /*fscanf(s,"%s\n",twocolor);*/
    fscanf(s, "%d\n", threeMoves);
    fscanf(s, "%d\n", threescore);
    fscanf(s, "%s\n", threeName);
    /*fscanf(s,"%s\n",threecolor);*/
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            char c;
            fscanf(s, "%c\n", &c);
            arr[i][j] = c;
        }
    }
    fclose(s);
}

void typeOfGame()
{
    if (firstPage == 2)
    {
        printf("Load : \n\n1-game1 \n2-game2\n3-game3\n");
        int fileNum;
        checkScan(3, &fileNum);
        load(fileNum, &secondPage, &thirdPage, &remainline, &totalmoves, &player1.numofmoves, &player1.score, &player1.name, /*&player1.color,*/ &player2.numofmoves, &player2.score, &player2.name, /*&player2.color,*/ &player3.numofmoves, &player3.score, &player3.name, /*&player3.color,*/ arrayOfGame);
        system("cls");
    }
    if (secondPage == 1 && thirdPage == 2)
    {
        if (firstPage == 1)
            remainline = 12;
        int m = 6;
        seconds = time(NULL);
        leadboard(m);
        while (1)
        {
            int numOfRow, numOfColumn;
            printf("\n");
            printf("Write the needed row :  ");
            checkScan(m - 1, &numOfRow);
            printf("\n");
            printf("Write the needed column :  ");
            checkScan(m - 1, &numOfColumn);
            if (numOfColumn == 3 && numOfRow == 3)
            {
                system("cls");
                main();
                break;
            }
            else
            {
                game(numOfRow, numOfColumn, m);
            }
            if (player1.score + player2.score == 4)
            {
                if (player1.score > player2.score)
                {
                    savetop(player1.score, player1.name);
                    printf("CONGRATULATIONS! %s is the winner ", player1.name);
                }
                else if (player2.score > player1.score)
                {
                    savetop(player2.score, player2.name);

                    printf("CONGRATULATIONS! %s is the winner ", player2.name);
                }
                else
                {
                    printf("TIE\n");
                }
                printf("\nto main menu enter(1) \t to exit enter(2)\n");
                checkScan(2, &menu);
                if (menu == 1)
                {
                    system("cls");
                    main();
                }
                break;
            }
        }
    }
    //hard and 2 player
    if (secondPage == 2 && thirdPage == 2)
    {
        if (firstPage == 1)
            remainline = 60;
        int m = 12;
        seconds = time(NULL);
        leadboard(m);
        while (1)
        {
            int numOfRow, numOfColumn;
            printf("\n");
            printf("Write the needed row :  ");
            checkScan(m - 1, &numOfRow);
            printf("\n");
            printf("Write the needed column :  ");
            checkScan(m - 1, &numOfColumn);
            if (numOfColumn == 3 && numOfRow == 3)
            {
                system("cls");
                main();
                break;
            }
            else
            {
                game(numOfRow, numOfColumn, m);
            }

            if (player1.score + player2.score == 25)
            {
                if (player1.score > player2.score)
                {
                    savetop(player1.score, player1.name);
                    printf("CONGRATULATIONS! %s is the winner ", player1.name);
                }
                else if (player2.score > player1.score)
                {
                    savetop(player1.score, player1.name);
                    printf("CONGRATULATIONS! %s is the winner ", player2.name);
                }
                else
                {
                    printf("TIE\n");
                }
                printf("\nto main menu enter(1) \t to exit enter(2)\n");
                checkScan(2, &menu);
                if (menu == 1)
                {
                    system("cls");
                    main();
                }
                break;
            }
        }
    }
    if (secondPage == 1 && thirdPage == 1)
    {
        if (firstPage == 1)
            remainline = 12;
        int m = 6;
        seconds = time(NULL);
        leadboard(m);
        while (1)
        {
            int numOfRow, numOfColumn;
            if (totalmoves % 2 == 1)
            {
                printf("\n");
                printf("Write the needed row :  ");
                checkScan(m - 1, &numOfRow);
                printf("\n");
                printf("Write the needed column :  ");
                checkScan(m - 1, &numOfColumn);
                if (numOfColumn == 3 && numOfRow == 3)
                {
                    system("cls");
                    main();
                    break;
                }
                else
                {
                    gameOfcomputer(numOfRow, numOfColumn, m);
                }
            }
            else
            {
                for (int i = 1; i < m; i++)
                {
                    int x = 0;
                    for (int j = 1; j < m; j++)
                    {
                        if (i < m && j < m && arrayOfGame[i][j] == 0 && !(j % 2 == 0 && i % 2 == 0))
                        {
                            x = gameOfcomputer(i, j, m);
                            break;
                        }
                    }
                    if (x == 1)
                        break;
                }
            }
            if (player1.score + player3.score == 4)
            {
                if (player1.score > player3.score)
                {
                    savetop(player1.score, player1.name);

                    printf("CONGRATULATIONS! %s is the winner ", player1.name);
                }
                else if (player3.score > player1.score)
                {
                    printf("CONGRATULATIONS! %s is the winner ", player3.name);
                }
                else
                {
                    printf("TIE\n");
                }
                printf("\nto main menu enter(1) \t to exit enter(2)\n");
                checkScan(2, &menu);
                if (menu == 1)
                {
                    system("cls");
                    main();
                }
                break;
            }
        }
    }
    if (secondPage == 2 && thirdPage == 1)
    {

        if (firstPage == 1)
            remainline = 60;
        int m = 12;
        seconds = time(NULL);
        leadboard(m);
        while (1)
        {
            int numOfRow, numOfColumn;
            if (totalmoves % 2 == 1)
            {
                printf("\n");
                printf("Write the needed row :  ");
                checkScan(m - 1, &numOfRow);
                printf("\n");
                printf("Write the needed column :  ");
                checkScan(m - 1, &numOfColumn);
                if (numOfColumn == 3 && numOfRow == 3)
                {
                    system("cls");
                    main();
                    break;
                }
                else
                {
                    gameOfcomputer(numOfRow, numOfColumn, m);
                }
            }
            else
            {
                for (int i = 1; i < m; i++)
                {
                    int x = 0;
                    for (int j = 1; j < m; j++)
                    {
                        if (i < m && j < m && arrayOfGame[i][j] == 0 && !(j % 2 == 0 && i % 2 == 0))
                        {
                            x = gameOfcomputer(i, j, m);
                            break;
                        }
                    }
                    if (x == 1)
                        break;
                }
            }
            if (player1.score + player3.score == 25)
            {
                if (player1.score > player3.score)
                {
                    savetop(player1.score, player1.name);
                    printf("CONGRATULATIONS! %s is the winner\n ", player1.name);
                }
                else if (player3.score > player1.score)
                {
                    printf("CONGRATULATIONS! %s is the winner\n ", player3.name);
                }
                else
                {
                    printf("TIE\n");
                }
                printf("\n\nto main menu enter(1) \t to exit enter(2)\n");

                checkScan(2, &menu);
                if (menu == 1)
                {
                    system("cls");
                    main();
                }
                break;
            }
        }
    }
}

#endif
