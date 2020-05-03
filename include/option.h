/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** option.h
*/


#ifndef OPTION_H_
#define OPTION_H_
#include "my_rpg.h"

#define NB_BUTTON (10)

typedef struct game_s game_t;

typedef enum button_e {
    TOP,
    BOT,
    LEFT,
    RIGHT,
    INTERACT,
    INV,
    PAUSED,
    SHIELDED,
    FARM,
    ATTACK
} button;

typedef struct button_s {
    sfIntRect rect;
    sfVector2f pos;
    void (*fct) (game_t *game);
    int nb_b;
} button_t;

typedef struct option_s {
    int top;
    int bot;
    int left;
    int right;
    int inter;
    int inv;
    int pause;
    int key;
    int shield;
    int farm;
    int attack;
    button_t button[NB_BUTTON];
} option_t;

#endif /*OPTION_H_*/