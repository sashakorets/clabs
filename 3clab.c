#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lower_string(char *string)
{
    while (*string)
    {
        if (*string >= 'A' && *string <= 'Z')
        {
            *string = *string + 32;
        }
        string++;
    }
}

void n_func(char input[])
{
    char word[128];
    strcpy(word, input);
    lower_string(word);
    for (int i = 0; i < strlen(word); i++)
    {
        if (&word[i] != strrchr(word, word[i]))
        {
            printf("|_____|\n");
            break;
        }
        else if (i == (strlen(word) - 1))
        {
            printf("%s\n", input);
        }
    }
}
void f_task(char word[])
{
    char s_t_a[128] = {};
    int k = 0;
    for (int i = 0; i <= strlen(word); i++)
    {
        if (word[i] != ' ' && word[i] != '\0')
        {
            s_t_a[k] = word[i];
            k++;
        }
        else
        {
            n_func(s_t_a);
            k = 0;
            memset(s_t_a, 0, sizeof(s_t_a));
        }
    }
}

void main()
{
    system("clear");
    printf("---------------------------------------------------------------------------------\n|\t\t\t\t\tlab 3\t\t\t\t\t|\n|\t\t\ttheme: Symbolic data processing\t\t\t\t|\n|Korets Sasha\t\t\t\t\t\t\t\tKM - 92 |\n|\t\t\t\t     variat - 4 \t\t\t\t|\n---------------------------------------------------------------------------------\npress any button ...\n");
    getchar();
    system("clear");
    char word[] = "q qwe  swad  zcxc qwz"; // limit 127 characters
    f_task(word);
}
