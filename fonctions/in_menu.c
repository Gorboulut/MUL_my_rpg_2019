/*
** EPITECH PROJECT, 2020
** in_menu.c
** File description:
** in_menu.c
*/

#include "../include/my_rpg.h"

void print_button_menu(game_t *game, sfVector2i c)
{
    if (c.x > 1845 && c.x < 1895 && c.y < 74 && c.y > 24)
        sfRenderWindow_drawSprite(game->window, game->menu_sp[OPTION].sprite,
        NULL);
    if (c.x > 600 && c.x < 823 && c.y < 1106 && c.y > 883)
        sfRenderWindow_drawSprite(game->window, game->menu_sp[NEW].sprite,
        NULL);
    if (c.x > 849 && c.x < 1072 && c.y < 1106 && c.y > 883)
        sfRenderWindow_drawSprite(game->window, game->menu_sp[LOAD].sprite,
        NULL);
    if (c.x > 1095 && c.x < 1318 && c.y < 1106 && c.y > 883)
        sfRenderWindow_drawSprite(game->window, game->menu_sp[EXIT].sprite,
        NULL);
    if (c.x > 1809 && c.x < 1875 && c.y < 1059 && c.y > 984)
        sfRenderWindow_drawSprite(game->window, game->menu_sp[INTER].sprite,
        NULL);
}

void create_my_texture_first(game_t *game)
{
    create_my_sprite((sfIntRect) {0, 0, 1920, 1080},
                    (sfVector2f) {0, 0}, &game->menu_sp[MENU]);
    create_my_sprite((sfIntRect) {0, 0, 50, 50},
                    (sfVector2f) {1845, 24}, &game->menu_sp[OPTION]);
    create_my_sprite((sfIntRect) {0, 0, 1920, 1080},
                    (sfVector2f) {0, 0}, &game->menu_sp[SETTINGS]);
    create_my_sprite((sfIntRect) {0, 0, 1920, 1080},
                    (sfVector2f) {0, 0}, &game->menu_sp[HOW]);
    create_my_sprite((sfIntRect) {0, 0, 1920, 1080},
                    (sfVector2f) {0, 0}, &game->inven_sp[PAUSE]);
    create_my_sprite((sfIntRect) {0, 0, 44, 40},
                    (sfVector2f) {356, 686}, &game->menu_sp[BACK_PLAY]);
    create_my_sprite((sfIntRect) {0, 0, 53, 43},
                    (sfVector2f) {233, 862}, &game->menu_sp[BACK_OP]);
    create_my_sprite((sfIntRect) {0, 0, 223, 175},
                    (sfVector2f) {602, 884}, &game->menu_sp[NEW]);
    create_my_sprite((sfIntRect) {0, 0, 223, 174},
                    (sfVector2f) {849, 885}, &game->menu_sp[LOAD]);
    create_my_sprite((sfIntRect) {0, 0, 223, 175},
                    (sfVector2f) {1095, 884}, &game->menu_sp[EXIT]);
}

void create_my_texture_second(game_t *game)
{
    create_my_sprite((sfIntRect) {0, 0, 66, 75},
                    (sfVector2f) {1809, 984}, &game->menu_sp[INTER]);
}

void create_my_texture(game_t *game)
{
    create_my_texture_first(game);
    create_my_texture_second(game);
}

void in_menu(game_t *game)
{
    sfVector2i c = sfMouse_getPositionRenderWindow(game->window);
    if (game->count == 0) {
        create_my_texture(game);
        game->count = 1;
    }
    sfView_setCenter(game->camera, (sfVector2f) {1920 / 2, 1080 / 2});
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->menu_sp[MENU].sprite, NULL);
    sfRenderWindow_drawText(game->window, game->text[TITLE_TX].text, NULL);
    print_button_menu(game, c);
}