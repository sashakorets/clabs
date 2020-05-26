// 8 lab

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    F,
    T
} boolean;

typedef struct PASIANT
{
    char PIB[50];
    char adres[20];
    int Number;
    boolean Status;
} PASIANT;

void inFile(char NameFile[50], PASIANT arr[], int len);
void inputStract(char NameFile[50]);

void outFile(char name[50]);
void cpF2toF1(char Name1[50], char Name2[50], int n);

void main()
{
    FILE *f = fopen("NoName.txt", "a+");
    for (int i = 0; i < 4; i++)
    {
        fputs("k1", f);
        fputs("\n", f);
    }
    fclose(f);
    outFile("NoName.txt");

    printf("*******\n");

    inputStract("NoName.txt");
    //cpF2toF1("NoNameTest.txt", "NoName.txt", 3);
    //outFile("NoNameTest.txt");
}

void outFile(char name[50])
{
    //несхотів юзати динамічну пам'ять, гадаю 2048 символів вистачить щоб записати файл із невеликої лаби
    FILE *f = fopen(name, "r");
    char buffer[2048];
    while (fgets(buffer, 127, f) != NULL)
    {

        // Print the dataToBeRead
        printf("%s", buffer);
    }
    fclose(f);
}

void cpF2toF1(char Name1[50], char Name2[50], int n)
{
    FILE *f1 = fopen(Name1, "a+");
    FILE *f2 = fopen(Name2, "a+");
    int i = 0;
    char ch;
    while ((ch = getc(f2)) != EOF)
    {
        if (i >= n)
        {
            putc(ch, f1);
        }
        i++;
    }
    fclose(f1);
    fclose(f2);
}

void inFile(char NameFile[50], PASIANT arr[], int len)
{
    FILE *f = fopen(NameFile, "a+");
    for (int i = 0; i < len; i++)
    {
        fputs(arr[i].PIB, f);
        fputs(arr[i].adres, f);
        //fputs(itoa(arr[i].Number), f);
    }
    fclose(f);
}

void inputStract(char NameFile[50])
{
    PASIANT array[16];
    int i = 0;
    char flag = '1';
    while (flag == '1')
    {
        printf("input PIB like KoretsOM\n");
        scanf("%s", array[i].PIB);
        printf("input adres like LesiUkr8\n");
        scanf("%s", array[i].adres);
        printf("input number ur medicin cart\n");
        scanf("%d", array[i].Number);
        array[i].Status = F;
        // printf("input statuc F or T\n");
        // scanf("%c", array[i].Status);
        printf("go - 1, other - exit\n");
        scanf("%c", &flag);
        i++;
    }
    inFile(NameFile, array, i);
}
