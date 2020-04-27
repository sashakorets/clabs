#include <stdio.h>
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
    // this function checks the repetition of letters
    char word[128];
    strcpy(word, input);
    lower_string(word);
    for (int i = 0; i < strlen(word); i++)
    {
        if (&word[i] != strrchr(word, word[i]))
        {
            printf("the same symbol is repeated twice in this word\n");
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
    // this function breaks the text into words
    char s_t_a[128];
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

int main(void)
{
    printf("---------------------------------------------------------------------------------\n|\t\t\t\t\tlab 3\t\t\t\t\t|\n|\t\t\ttheme: Symbolic data processing\t\t\t\t|\n|Korets Sasha\t\t\t\t\t\t\t\tKM - 92 |\n|\t\t\t\t     variat - 4 \t\t\t\t|\n---------------------------------------------------------------------------------\npress any button ...\n");
                                        // at the top of the start information
    do
    {
        while ((getchar()) != '\n');        // clear buffer
        char word[128];                     // limit 127 characters
        printf("input ur text\n");
        gets(word);                         // ur input
        f_task(word);// go to see fucn
        printf("\n\n\ngo try again\n");
    }while(1);
}
