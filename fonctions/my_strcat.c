/*
** EPITECH PROJECT, 2019
** CPool_Day07_2019
** File description:
** my_strcat.c
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(void);

int my_strlen(char const *dest);

char *new_strcat(char *dest, char c)
{
    int i = my_strlen(dest);
    int j = 0;
    char *result = malloc(sizeof(char) * i + 2);

    if (dest == NULL) {
        result[0] = c;
        result[1] = '\0';
        return (result);
    }
    for (; dest[j]; j++)
        result[j] = dest[j];
    result[j] = c;
    result[j + 1] = '\0';
    return (result);
}

char *my_strcat(char *dest, char const *src)
{
    int i = my_strlen(dest);
    int j = 0;
    char *result = malloc(sizeof(char) * i + my_strlen(src) + 1);

    for (j = 0; dest[j] != '\0'; j++)
        result[j] = dest[j];
    for (j = 0; src[j] != '\0'; j++)
        result[i + j] = src[j];
    result[j + i] = '\0';
    return (result);
}
