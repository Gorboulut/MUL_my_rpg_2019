/*
** EPITECH PROJECT, 2020
** marvin_attack_two.c
** File description:
** marvin_attack_two.c
*/

#include "../include/my_rpg.h"

void check_hit_two(game_t *game)
{
    if (game->marv->activ3 == 1 && game->marv->atk3_i->rect.left > 700)
        if (game->marv->atk3->pos.x + 40 >= game->sprite[TEK1].pos.x &&
            game->marv->atk3->pos.x - 20 <= game->sprite[TEK1].pos.x &&
            game->marv->atk3->pos.y + 340 >= game->sprite[TEK1].pos.y &&
            game->marv->atk3->pos.y + 280 <= game->sprite[TEK1].pos.y)
            change_hp(game, -50);
}