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

void main()
{
    char word[] = "we have text on condition";
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
