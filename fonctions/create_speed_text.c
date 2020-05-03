/*
** EPITECH PROJECT, 2020
** create_speed_text.c
** File description:
** create_speed_text.c
*/

#include "../include/my_rpg.h"

vol_t *push_speed(game_t *game, int speed, char *text)
{
    vol_t *new = malloc(sizeof(vol_t));
    vol_t *tmp;

    new->vol = speed;
    new->sprite = sfSprite_create();
    new->texture = sfTexture_createFromFile(text, NULL);
    new->pos.x = 835;
    new->pos.y = 550;
    new->next = NULL;
    new->prev = NULL;
    if (!game->text_speed)
        return (new);
    tmp = game->text_speed;
    while (tmp->next != NULL) {
        tmp->next->prev = tmp;
        tmp = tmp->next;
    } tmp->next = new;
    return (game->text_speed);
}

vol_t *make_it_double_speed(game_t *game)
{
    vol_t *new = game->text_speed;

    new->next->prev = new;
    while (new->next != NULL) {
        new->next->prev = new;
        new = new->next;
    }
    new->next = game->text_speed;
    new->next->prev = new;
    return (new);
}

void create_speed_text(game_t *game)
{
    game->text_speed = NULL;
    game->text_speed = push_speed(game, 26, "assets/img/slow.png");
    game->text_speed = push_speed(game, 22, "assets/img/normal.png");
    game->text_speed = push_speed(game, 18, "assets/img/fast.png");
    game->text_speed = make_it_double_speed(game);
    game->text_speed = game->text_speed->next;
}
