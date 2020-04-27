//************************************************************************************************************************************
// 6 lab
//************************************************************************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <malloc.h>

void matrix();//this function randomly populates the matrix, searches for the maximum column, and displays all information on the screen
void start_info();
int check_int(char masage[],int min,int max);// validator for int with border

int main(void)
{
    start_info();
    int id;
    do {
        matrix();
        printf("0 - continue\n1 - exit\n");
        id = check_int("",0,1);
    }while(id == 0);
    printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\t\t\tgoodbye\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
}


void matrix()
{
    int row,stack;
    /*оголошуємо matr - указівник на масив указівників*/
    int **matr;
    /*arr - указівник на одновимірний масив*/
    int *arr;
    printf("Input row of  matrix : ");
    row = check_int(" min - 1, max - 10 ",1,10);
    printf("Input stack matrix : ");
    stack = check_int(" min - 1, max - 10 ",1,10);
    /*виділяємо пам'ять під одновимірний масив*/
    arr = (int *) malloc(row * sizeof(int));
    /*виділяємо пам'ять під масив указівників*/
    matr = (int **) malloc(sizeof(int *) * stack);
    srand(time(NULL));
    for (int i = 0; i < stack; i++) {
        /*виділяємо пам'ять під i-й рядок*/
        matr[i] = (int *) malloc(sizeof(int) * row);
        for (int j = 0; j < row; j++)
            matr[i][j] = rand() % 10;
    }
    
    for (int i = 0; i < stack; i++)     // 
    {                                   //
        printf("(");                    //
        for (int j = 0; j < row; j++)   //
        {                               //  here print all matrix
            printf(" %d ", matr[i][j]); //
        }                               //
        printf(")\n");                  //
    }

    int temp = 0;                               //  <-
    int max = NULL;                             //  <-  var-helpers
    int res = 0;                                //  <- 
    for(int i = 0; i < row; i++)                //
    {                                           //
        for(int j = 0; j < stack; j++)          //
        {                                       //  
            res += matr[j][i];                  //  <- here find all colums
        }                                       //  
        printf("#%d - %d \n",i+1,res);          //  <- print all colums
        if(res > max)                           //
        {                                       //
            temp = i;                           //
            max = res;                          //  < - and max colums
        }                                       //
        res = 0;                                //
    }                                           //
    printf("max row #%d = %d\n",temp+1,max);    //  <- print max colums

    for(int i = 0; i < stack; i++)
    {
        /*вивільняємо пам'ять i-го рядка*/
        free(matr[i]);
    }
    /*вивільняємо пам'ять масиву вказівників*/
    free(matr);
    /*вивільняємо пам'ять масиву сум*/
    free(arr);
}

void start_info()
{
    printf("---------------------------------------------------------------------------------\n|\t\t\t\t\tlab 6\t\t\t\t\t|\n|\t\t\t\tTema: dynamic memory\t\t\t\t|\n|Korets Sasha\t\t\t\t\t\t\t\tKM - 92 |\n|\t\t\t\t     variat - 4 \t\t\t\t|\n---------------------------------------------------------------------------------\npress enter to continue ...\n");
    while ((getchar()) != '\n');
}

int check_int(char masage[],int min,int max)
{
    printf("%s", masage);
    char input[20];
    short int isInt = 0; //we use int as a boolean value;
    do
    {
        scanf("%s", &input);

        for (int count = 0; input[count] != '\0'; count++)
        {
            if (isdigit(input[count]))
            {
                isInt = 1;
            }
            else
            {
                isInt = 0;
                break;
            }
        }
        if (isInt == 0 || (atoi(input)) < min || (atoi(input)) > max)
        {
            printf("no jokes please : ");
        }
    } while (isInt == 0 || (atoi(input)) < min || (atoi(input)) > max );

    return atoi(input);
}
