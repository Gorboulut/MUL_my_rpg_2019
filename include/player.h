/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** player.h
*/

#ifndef PLAYER_H_
#define PLAYER_H_

typedef struct s_s {
    int x;
    int y;
} s_t;

typedef struct player_s {
    int atk;
    int prot;
    int cut;
    int lvl;
    int damage;
    int def;
    s_t *pos;
    int wood;
    int touch;
    sprite_t *sword;
    sprite_t *shield;
    sprite_t *axe;
    sprite_t *joh;
} player_t;

#endif /* PLAYHER_H_*/
