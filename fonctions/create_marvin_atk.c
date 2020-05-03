/*
** EPITECH PROJECT, 2020
** my_rpg
** File description:
** marvin atk creation
*/
#include "../include/my_rpg.h"

m_atk_t *add_chain_marv_atk(m_atk_t *atk, char *text)
{
    m_atk_t *new = malloc(sizeof(m_atk_t));
    m_atk_t *tmp;

    new->spr = sfSprite_create();
    new->tex = sfTexture_createFromFile(text, NULL);
    sfSprite_setTexture(new->spr, new->tex, sfTrue);
    new->rect = ((sfIntRect) {0, 0, 44, 43});
    new->pos = ((sfVector2f) {2970, 100});
    sfSprite_setTextureRect(new->spr, new->rect);
    new->next = NULL;
    if (!atk)
        return (new);
    tmp = atk;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    return (atk);
}

m_atk_t *create_chain_list_marv(m_atk_t *atk)
{
    m_atk_t *tmp = atk;

    while (tmp->next)
        tmp = tmp->next;
    tmp->next = atk;
    return (tmp);
}

m_atk_t *add_chain_marv_atk3(m_atk_t *atk, char *text, int x, int y)
{
    m_atk_t *new = malloc(sizeof(m_atk_t));
    m_atk_t *tmp;

    new->spr = sfSprite_create();
    new->tex = sfTexture_createFromFile(text, NULL);
    sfSprite_setTexture(new->spr, new->tex, sfTrue);
    new->rect = ((sfIntRect) {0, 0, x, y});
    new->pos = ((sfVector2f) {2970, 100});
    sfSprite_setTextureRect(new->spr, new->rect);
    new->next = NULL;
    if (!atk)
        return (new);
    tmp = atk;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    return (atk);
}

void create_marv_attack_two(game_t *game)
{
    for  (int i = 0; i < 4; i++) {
        game->marv->atk3 = add_chain_marv_atk3(game->marv->atk3,
            "assets/img/laser.png", 120, 322);
        game->marv->atk3_i = add_chain_marv_atk3(game->marv->atk3_i,
            "assets/img/prep_atk3.png", 100, 32);
    }
    game->marv->atk3 = game->marv->atk3->next;
    game->marv->atk3_i = game->marv->atk3_i->next;
    game->marv->atk2 = game->marv->atk2->next;
    game->marv->atk1 = game->marv->atk1->next;
}

void create_marv_attack(game_t *game)
{
    game->marv->reset_atk = 0;
    game->marv->phase = 1;
    game->marv->atk1 = NULL;
    game->marv->atk2 = NULL;
    game->marv->atk3 = NULL;
    game->marv->atk3_i = NULL;
    for (int i = 0; i < 8; i++)
        game->marv->atk1 = add_chain_marv_atk(game->marv->atk1,
            "assets/img/meteor.png");
    game->marv->atk1 = create_chain_list_marv(game->marv->atk1);
    for (int i = 0; i < 8; i++)
        game->marv->atk2 = add_chain_marv_atk(game->marv->atk2,
            "assets/img/meteor.png");
    game->marv->atk2 = create_chain_list_marv(game->marv->atk2);
    create_marv_attack_two(game);
}
