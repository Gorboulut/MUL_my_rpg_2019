/*
** EPITECH PROJECT, 2020
** text.h
** File description:
** text.h
*/

#ifndef TEXT_H
#define TEXT_H

#define TXT (13)

typedef enum text_nb_s {
    EMPTY,
    COLLIDE,
    ROCK1,
    ROCK2,
    ROCK3,
    ROCK4,
    ROCK5,
    ROCK6,
    FOUNTAIN,
    CHERRY,
    MAILBOX,
    MAILBOXA,
    DIRECTION,
    GRAVES,
    CARAVANE,
    TRASH,
    GAMES,
    BRIDGE,
    CAVE,
    ARCHI,
    WILLY,
    CHILD,
    MOM,
    PIRATE,
    FORGER,
    GRAVEMAN,
    DRUNKMAN,
    MINEROCK,
    PIRATEBRIDGE
} text_nb_t;

typedef enum text_name_s {
    ARCHI_TX,
    TITLE_TX,
    TOP_TX,
    BOT_TX,
    LEFT_TX,
    RIGHT_TX,
    INTERACT_TX,
    INV_TX,
    PAUSED_TX,
    SHIELD_TX,
    ATTACK_TX,
    FARM_TX,
    QUEST_TX
} text_name_t;

typedef struct text_s {
    sfText *text;
    sfFont *font;
} text_t;

#endif