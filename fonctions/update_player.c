/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** update_player.c
*/

#include "my_rpg.h"

void reset_value(game_t *game)
{
    game->dialogue = 0;
    game->inventory = 0;
    game->load = 0;
    game->count = 0;
    game->perso->in_hand = 0;
    game->perso->perso_sharp = 1;
    game->perso->bouclier = 0;
    game->perso->pickaxe = 0;
    game->perso->sharp = 0;
    game->perso->axe = 0;
    game->marv->atk = 0;
    game->marv->mode = 0;
    game->marv->phase = 1;
    game->marv->activ = 0;
    game->sprite[TEK1].pos.x = 365;
    game->sprite[TEK1].pos.y = 335;
    setting_value_two(game);
}

void stat_up(game_t *game)
{
    game->pl->damage += 5;
    game->pl->def += 5;
}

void change_hp(game_t *game, int hp)
{
    if (hp > 0)
        game->sprite[HP].rect.width += hp;
    if (hp < 0)
        game->sprite[HP].rect.width += (hp - (game->pl->def / 5));
    if (game->sprite[HP].rect.width > 306)
        game->sprite[HP].rect.width = 306;
    sfSprite_setTextureRect(game->sprite[HP].sprite, game->sprite[HP].rect);
}

void lvl_up(game_t *game, int test)
{
    if (game->sprite[XP].rect.width > 250) {
        game->pl->lvl++;
        stat_up(game);
        game->sprite[XP].rect.width = test;
        sfSprite_setTextureRect(game->sprite[XP].sprite,
            game->sprite[XP].rect);
    }
}

void change_xp(game_t *game, int xp)
{
    int test = 0;

    if ((game->pl->lvl * 10) < xp)
        game->sprite[XP].rect.width += (xp - (game->pl->lvl * 10));
    if (game->sprite[XP].rect.width > 250) {
        test = game->sprite[XP].rect.width - 250;
        lvl_up(game, test);
    }
    sfSprite_setTextureRect(game->sprite[XP].sprite, game->sprite[XP].rect);
}
