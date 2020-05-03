/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** create game
*/
#include "../include/my_rpg.h"

void set_my_texture_inventory(game_t *game)
{
    setting_texture("assets/img/inv_1.png", &game->inven_sp[ONE]);
    setting_texture("assets/img/inv_2.png", &game->inven_sp[TWO]);
    setting_texture("assets/img/inv_3.png", &game->inven_sp[THREE]);
    setting_texture("assets/img/inv_4.png", &game->inven_sp[FOUR]);
    setting_texture("assets/img/inv_5.png", &game->inven_sp[FIVE]);
    setting_texture("assets/img/inv_6.png", &game->inven_sp[SIX]);
    setting_texture("assets/img/inv_7.png", &game->inven_sp[SEVEN]);
    setting_texture("assets/img/inv_8.png", &game->inven_sp[EIGHT]);
    setting_texture("assets/img/R_sword.png", &game->inven_sp[SWORD]);
    setting_texture("assets/img/axe_inv.png", &game->inven_sp[AXE]);
    setting_texture("assets/img/pickaxe.png", &game->inven_sp[PICKAXE]);
    setting_texture("assets/img/wood.png", &game->inven_sp[WOOD]);
    setting_texture("assets/img/shield_inv.png", &game->inven_sp[SHIELD]);
    setting_texture("assets/img/pain.png", &game->inven_sp[PAIN]);
    setting_texture("assets/img/vin.png", &game->inven_sp[VIN]);
    setting_texture("assets/img/cherry.png", &game->inven_sp[CHERRY_INV]);
    setting_texture("assets/img/fire.png", &game->sprite[FIRE]);
}

void create_simple_elem(char *text, sprite_t *s)
{
    s->sprite = sfSprite_create();
    s->texture = sfTexture_createFromFile(text, NULL);
    sfSprite_setTexture(s->sprite, s->texture, sfTrue);
    s->rect = ((sfIntRect) {0, 0, 100, 100});
    s->pos = ((sfVector2f) {0, 0});
}

void create_simple_marvin(char *text, sprite_t *s)
{
    s->sprite = sfSprite_create();
    s->texture = sfTexture_createFromFile(text, NULL);
    sfSprite_setTexture(s->sprite, s->texture, sfTrue);
    s->rect = ((sfIntRect) {0, 0, 84, 77});
    s->pos = ((sfVector2f) {2950, 100});
    sfSprite_setPosition(s->sprite, s->pos);
    sfSprite_setTextureRect(s->sprite, s->rect);
}

void malloc_elem(game_t *game)
{
    game->pl = malloc(sizeof(player_t));
    game->pl->sword = malloc(sizeof(sprite_t));
    game->pl->pos = malloc(sizeof(s_t));
    game->pl->shield = malloc(sizeof(sprite_t));
    game->pl->axe = malloc(sizeof(sprite_t));
    game->marv = malloc(sizeof(marv_t));
    game->marv->start = malloc(sizeof(sprite_t));
    game->marv->idle = malloc(sizeof(sprite_t));
    game->marv->attack = malloc(sizeof(sprite_t));
    game->marv->hp = malloc(sizeof(sprite_t));
    game->marv->end = malloc(sizeof(sprite_t));
    game->marv->end_x = malloc(sizeof(sprite_t));
    game->death = malloc(sizeof(button_dead) * NB_BUTTON);
    game->pl->joh = malloc(sizeof(sprite_t));
    game->endsc = malloc(sizeof(sprite_t));
    game->pl->lvl = 1;
    game->pl->damage = 5;
    game->pl->def = 0;
}

void check_create(game_t *game)
{
    malloc_elem(game);
    create_simple_elem("assets/img/shield.png", game->pl->shield);
    create_simple_elem("assets/img/merci.png", game->endsc);
    create_simple_elem("assets/img/johan.png", game->pl->joh);
    create_simple_elem("assets/img/sword.png", game->pl->sword);
    create_simple_elem("assets/img/axe.png", game->pl->axe);
    create_simple_marvin("assets/img/marvin_attack.png", game->marv->attack);
    create_simple_marvin("assets/img/marvin_idle.png", game->marv->idle);
    create_simple_marvin("assets/img/marvin_start.png", game->marv->start);
    create_simple_marvin("assets/img/hp_bar.png", game->marv->hp);
    create_simple_marvin("assets/img/dead_marvin.png", game->marv->end);
    create_simple_marvin("assets/img/marvin_end.png", game->marv->end_x);
    game->pl->axe->rect = ((sfIntRect) {0, 0, 150, 150});
    game->marv->hp->rect = ((sfIntRect) {0, 442, 294, 55});
    game->endsc->rect = ((sfIntRect) {0, 0, 1920, 1080});
    game->endsc->pos = ((sfVector2f) {0, 0});
    sfSprite_setPosition(game->endsc->sprite, game->endsc->pos);
    sfSprite_setTextureRect(game->endsc->sprite, game->endsc->rect);
    sfSprite_setTextureRect(game->marv->hp->sprite, game->marv->hp->rect);
    sfSprite_setTextureRect(game->pl->axe->sprite, game->pl->axe->rect);
    create_marvin_death(game);
    create_marv_attack(game);
}
