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

float check_positive_float(char msg[])
{
    float input, temp, status;
    printf("%s", msg);
    status = scanf("%f", &input);
    while (status != 1 || input <= 0) // delete "|| input <= 0" --> all float
    {
        while ((temp = getchar()) != EOF && temp != '\n')
            ;
        printf("Invalid input...Please enter a number: ");
        status = scanf("%f", &input);
    }
    return input;
}
float check_float(char msg[])
{
    float input, temp, status;
    printf("%s", msg);
    status = scanf("%f", &input);
    while (status != 1)
    {
        printf("Invalid input...Please enter a number: ");
        status = scanf("%f", &input);
    }
    return input;
}

float high_paralelepiped()
{
    int i;
    float a[3], high = 0;
    for (i = 0; i < 3; i++)
    {
        printf("input side %d : ", i + 1);
        a[i] = check_positive_float("");
        if (high < a[i])
        {
            high = a[i];
        }
        else
        {
            continue;
        }
    }
    return high;
}
float length_x_y()
{
    float x1, y1, x2, y2; 
    x1 = check_float("x1 : ");
    x2 = check_float("x2 : ");
    y1 = check_float("y1 : ");
    y2 = check_float("y2 : ");
    return sqrt(((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}
// unsigned int check_hex()
// {
//     unsigned int input;
//     do
//     {
//         scanf("%04x", &input);
//         if ((input & 0xFF00) == ((unsigned int)0xE2) << 8 || (input & 0xFF00) == ((unsigned int)0xE3) << 8)
//         {
//             return input;
//             printf("oley");
//         }
//         else
//         {
//             printf("\ntry again : ");
//         }
//     } while (1);
// }
int in(void)
{
    char d;                     /*napriamok peredachi*/
    char r;                     /*first registr*/
    char a;                     /*link on next registr*/
    unsigned int UnitStateWord; /*слово стану*/
    /*уведення складових частин*/
    printf("input napriamok peredachi (0-1): ");
    d = check_int("");
    while (d != 0 && d != 1)
    {
        printf("try again : ");
        d = check_int("");
    }
    printf("input first registr (0-15): ");
    r = check_int("");
    while (r != 0 && r != 1 && r != 2 && r != 3 && r != 4 && r != 5 && r != 6 && r != 7 && r != 8 && r != 9 && r != 10 && r != 11 && r != 12 && r != 13 && r != 14 && r != 15)
    {
        printf("try again : ");
        r = check_int("");
    }
    printf("input link on next registr (0-15): ");
    a = check_int("");
    while (r != 0 && r != 1 && r != 2 && r != 3 && r != 4 && r != 5 && r != 6 && r != 7 && r != 8 && r != 9 && r != 10 && r != 11 && r != 12 && r != 13 && r != 14 && r != 15)
    {
        printf("try again : ");
        a = check_int("");
    }
    /*формування упакованого коду*/
    UnitStateWord = (unsigned int)0xE2 << 8;
    UnitStateWord |= ((unsigned int)d & 1) << 8;
    UnitStateWord |= ((unsigned int)r & 0x0F) << 4;
    UnitStateWord |= ((unsigned int)a & 0x0F);
    /*виведення результату*/
    printf("\n\n\n------------------------------\n");
    printf("\nstatus device  = %04x\n", UnitStateWord);
    printf("\n------------------------------\n\n\n");
}

int out(void)
{
    char d;                     /*napriamok peredachi*/
    char r;                     /*first redister*/
    char a;                     /*link on next redister*/
    unsigned int UnitStateWord; /*слово стану*/
    /*уведення слова стану пристрою*/
    printf("input status device\n");
    printf("(HEX-number from e200 to e3ff): ");
    //scanf("%x", &UnitStateWord);
    scanf("%04x", &UnitStateWord);
    /*виділення складових частин*/
    d = (UnitStateWord >> 8) & 0001;
    r = (UnitStateWord >> 4) & 0x0F;
    //b = (UnitStateWord >> 8) & 1;
    a = UnitStateWord & 0x0F;
    /*виведення результатів*/
    putchar('\n');
    printf("\n\n\n------------------------------\n");
    printf("napriamok peredachi = %d\n", d);
    printf("first redister = %d\n", r);
    printf("link on next redister= %d", a);
    printf("\n------------------------------\n\n\n");
}

int main(void)
{
    int id_first_level;
    int id_second_level;
    system("clear");
    printf("-----------------\n|Korets Sasha\t|\n|KM - 92\t|\n|variat - 4\t|\n-----------------\n");

    while (1)
    {
        printf("-----------------\n|1 - first task\t|\n|2 - second task|\n|3 - third task\t|\n|other - exit\t|\n-----------------\n");
        scanf("%d", &id_first_level);
        if (id_first_level == 1)
        {
            system("clear");
            printf("\n\n\n----------------------------\n");
            printf("find high of paralelepiped : \n");
            printf("%f", high_paralelepiped());
            printf("\n----------------------------\n\n\n");
        }
        else if (id_first_level == 2)
        {
            system("clear");
            printf("\n\n\n---------------------------------------\n");
            printf("lenght betwen M1(x1;y1) and M2(x2;y2) : \n");
            printf("%f\n", length_x_y());
            printf("---------------------------------------\n\n\n");
        }
        else if (id_first_level == 3)
        {
            while (1)
            {
                printf("**********************\n1 - create data stucte\n2 - use data stucte\nother - exit\n**********************\n");
                scanf("%d", &id_second_level);
                if (id_second_level == 1)
                {
                    system("clear");
                    in();
                    getchar();
                }
                else if (id_second_level == 2)
                {
                    system("clear");
                    out();
                }
                else
                {
                    system("clear");
                    break;
                }
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