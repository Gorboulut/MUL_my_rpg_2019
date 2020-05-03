/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** third marvin attack
*/
#include "../include/my_rpg.h"

void activ_laser(game_t *game)
{
    if (game->marv->atk3->rect.left == 0)
        sfSound_play(game->s->laser);
    game->marv->atk3->rect.left += 130;
    sfSprite_setTextureRect(game->marv->atk3->spr, game->marv->atk3->rect);
}

void show_laser(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->marv->atk3->spr, NULL);
}

void activ_cible(game_t *game)
{
    game->marv->atk3_i->rect.left += 100;
    sfSprite_setTextureRect(game->marv->atk3_i->spr, game->marv->atk3_i->rect);
}

void show_cible(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->marv->atk3_i->spr, NULL);
    if (game->secondes % 14 == 0)
        activ_cible(game);
}

void marvin_third_attack(game_t *game)
{
    if (game->secondes % 280 == 0) {
        game->marv->activ3 = 1;
        sfSound_play(game->s->prep);
        game->marv->atk3_i->pos = game->sprite[TEK1].pos;
        sfSprite_setPosition(game->marv->atk3_i->spr, game->marv->atk3_i->pos);
        game->marv->atk3->pos.y = game->sprite[TEK1].pos.y - 300;
        game->marv->atk3->pos.x = game->sprite[TEK1].pos.x;
        sfSprite_setPosition(game->marv->atk3->spr, game->marv->atk3->pos);
    } if (game->marv->activ3 == 1) {
        if (game->marv->atk3_i->rect.left > 780) {
            if (game->secondes % 8 == 0)
                activ_laser(game);
            show_laser(game);
        } else
            show_cible(game);
    } if (game->marv->atk3->rect.left > 960) {
        game->marv->atk3->rect.left = 0;
        game->marv->atk3_i->rect.left = 0;
        game->marv->activ3 = 0;
    }
}
