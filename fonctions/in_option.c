/*
** EPITECH PROJECT, 2020
** in_option.c
** File description:
** in_option.c
*/

#include "../include/my_rpg.h"

void how_to_play(game_t *game)
{
    sfVector2i c = sfMouse_getPositionRenderWindow(game->window);

    sfRenderWindow_drawSprite(game->window, game->menu_sp[HOW].sprite, NULL);
    if (c.x > 355 && c.x < 400 && c.y < 720 && c.y > 695)
        sfRenderWindow_drawSprite(game->window, game->menu_sp[BACK_PLAY].sprite,
        NULL);
}

void in_option(game_t *game)
{
    sfVector2i c = sfMouse_getPositionRenderWindow(game->window);
    sfSprite_setPosition(game->volume->sprite, game->volume->pos);
    sfSprite_setTexture(game->volume->sprite, game->volume->texture, 1);
    sfSprite_setPosition(game->text_speed->sprite, game->text_speed->pos);
    sfSprite_setTexture(game->text_speed->sprite,
        game->text_speed->texture, 1);
    sfRenderWindow_drawSprite(game->window, game->menu_sp[SETTINGS].sprite,
    NULL);
    sfRenderWindow_drawSprite(game->window, game->volume->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->text_speed->sprite, NULL);
    if (c.x > 230 && c.x < 290 && c.y < 900 && c.y > 868)
        sfRenderWindow_drawSprite(game->window, game->menu_sp[BACK_OP].sprite,
        NULL);
}