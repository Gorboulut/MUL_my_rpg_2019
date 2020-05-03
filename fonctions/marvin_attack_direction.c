/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** direction for marvin attack
*/
#include "../include/my_rpg.h"

void marvin_direction_first_attack(game_t *game)
{
    game->marv->atk1->pos.x -= 2;
    game->marv->atk1 = game->marv->atk1->next;
    game->marv->atk1->pos.x += 2;
    game->marv->atk1 = game->marv->atk1->next;
    game->marv->atk1->pos.y -= 2;
    game->marv->atk1 = game->marv->atk1->next;
    game->marv->atk1->pos.y += 2;
    game->marv->atk1 = game->marv->atk1->next;
    game->marv->atk1->pos.x += 2;
    game->marv->atk1->pos.y += 2;
    game->marv->atk1 = game->marv->atk1->next;
    game->marv->atk1->pos.x -= 2;
    game->marv->atk1->pos.y += 2;
    game->marv->atk1 = game->marv->atk1->next;
    game->marv->atk1->pos.x += 2;
    game->marv->atk1->pos.y -= 2;
    game->marv->atk1 = game->marv->atk1->next;
    game->marv->atk1->pos.x -= 2;
    game->marv->atk1->pos.y -= 2;
    game->marv->atk1 = game->marv->atk1->next;
}

void marvin_direction_second_attack_two(game_t *game)
{
    game->marv->atk2->pos.x += 2;
    game->marv->atk2->pos.y += 1;
    game->marv->atk2 = game->marv->atk2->next;
    game->marv->atk2->pos.x += 1;
    game->marv->atk2->pos.y += 2;
    game->marv->atk2 = game->marv->atk2->next;
}

void marvin_direction_second_attack(game_t *game)
{
    game->marv->atk2->pos.x -= 2;
    game->marv->atk2->pos.y -= 1;
    game->marv->atk2 = game->marv->atk2->next;
    game->marv->atk2->pos.x -= 1;
    game->marv->atk2->pos.y -= 2;
    game->marv->atk2 = game->marv->atk2->next;
    game->marv->atk2->pos.x -= 2;
    game->marv->atk2->pos.y += 1;
    game->marv->atk2 = game->marv->atk2->next;
    game->marv->atk2->pos.x += 2;
    game->marv->atk2->pos.y -= 1;
    game->marv->atk2 = game->marv->atk2->next;
    game->marv->atk2->pos.x -= 1;
    game->marv->atk2->pos.y += 2;
    game->marv->atk2 = game->marv->atk2->next;
    game->marv->atk2->pos.x += 1;
    game->marv->atk2->pos.y -= 2;
    game->marv->atk2 = game->marv->atk2->next;
    marvin_direction_second_attack_two(game);
}

void reset_atk(game_t *game)
{
    if (game->marv->phase == 2 && game->marv->activ2 == 1)
        game->marv->activ2++;
    game->marv->reset_atk = 0;
    sfSound_play(game->s->fire);
    for (int i = 0; i < 8; i++) {
        game->marv->atk1->pos = ((sfVector2f) {2970, 100});
        game->marv->atk1 = game->marv->atk1->next;
        game->marv->atk2->pos = ((sfVector2f) {2970, 100});
        game->marv->atk2 = game->marv->atk2->next;
    }
}
