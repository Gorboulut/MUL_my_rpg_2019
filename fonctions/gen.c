/*
** EPITECH PROJECT, 2020
** gen.c
** File description:
** gen.c
*/

#include "../include/my_rpg.h"
#include <unistd.h>

char **parsing(char *path)
{
    char *buffer = NULL;
    char **stk = NULL;
    size_t hello = 0;
    FILE *file = fopen(path, "r");

    if (file == NULL)
        return NULL;
    buffer = malloc(sizeof(char) * 3);
    getline(&buffer, &hello, file);
    stk = malloc(sizeof(char *) * (my_getnbr(buffer) + 1));
    memset(stk, 0, sizeof(char *) * (my_getnbr(buffer) + 1));
    for (int i = 0; i < my_getnbr(buffer); i++)
        if (getline(&stk[i], &hello, file) == -1)
            return (NULL);
    return (stk);
}