/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** buttons_function_1.c
*/

#include "my_rpg.h"

void change_up(game_t *game)
{
    sfText_setString(game->text[TOP_TX].text, "...");
    game->menu = 9;
    game->option->key = 1;
}

void change_down(game_t *game)
{
    sfText_setString(game->text[BOT_TX].text, "...");
    game->menu = 9;
    game->option->key = 2;
}

void change_left(game_t *game)
{
    sfText_setString(game->text[LEFT_TX].text, "...");
    game->menu = 9;
    game->option->key = 3;
}

void change_right(game_t *game)
{
    sfText_setString(game->text[RIGHT_TX].text, "...");
    game->menu = 9;
    game->option->key = 4;
}

void change_inter(game_t *game)
{
    sfText_setString(game->text[INTERACT_TX].text, "...");
    game->menu = 9;
    game->option->key = 5;
}
