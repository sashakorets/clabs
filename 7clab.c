// lab 7
#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct AEROFLOT
{
    char destination[16];
    int flight_number;
    char type_plane[16];
    struct AEROFLOT *next;
} AEROFLOT;

struct AEROFLOT *enter_element(int i);
/*функція створення списку*/
struct AEROFLOT *create(void);
/*функція перегляду списку*/
void show(AEROFLOT *head);
/*глобальна змінна – адреса голови списку*/
struct AEROFLOT *head = NULL;
// функція додавання елементу у список структур
struct AEROLFOT *element_add(struct AEROFLOT *head);
// функція видалення елементу зі списку структур
struct AEROFLOT *element_del(struct AEROFLOT *head);
// сортування за часом відправлення
void sort(struct AEROFLOT *head);
// Перше завдання (структури)
void first_task();
//...
void free_struct(AEROFLOT *head);

void second_task();

int check_int(char masage[]);
void start_info();

int main(void)
{
    start_info();
    int a = 3;
    while (a != 0)
    {
        printf("\nTo work with structures, enter 1. \nTo work with simple linked list, enter 2. \nTo exit enter 0.\n");
        a = check_int("");
        if (a == 1)
            first_task();
        else if (a == 2)
            second_task();
    }
    printf("\nGoodbye!\n");
    free_struct(head);
    return 0;
}

void start_info()
{

    printf("---------------------------------------------------------------------------------\n|\t\t\t\t\tlab 7\t\t\t\t\t|\n|\t\t\t\tTema: linker list\t\t\t\t|\n|Korets Sasha\t\t\t\t\t\t\t\tKM - 92 |\n|\t\t\t\t     variat - 4 \t\t\t\t|\n---------------------------------------------------------------------------------\npress enter to continue ...\n");
    while ((getchar()) != '\n')
        ;
}

struct AEROFLOT *create(void)
{
    int n;
    if (head != NULL)
    {
        printf("\n\nWARNING! The list of structures is not empty. Do you want to clear it?\n1 - Yes. 2 - no.\n\n");
        n = check_int("");

        if (n == 1)
        {
            free(head);
        }
        else
        {
            printf("\nThe list of structures already exists.\n");
            return head;
        }
    }

    int a = 1;
    int i = 0;

    struct AEROFLOT *p, *previous;
    head = previous = p = enter_element(i);

    i++;

    printf("\n\nFinish entering - 0. Continue - any other number.\n");
    a = check_int("");

    while (a != 0)
    {
        p = enter_element(i);
        previous->next = p;
        previous = p;
        printf("\n\nFinish entering - 0. Continue - any other number.\n");
        a = check_int("");
        i++;
    }

    return head;
}

void free_struct(AEROFLOT *head)
{
    AEROFLOT *p;

    while (head)
    {
        p = head;
        head = head->next;
        free(p);
    }
}

void show(AEROFLOT *head)
{
    if (head == NULL)
    {
        printf("\n\n    The list is empty!\n\n");
        return;
    }
    AEROFLOT *p;
    p = head;
    int i = 1;
    printf("\n\n\n#\tdestination\tflight number\ttype plane\n--------------------------------------------------");
    do
    {
        /*поки не кінець списку*/
        printf("\n%d\t%s\t\t%d\t\t%s", i, p->destination, p->flight_number, p->type_plane);
        /*просування за списком*/
        i++;
        p = p->next;
    } while (p != NULL);
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

int len_struct(AEROFLOT *head)
{
    AEROFLOT *p = head;
    int k = 0;
    while (p != NULL)
    {
        k++;
        p = p->next;
    }
    return k;
}
struct AEROFLOT *enter_element(int i)
{
    AEROFLOT *p;
    p = (AEROFLOT *)malloc(sizeof(AEROFLOT));

    printf("\n\nNote №%d.", i + 1);

    printf("\ninput destination :");
    scanf("%s", p->destination);
    printf("input flight number :");
    p->flight_number = check_int("");
    printf("input type plane :");
    scanf("%s", p->type_plane);

    return p;
}

// функція додавання елементу у список структур
struct AEROLFOT *element_add(struct AEROFLOT *head)
{
    int n, el_n;

    int m;
    m = len_struct(head);

    int key;

    if (head == NULL)
    {
        printf("\n   The list is empty!\n    The item will be added to the beginning of the list.\n\n");
        head = enter_element(0);
        head->next = NULL;
        return head;
    }

    struct AEROFLOT *tmp = head;
    struct AEROFLOT *tmp_nxt = tmp->next;
    struct AEROFLOT *p = enter_element(m);

    printf("\nWhere to add an item?\n1 - to the beginning.\n2 - to the end.\n3 - after the item by number.\n4 - after the item by key.\n\nIf you enter any other number, the item will not be added to the list of structures.\n");
    n = check_int("");

    switch (n)
    {
        case 1:
            head = p;
            p->next = tmp;
            break;
        case 2:
            while (tmp->next != NULL)
            {
                tmp = tmp->next;
            }
            tmp->next = p;
            p->next = NULL;
            break;
        case 3:
            printf("\nEnter the number after which to add the item.\n");
            el_n = check_int("");
            int i = 0;
            if (el_n <= 0 || el_n > m)
            {
                printf("\nYou are out of the list, the item will not be added.\n");
                break;
            }
            i = 1;
            while (i < el_n)
            {
                tmp = tmp->next;
                i++;
            }
            tmp_nxt = tmp->next;
            tmp->next = p;
            p->next = tmp_nxt;
            break;
        case 4:
            printf("\nEnter the AEROFLOT number after which you want to add the item.\n");

            key = check_int("");

            bool success = false;
            while (tmp != NULL)
            {
                if (tmp->flight_number == key)
                {
                    tmp_nxt = tmp->next;
                    tmp->next = p;
                    p->next = tmp_nxt;
                    success = true;
                    break;
                }
                tmp = tmp->next;
            }
            if (success == false)
                printf("There is no such number in the list!");
            break;
        default:
            printf("\nItem not added.\n");
    }

    return head;
}

// функція видалення елементу зі списку структур
struct AEROFLOT *element_del(struct AEROFLOT *head)
{
    if (head == NULL)
    {
        printf("\n    The list is empty!\n\n");
        return head;
    }

    struct AEROFLOT *head_nxt = head->next;
    struct AEROFLOT *tmp = head;
    struct AEROFLOT *tmp_nxt = tmp->next;
    struct AEROFLOT *prev;

    int num;
    int i = 1;
    int arr_n = len_struct(head);

    int key;

    int a;
    printf("\nWhere to delete an item? \n1 - from the beginning.\n2 - from the end.\n3 - by the number.\n4 - by the key.\n\nУ If you enter any other number, the item will not be deleted from the list of structures. \n\n");
    a = check_int("");

    bool key_exist = false;

    switch (a)
    {
        case 1:
            head = head_nxt;
            break;
        case 2:
            while ((tmp->next)->next != NULL)
                tmp = tmp->next;
            tmp->next = NULL;
            break;
        case 3:
            printf("\nEnter the number of the item you want to delete in the list of structures.\n");
            num = check_int("");

            if (num <= 0 || num > arr_n)
                printf("\nSuch a number does not exist in the list. \n");
            else
            {
                if (num == 1)
                {
                    free(head->next);
                    head = head_nxt;
                }
                else
                {
                    while (i < num)
                    {
                        tmp = tmp->next;
                        i++;
                    }
                    tmp->next = (tmp->next)->next;
                }
            }
            break;
        case 4:
            printf("\nEnter the number of the AEROFLOT which you want to delete.\n");
            key = check_int("");

            if (tmp->flight_number == key)
            {
                head = tmp->next;
                break;
            }

            prev = tmp;
            tmp = tmp->next;

            while (tmp != NULL)
            {
                if (tmp->flight_number == key)
                {
                    key_exist = true;
                    tmp_nxt = tmp->next;
                    prev->next = tmp_nxt;
                    break;
                }
                prev = tmp;
                tmp = tmp->next;
            }
            if (key_exist == false)
                printf("\nThere is no such AEROFLOT in the list.\n");
            break;
        default:
            printf("");
    }
    return head;
}

void swap_values(struct AEROFLOT *p_1, struct AEROFLOT *p_2)
{
    char destination_tmp[16];
    int flight_number_tmp;
    char type_plane_tmp[16];
    // copying values of p to tmp
    strcpy(destination_tmp, p_1->destination);
    flight_number_tmp = p_1->flight_number;
    strcpy(type_plane_tmp, p_1->type_plane);

    // copying values of p to p->next
    strcpy(p_1->destination, p_2->destination);
    p_1->flight_number = p_2->flight_number;
    strcpy(p_1->type_plane, p_2->type_plane);

    // copying values of tmp to p
    strcpy(p_2->destination, destination_tmp);
    p_2->flight_number = flight_number_tmp;
    strcpy(p_2->type_plane, type_plane_tmp);
}
// сортування за часом відправлення
void sort(struct AEROFLOT *head)
{
    if (head == NULL)
    {
        printf("\n\nThe list is empty!\n\n");
        return;
    }

    struct AEROFLOT *p;
    struct AEROFLOT *start;
    start = head;

    while (head->next != NULL)
    {
        p = head->next;

        do
        {
            if (p->flight_number < head->flight_number)
            {
                swap_values(p, head);
            }
            p = p->next;

        } while (p != NULL);

        head = head->next;
    }
}

// Перше завдання (структури)
void first_task()
{
    int a = 1;
    while (a != 6)
    {
        printf("\n\n--To create a list of structures, enter 1.\n--To show a list of structures, enter 2.\n--To add element - 3.\n--To delete element - 4.\n--To sort list - 5.\n--To exit - 6   \n\n");
        a = check_int("");
        switch (a)
        {
            case 1:
                head = create();
                continue;
            case 2:
                show(head);
                continue;
            case 3:
                head = element_add(head);
                continue;
            case 4:
                head = element_del(head);
                continue;
            case 5:
                sort(head);
                continue;
            case 6:
                continue;
            default:
                continue;
        }
    }
}

// Структура для однозвязного списку з простих елементів
struct NATURAL_NUM
{
    int n;
    struct NATURAL_NUM *next;
} NATURAL_NUM;

struct NATURAL_NUM *start = NULL;
struct NATURAL_NUM *parni = NULL;
struct NATURAL_NUM *ne_parni = NULL;

struct NATURAL_NUM *enter_natural()
{
    struct NATURAL_NUM *p;
    p = (struct NATURAL_NUM *)malloc(sizeof(struct NATURAL_NUM));
    printf("\nEnter natural num - ");
    p->n = check_int("");
    return p;
}

struct NATURAL_NUM *kostil(int number)
{
    struct NATURAL_NUM *p;
    p = (struct NATURAL_NUM *)malloc(sizeof(struct NATURAL_NUM));
    p->n = number;
    return p;
}

struct NATURAL_NUM *create_start(void)
{
    int n;
    if (start != NULL)
    {
        printf("\n\nWARNING! The list of structures is not empty. Do you want to clear it?\n1 - Yes. 2 - no.\n\n");
        n = check_int("");

        if (n == 1)
        {
            free(start);
        }
        else
        {
            printf("\nThe list of structures already exists.\n");
            return start;
        }
    }

    int a = 1;

    struct NATURAL_NUM *p, *previous;
    start = previous = p = enter_natural();

    printf("\n\nFinish entering - 0. Continue - any other number.\n");
    a = check_int("");

    while (a != 0)
    {
        p = enter_natural();
        previous->next = p;
        previous = p;
        printf("\n\nFinish entering - 0. Continue - any other number.\n");
        a = check_int("");
    }

    return start;
}

void show_num(struct NATURAL_NUM *head)
{
    if (head == NULL)
    {
        printf("\n\n    The list is empty!\n\n");
        return;
    }
    struct NATURAL_NUM *p;
    p = head;
    printf("\n****************\n");
    do
    {
        /*поки не кінець списку*/
        printf("%d ,", p->n);
        /*просування за списком*/
        p = p->next;
    } while (p != NULL);
}

void second_task()
{
    struct NATURAL_NUM *nepa, *nepa_poperedniy;
    struct NATURAL_NUM *pa, *pa_poperedniy;

    start = create_start();
    printf("\nUr input info :");
    show_num(start);
    struct NATURAL_NUM *tm = start;
    int pa_flag = 0;
    int nepa_flag = 0;
    do
    {
        if ((tm->n % 2) == 1)
        {
            if (nepa_flag == 0)
            {
                nepa = nepa_poperedniy = ne_parni = kostil(tm->n);
                nepa_flag++;
                tm = tm->next;
            }
            else
            {
                nepa = kostil(tm->n);
                nepa_poperedniy->next = nepa;
                nepa_poperedniy = nepa;
                tm = tm->next;
            }
        }
        else if ((tm->n % 2) == 0)
        {
            if (pa_flag == 0)
            {
                pa = pa_poperedniy = parni = kostil(tm->n);
                pa_flag++;
                tm = tm->next;
            }
            else
            {
                pa = kostil(tm->n);
                pa_poperedniy->next = pa;
                pa_poperedniy = pa;
                tm = tm->next;
            }
        }
    } while (tm != NULL);
    printf("\nne parni :");
    show_num(ne_parni);
    printf("\nparni :");
    show_num(parni);

    printf("\n\n");
}
