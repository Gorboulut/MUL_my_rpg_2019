/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** button_function_3.c
*/

#include "my_rpg.h"

void change_shield(game_t *game)
{
    sfText_setString(game->text[SHIELD_TX].text, "...");
    game->menu = 9;
    game->option->key = 8;
}

void change_attack(game_t *game)
{
    sfText_setString(game->text[ATTACK_TX].text, "...");
    game->menu = 9;
    game->option->key = 9;
}

void change_farm(game_t *game)
{
    sfText_setString(game->text[FARM_TX].text, "...");
    game->menu = 9;
    game->option->key = 10;
}