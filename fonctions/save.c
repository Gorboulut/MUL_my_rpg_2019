/*
** EPITECH PROJECT, 2020
** save.c
** File description:
** save.c
*/

#include "../include/my_rpg.h"

static void save_that(int data, FILE *file_ptr)
{
    char *save = my_itoa(data);
    save = new_strcat(save, '\n');

    fwrite(save, 1, my_strlen(save), file_ptr);
}

void save_key(game_t *game, FILE *file_ptr)
{
    save_that(game->option->top, file_ptr);
    save_that(game->option->bot, file_ptr);
    save_that(game->option->left, file_ptr);
    save_that(game->option->right, file_ptr);
    save_that(game->option->inter, file_ptr);
    save_that(game->option->inv, file_ptr);
    save_that(game->option->pause, file_ptr);
    save_that(game->option->shield, file_ptr);
    save_that(game->option->attack, file_ptr);
    save_that(game->option->farm, file_ptr);
}

void save_inv(game_t *game, FILE *file_ptr)
{
    save_that(game->perso->pain, file_ptr);
    save_that(game->perso->vin, file_ptr);
    save_that(game->perso->sharp, file_ptr);
    save_that(game->perso->axe, file_ptr);
    save_that(game->perso->pickaxe, file_ptr);
    save_that(game->pl->wood, file_ptr);
    save_that(game->perso->bouclier, file_ptr);
    save_that(game->perso->cherry, file_ptr);
}

void create_my_save(game_t *game)
{
    FILE *file_ptr;

    file_ptr = fopen("save/save.txt", "wb");
    if (file_ptr == NULL)
        return;
    save_that(25, file_ptr);
    save_that(game->sprite[TEK1].pos.x, file_ptr);
    save_that(game->sprite[TEK1].pos.y, file_ptr);
    save_inv(game, file_ptr);
    save_that(game->sprite[HP].rect.width, file_ptr);
    save_that(game->sprite[XP].rect.width, file_ptr);
    save_that(game->pl->damage, file_ptr);
    save_that(game->pl->def, file_ptr);
    save_that(game->pl->lvl, file_ptr);
    save_key(game, file_ptr);
    fclose(file_ptr);
}