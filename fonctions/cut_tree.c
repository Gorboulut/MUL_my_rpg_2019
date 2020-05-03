/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** fonction for cutting tree
*/
#include "../include/my_rpg.h"

void call_direction_sec(game_t *game)
{
    if (game->pl->atk == 3) {
        if (my_strcmp(collision(game, 1, 0), "9") == 0) {
            game->pl->axe->pos = ((sfVector2f)
            {game->sprite[TEK1].pos.x - 75, game->sprite[TEK1].pos.y + 5});
            game->pl->cut = 1;
        }
    } if (game->pl->atk == 4) {
        if (my_strcmp(collision(game, -1, 0), "9") == 0) {
            game->pl->axe->pos = ((sfVector2f)
            {game->sprite[TEK1].pos.x - 50, game->sprite[TEK1].pos.y - 55});
            game->pl->cut = 1;
        }
    }
}

void call_direction_tree(game_t *game)
{
    if (game->pl->atk == 1) {
        if (my_strcmp(collision(game, 0, -1), "9") == 0) {
            game->pl->axe->pos = ((sfVector2f)
            {game->sprite[TEK1].pos.x - 100, game->sprite[TEK1].pos.y - 20});
            game->pl->cut = 1;
        }
    } if (game->pl->atk == 2) {
        if (my_strcmp(collision(game, 0, 1), "9") == 0) {
            game->pl->axe->pos = ((sfVector2f)
            {game->sprite[TEK1].pos.x + 10, game->sprite[TEK1].pos.y - 30});
            game->pl->cut = 1;
        }
    } call_direction_sec(game);
    if (game->pl->cut == 1)
        sfSprite_setPosition(game->pl->axe->sprite, game->pl->axe->pos);
}

void start_axe_animation(game_t *game)
{
    srand(time(NULL));
    sfRenderWindow_drawSprite(game->window, game->pl->axe->sprite, NULL);
    if (game->secondes % 20 == 0) {
        game->pl->axe->rect.left += 150;
        sfSprite_setTextureRect(game->pl->axe->sprite, game->pl->axe->rect);
        if (game->pl->axe->rect.left > 700) {
            game->pl->axe->rect.left = 0;
            sfSprite_setTextureRect(game->pl->axe->sprite,
                game->pl->axe->rect);
            game->pl->cut = 0;
            game->pl->wood += 1;
            game->perso->cherry += rand() % 3;
            change_xp(game, 100);
        }
    }
}
