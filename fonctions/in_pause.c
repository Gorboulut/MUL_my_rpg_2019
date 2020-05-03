/*
** EPITECH PROJECT, 2020
** in_pause.c
** File description:
** in_pause.c
*/

#include "../include/my_rpg.h"

void in_pause(game_t *game)
{
    in_play(game);
    sfSprite_setPosition(game->inven_sp[PAUSE].sprite,
                        (sfVector2f) {game->pos_camera.x - (1920 / 2),
                        game->pos_camera.y - (1080 / 2)});
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfRenderWindow_drawSprite(game->window, game->inven_sp[PAUSE].sprite,
        NULL);
}

void call_escape(game_t *game)
{
    if (game->menu == 2) {
        game->menu = 3;
        return;
    }
    if (game->menu == 3)
        game->menu = 2;
    if (game->menu == 7)
        game->menu = 2;
}

void click_pause(game_t *game, sfVector2i c)
{
    if (c.x > 662 && c.x < 1250 && c.y < 585 && c.y > 520)
        game->menu = 2;
    if (c.x > 662 && c.x < 1250 && c.y < 685 && c.y > 620) {
        game->menu = 0;
        game->count = 0;
    }
    if (c.x > 662 && c.x < 1250 && c.y < 790 && c.y > 725)
        sfRenderWindow_close(game->window);
}