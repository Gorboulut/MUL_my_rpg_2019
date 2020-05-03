/*
** EPITECH PROJECT, 2020
** create_game.c
** File description:
** create_game.c
*/

#include "../include/my_rpg.h"
#include <stdio.h>

void set_my_texture(game_t *game)
{
    set_my_texture_inventory(game);
    setting_texture("assets/img/menu.png", &game->menu_sp[MENU]);
    setting_texture("assets/img/settings.png", &game->menu_sp[OPTION]);
    setting_texture("assets/img/option.png", &game->menu_sp[SETTINGS]);
    setting_texture("assets/img/how_play.png", &game->menu_sp[HOW]);
    setting_texture("assets/img/pause.png", &game->inven_sp[PAUSE]);
    setting_texture("assets/img/back_play.png", &game->menu_sp[BACK_PLAY]);
    setting_texture("assets/img/new.png", &game->menu_sp[NEW]);
    setting_texture("assets/img/load.png", &game->menu_sp[LOAD]);
    setting_texture("assets/img/exit.png", &game->menu_sp[EXIT]);
    setting_texture("assets/img/inter.png", &game->menu_sp[INTER]);
    setting_texture("assets/img/back_op.png", &game->menu_sp[BACK_OP]);
    setting_texture("assets/img/tek1.png", &game->sprite[TEK1]);
    setting_texture("assets/img/hp.png", &game->sprite[HP]);
    setting_texture("assets/img/xp.png", &game->sprite[XP]);
    setting_texture("assets/img/hp_xp.png", &game->sprite[BAR]);
    setting_texture("assets/img/text.png", &game->sprite[TEXT]);
    setting_texture("assets/img/option2.png", &game->menu_sp[SETTINGS2]);
}

void game_initialisation(game_t *game)
{
    create_my_sprite((sfIntRect) {0, 0, 1920, 1080},
                    (sfVector2f) {0, 0}, &game->inven_sp[ONE]);
    create_my_sprite((sfIntRect) {0, 0, 1920, 1080},
                    (sfVector2f) {0, 0}, &game->inven_sp[TWO]);
    create_my_sprite((sfIntRect) {0, 0, 1920, 1080},
                    (sfVector2f) {0, 0}, &game->inven_sp[THREE]);
    create_my_sprite((sfIntRect) {0, 0, 1920, 1080},
                    (sfVector2f) {0, 0}, &game->inven_sp[FOUR]);
    create_my_sprite((sfIntRect) {0, 0, 1920, 1080},
                    (sfVector2f) {0, 0}, &game->inven_sp[FIVE]);
    create_my_sprite((sfIntRect) {0, 0, 1920, 1080},
                    (sfVector2f) {0, 0}, &game->inven_sp[SIX]);
    create_my_sprite((sfIntRect) {0, 0, 1920, 1080},
                    (sfVector2f) {0, 0}, &game->inven_sp[SEVEN]);
    create_my_sprite((sfIntRect) {0, 0, 1920, 1080},
                    (sfVector2f) {0, 0}, &game->inven_sp[EIGHT]);
    create_my_sprite((sfIntRect) {0, 0, 117, 86},
                    (sfVector2f) {game->basic_pos.x + 388,
                    game->basic_pos.y + 217}, &game->inven_sp[SWORD]);
    game_initialisation_two(game);
}

void *create_map(game_t *game, char ***map, sfVector2i tSize, char *tileset)
{
    if (map == NULL)
        return (NULL);
    create_vertex_array(game, tileset);
    create_vertex(game, map, tSize);
    game->tile->tabvertex++;
    return (NULL + 1);
}

void set_text_option(game_t *game)
{
    create_my_text("assets/txt/pokemon.ttf", get_key(game->option->top),
            (sfVector2f) {624, 356}, &game->text[TOP_TX]);
    create_my_text("assets/txt/pokemon.ttf", get_key(game->option->bot),
            (sfVector2f) {624, 486}, &game->text[BOT_TX]);
    create_my_text("assets/txt/pokemon.ttf", get_key(game->option->left),
            (sfVector2f) {624, 611}, &game->text[LEFT_TX]);
    create_my_text("assets/txt/pokemon.ttf", get_key(game->option->right),
            (sfVector2f) {624, 728}, &game->text[RIGHT_TX]);
    create_my_text("assets/txt/pokemon.ttf", get_key(game->option->inter),
            (sfVector2f) {624, 835}, &game->text[INTERACT_TX]);
    create_my_text("assets/txt/pokemon.ttf", get_key(game->option->inv),
            (sfVector2f) {1210, 356}, &game->text[INV_TX]);
    create_my_text("assets/txt/pokemon.ttf", get_key(game->option->pause),
            (sfVector2f) {1210, 476}, &game->text[PAUSED_TX]);
    create_my_text("assets/txt/pokemon.ttf", get_key(game->option->pause),
            (sfVector2f) {1210, 603}, &game->text[SHIELD_TX]);
    create_my_text("assets/txt/pokemon.ttf", get_key(game->option->pause),
            (sfVector2f) {1210, 728}, &game->text[ATTACK_TX]);
    create_my_text("assets/txt/pokemon.ttf", get_key(game->option->pause),
            (sfVector2f) {1210, 833}, &game->text[FARM_TX]);
}

void set_my_text(game_t *game)
{
    game->dialogue = 0;
    game->count_quest = 0;
    game->current_quest = NULL;
    game->checking_quest = 0;
    create_my_text("assets/txt/pokemon.ttf", "\0", (sfVector2f) {game->sprite
    [TEK1].pos.x, game->sprite[TEK1].pos.y}, &
    game->text[ARCHI_TX]);
    create_my_text("assets/txt/pokemon.ttf",
    "TEK ONE'S QUEST \n\n\n       AND \n\n\n  THE CURSE OF MARVIN",
    (sfVector2f) {450, 200}, &game->text[TITLE_TX]);
    create_my_text("assets/txt/pokemon.ttf", "\0", (sfVector2f) {600,
    600}, &game->text[QUEST_TX]);
    sfText_setColor(game->text[TITLE_TX].text, sfBlue);
    sfText_setCharacterSize(game->text[TITLE_TX].text, 50);
    sfText_setCharacterSize(game->text[QUEST_TX].text, 50);
    set_text_option(game);
}
