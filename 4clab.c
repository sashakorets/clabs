#include <stdlib.h>
#include <stdio.h>
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
    float input, temp, status;
    printf("%s", msg);
    status = scanf("%f", &input);
    while (status != 1)
    {
        while ((temp = getchar()) != EOF && temp != '\n')
            ;
        printf("Invalid input...Please enter a number: ");
        status = scanf("%f", &input);
    }
    return input;
}

void f_f_task()
{
    int kil;
    float num = check_float("input ur num : ");
    scanf("%d", &kil);
    printf("%.*f\n", num, kil);
}

void f_s_task(n)
{
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

void main()
{
    int id_first_level;
    int id_second_level;
    system("clear");
    printf("---------------------------------------------------------------------------------\n|\t\t\t\t\tlab 4\t\t\t\t\t|\n|\t\t\ttheme: Pointers, functions, recursion\t\t\t|\n|Korets Sasha\t\t\t\t\t\t\t\tKM - 92 |\n|\t\t\t\t     variat - 4 \t\t\t\t|\n---------------------------------------------------------------------------------\npress any button ...\n");
    getchar();
    system("clear");
    while (1)
    {
        printf("-------------------------\n|1 - simple func\t|\n|2 -recursion func\t|\n|other - exit\t\t|\n-------------------------\n");
        scanf("%d", &id_first_level);
        if (id_first_level == 1)
        {
            while (1)
            {
                printf("\n**********************\n1 - round Q-num\n2 - find the divisors\nother - exit\n**********************\n");
                scanf("%d", &id_second_level);
                if (id_second_level == 1)
                {
                    f_f_task();
                }
                else if (id_second_level == 2)
                {
                    int num = check_int("");
                    f_s_task(num);
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
            char str[128];
            scanf("%s", &str); //lim 127, no use tab,spase
            printf("%d\n", recLen(str));
        }
        else
        {
            system("clear");
            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\t\t\tgoodbye\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            break;
        }
    }
}