/*
** EPITECH PROJECT, 2020
** interaction_two.c
** File description:
** interaction_two.c
*/

#include "../include/my_rpg.h"

void all_interaction_object_two(game_t *game)
{
    interaction_object(game, game->third_rock, ROCK3);
    interaction_object(game, game->fourth_rock, ROCK4);
    interaction_object(game, game->fifth_rock, ROCK5);
    interaction_object(game, game->sixth_rock, ROCK6);
    interaction_object(game, game->forger, FORGER);
    interaction_object(game, game->drunkman, DRUNKMAN);
    interaction_object(game, game->minerock, MINEROCK);
    interaction_object(game, game->piratebridge, PIRATEBRIDGE);
}