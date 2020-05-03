/*
** EPITECH PROJECT, 2020
** create_game_three.c
** File description:
** create_game_three.c
*/

#include "../include/my_rpg.h"

void set_nb_text(game_t *game)
{
    game->perso->fontext = sfFont_createFromFile("assets/txt/pokemon.ttf");
    game->perso->txt = sfText_create();
    game->perso->txt_pain = sfText_create();
    game->perso->txt_vin = sfText_create();
    game->perso->txt_cherry = sfText_create();
    sfText_setFont(game->perso->txt, game->perso->fontext);
    sfText_setFont(game->perso->txt_pain, game->perso->fontext);
    sfText_setFont(game->perso->txt_vin, game->perso->fontext);
    sfText_setFont(game->perso->txt_cherry, game->perso->fontext);
    sfText_setPosition(game->perso->txt, (sfVector2f) {870, 285});
    sfText_setPosition(game->perso->txt_pain, (sfVector2f) {50, 285});
    sfText_setPosition(game->perso->txt_vin, (sfVector2f) {100, 285});
    sfText_setPosition(game->perso->txt_cherry, (sfVector2f) {100, 285});
    set_nb_text_two(game);
}

void setting_value(game_t *game)
{
    game->perso = malloc(sizeof(inv_t));
    game->option = malloc(sizeof(option_t));
    game->dialogue = 0;
    game->menu = 0;
    game->inventory = 0;
    game->load = 0;
    game->count = 0;
    game->tile->tabvertex = 0;
    game->option->top = sfKeyUp;
    game->option->bot = sfKeyDown;
    game->option->left = sfKeyLeft;
    game->option->right = sfKeyRight;
    game->option->inter = sfKeyC;
    game->option->inv = sfKeyI;
    game->option->pause = sfKeyEscape;
    game->option->shield = sfKeyX;
    game->option->attack = sfKeySpace;
    game->option->farm = sfKeyF;
    setting_value_two(game);
}

void creating_tiled_map_first(game_t *game)
{
    game->tile->tilemap = NULL;
    create_map(game, get_map(game, "tilemap/map_grass.csv"),
                (sfVector2i) {16, 16}, "tilemap/tileset.png");
    create_map(game, get_map(game, "tilemap/map_water.csv"),
                (sfVector2i) {16, 16}, "tilemap/tileset.png");
    create_map(game, get_map(game, "tilemap/map_water_stuffs.csv"),
                (sfVector2i) {16, 16}, "tilemap/city.png");
    create_map(game, get_map(game, "tilemap/map_water_side.csv"),
                (sfVector2i) {16, 16}, "tilemap/tileset.png");
    create_map(game, get_map(game, "tilemap/map_stairs.csv"),
                (sfVector2i) {16, 16}, "tilemap/city.png");
    create_map(game, get_map(game, "tilemap/map_bridges.csv"),
                (sfVector2i) {16, 16}, "tilemap/tileset.png");
    create_map(game, get_map(game, "tilemap/map_bridges_bars.csv"),
                (sfVector2i) {16, 16}, "tilemap/tileset.png");
    create_map(game, get_map(game, "tilemap/map_roads.csv"),
                (sfVector2i) {16, 16}, "tilemap/city.png");
}

void creating_tiled_map_second(game_t *game)
{
    create_map(game, get_map(game, "tilemap/map_stuffs.csv"),
                (sfVector2i) {16, 16}, "tilemap/city.png");
    create_map(game, get_map(game, "tilemap/map_walls_back.csv"),
                (sfVector2i) {16, 16}, "tilemap/tileset.png");
    create_map(game, get_map(game, "tilemap/map_walls.csv"),
                (sfVector2i) {16, 16}, "tilemap/tileset.png");
    create_map(game, get_map(game, "tilemap/map_furnitures_top.csv"),
                (sfVector2i) {16, 16}, "tilemap/tileset.png");
    create_map(game, get_map(game, "tilemap/map_houses.csv"),
                (sfVector2i) {16, 16}, "tilemap/city.png");
    create_map(game, get_map(game, "tilemap/map_front_houses.csv"),
                (sfVector2i) {16, 16}, "tilemap/city.png");
    create_map(game, get_map(game, "tilemap/map_trees.csv"),
                (sfVector2i) {16, 16}, "tilemap/tileset.png");
    create_map(game, get_map(game, "tilemap/map_PNJ.csv"),
                (sfVector2i) {16, 16}, "tilemap/pnj.png");
    game->tile->map = get_map(game, "tilemap/map_collision.csv");
}

void creating_tiled_map(game_t *game)
{
    creating_tiled_map_first(game);
    creating_tiled_map_second(game);
    add_fire(game);
}
