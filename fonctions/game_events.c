/*
** EPITECH PROJECT, 2020
** game_events.c
** File description:
** game_event.c
*/

#include "../include/my_rpg.h"

void menu_change(game_t *game, sfVector2i c)
{
    if (game->menu == 0 && c.x > 600 && c.x < 825 && c.y < 1060 && c.y > 885) {
        reset_value(game);
        game->menu = 2;
    }
    if (game->menu == 0 && c.x > 1845 && c.x < 1895 && c.y < 74 && c.y > 24)
        game->menu = 1;
    if (game->menu == 0 && c.x > 1095 && c.x < 1318 && c.y < 1060 && c.y > 885)
        sfRenderWindow_close(game->window);
    if (game->menu == 0 && c.x > 1810 && c.x < 1875 && c.y < 1060 && c.y > 985)
        game->menu = 6;
    if ((game->menu == 1 || game->menu == 8 || game->menu == 9)
        && c.x > 230 && c.x < 290 && c.y < 900 && c.y > 868)
        game->menu = 0;
    if (game->menu == 6 && c.x > 355 && c.x < 400 && c.y < 720 && c.y > 695)
        game->menu = 0;
    if (game->menu == 0 && c.x > 846 && c.x < 1072 && c.y < 1060 && c.y > 885)
        load_game(game);
    if (game->menu == 1 && c.x > 620 && c.x < 1290 && c.y > 680 && c.y < 825)
        game->menu = 8;
}

void check_volume_change(game_t *game, sfVector2i c)
{
    if (c.x > 835 && c.x < 870 && c.y > 400 && c.y < 435) {
        game->volume = game->volume->prev;
        sfMusic_setVolume(game->game_music, game->volume->vol);
        sfSound_setVolume(game->s->shield, game->volume->vol);
        sfSound_setVolume(game->s->sword, game->volume->vol);
        sfSound_setVolume(game->s->prep, game->volume->vol);
        sfSound_setVolume(game->s->laser, game->volume->vol);
        sfSound_setVolume(game->s->fire, game->volume->vol);
    }
    if (c.x > 1050 && c.x < 1085 && c.y > 400 && c.y < 435) {
        game->volume = game->volume->next;
        sfMusic_setVolume(game->game_music, game->volume->vol);
        sfSound_setVolume(game->s->shield, game->volume->vol);
        sfSound_setVolume(game->s->sword, game->volume->vol);
        sfSound_setVolume(game->s->prep, game->volume->vol);
        sfSound_setVolume(game->s->laser, game->volume->vol);
        sfSound_setVolume(game->s->fire, game->volume->vol);
    } if (c.x > 835 && c.x < 870 && c.y > 550 && c.y < 585)
        game->text_speed = game->text_speed->prev;
    if (c.x > 1050 && c.x < 1085 && c.y > 550 && c.y < 585)
        game->text_speed = game->text_speed->next;
}

void manage_click(game_t *game)
{
    sfVector2i c = sfMouse_getPositionRenderWindow(game->window);

    if (game->menu == 1 || game->menu == 0 || game->menu == 6
        || game->menu == 8 || game->menu == 9)
        menu_change(game, c);
    if (game->menu == 1)
        check_volume_change(game, c);
    if (game->menu == 7)
        change_inventory(game, c);
    if (game->menu == 3)
        click_pause(game, c);
    if (game->menu == 8)
        button_is_clicked(game, c);
    if (game->menu == 5)
        button_is_clicked_death(game, c);
}

void game_change_key(game_t *game)
{
    if (game->menu == 9) {
        switch (game->option->key) {
            case 1: game->option->top = game->key.code; break;
            case 2: game->option->bot = game->key.code; break;
            case 3: game->option->left = game->key.code; break;
            case 4: game->option->right = game->key.code; break;
            case 5: game->option->inter = game->key.code; break;
            case 6: game->option->inv = game->key.code; break;
            case 7: game->option->pause = game->key.code; break;
            case 8: game->option->shield = game->key.code; break;
            case 9: game->option->attack = game->key.code; break;
            case 10: game->option->farm = game->key.code; break;
        }
        game->menu = 8;
    }
}

void game_events(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (game->event.type == sfEvtKeyPressed) {
            game->key = game->event.key;
            game_change_key(game);
            in_game_events(game);
        }
        if (game->event.type == sfEvtMouseButtonPressed)
            if (game->event.mouseButton.button == sfMouseLeft)
                manage_click(game);
    }
    set_value_in_string(game);
}
