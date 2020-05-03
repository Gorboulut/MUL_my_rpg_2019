/*
** EPITECH PROJECT, 2020
** in_inventory_two.c
** File description:
** in_inventory_two.c
*/

#include "../include/my_rpg.h"

void set_object_in_inventory_two(game_t *game)
{
    if (game->pl->wood != 0) {
        sfRenderWindow_drawSprite(game->window, game->inven_sp[WOOD].sprite,
            NULL);
        sfRenderWindow_drawText(game->window, game->perso->txt, NULL);
    }
    if (game->perso->bouclier == 1)
        sfRenderWindow_drawSprite(game->window, game->inven_sp[SHIELD].sprite,
            NULL);
    if (game->perso->cherry != 0) {
        sfRenderWindow_drawSprite(game->window,
            game->inven_sp[CHERRY_INV].sprite, NULL);
        sfRenderWindow_drawText(game->window, game->perso->txt_cherry, NULL);
    }
}