#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void n_func(char word[])
{
    for (int i = 0; i < strlen(word); i++)
    {
        if (&word[i] != strrchr(word, word[i]))
        {
            printf("|_____|\n");
            break;
        }
        else if (i == (strlen(word) - 1))
        {
            printf("%s\n", word);
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
