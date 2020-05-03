/*
** EPITECH PROJECT, 2020
** inventory.c
** File description:
** inventory.c
*/

#include "../include/my_rpg.h"

void save_game(game_t *game)
{
    create_my_save(game);
}

void set_values_perso(game_t *game)
{
    if (game->perso->in_hand == 1 && game->perso->pain > 0) {
        change_hp(game, 20);
        game->perso->pain -= 1;
    } if (game->perso->in_hand == 2  && game->perso->vin > 0) {
        change_hp(game, 15);
        game->perso->vin -= 1;
    } if (game->perso->in_hand == 3 || game->perso->in_hand == 5
        || game->perso->in_hand == 6) {
        game->perso->pickaxe = 1;
        game->perso->perso_sharp = 1;
    } if (game->perso->in_hand == 4) {
        game->perso->pickaxe = game->perso->axe;
        game->perso->perso_sharp = 1;
    }
    if (game->perso->in_hand == 8 && game->perso->cherry > 0) {
        change_hp(game, 10);
        game->perso->cherry -= 1;
    }
}

void set_object(game_t *game, sfVector2i c)
{
    if (c.x > 110 && c.x < 246 && c.y > 211 && c.y < 310)
        game->perso->in_hand = 1;
    if (c.x > 246 && c.x < 379 && c.y > 211 && c.y < 310)
        game->perso->in_hand = 2;
    if (c.x > 379 && c.x < 513 && c.y > 211 && c.y < 310)
        game->perso->in_hand = 3;
    if (c.x > 513 && c.x < 647 && c.y > 211 && c.y < 310)
        game->perso->in_hand = 4;
    if (c.x > 647 && c.x < 780 && c.y > 211 && c.y < 310)
        game->perso->in_hand = 5;
    if (c.x > 780 && c.x < 915 && c.y > 211 && c.y < 310)
        game->perso->in_hand = 6;
    if (c.x > 915 && c.x < 1047 && c.y > 211 && c.y < 310)
        game->perso->in_hand = 7;
    if (c.x > 1047 && c.x < 1181 && c.y > 211 && c.y < 310)
        game->perso->in_hand = 8;
    if (c.x > 1181 && c.x < 1314 && c.y > 211 && c.y < 310)
        game->perso->in_hand = 9;
    if (c.x > 1314 && c.x < 1447 && c.y > 211 && c.y < 310)
        game->perso->in_hand = 10;
    set_values_perso(game);
}

void change_inventory_2(game_t *game, sfVector2i c)
{
    if (c.x > 1064 && c.x < 1197 && c.y > 50 && c.y < 150)
        game->inventory = 8;
    if (game->inventory == 7 &&
        c.x > 460 && c.x < 1130 && c.y > 570 && c.y < 725)
        save_game(game);
    if (game->inventory == 8 &&
        c.x > 460 && c.x < 1130 && c.y > 570 && c.y < 725)
        sfRenderWindow_close(game->window);
}

void change_inventory(game_t *game, sfVector2i c)
{
    set_object(game, c);
    if (c.x > 1765 && c.x < 1850 && c.y > 17 && c.y < 80) {
        game->menu = 2;
        game->inventory = 0;
    }
    if (c.x > 130 && c.x < 263 && c.y > 50 && c.y < 150)
        game->inventory = 0;
    if (c.x > 263 && c.x < 396 && c.y > 50 && c.y < 150)
        game->inventory = 2;
    if (c.x > 396 && c.x < 530 && c.y > 50 && c.y < 150)
        game->inventory = 3;
    if (c.x > 530 && c.x < 663 && c.y > 50 && c.y < 150)
        game->inventory = 4;
    if (c.x > 663 && c.x < 796 && c.y > 50 && c.y < 150)
        game->inventory = 5;
    if (c.x > 796 && c.x < 933 && c.y > 50 && c.y < 150)
        game->inventory = 6;
    if (c.x > 933 && c.x < 1063 && c.y > 50 && c.y < 150)
        game->inventory = 7;
    change_inventory_2(game, c);
}
