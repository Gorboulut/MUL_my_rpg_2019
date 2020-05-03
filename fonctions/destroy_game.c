/*
** EPITECH PROJECT, 2020
** destroy_game.c
** File description:
** destroy_game.c
*/

#include "../include/my_rpg.h"

void destroy_game(game_t *game)
{
    for (int i = 0; i < NB_SPRITES; i++)
        sfSprite_destroy(game->sprite[i].sprite);
    sfMusic_destroy(game->game_music);
    sfSound_destroy(game->s->shield);
    sfSound_destroy(game->s->sword);
    sfSound_destroy(game->s->laser);
    sfSound_destroy(game->s->fire);
    sfSound_destroy(game->s->prep);
    sfSound_destroy(game->s->end);
    sfSoundBuffer_destroy(game->s->buf_f);
    sfSoundBuffer_destroy(game->s->buf_sh);
    sfSoundBuffer_destroy(game->s->buf_sw);
    sfSoundBuffer_destroy(game->s->buf_p);
    sfSoundBuffer_destroy(game->s->buf_l);
    sfSoundBuffer_destroy(game->s->buf_e);
    for (int i = 0; i < game->tile->tabvertex; i++)
        sfVertexArray_destroy(game->tile->tilemap[i]);
}
