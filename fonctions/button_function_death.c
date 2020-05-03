/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** button_function_death.c
*/

#include "my_rpg.h"

void init_button_d(game_t *game, void *func, sfIntRect rect, sfVector2f pos)
{
    static int i = 0;
    game->death[i].pos = pos;
    game->death[i].rect = rect;
    game->death[i].fct = func;
    i++;
}

void retry(game_t *game)
{
    create_my_texture(game);
    game->sprite[HP].rect.width = 306;
    game->menu = 0;
}

void exit_end(game_t *game)
{
    sfRenderWindow_close(game->window);
}