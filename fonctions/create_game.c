/*
** EPITECH PROJECT, 2020
** create_game.c
** File description:
** create_game.c
*/

#include "../include/my_rpg.h"

void create_my_window(game_t *game)
{
    sfVideoMode mode = {1920, 1080, 32};
    game->window = sfRenderWindow_create(mode, "RPG", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    game->view_rect = (sfFloatRect) {0, 0, 1000, 540};
    game->camera = sfView_createFromRect(game->view_rect);
}

void create_my_text(char *font, char *text, sfVector2f x, text_t *tx)
{
    if (tx == NULL)
        return;
    tx->text = sfText_create();
    sfText_setString(tx->text, text);
    tx->font = sfFont_createFromFile(font);
    sfText_setFont(tx->text, tx->font);
    sfText_setCharacterSize(tx->text, 13);
    sfText_setPosition(tx->text, x);
    sfText_setColor(tx->text, sfBlack);
}

void create_my_sprite(sfIntRect pos, sfVector2f x, sprite_t *sp)
{
    if (sp == NULL)
        return;
    sp->sprite = sfSprite_create();
    sfSprite_setTexture(sp->sprite, sp->texture, sfTrue);
    sp->rect = pos;
    sfSprite_setTextureRect(sp->sprite, sp->rect);
    sp->pos = x;
    sfSprite_setPosition(sp->sprite, sp->pos);
}

void setting_texture(char *path, sprite_t *sp)
{
    sp->texture = sfTexture_createFromFile(path, NULL);
}

void create_game(game_t *game)
{
    check_create(game);
    setting_value(game);
    create_my_window(game);
    set_my_texture(game);
    set_my_text(game);
    create_vol(game);
    create_speed_text(game);
    creating_tiled_map(game);
    init_option(game);
    set_nb_text(game);
    set_sound(game);
    game->sprite[TEK1].speed = 100;
    game->text_speed = game->text_speed->next;
    game->game_music = sfMusic_createFromFile("assets/sound/music.ogg");
    game->volume = game->volume->next;
    sfMusic_setVolume(game->game_music, game->volume->vol);
}
