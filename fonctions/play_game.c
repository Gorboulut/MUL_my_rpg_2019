/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** action
*/
#include "../include/my_rpg.h"

void marvin_idle_move(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->marv->idle->sprite, NULL);
    if (game->secondes % 10 == 0) {
        game->marv->idle->rect.left += 85;
        if (game->marv->idle->rect.left > 940)
            game->marv->idle->rect.left = 0;
        sfSprite_setTextureRect(game->marv->idle->sprite,
            game->marv->idle->rect);
    }
}

void marvin_start_move(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->marv->start->sprite, NULL);
    if (game->secondes % 5 == 0) {
        game->marv->start->rect.left += 85;
        if (game->marv->start->rect.left > 2000)
            game->marv->mode = 2;
        sfSprite_setTextureRect(game->marv->start->sprite,
            game->marv->start->rect);
    }
}

void marvin_attack_move(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->marv->attack->sprite, NULL);
    if (game->secondes % 10 == 0) {
        game->marv->attack->rect.left += 85;
        if (game->marv->attack->rect.left > 480) {
            game->marv->reset_atk++;
            game->marv->atk = 1;
            game->marv->attack->rect.left = 0;
        }
        sfSprite_setTextureRect(game->marv->attack->sprite,
            game->marv->attack->rect);
    }
}

void marvin_play(game_t *game)
{
    if (game->marv->death == 0) {
        if (game->sprite[TEK1].pos.x > 2750 && game->sprite[TEK1].pos.y < 400
            && game->marv->activ == 0) {
            game->marv->mode = 1;
            game->marv->activ = 1;
        } if (game->marv->mode == 0)
            marvin_idle_move(game);
        if (game->marv->mode == 1)
            marvin_start_move(game);
        if (game->marv->mode == 2)
            marvin_attack_move(game);
        if (game->marv->atk == 1 && game->secondes % 3 == 0)
            marvin_launch_attack(game);
        if (game->marv->phase == 3)
            marvin_third_attack(game);
        if (game->marv->atk == 1)
            show_attack(game);
        if (game->marv->reset_atk == 5)
            reset_atk(game);
    } if (game->marv->death == 1)
        marvin_death(game);
}
