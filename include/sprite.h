/*
** EPITECH PROJECT, 2020
** sprite.h
** File description:
** sprite.h
*/

#ifndef SPRITE_H
#define SPRITE_H

#define NB_SPRITES (7)
#define NB_INV (17)

typedef enum sprite_name_s {
    FIRE,
    TEK1,
    HP,
    XP,
    BAR,
    DEATH,
    TEXT
} sprite_name_t;

typedef enum sprite_inventory_s {
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    PAUSE,
    SWORD,
    AXE,
    PICKAXE,
    WOOD,
    VIN,
    PAIN,
    SHIELD,
    CHERRY_INV
} sprite_inventory_t;

typedef struct inv_s {
    int in_hand;
    int sharp;
    int perso_sharp;
    int bouclier;
    int axe;
    int pain;
    int vin;
    int pickaxe;
    char *text_wood;
    int cherry;
    char *text_pain;
    char *text_vin;
    char *text_cherry;
    sfFont *fontext;
    sfText *txt;
    sfText *txt_pain;
    sfText *txt_vin;
    sfText *txt_cherry;
} inv_t;

typedef struct sprite_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f pos;
    int speed;
} sprite_t;

#endif
