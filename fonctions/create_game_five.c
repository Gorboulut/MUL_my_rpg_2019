/*
** EPITECH PROJECT, 2020
** create_game_five.c
** File description:
** create_game_five.c
*/

#include "../include/my_rpg.h"

void set_sound(game_t *game)
{
    game->s = malloc(sizeof(sound_t));
    game->s->shield = sfSound_create();
    game->s->sword = sfSound_create();
    game->s->laser = sfSound_create();
    game->s->fire = sfSound_create();
    game->s->prep = sfSound_create();
    game->s->end = sfSound_create();
    game->s->buf_f = sfSoundBuffer_createFromFile("assets/sound/fire.wav");
    game->s->buf_sh = sfSoundBuffer_createFromFile("assets/sound/shield.wav");
    game->s->buf_sw = sfSoundBuffer_createFromFile("assets/sound/sword.wav");
    game->s->buf_p = sfSoundBuffer_createFromFile("assets/sound/in.wav");
    game->s->buf_l = sfSoundBuffer_createFromFile("assets/sound/laser.wav");
    game->s->buf_e = sfSoundBuffer_createFromFile("assets/sound/explo.wav");
    sfSound_setBuffer(game->s->shield, game->s->buf_sh);
    sfSound_setBuffer(game->s->sword, game->s->buf_sw);
    sfSound_setBuffer(game->s->fire, game->s->buf_f);
    sfSound_setBuffer(game->s->prep, game->s->buf_p);
    sfSound_setBuffer(game->s->laser, game->s->buf_l);
    sfSound_setBuffer(game->s->end, game->s->buf_e);
}

void setting_value_two(game_t *game)
{
    game->perso->in_hand = 0;
    game->perso->perso_sharp = 1;
    game->perso->bouclier = 0;
    game->perso->pickaxe = 0;
    game->perso->sharp = 0;
    game->perso->axe = 0;
    game->pl->atk = 3;
    game->pl->prot = 0;
    game->pl->cut = 0;
    game->pl->wood = 0;
    game->perso->cherry = 0;
    game->secondes = 0;
    game->quest = 0;
    game->perso->pain = 5;
    game->perso->vin = 5;
    game->pl->touch = 0;
    game->marv->activ2 = 1;
    game->marv->activ3 = 0;
    game->marv->death = 0;
}

void add_fire(game_t *game)
{
    create_my_sprite((sfIntRect) {0, 0, 20, 22},
                    (sfVector2f) {150, 3070}, &game->sprite[FIRE]);
}

void game_initialisation_three(game_t *game)
{
    create_my_sprite((sfIntRect) {0, 0, 117, 86},
                    (sfVector2f) {game->basic_pos.x + 255,
                    game->basic_pos.y + 217}, &game->inven_sp[VIN]);
    create_my_sprite((sfIntRect) {0, 0, 117, 86},
                    (sfVector2f) {game->basic_pos.x + 1055,
                    game->basic_pos.y + 217}, &game->inven_sp[CHERRY_INV]);
}

void game_initialisation_two(game_t *game)
{
    create_my_sprite((sfIntRect) {0, 0, 117, 86},
                    (sfVector2f) {game->basic_pos.x + 523,
                    game->basic_pos.y + 217}, &game->inven_sp[AXE]);
    create_my_sprite((sfIntRect) {0, 0, 100, 90},
                    (sfVector2f) {game->basic_pos.x + 660,
                    game->basic_pos.y + 212}, &game->inven_sp[PICKAXE]);
    create_my_sprite((sfIntRect) {0, 0, 89, 87},
                    (sfVector2f) {game->basic_pos.x + 800,
                    game->basic_pos.y + 217}, &game->inven_sp[WOOD]);
    create_my_sprite((sfIntRect) {0, 0, 85, 82},
                    (sfVector2f) {game->basic_pos.x + 940,
                    game->basic_pos.y + 217}, &game->inven_sp[SHIELD]);
    create_my_sprite((sfIntRect) {0, 0, 117, 86},
                    (sfVector2f) {game->basic_pos.x + 123,
                    game->basic_pos.y + 217}, &game->inven_sp[PAIN]);
    game_initialisation_three(game);
}
