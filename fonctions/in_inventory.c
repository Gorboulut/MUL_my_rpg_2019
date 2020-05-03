/*
** EPITECH PROJECT, 2020
** in_inventory
** File description:
** in_inventory.c
*/

#include "../include/my_rpg.h"

void draw_xp_and_hp(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->sprite[HP].sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->sprite[XP].sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->sprite[BAR].sprite, NULL);
}

void set_object_in_inventory(game_t *game)
{
    if (game->perso->pain >= 1) {
        sfRenderWindow_drawSprite(game->window, game->inven_sp[PAIN].sprite,
            NULL);
        sfRenderWindow_drawText(game->window, game->perso->txt_pain, NULL);
    }
    if (game->perso->vin >= 1) {
        sfRenderWindow_drawSprite(game->window, game->inven_sp[VIN].sprite,
            NULL);
        sfRenderWindow_drawText(game->window, game->perso->txt_vin, NULL);
    }
    if (game->perso->sharp == 1)
        sfRenderWindow_drawSprite(game->window, game->inven_sp[SWORD].sprite,
            NULL);
    if (game->perso->axe == 1)
        sfRenderWindow_drawSprite(game->window, game->inven_sp[AXE].sprite,
            NULL);
    if (game->perso->pickaxe == 1)
        sfRenderWindow_drawSprite(game->window, game->inven_sp[PICKAXE].sprite,
            NULL);
    set_object_in_inventory_two(game);
}

static void in_inventory_end_2(game_t *game)
{
    if (game->inventory == 6) {
        sfRenderWindow_drawSprite(game->window, game->inven_sp[SIX].sprite,
        NULL);
        sfText_setPosition(game->text[QUEST_TX].text, (sfVector2f)
                {game->basic_pos.x + 100, game->basic_pos.y + 400});
        if (game->quest == 0) {
            showing_quest(game, game->first_quest);
        }
        sfText_setString(game->text[QUEST_TX].text, game->current_quest);
        sfRenderWindow_drawText(game->window, game->text[QUEST_TX].text, NULL);
    }
    if (game->inventory == 7)
        sfRenderWindow_drawSprite(game->window, game->inven_sp[SEVEN].sprite,
        NULL);
    if (game->inventory == 8)
        sfRenderWindow_drawSprite(game->window, game->inven_sp[EIGHT].sprite,
        NULL);
}

static void in_inventory_end(game_t *game)
{
    if (game->inventory == 0) {
        sfRenderWindow_drawSprite(game->window, game->inven_sp[ONE].sprite,
        NULL);
        set_object_in_inventory(game);
    }
    if (game->inventory == 2)
        sfRenderWindow_drawSprite(game->window, game->inven_sp[TWO].sprite,
        NULL);
    if (game->inventory == 3) {
        sfRenderWindow_drawSprite(game->window, game->inven_sp[THREE].sprite,
        NULL);
        draw_xp_and_hp(game);
    }
    if (game->inventory == 4)
        sfRenderWindow_drawSprite(game->window, game->inven_sp[FOUR].sprite,
        NULL);
    if (game->inventory == 5)
        sfRenderWindow_drawSprite(game->window, game->inven_sp[FIVE].sprite,
        NULL);
    in_inventory_end_2(game);
}

void in_inventory(game_t *game)
{
    in_play(game);
    sfView_setCenter(game->camera, (sfVector2f) {game->sprite[TEK1].pos.x,
                    game->sprite[TEK1].pos.y});
    game_initialisation(game);
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfText_setPosition(game->perso->txt, (sfVector2f) {game->basic_pos.x + 870,
        game->basic_pos.y + 285});
    sfText_setPosition(game->perso->txt_pain, (sfVector2f) {game->basic_pos.x +
        220, game->basic_pos.y + 285});
    sfText_setPosition(game->perso->txt_vin, (sfVector2f) {game->basic_pos.x +
        358, game->basic_pos.y + 285});
    sfText_setPosition(game->perso->txt_cherry, (sfVector2f) {game->basic_pos.x
        + 1150, game->basic_pos.y + 285});
    for (int i = 0; i != NB_INV - 8; i++)
        sfSprite_setPosition(game->inven_sp[i].sprite,
                        (sfVector2f) {game->basic_pos.x, game->basic_pos.y});
    in_inventory_end(game);
}