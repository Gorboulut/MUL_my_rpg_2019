/*
** EPITECH PROJECT, 2019
** memeknaci lib
** File description:
** my_realloc
*/

#include <stdlib.h>

void my_memmove(void const *dest, void const *src, size_t size)
{
    char *string_src = (char *) src;
    char *string_dest = (char *) dest;
    char *temp = malloc(sizeof(char) * (size + 1));
    size_t j = 0;

    if (temp == NULL)
        return;
    for (j = 0; j < size; j++)
        temp[j] = string_src[j];
    temp[j] = 0;
    for (size_t i = 0; i < size; i++)
        string_dest[i] = temp[i];
    free(temp);
}

void *my_realloc(void *src, size_t old_size, size_t size)
{
    char *ptr = NULL;

    if (size == 0)
        return (NULL);
    if ((ptr = malloc(size)) == NULL || src == NULL)
        return (ptr);
    my_memmove(ptr, src, size < old_size ? size : old_size);
    free(src);
    return (ptr);
}
