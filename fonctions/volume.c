/*
** EPITECH PROJECT, 2020
** volume.c
** File description:
** volume.c
*/

#include "../include/my_rpg.h"
#include <stdlib.h>

vol_t *push_vol(game_t *game, int vol, char *text)
{
    vol_t *new = malloc(sizeof(vol_t));
    vol_t *tmp;

    new->vol = vol;
    new->sprite = sfSprite_create();
    new->texture = sfTexture_createFromFile(text, NULL);
    new->pos.x = 835;
    new->pos.y = 400;
    new->next = NULL;
    new->prev = NULL;
    if (!game->volume)
        return (new);
    tmp = game->volume;
    while (tmp->next != NULL) {
        tmp->next->prev = tmp;
        tmp = tmp->next;
    } tmp->next = new;
    return (game->volume);
}

vol_t *make_it_double(game_t *game)
{
    vol_t *new = game->volume;

    new->next->prev = new;
    while (new->next != NULL) {
        new->next->prev = new;
        new = new->next;
    }
    new->next = game->volume;
    new->next->prev = new;
    return (new);
}

void create_vol(game_t *game)
{
    game->volume = NULL;
    game->volume = push_vol(game, 0, "assets/img/vol_0.png");
    game->volume = push_vol(game, 15, "assets/img/vol_25.png");
    game->volume = push_vol(game, 45, "assets/img/vol_50.png");
    game->volume = push_vol(game, 75, "assets/img/vol_75.png");
    game->volume = push_vol(game, 100, "assets/img/vol_100.png");
    game->volume = make_it_double(game);
    game->volume = game->volume->next;
}