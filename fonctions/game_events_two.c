/*
** EPITECH PROJECT, 2020
** game_events_two.c
** File description:
** game_events_two.c
*/

#include "../include/my_rpg.h"

void set_value_in_string(game_t *game)
{
    game->perso->text_wood = my_itoa(game->pl->wood);
    sfText_setString(game->perso->txt, game->perso->text_wood);
    game->perso->text_cherry = my_itoa(game->perso->cherry);
    sfText_setString(game->perso->txt_cherry, game->perso->text_cherry);
    game->perso->text_pain = my_itoa(game->perso->pain);
    sfText_setString(game->perso->txt_pain, game->perso->text_pain);
    game->perso->text_vin = my_itoa(game->perso->vin);
    sfText_setString(game->perso->txt_vin, game->perso->text_vin);
}

void in_game_events(game_t *game)
{
    if (game->key.code == game->option->pause)
        call_escape(game);
    if (game->key.code == game->option->inv && game->menu == 2)
        game->menu = 7;
    if (game->key.code == game->option->attack && game->menu == 2
        && game->anim == 0 && game->perso->sharp == 1)
        call_atk(game);
    if (game->key.code != game->option->shield && game->pl->prot == 1)
        game->pl->prot = 0;
    if (game->key.code == game->option->shield && game->menu == 2
        && game->anim == 0 && game->perso->bouclier == 1) {
        game->pl->prot = 1;
        sfSound_play(game->s->shield);
    }
    if (game->key.code == game->option->farm && game->menu == 2 &&
        game->perso->axe == 1) {
        call_direction_tree(game);
        quest_list(game, game->obj, game->sixth_quest, 4);
    }
}