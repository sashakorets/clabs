************************************************************************************************************************************
 5 lab
************************************************************************************************************************************
 #include<malloc.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct AEROFLOT
{
    char destination[16];
    int flight_number;
    char type_plane[16];
} AEROFLOT;

#define SIZE 5  // defolt len of array

//main func in this lab
int swap(AEROFLOT *x , AEROFLOT *y );   //this func help to sort
int bubbleSort(AEROFLOT arr[], int len);  // sort from low to high
void find_plane(AEROFLOT arr[], int len, char key[]);
void inputArray(AEROFLOT arr[],int  len);
void printArray(AEROFLOT arr[],int  len);

//func-helpers
int check_int(char masage[]);
void start_info();

int main(void)
{
    char key[128];
    char  j_var ;
    AEROFLOT arr[SIZE];
    start_info();
    printf("\nenter %d elements of the structure *AEROFLOT* \n",SIZE);
    inputArray(arr, SIZE);
    //system("cls");
    do
    {
    printf("\nf - print all element \ns - find the element by key\ne - exit\n");
    scanf("%s",&j_var);
    if (j_var == 'f' )
    {
        bubbleSort(arr, SIZE);
        printArray(arr, SIZE);
    }
    else if(j_var == 's')
    {
        printf("\nenter key :");
        scanf("%s",&key);
        find_plane(arr, SIZE, key);
    }
    else {
        printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\t\t\tgoodbye\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        break;
    }
    }while(1);
}

int check_int(char masage[])
{
    printf("%s", masage);
    char input[20];
    short int isInt = 0; //we use int as a boolean value;
    int count;
    do
    {
        scanf("%s", &input);

        for (count = 0; input[count] != '\0'; count++)
        {
            if (isdigit(input[count])) //you should include ctype.h at the beginning of this program
            {
                isInt = 1;
            }
            else
            {
                isInt = 0;
                break;
            }
        }
        if (isInt == 0)
        {
            printf("no jokes please : ");
        }
    } while (isInt == 0);

    return atoi(input);
}

void start_info()
{
    printf("---------------------------------------------------------------------------------\n|\t\t\t\t\tlab 5\t\t\t\t\t|\n|\t\t\tTema: Typy danykh, vyznacheni korystuvachem\t\t|\n|Korets Sasha\t\t\t\t\t\t\t\tKM - 92 |\n|\t\t\t\t     variat - 4 \t\t\t\t|\n---------------------------------------------------------------------------------\npress any button ...\n");
    getchar();
    printf("----------------------------\nWe have struct *AEROFLOT*\n\tchar destination[16];\n\tint flight_number;\n\tchar type_plane[16];\n-----------------------------\npress any button ...");
    getchar();
}

void inputArray(AEROFLOT arr[],int  len)
{
    for (int i = 0; i < len; i++)
    {
        printf("\n\ninput destination :");
        scanf("%s",arr[i].destination);
        printf("input flight number :");
        arr[i].flight_number = check_int("");
        printf("input type plane :");
        scanf("%s",arr[i].type_plane);
    }
}

void printArray(AEROFLOT arr[], int len)
{
    printf("\n\n\n#\tdestination\tflight number\ttype plane\n--------------------------------------------------");
    for (int i = 0; i < len; i++)
    {
        printf("\n%d\t%s\t\t%d\t\t%s", i + 1, arr[i].destination, arr[i].flight_number, arr[i].type_plane);
    }
    printf("\n--------------------------------------------------\n\n\n");
}

int swap(AEROFLOT *x , AEROFLOT *y )
{
    AEROFLOT temp = *x ;
    *x  = *y ;
    *y  = temp;
}

int bubbleSort(AEROFLOT arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j].flight_number > arr[j + 1].flight_number)
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

void find_plane(AEROFLOT arr[],int len, char key[])
{
    int tiva = 0;
    for(int i = 0; i < len ; i++)
    {
        if ( !strcmp(key,arr[i].destination) )
        {
            printf("\n\n\n#\tdestination\tflight number\ttype plane\n--------------------------------------------------");
            printf("\n%d\t%s\t\t%d\t\t%s", i + 1, arr[i].destination, arr[i].flight_number, arr[i].type_plane);
            printf("\n--------------------------------------------------\n\n\n");
            tiva++;
        }
    }
    if (!tiva)
    {
        printf("\nNo found , sorry :( \n\n\n");
    }

}
