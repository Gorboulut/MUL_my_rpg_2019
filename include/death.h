/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** death.h
*/

#ifndef DEATH_H_
#define DEATH_H_

#include "my_rpg.h"

#define BUTTON_DEATH (2)

typedef struct game_s game_t;

typedef enum button_m {
    RETRY,
    EXIT_END
} button_death;

typedef struct button_d {
    sfIntRect rect;
    sfVector2f pos;
    void (*fct) (game_t *game);
    int nb_b;
} button_dead;

#endif /* DEATH_H_ */