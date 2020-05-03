/*
** EPITECH PROJECT, 2019
** CPool_Day08_2019
** File description:
** my_strdup.c
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av);

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *str;
    int j;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (str == NULL)
        return (NULL);
    for (j = 0; j != my_strlen(src); j++)
        str[j] = src[j];
    str[j] = '\0';
    return (str);
}
