/*
** EPITECH PROJECT, 2020
** in_play.c
** File description:
** in_play.c
*/

#include "../include/my_rpg.h"

static void  destroying_menu(game_t *game)
{
    static int i = 0;

    for (; i <= NB_MENU; i++)
        sfSprite_destroy(game->menu_sp[i].sprite);
}

void control(game_t *game)
{
    create_my_sprite((sfIntRect) {0, 0, 15, 26},
        (sfVector2f) {365, 335}, &game->sprite[TEK1]);
    create_my_sprite((sfIntRect) {0, 0, 189, 32},
        (sfVector2f) {600, 850}, &game->sprite[TEXT]);
    create_my_sprite((sfIntRect) {0, 0, 306, 25},
                        (sfVector2f) {0, 0}, &game->sprite[HP]);
    create_my_sprite((sfIntRect) {0, 0, 0, 20},
                        (sfVector2f) {0, 25}, &game->sprite[XP]);
    create_my_sprite((sfIntRect) {0, 0, 310, 50},
                        (sfVector2f) {0, 0}, &game->sprite[BAR]);
    sfSprite_scale(game->sprite[TEK1].sprite, (sfVector2f) {1.5, 1.5});
    sfSprite_scale(game->sprite[TEXT].sprite, (sfVector2f) {3, 3});
}

void set_view_two(game_t *game)
{
    if (game->sprite[TEK1].pos.x >= 2750 && game->sprite[TEK1].pos.y >= 2930)
        sfView_setCenter(game->camera, (sfVector2f) {2750, 2930});
    if (game->sprite[TEK1].pos.x <= 450 && game->sprite[TEK1].pos.y <= 270)
        sfView_setCenter(game->camera, (sfVector2f) {450, 270});
    if (game->sprite[TEK1].pos.x >= 2750 && game->sprite[TEK1].pos.y <= 270)
        sfView_setCenter(game->camera, (sfVector2f) {2750, 270});
    if (game->sprite[TEK1].pos.x <= 450 && game->sprite[TEK1].pos.y >= 2930)
        sfView_setCenter(game->camera, (sfVector2f) {450, 2930});
    game->pos_camera = sfView_getCenter(game->camera);
    sfSprite_setPosition(game->sprite[HP].sprite, (sfVector2f)
        {game->pos_camera.x - 450, game->pos_camera.y - 270});
    sfSprite_setPosition(game->sprite[XP].sprite, (sfVector2f)
        {game->pos_camera.x - 450, game->pos_camera.y - 270 + 25});
    sfSprite_setPosition(game->sprite[BAR].sprite, (sfVector2f)
        {game->pos_camera.x - 450, game->pos_camera.y - 271});
}

void set_view(game_t *game)
{
    if (death_animation(game) == 0 && game->pl->joh->pos.x == 0) {
        sfView_setSize(game->camera, (sfVector2f) {900, 540});
        if (game->sprite[TEK1].pos.x > 450 && game->sprite[TEK1].pos.y > 270)
            sfView_setCenter(game->camera,
            (sfVector2f) {game->sprite[TEK1].pos.x, game->sprite[TEK1].pos.y});
        if (game->sprite[TEK1].pos.x >= 2750)
            sfView_setCenter(game->camera, (sfVector2f) {2750,
                game->sprite[TEK1].pos.y});
        if (game->sprite[TEK1].pos.y >= 2930)
            sfView_setCenter(game->camera, (sfVector2f)
                {game->sprite[TEK1].pos.x, 2930});
        if (game->sprite[TEK1].pos.x <= 450)
            sfView_setCenter(game->camera, (sfVector2f)
                {450, game->sprite[TEK1].pos.y});
        else if (game->sprite[TEK1].pos.y <= 270)
            sfView_setCenter(game->camera, (sfVector2f)
                {game->sprite[TEK1].pos.x, 270});
        set_view_two(game);
        sfRenderWindow_setView(game->window, game->camera);
    }
}

void in_play(game_t *game)
{
    static int j = 0;

    destroying_menu(game);
    if (j == 0 && game->load == 0) {
        setting_texture("assets/img/inv_1.png", &game->inven_sp[ONE]);
        control(game);
        j = 1;
    }
    if (game->menu == 2) {
        set_view(game);
        sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    } sfRenderWindow_clear(game->window, sfBlack);
    for (int i = 0; i < game->tile->tabvertex; i++)
        sfRenderWindow_drawVertexArray(game->window, game->tile->tilemap[i],
        &game->tile->states[i]);
    for (int i = 0; i < (NB_SPRITES - 2); i++)
        sfRenderWindow_drawSprite(game->window, game->sprite[i].sprite, NULL);
    all_interaction_object(game);
    marvin_play(game);
}
