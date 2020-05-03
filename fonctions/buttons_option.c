/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** buttons_option.c
*/

#include "my_rpg.h"

int condition(game_t *game, int i, sfVector2i c)
{
    if (c.x >= game->option->button[i].pos.x
    && c.x <= (game->option->button[i].pos.x
    + game->option->button[i].rect.width)
    && c.y >= game->option->button[i].pos.y
    && c.y <= (game->option->button[i].pos.y
    + game->option->button[i].rect.height))
        return (1);
    return (0);
}

int button_is_clicked(game_t *game, sfVector2i c)
{
    for (int i = 0; i != NB_BUTTON; i++) {
        if (condition(game, i, c) == 1) {
            if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
                game->option->button[i].fct(game);
                break;
            }
        }
    }
    return (0);
}

int condition_death(game_t *game, int i, sfVector2i c)
{
    if (c.x >= game->death[i].pos.x
    && c.x <= (game->death[i].pos.x
    + game->death[i].rect.width)
    && c.y >= game->death[i].pos.y
    && c.y <= (game->death[i].pos.y
    + game->death[i].rect.height))
        return (1);
    return (0);
}

int button_is_clicked_death(game_t *game, sfVector2i c)
{
    for (int i = 0; i != NB_BUTTON; i++) {
        if (condition_death(game, i, c) == 1) {
            if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
                game->death[i].fct(game);
                break;
            }
        }
    }
    return (0);
}