#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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
            if (isdigit(input[count]) || input[0] == '-') //you should include ctype.h at the beginning of this program
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
int int_with_random(char masage[], int variant)
{
    if (variant == 1)
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
                if (isdigit(input[count]) || input[0] == '-') //you should include ctype.h at the beginning of this program
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
        //printf("Ur num : %s\n", input);
        return atoi(input);
    }
    else if (variant == 0)
    {
        int r = rand() % 10;
        int znak = rand() % 2;
        if (znak == 1)
        {
            //printf("Ur num : %d\n", r);
            return r;
        }
        else
        {
            //printf("Ur num : %d\n", r * -1);
            return r * (-1);
        }
    }
}
int positive_int_with_random(char masage[], int variant)
{
    if (variant == 1)
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
                if (isdigit(input[count]) && (atoi(input)) > 0) //you should include ctype.h at the beginning of this program
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
        //printf("Ur num : %s\n", input);
        return atoi(input);
    }
    else if (variant == 0)
    {
        int res;
        do
        {
            res = rand() % 10;
        } while (res == 0);
        //printf("Ur num : %d\n", res);
        return res;
    }
}
void printArray(int n, int arr[])
{
    for (int i = 0; i < n; i++)
        printf("%d   ", arr[i]);
    printf("\n");
}
int max_element(int n, int arr[n])
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
int min_element(int n, int arr[n])
{
    int min = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}
void f_f_task(int var)
{
    int i;
    int n = positive_int_with_random("input lengh first A[] : ", var);
    //check_int("input lengh first A[] : ");
    int A[n];
    for (i = 0; i < n; i++)
    {
        A[i] = int_with_random("input element of first array : ", var);
    }
    int m = positive_int_with_random("input lengh of second B[] : ", var);
    int B[m];
    for (i = 0; i < m; i++)
    {
        B[i] = int_with_random("input element of second array : ", var);
    }
    printArray(n, A);
    printArray(m, B);

    // printf("\n%d", max_element(n, A));
    // printf("\n%d", min_element(m, B));
    //system("clear");
    printf("multiplate max element of first array and min element of second array : %d\n\n\n", (max_element(n, A) * min_element(m, B)));
}

void ExchangeSort(int n, int num[n])
{
    int i, j;
    int temp; // holding variable
    int numLength = n;
    for (i = 0; i < (numLength - 1); i++) // element to be compared
    {
        for (j = (i + 1); j < numLength; j++) // rest of the elements
        {
            if (num[i] < num[j]) // descending order
            {
                temp = num[i]; // swap
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    printArray(n, num);
}
void f_s_task(int var)
{
    int i;
    int n = positive_int_with_random("input lengh array A[] : ", var);
    int A[n];
    for (i = 0; i < n; i++)
    {
        A[i] = int_with_random("input element array : ", var);
    }
    system("clear");
    printArray(n, A);
    printf("- old\n\n");
    ExchangeSort(n, A);
    printf("- new\n\n");
}
int matrix(var)
{
    int ROW = positive_int_with_random("input row of mat : ", var), STACK = positive_int_with_random("input stack of mat : ", var);
    int i, j, cof = 0;
    int A[ROW][STACK];
    int res = 0;
    for (i = 1; i < STACK; i++)
    {
        for (j = 0; j < ROW && i < STACK; j++)
        {
            //scanf("%d", &A[j][i]);
            A[j][i] = int_with_random("input element of mat : ", var);
            cof++;
            i++;
        }
        i -= cof;
        cof = 0;
    }
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < STACK && i < ROW; j++)
        {
            A[i][j] = 0;
            cof++;
            i++;
        }
        i -= cof;
        cof = 0;
    }
    for (i = 0; i < ROW; i++)
    {
        printf("(");
        for (j = 0; j < STACK; j++)
        {
            printf(" %d ", A[i][j]);
        }
        printf(")\n");
    }
    for (i = 1; i < STACK; i++)
    {
        for (j = 0; j < ROW && i < STACK; j++)
        {
            if (A[j][i] == 0)
            {
                res++;
            }
            cof++;
            i++;
        }
        i -= cof;
        cof = 0;
    }
    printf("element wit value '0' up of main diagonal : %d\n", res);
}
void main()
{
    int id_first_level;
    int id_second_level;
    system("clear");
    printf("-----------------\n|Korets Sasha\t|\n|KM - 92\t|\n|variat - 4\t|\n-----------------\n");

    while (1)
    {
        printf("-------------------------\n|1 - work with vectors\t|\n|2 - work with matrixs\t|\n|other - exit\t\t|\n-------------------------\n");
        scanf("%d", &id_first_level);
        if (id_first_level == 1)
        {
            while (1)
            {
                printf("\n**********************\n1 - multiplace max elements of first array and min element second array\n2 - sorted array\nother - exit\n**********************\n");
                scanf("%d", &id_second_level);
                if (id_second_level == 1)
                {
                    int same_time_var1;
                    system("clear");
                    printf("1 - use hands\n0 - random\nother - break\n");
                    scanf("%d", &same_time_var1);
                    if (same_time_var1 == 1)
                    {
                        system("clear");
                        f_f_task(1);
                    }
                    else if (same_time_var1 == 0)
                    {
                        system("clear");
                        f_f_task(0);
                    }
                    else
                    {
                        system("clear");
                        break;
                    }
                }
                else if (id_second_level == 2)
                {
                    int same_time_var2;
                    system("clear");
                    printf("1 - use hands\n0 - random\nother - break\n");
                    scanf("%d", &same_time_var2);
                    if (same_time_var2 == 1)
                    {
                        system("clear");
                        f_s_task(1);
                    }
                    else if (same_time_var2 == 0)
                    {
                        system("clear");
                        f_s_task(0);
                    }
                    else
                    {
                        system("clear");
                        break;
                    }
                }
                else
                {
                    system("clear");
                    break;
                }
            }
        }
        else if (id_first_level == 2)
        {
            int same_time_var3;
            system("clear");
            printf("1 - use hands\n0 - random\nother - break\n");
            scanf("%d", &same_time_var3);
            if (same_time_var3 == 1)
            {
                system("clear");
                printf("\n\n\n----------------------------\n");
                matrix(1);
                printf("\n----------------------------\n\n\n");
            }
            else if (same_time_var3 == 0)
            {
                system("clear");
                printf("\n\n\n----------------------------\n");
                matrix(0);
                printf("\n----------------------------\n\n\n");
            }
            else
            {
                system("clear");
                break;
            }
        }
        else
        {
            system("clear");
            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\t\t\tgoodbye\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            break;
        }
    }
}