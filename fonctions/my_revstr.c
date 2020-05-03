/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_revstr.c
*/

#include <stdio.h>
#include <unistd.h>

int main(void);

int my_strlen(char *str)
{
    int u = 0;

    if (str == NULL)
        return (0);
    for (; str[u]; u++);
    return (u);
}

int exchange(char *o, char *p)
{
    char c;

    c = *o;
    *o = *p;
    *p = c;
    return (1);
}

char *my_revstr(char *str)
{
    int j = my_strlen(str);

    if (str == NULL)
        return (NULL);
    for (int i = 0; i < j / 2; i++)
        exchange(str + i, str + j - i - 1);
    return (str);
}