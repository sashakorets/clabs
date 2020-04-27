
//************************************************************************************************************************************
// 4 lab
//************************************************************************************************************************************
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int check_int(char masage[])
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
        if (isInt == 0)
        {
            printf("no jokes please : ");
        }
    } while (isInt == 0);

    return atoi(input);
}

float check_float(char msg[])
{
    printf("%s", msg);
    char input[20];
    short int isFloat = 0; //we use int as a boolean value;
    short int is2point = 0; //we use int as a boolean value;
    do
    {
        scanf("%s", &input);

        for (int count = 0; input[count] != '\0'; count++)
        {
            if (isdigit(input[count]) || input[count] == '.' && is2point!=2 )
            {
                isFloat = 1;
                if(input[count] == '.')
                {
                    is2point++;
                }
            }
            else
            {
                is2point = 0;
                isFloat = 0;
                break;
            }
        }
        if (isFloat == 0 || is2point ==2)
        {
            printf("no jokes please : ");
        }
    } while (isFloat == 0 || is2point >= 2);

    return atof(input);
}

void f_f_task()
{
    float num = check_float("input float num : ");
    int kil = check_int("input the number of decimal places");
    printf("%.*f\n", kil, num);
}

void f_s_task()
{
    int n = 0;
    while( n == 0 )
    {
        n = check_int("input natural num");
    }
    // function to print the divisors
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            printf("%d ", i);
}

int recLen(char *str)
{
    // if we reach at the end of the string
    if (*str == '\0')
        return 0;
    else
        return 1 + recLen(str + 1);
}

int main(void)
{
    char id;
    printf("---------------------------------------------------------------------------------\n|\t\t\t\t\tlab 4\t\t\t\t\t|\n|\t\t\ttheme: Pointers, functions, recursion\t\t\t|\n|Korets Sasha\t\t\t\t\t\t\t\tKM - 92 |\n|\t\t\t\t     variat - 4 \t\t\t\t|\n---------------------------------------------------------------------------------\npress enter ...\n");
    while ((getchar()) != '\n');
    while (1)
    {
        printf("\n**********************\n1 - round Q-num\n2 - find the divisors\n3 - lenght of text\nother - exit\n**********************\n");
        do
        {
            id = getchar();
        }while(id =='\n');

        while ((getchar()) != '\n');
        if (id == '1')
        {
            f_f_task();
        }
        else if (id == '2')
        {
            f_s_task();
        }
        else if (id == '3')
        {
            char str[128];
            printf("input test, max 127 characters\n");
            gets(str);   //scanf("%s", &str); //lim 127
            printf("%d\n", recLen(str));
        }
        else
        {
            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\t\t\tgoodbye\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            break;
        }
    }
}
