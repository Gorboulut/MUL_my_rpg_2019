/*
** EPITECH PROJECT, 2020
** my_prg
** File description:
** create marvin death
*/
#include "../include/my_rpg.h"

void create_marvin_death(game_t *game)
{
    game->pl->pos->x = -20;
    game->pl->pos->y = 0;
    game->pl->prot = 0;
    game->marv->mode = 0;
    game->marv->activ = 0;
    game->marv->atk = 0;
    game->marv_l = 0;
    game->marv->end->rect = ((sfIntRect) {0, 0, 80, 80});
    game->marv->end_x->rect = ((sfIntRect) {0, 0, 80, 170});
    game->marv->end_x->pos.y -= 130;
    sfSprite_setPosition(game->marv->end_x->sprite, game->marv->end_x->pos);
    sfSprite_setTextureRect(game->marv->end->sprite,
                            game->marv->end->rect);
    sfSprite_setTextureRect(game->marv->end_x->sprite,
                            game->marv->end_x->rect);
}
