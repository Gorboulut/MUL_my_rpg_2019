/*
** EPITECH PROJECT, 2020
** interaction.c
** File description:
** interaction.c
*/

#include "../include/my_rpg.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void all_interaction_object(game_t *game)
{
    interaction_object(game, game->first_rock, ROCK1);
    interaction_object(game, game->mail, MAILBOX);
    interaction_object(game, game->archi, ARCHI);
    interaction_object(game, game->bridge, BRIDGE);
    interaction_object(game, game->cave, CAVE);
    interaction_object(game, game->cherry_tree, CHERRY);
    interaction_object(game, game->drunk, CARAVANE);
    interaction_object(game, game->fountain, FOUNTAIN);
    interaction_object(game, game->kid, CHILD);
    interaction_object(game, game->mother, MOM);
    interaction_object(game, game->park, GAMES);
    interaction_object(game, game->sign, DIRECTION);
    interaction_object(game, game->tombe_man, GRAVEMAN);
    interaction_object(game, game->trash, TRASH);
    interaction_object(game, game->willy, WILLY);
    interaction_object(game, game->pirate, PIRATE);
    interaction_object(game, game->grave, GRAVES);
    interaction_object(game, game->mail_archi, MAILBOXA);
    interaction_object(game, game->second_rock, ROCK2);
    all_interaction_object_two(game);
}

void add_in_inventory(game_t *game, int object)
{
    if (object == 19)
        game->perso->sharp = 1;
    if (object == 20)
        game->perso->axe = 1;
    if (object == PIRATE && game->pl->wood >= 10) {
        game->perso->pickaxe = 1;
        game->pl->wood -= 10;
    }
    if (object == TRASH)
        game->perso->bouclier = 1;
}

char *collision(game_t *game, int y, int x)
{
    if (my_strcmp(game->tile->map[(int)((game->sprite[TEK1].pos.y + 28) /
        16) + y]
        [(int) ((game->sprite[TEK1].pos.x + 13) / 16) + x], "1") == 0) {
            return (NULL);
    }
    return (game->tile->map[(int)((game->sprite[TEK1].pos.y + 30) / 16) + y]
        [(int) ((game->sprite[TEK1].pos.x + 15) / 16) + x]);
}

int print_text(game_t *game, sfText *text, char *str)
{
    static int i = 0;
    static char *to_display = NULL;

    sfRenderWindow_drawText(game->window, text, NULL);
    if (my_strcmp(str, to_display) == 0) {
        game->tmp += game->clock;
        if (game->tmp > 1) {
            i = 0;
            to_display = NULL;
            game->tmp = 0;
            return (-1);
        } else
            return (0);
    }
    if (game->clock > (float) game->text_speed->vol / 1000) {
        to_display = new_strcat(to_display, str[i]);
        i++;
    } if (str == NULL)
        to_display = NULL;
    sfText_setString(text, to_display);
    return (0);
}

void interaction_object(game_t *game, char **stk, int object)
{
    static int i = 0;

    if (my_getnbr(collision(game, -1, 0)) == object &&
        game->key.code == game->option->inter && stk[i] != NULL) {
        add_in_inventory(game, object);
        game->dialogue = 1;
        first_quest(game, object);
        sfText_setPosition(game->text[ARCHI_TX].text, (sfVector2f)
        {game->pos_camera.x - 270, game->pos_camera.y + 200});
        sfSprite_setPosition(game->sprite[TEXT].sprite, (sfVector2f)
        {game->pos_camera.x - 300, game->pos_camera.y + 150});
        sfRenderWindow_drawSprite(game->window, game->sprite[TEXT].sprite,
                                    NULL);
        if (print_text(game, game->text[ARCHI_TX].text, stk[i]) == -1) {
            i++;
            if (stk[i] == NULL) {
                i = 0;
                game->dialogue = 0;
                game->key.code = sfFalse;
            }
        } }
}
