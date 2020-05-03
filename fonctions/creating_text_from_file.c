/*
** EPITECH PROJECT, 2020
** creating_text_from_file.c
** File description:
** creating_text_from_file.c
*/

#include "../include/my_rpg.h"

int creating_text_from_file_four(game_t *game)
{
    if ((game->forger = parsing("assets/txt/forger.txt")) == NULL)
        return (84);
    if ((game->drunkman = parsing("assets/txt/drunkman.txt")) == NULL)
        return (84);
    if ((game->minerock = parsing("assets/txt/minerock.txt")) == NULL)
        return (84);
    if ((game->piratebridge = parsing("assets/txt/piratebridge.txt")) == NULL)
        return (84);
    if ((game->fourth_quest = parsing("assets/txt/fourth_quest.txt")) == NULL)
        return (84);
    if ((game->fifth_quest = parsing("assets/txt/fifth_quest.txt")) == NULL)
        return (84);
    if ((game->sixth_quest = parsing("assets/txt/sixth_quest.txt")) == NULL)
        return (84);
    if ((game->johan = parsing("assets/txt/johan.txt")) == NULL)
        return (84);
    return (0);
}

int creating_text_from_file_three(game_t *game)
{
    if ((game->second_quest = parsing("assets/txt/second_quest.txt")) == NULL)
        return (84);
    if ((game->third_quest = parsing("assets/txt/third_quest.txt")) == NULL)
        return (84);
    if ((game->mail_archi = parsing("assets/txt/mail_archi.txt")) == NULL)
        return (84);
    if ((game->second_rock = parsing("assets/txt/rock2.txt")) == NULL)
        return (84);
    if ((game->third_rock = parsing("assets/txt/rock3.txt")) == NULL)
        return (84);
    if ((game->fourth_rock = parsing("assets/txt/rock4.txt")) == NULL)
        return (84);
    if ((game->fifth_rock = parsing("assets/txt/rock5.txt")) == NULL)
        return (84);
    if ((game->sixth_rock = parsing("assets/txt/rock6.txt")) == NULL)
        return (84);
    creating_text_from_file_four(game);
    return (0);
}