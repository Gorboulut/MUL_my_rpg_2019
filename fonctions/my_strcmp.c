/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** my_strcmp.c
*/

#include "../include/my_rpg.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return (-1);
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i++;
    if ((s1[i] - s2[i]) == 0)
        return (0);
    else
        return (-1);
}