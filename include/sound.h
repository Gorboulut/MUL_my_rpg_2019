/*
** EPITECH PROJECT, 2020
** sound.h
** File description:
** sound.h
*/

#ifndef SOUND_H
#define SOUND_H

typedef struct vol_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    struct vol_s *next;
    struct vol_s *prev;
    int vol;
} vol_t;

typedef struct music_s {
    sfMusic *music_menu;
    sfMusic *game_music;
} music_t;

typedef struct sound_s {
    sfSound *shield;
    sfSound *sword;
    sfSound *laser;
    sfSound *fire;
    sfSound *prep;
    sfSound *end;
    sfSoundBuffer *buf_sh;
    sfSoundBuffer *buf_sw;
    sfSoundBuffer *buf_l;
    sfSoundBuffer *buf_f;
    sfSoundBuffer *buf_p;
    sfSoundBuffer *buf_e;
} sound_t;

#endif
