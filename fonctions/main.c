/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** main.c
*/
#include "../include/my_rpg.h"
#include <stdlib.h>

void game_animation(game_t *game)
{
    if (game->pl->prot == 1) {
        call_shield(game);
        sfRenderWindow_drawSprite(game->window,
            game->pl->shield->sprite, NULL);
    } if (game->anim == 1)
        start_sword_animation(game);
    if (game->pl->cut == 1)
        start_axe_animation(game);
}

void main_loop(game_t *game)
{
    float elapsed = 0;
    game->cl = sfClock_create();

    sfMusic_play(game->game_music);
    while (sfRenderWindow_isOpen(game->window)) {
        elapsed = sfClock_getElapsedTime(game->cl).microseconds / 1000000.0;
        sfClock_restart(game->cl);
        game->secondes += 1;
        game->clock = elapsed;
        game_events(game);
        game_update(game, elapsed);
        game_render(game);
        game_animation(game);
        sfRenderWindow_display(game->window);
    }
}

int creating_text_from_file_two(game_t *game)
{
    if ((game->mother = parsing("assets/txt/mother.txt")) == NULL)
        return (84);
    if ((game->park = parsing("assets/txt/park.txt")) == NULL)
        return (84);
    if ((game->sign = parsing("assets/txt/sign.txt")) == NULL)
        return (84);
    if ((game->tombe_man = parsing("assets/txt/tombe_man.txt")) == NULL)
        return (84);
    if ((game->trash = parsing("assets/txt/trash.txt")) == NULL)
        return (84);
    if ((game->willy = parsing("assets/txt/willy.txt")) == NULL)
        return (84);
    if ((game->grave = parsing("assets/txt/grave.txt")) == NULL)
        return (84);
    if ((game->pirate = parsing("assets/txt/pirate.txt")) == NULL)
        return (84);
    if ((game->first_quest = parsing("assets/txt/first_quest.txt")) == NULL)
        return (84);
    if (creating_text_from_file_three(game) == 84)
        return (84);
    return (0);
}

int creating_text_from_file(game_t *game)
{
    if ((game->archi = parsing("assets/txt/archi.txt")) == NULL)
        return (84);
    if ((game->first_rock = parsing("assets/txt/first_stone.txt")) == NULL)
        return (84);
    if ((game->mail = parsing("assets/txt/mail.txt")) == NULL)
        return (84);
    if ((game->bridge = parsing("assets/txt/bridge.txt")) == NULL)
        return (84);
    if ((game->cave = parsing("assets/txt/cave.txt")) == NULL)
        return (84);
    if ((game->cherry_tree = parsing("assets/txt/cherry_tree.txt")) == NULL)
        return (84);
    if ((game->drunk = parsing("assets/txt/drunk.txt")) == NULL)
        return (84);
    if ((game->fountain = parsing("assets/txt/fountain.txt")) == NULL)
        return (84);
    if ((game->kid = parsing("assets/txt/kid.txt")) == NULL)
        return (84);
    if (creating_text_from_file_two(game) == 84)
        return (84);
    return (0);
}

int main(int ac, char **av)
{
    UNUSED(av);
    game_t *game = malloc(sizeof(game_t));
    game->tile = malloc(sizeof(tilemap_t));
    game->cl = sfClock_create();

    if (ac != 1)
        return (84);
    if (creating_text_from_file(game) == 84)
        return (84);
    create_game(game);
    main_loop(game);
    destroy_game(game);
    return (0);
}
