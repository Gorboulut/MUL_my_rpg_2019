/*
** EPITECH PROJECT, 2020
** game_update.c
** File description:
** game_update.c
*/

#include "../include/my_rpg.h"

static void control_left(game_t *game, int speed)
{
    if (sfKeyboard_isKeyPressed(game->option->left) &&
        collision(game, 0, -1) != NULL) {
        game->pl->atk = 1;
        game->sprite[TEK1].pos.x -= speed * game->clock;
        game->sprite[TEK1].rect.top = 72;
        if (game->sprite[TEK1].rect.left >= 45)
            game->sprite[TEK1].rect.left = 0;
        game->sprite[TEK1].rect.left += 15;
        sfSprite_setPosition(game->sprite[TEK1].sprite,
                game->sprite[TEK1].pos);
        sfView_setCenter(game->camera, (sfVector2f) {game->sprite[TEK1].pos.x,
                game->sprite[TEK1].pos.y});
        sfSprite_setTextureRect(game->sprite[TEK1].sprite,
                                game->sprite[TEK1].rect);
    }
}

static void control_right(game_t *game, int speed)
{
    if (sfKeyboard_isKeyPressed(game->option->right) &&
        collision(game, 0, 1) != NULL) {
        game->pl->atk = 2;
        game->sprite[TEK1].pos.x += speed * game->clock;
        game->sprite[TEK1].rect.top = 24;
        if (game->sprite[TEK1].rect.left >= 45)
            game->sprite[TEK1].rect.left = 0;
        game->sprite[TEK1].rect.left += 15;
        sfSprite_setPosition(game->sprite[TEK1].sprite,
                game->sprite[TEK1].pos);
        sfView_setCenter(game->camera, (sfVector2f) {game->sprite[TEK1].pos.x,
        game->sprite[TEK1].pos.y});
        sfSprite_setTextureRect(game->sprite[TEK1].sprite,
                game->sprite[TEK1].rect);
    }

}

static void control_down(game_t *game, int speed)
{
    if (sfKeyboard_isKeyPressed(game->option->bot) &&
        collision(game, 1, 0) != NULL) {
        game->pl->atk = 3;
        game->sprite[TEK1].pos.y += speed * game->clock;
        game->sprite[TEK1].rect.top = 0;
        if (game->sprite[TEK1].rect.left >= 45)
            game->sprite[TEK1].rect.left = 0;
        game->sprite[TEK1].rect.left += 15;
        sfSprite_setPosition(game->sprite[TEK1].sprite,
                game->sprite[TEK1].pos);
        sfView_setCenter(game->camera, (sfVector2f) {game->sprite[TEK1].pos.x,
        game->sprite[TEK1].pos.y});
        sfSprite_setTextureRect(game->sprite[TEK1].sprite,
                                game->sprite[TEK1].rect);
    }
}

static void control_top(game_t *game, int speed)
{
    if (sfKeyboard_isKeyPressed(game->option->top) &&
        collision(game, -1, 0) != NULL) {
        game->pl->atk = 4;
        game->sprite[TEK1].pos.y -= speed * game->clock;
        game->sprite[TEK1].rect.top = 48;
        if (game->sprite[TEK1].rect.left >= 45)
            game->sprite[TEK1].rect.left = 0;
        game->sprite[TEK1].rect.left += 15;
        sfSprite_setPosition(game->sprite[TEK1].sprite,
                game->sprite[TEK1].pos);
        sfView_setCenter(game->camera, (sfVector2f) {game->sprite[TEK1].pos.x,
        game->sprite[TEK1].pos.y});
        sfSprite_setTextureRect(game->sprite[TEK1].sprite,
                game->sprite[TEK1].rect);
    }
}

void game_update(game_t *game, float elapsed)
{

    game->size = sfRenderWindow_getSize(game->window);

    if (game->menu == 2 && game->dialogue == 0) {
        control_right(game, 400);
        control_down(game, 400);
        control_left(game, 400);
        control_top(game, 400);
    }
    if (elapsed > 0.02) {
        game->sprite[FIRE].rect.left += 20;
        if (game->sprite[FIRE].rect.left >= 60)
            game->sprite[FIRE].rect.left = 0;
        sfSprite_setTextureRect(game->sprite[FIRE].sprite,
                game->sprite[FIRE].rect);
    }
}
