/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** attack manager
*/
#include "../include/my_rpg.h"

void check_hit_enemy(game_t *game)
{
    if (game->pl->sword->pos.x > game->marv->attack->pos.x - 50 &&
        game->pl->sword->pos.x < game->marv->attack->pos.x + 70 &&
        game->pl->sword->pos.y > game->marv->attack->pos.y - 30 &&
        game->pl->sword->pos.y < game->marv->attack->pos.y + 40)
        game->pl->touch += 1;
}

void start_sword_animation(game_t *game)
{
    game->pl->sword->pos = ((sfVector2f)
    {game->sprite[TEK1].pos.x + game->pl->pos->x,
    game->sprite[TEK1].pos.y + game->pl->pos->y});
    check_hit_enemy(game);
    sfSprite_setPosition(game->pl->sword->sprite, game->pl->sword->pos);
    sfRenderWindow_drawSprite(game->window, game->pl->sword->sprite, NULL);
    if (game->secondes % (6 - (game->pl->lvl / 5)) == 0) {
        if (game->pl->sword->rect.left == 0)
            sfSound_play(game->s->sword);
        game->pl->sword->rect.left += 75;
        sfSprite_setTextureRect(game->pl->sword->sprite,
            game->pl->sword->rect);
        if (game->pl->sword->rect.left > 300) {
            game->pl->pos->y = 0;
            game->pl->touch = 0;
            game->pl->pos->x = -15;
            game->anim = 0;
        }
    }
}

void call_atk(game_t *game)
{
    int y = 0;

    if (game->pl->atk == 1) {
        y = 10;
        game->pl->pos->x = -50;
    } if (game->pl->atk == 2) {
        y = 250;
        game->pl->pos->x = 10;
    } if (game->pl->atk == 3) {
        y = 130;
        game->pl->pos->y = 5;
    } if (game->pl->atk == 4) {
        y = 380;
        game->pl->pos->y = -55;
    } game->pl->sword->rect = ((sfIntRect) {0, y, 75, 70});
    sfSprite_setTextureRect(game->pl->sword->sprite, game->pl->sword->rect);
    game->anim = 1;
}

void call_shield(game_t *game)
{
    game->pl->shield->pos =
    ((sfVector2f) {game->sprite[TEK1].pos.x - 28,
        game->sprite[TEK1].pos.y - 12});
    sfSprite_setPosition(game->pl->shield->sprite, game->pl->shield->pos);
}
