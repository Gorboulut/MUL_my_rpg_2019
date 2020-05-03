/*
** EPITECH PROJECT, 2020
** quest.c
** File description:
** quest.c
*/

#include "../include/my_rpg.h"

void showing_quest(game_t *game, char **quest)
{
    game->current_quest = "\0";
    for (int i = 0; quest[i] != NULL; i++) {
        game->current_quest = my_strcat(game->current_quest, quest[i]);
        game->current_quest = new_strcat(game->current_quest, '\n');
    }
    game->count_quest = 1;
}

void changing_quest(game_t *game, char **quest)
{
    game->quest++;
    game->current_quest = "\0";
    showing_quest(game, quest);
}

void quest_list(game_t *game, int inter, char **quest, int count)
{
    game->count_quest = 0;
    if (game->quest == count && game->obj == inter)
        changing_quest(game, quest);
}

void first_quest(game_t *game, int object)
{
    game->obj = object;
    quest_list(game, ROCK1, game->second_quest, 0);
    quest_list(game, ARCHI, game->third_quest, 1);
    quest_list(game, ROCK4, game->fourth_quest, 2);
    quest_list(game, WILLY, game->fifth_quest, 3);
}