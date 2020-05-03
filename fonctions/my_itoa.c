/*
** EPITECH PROJECT, 2020
** lib/my
** File description:
** my_itoa.c
*/

#include "../include/my_rpg.h"
#include <stdlib.h>

char *my_itoa(int array)
{
    char *str = malloc(sizeof(char) * 10);
    int j = 0;

    if (array == 0) {
        str[j] = 48;
        str[j + 1] = '\0';
        return (str);
    }
    while (array > 0) {
        str[j] = array % 10 + 48;
        j++;
        array /= 10;
    }
    str[j] = '\0';
    str = my_revstr(str);
    return (str);
}