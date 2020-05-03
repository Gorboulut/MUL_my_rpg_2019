/*
** EPITECH PROJECT, 2020
** in_lose.c
** File description:
** in_lose.c
*/

#include "../include/my_rpg.h"

void create_button_death(game_t *game)
{
    init_button_d(game, retry, (sfIntRect) {0, 0, 370, 120},
        (sfVector2f) {504, 690});
    init_button_d(game, exit_end, (sfIntRect) {0, 0, 355, 120},
        (sfVector2f) {1095, 690});
}

int death_animation(game_t *game)
{
    static float zoom = 0.5;

    if (game->sprite[HP].rect.width <= 0) {
        sfView_setCenter(game->camera, (sfVector2f)
            {game->sprite[TEK1].pos.x + 15, game->sprite[TEK1].pos.y + 18});
        sfView_zoom(game->camera, zoom);
        sfRenderWindow_setView(game->window, game->camera);
        zoom -= 0.01;
        if (zoom <= 0.0) {
            setting_texture("assets/img/death.png", &game->sprite[DEATH]);
            create_my_sprite((sfIntRect) {0, 0, 1920, 1080},
                (sfVector2f) {game->basic_pos.x, game->basic_pos.y},
                &game->sprite[DEATH]);
            create_button_death(game);
            game->menu = 5;
        }
        return (1);
    }
    return (0);
}

void in_lose(game_t *game)
{
    sfView_setSize(game->camera, (sfVector2f) {1920, 1080});
    sfRenderWindow_setView(game->window, game->camera);
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, game->sprite[DEATH].sprite, NULL);
}