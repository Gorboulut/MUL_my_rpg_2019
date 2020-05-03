/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** marvin death
*/
#include "../include/my_rpg.h"

void make_remerciement(game_t *game)
{
    if (game->endsc->rect.top < 3000) {
        sfRenderWindow_drawSprite(game->window, game->endsc->sprite, NULL);
        if (game->secondes % 2 == 0) {
            game->endsc->rect.top += 2;
            sfSprite_setTextureRect(game->endsc->sprite, game->endsc->rect);
        }
    } else
        sfRenderWindow_close(game->window);
}

void interaction_johan(game_t *game)
{
    static int i = 0;

    if (game->johan[i] != NULL) {
        sfView_zoom(game->camera, 0.3);
        sfText_setScale(game->text[ARCHI_TX].text, (sfVector2f) {0.6, 0.6});
        sfText_setPosition(game->text[ARCHI_TX].text, (sfVector2f)
        {2820, 220});
        sfSprite_setScale(game->sprite[TEXT].sprite, (sfVector2f) {2, 1.5});
        sfView_setCenter(game->camera, ((sfVector2f) {2900, 180}));
        sfSprite_setPosition(game->sprite[TEXT].sprite,
            (sfVector2f) {2800, 200});
        sfRenderWindow_drawSprite(game->window,
            game->sprite[TEXT].sprite, NULL);
        if (print_text(game, game->text[ARCHI_TX].text, game->johan[i]))
            i++;
    }
    if (game->johan[i] == NULL) {
        sfView_zoom(game->camera, 1);
        sfView_setCenter(game->camera, ((sfVector2f) {960, 525}));
        make_remerciement(game);
    }
    sfRenderWindow_setView(game->window, game->camera);
    sfRenderWindow_drawSprite(game->window, game->pl->joh->sprite, NULL);
}

void start_cin_end(game_t *game)
{
    if (game->pl->joh->pos.x == 0) {
        game->pl->joh->pos = ((sfVector2f) {2900, 120});
        game->sprite[TEK1].pos = ((sfVector2f) {2820, 120});
        game->key.code = sfFalse;
        sfSprite_setPosition(game->pl->joh->sprite, game->pl->joh->pos);
        sfSprite_setPosition(game->sprite[TEK1].sprite, game->sprite[TEK1].pos);
    }
    interaction_johan(game);
}

void marvin_death(game_t *game)
{
    if (game->marv->end_x->rect.left == 0)
        sfSound_play(game->s->end);
    if (game->marv->end_x->rect.left < 650) {
        sfRenderWindow_drawSprite(game->window,
            game->marv->end_x->sprite, NULL);
        if (game->secondes % 14 == 0) {
            game->marv->end_x->rect.left += 90;
            sfSprite_setTextureRect(game->marv->end_x->sprite,
                game->marv->end_x->rect);
        }
    } else
        start_cin_end(game);
    sfRenderWindow_drawSprite(game->window, game->marv->end->sprite, NULL);
}
