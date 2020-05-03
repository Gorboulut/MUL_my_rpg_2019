/*
** EPITECH PROJECT, 2020
** create_game_six.c
** File description:
** create_game_six.c
*/

#include "../include/my_rpg.h"

void set_nb_text_two(game_t *game)
{
    sfText_setColor(game->perso->txt, sfBlack);
    sfText_setColor(game->perso->txt_pain, sfBlack);
    sfText_setColor(game->perso->txt_vin, sfBlack);
    sfText_setColor(game->perso->txt_cherry, sfBlack);
    sfText_setCharacterSize(game->perso->txt, 15);
    sfText_setCharacterSize(game->perso->txt_pain, 15);
    sfText_setCharacterSize(game->perso->txt_vin, 15);
    sfText_setCharacterSize(game->perso->txt_cherry, 15);
}