#ifndef RANK_H_INCLUDED
#define RANK_H_INCLUDED
#include "rank.h"
#include "write.h"
#include<string.h>
int topIndex=0;


typedef struct play{
    char name[100];
    int score;
}Top;
Top TopTen[30];
void sortTop(){
    for (int i=0;i<topIndex;i++){
        for(int j=i+1;j<topIndex;j++){
                if (TopTen[i].score<TopTen[j].score){
                        TopTen[29]=TopTen[i];
                        TopTen[i]=TopTen[j];
                        TopTen[j]=TopTen[29];
                }
        }
    }
}
void loadTop()
    {
        FILE *topT;
        topT=fopen("Top.bin","rb");
        for( topIndex=0;topIndex<30;topIndex++){
            fscanf(topT,"%s\n",&TopTen[topIndex].name);
            fscanf(topT,"%d\n",&TopTen[topIndex].score);
        }
        fclose(topT);
    }
void getRank(){
    loadTop();
    sortTop();
    for(int i=0;i<10;i++){
            printf("\t\t\t\t\t\t%2d \t%2d\t%s\n",i+1,TopTen[i].score,TopTen[i].name);
    }
}

void savetop(int score,char a[100]){
    FILE *topT;
    topT=fopen("Top.bin","ab");
    fprintf(topT,"%s\n",a);
    fprintf(topT,"%d\n",score);
    fclose(topT);
}
#endif // RANK_H_INCLUDED
