/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** marvin
*/
#include "my_rpg.h"

#ifndef MARVIN_H_
#define MARVIN_H_

typedef struct marvin_atk_s {
    sfSprite *spr;
    sfTexture *tex;
    sfVector2f pos;
    sfIntRect rect;
    struct marvin_atk_s *next;
} m_atk_t;

typedef struct marvin_s {
    sprite_t *start;
    sprite_t *idle;
    sprite_t *attack;
    sprite_t *hp;
    sprite_t *end_x;
    sprite_t *end;
    m_atk_t *atk1;
    m_atk_t *atk2;
    m_atk_t *atk3;
    m_atk_t *atk3_i;
    int atk;
    int phase;
    int activ2;
    int activ3;
    int reset_atk;
    int activ;
    int mode;
    int death;
} marv_t;

#endif
