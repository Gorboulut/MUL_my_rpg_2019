/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** button_function_2.c
*/

#include "my_rpg.h"

void change_inv(game_t *game)
{
    sfText_setString(game->text[INV_TX].text, "...");
    game->menu = 9;
    game->option->key = 6;
}

void change_pause(game_t *game)
{
    sfText_setString(game->text[PAUSED_TX].text, "...");
    game->menu = 9;
    game->option->key = 7;
}

void init_option(game_t *game)
{
    init_button(game, change_up, (sfIntRect) {0, 0, 190, 60},
        (sfVector2f) {763, 337});
    init_button(game, change_down, (sfIntRect) {0, 0, 190, 60},
        (sfVector2f) {763, 458});
    init_button(game, change_left, (sfIntRect) {0, 0, 190, 60},
        (sfVector2f) {763, 585});
    init_button(game, change_right, (sfIntRect) {0, 0, 190, 60},
        (sfVector2f) {763, 700});
    init_button(game, change_inter, (sfIntRect) {0, 0, 190, 60},
        (sfVector2f) {763, 809});
    init_button(game, change_inv, (sfIntRect) {0, 0, 190, 60},
        (sfVector2f) {1370, 337});
    init_button(game, change_pause, (sfIntRect) {0, 0, 190, 60},
        (sfVector2f) {1370, 458});
        init_button(game, change_shield, (sfIntRect) {0, 0, 190, 60},
        (sfVector2f) {1370, 585});
    init_button(game, change_attack, (sfIntRect) {0, 0, 190, 60},
        (sfVector2f) {1370, 700});
    init_button(game, change_farm, (sfIntRect) {0, 0, 190, 60},
        (sfVector2f) {1370, 809});
}
