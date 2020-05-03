/*
** EPITECH PROJECT, 2020
** game_render.c
** File description:
** game_render.c
*/

#include "../include/my_rpg.h"

void game_render_2(game_t *game)
{
    if (game->menu == 5)
        in_lose(game);
    if (game->menu == 6)
        how_to_play(game);
    if (game->menu == 7)
        in_inventory(game);
    if (game->menu == 8)
        in_option2(game);
    if (game->menu == 9)
        in_change_key(game);
}

void set_pos_null(game_t *game)
{
    game->basic_pos.x = game->sprite[TEK1].pos.x - (1920 / 2);
    game->basic_pos.y = game->sprite[TEK1].pos.y - (1080 / 2);
}

void game_render(game_t *game)
{
    sfView_setSize(game->camera, (sfVector2f) {1920, 1080});
    set_pos_null(game);
    if (game->menu == 0)
        in_menu(game);
    if (game->menu == 1)
        in_option(game);
    if (game->menu == 2)
        in_play(game);
    if (game->menu == 3)
        in_pause(game);
    if (game->menu == 4)
        in_win(game);
    game_render_2(game);
    sfRenderWindow_setView(game->window, game->camera);
}