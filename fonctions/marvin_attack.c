/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** marvin attack
*/

#include "../include/my_rpg.h"

void check_hit(game_t *game)
{
    for (int i = 0; i < 8 && game->pl->prot == 0; i++) {
        if (game->marv->atk1->pos.x + 38 > game->sprite[TEK1].pos.x &&
            game->marv->atk1->pos.x - 14 < game->sprite[TEK1].pos.x &&
            game->marv->atk1->pos.y + 38 >= game->sprite[TEK1].pos.y &&
            game->marv->atk1->pos.y - 14 <= game->sprite[TEK1].pos.y)
            change_hp(game, -4);
        game->marv->atk1 = game->marv->atk1->next;
    }
    if (game->marv->activ2 >= 2)
        for (int i = 0; i < 8 && game->pl->prot == 0; i++) {
                if (game->marv->atk2->pos.x + 38 > game->sprite[TEK1].pos.x &&
                    game->marv->atk2->pos.x - 14 < game->sprite[TEK1].pos.x &&
                    game->marv->atk2->pos.y + 38 > game->sprite[TEK1].pos.y &&
                    game->marv->atk2->pos.y - 14 < game->sprite[TEK1].pos.y)
                    change_hp(game, -4);
                game->marv->atk2 = game->marv->atk2->next;
        }
    check_hit_two(game);
}

void marvin_show_second_attack(game_t *game)
{
    for (int i = 0; i < 8; i++) {
        sfSprite_setPosition(game->marv->atk2->spr, game->marv->atk2->pos);
        game->marv->atk2 = game->marv->atk2->next;
    }
    for (int i = 0; i < 8; i++) {
        sfRenderWindow_drawSprite(game->window, game->marv->atk2->spr, NULL);
        game->marv->atk2 = game->marv->atk2->next;
    }
}

void show_first_attack(game_t *game)
{
    for (int i = 0; i < 8; i++) {
        sfSprite_setPosition(game->marv->atk1->spr, game->marv->atk1->pos);
        game->marv->atk1 = game->marv->atk1->next;
    }
    for (int i = 0; i < 8; i++) {
        sfRenderWindow_drawSprite(game->window, game->marv->atk1->spr, NULL);
        game->marv->atk1 = game->marv->atk1->next;
    }
}

void show_attack(game_t *game)
{
    game->marv->hp->pos = ((sfVector2f) {game->pos_camera.x + 158,
        game->pos_camera.y - 275});
    sfSprite_setPosition(game->marv->hp->sprite, game->marv->hp->pos);
    sfRenderWindow_drawSprite(game->window, game->marv->hp->sprite, NULL);
    if (game->pl->touch == 1) {
        game->marv_l += 1;
        if (game->marv_l == 3) {
            if (game->marv->hp->rect.top < 350)
                game->marv->phase = 2;
            if (game->marv->hp->rect.top < 190)
                game->marv->phase = 3;
            if (game->marv->hp->rect.top < 25)
                game->marv->death = 1;
            game->marv_l = 0;
            game->marv->hp->rect.top -= 55;
            sfSprite_setTextureRect(game->marv->hp->sprite,
                game->marv->hp->rect);
        }
    } show_first_attack(game);
    if (game->marv->activ2 >= 2)
        marvin_show_second_attack(game);
    check_hit(game);
}

void marvin_launch_attack(game_t *game)
{
    marvin_direction_first_attack(game);
    if (game->marv->activ2 >= 2)
        marvin_direction_second_attack(game);
    for (int i = 0; i < 8; i++) {
        sfSprite_setTextureRect(game->marv->atk1->spr, game->marv->atk1->rect);
        game->marv->atk1->rect.left += 46;
        if (game->marv->atk1->rect.left > 1350)
            game->marv->atk1->rect.left = 0;
        game->marv->atk1 = game->marv->atk1->next;
    } for (int i = 0; i < 8; i++) {
        sfSprite_setTextureRect(game->marv->atk2->spr, game->marv->atk2->rect);
        game->marv->atk2->rect.left += 46;
        if (game->marv->atk2->rect.left > 1350)
            game->marv->atk2->rect.left = 0;
        game->marv->atk2 = game->marv->atk2->next;
    }
}
