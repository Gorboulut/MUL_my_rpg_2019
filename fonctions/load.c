/*
** EPITECH PROJECT, 2020
** load.c
** File description:
** load.c
*/

#include "../include/my_rpg.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int load_that(char **tab, int j)
{
    int load = 0;
    load = my_getnbr(tab[j]);
    return (load);
}

void load_key(game_t *game, char **tab)
{
    game->option->top = load_that(tab, 15);
    game->option->bot = load_that(tab, 16);
    game->option->left = load_that(tab, 17);
    game->option->right = load_that(tab, 18);
    game->option->inter = load_that(tab, 19);
    game->option->inv = load_that(tab, 20);
    game->option->pause = load_that(tab, 21);
    game->option->shield = load_that(tab, 22);
    game->option->attack = load_that(tab, 23);
    game->option->farm = load_that(tab, 24);
    game->pl->wood = load_that(tab, 7);
    game->perso->bouclier = load_that(tab, 8);
    game->perso->cherry = load_that(tab, 9);
}

void load_inventory(game_t *game, char **tab)
{
    sfSprite_setPosition(game->sprite[TEK1].sprite,
            (sfVector2f) {game->sprite[TEK1].pos.x = load_that(tab, 0),
            game->sprite[TEK1].pos.y = load_that(tab, 1)});
    game->perso->pain = load_that(tab, 2);
    game->perso->vin = load_that(tab, 3);
    game->perso->sharp = load_that(tab, 4);
    game->perso->axe = load_that(tab, 5);
    game->perso->pickaxe = load_that(tab, 6);
    game->sprite[HP].rect.width = load_that(tab, 10);
    sfSprite_setTextureRect(game->sprite[HP].sprite,
            game->sprite[HP].rect);
    game->sprite[XP].rect.width = load_that(tab, 11);
    sfSprite_setTextureRect(game->sprite[XP].sprite,
            game->sprite[XP].rect);
    game->pl->damage = load_that(tab, 12);
    game->pl->def = load_that(tab, 13);
    game->pl->lvl = load_that(tab, 14);
    load_key(game, tab);
}

void load_game(game_t *game)
{
    char *buffer = NULL;
    char **tab = NULL;
    size_t hello = 0;
    FILE *file = fopen("save/save.txt", "r");

    if (file == NULL)
        return;
    control(game);
    getline(&buffer, &hello, file);
    tab = malloc(sizeof(char *) * (my_getnbr(buffer) + 1));
    for (int i = 0; i < my_getnbr(buffer); i++) {
        tab[i] = malloc(sizeof(char));
        if (getline(&tab[i], &hello, file) == -1)
            return;
    }
    load_inventory(game, tab);
    game->load = 1;
    game->menu = 2;
    setting_texture("assets/img/inv_1.png", &game->inven_sp[ONE]);
}