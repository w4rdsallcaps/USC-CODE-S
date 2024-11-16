#include <stdio.h>
#include<windows.h>

    //define module
    int ouputMatrix(int num[5][6]);

int main(void)
{
    //declare num with rows 6 col 5
    int num[5][6];
    //loop rows
    for(int i = 0; i < 5 ;i++){
            //loop for coloums
            for(int j = 0; j < 6;j++){
            //for value on that adress
            printf("give me a number for (%d,%d): ",i,j);
            scanf("%d", &num[i][j]);
            }
    }
    //input the function for output/display function
    outputMatrix(num);

    return 0;
}


int outputMatrix(int num[5][6]){
    //print a dot
    printf(".\t");
        //print adress cols
        for(int i = 0; i < 6;i++){
        printf("%d\t",i);
        Sleep(2000);
        }
        printf("\n");
        //printf  adress rows and space
        for(int i = 0; i < 5;i++){
            printf("\n\n");
            printf("%d",i);
            Sleep(2000);
            //print the numbers
            for(int j = 0; j < 6;j++){
                printf("\t%d",num[i][j]);
                Sleep(2000);
            }
        printf("\n");
        }
}


