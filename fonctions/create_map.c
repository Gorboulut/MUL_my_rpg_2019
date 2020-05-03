/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** create_map.c
*/

#include "../include/my_rpg.h"

char **malloc_map(game_t *game, char **map)
{
    map = malloc(sizeof(char *) * game->tile->width + 1);
    if (map == NULL)
        return (NULL);
    memset(map, 0, sizeof(char *) * game->tile->width + 1);
    for (int i = 0; i < game->tile->width; i++) {
        map[i] = malloc(sizeof(char) * (game->tile->height * 5) + 1);
        if (map[i] == NULL)
            return (NULL);
        memset(map[i], 0, (game->tile->height * 5) + 1);
    }
    return (map);
}

void get_width_height(game_t *game, FILE *file, size_t hello)
{
    game->tile->malloc = malloc(sizeof(char *) * 3);
    memset(game->tile->malloc, 0, sizeof(char *) * 3);
    for (int i = 0; i <= 1; i++) {
        game->tile->malloc[i] = malloc(sizeof(char) * 5);
        getline(&game->tile->malloc[i], &hello, file);
    } game->tile->width = my_getnbr(game->tile->malloc[0]);
    game->tile->height = my_getnbr(game->tile->malloc[1]);
    free(game->tile->malloc);
}

char ***get_map(game_t *game, char *tilemap)
{
    size_t hello = 4;
    char **map = NULL;
    char ***separe = NULL;
    FILE *file = fopen(tilemap, "r");

    get_width_height(game, file, hello);
    separe = malloc(sizeof(char **) * game->tile->width + 1);
    map = malloc_map(game, map);
    if (map == NULL)
        return (NULL);
    for (int i = 0; i < game->tile->width; i++)
        getline(&map[i], &hello, file);
    for (int i = 0; i < game->tile->width; i++)
        separe[i] = str_to_word_tab(map[i], ',');
    return (separe);
}

void create_vertex_array(game_t *game, char *tileset)
{
    game->tile->tilemap = my_realloc(game->tile->tilemap,
        sizeof(sfVertexArray*) * game->tile->tabvertex,
        sizeof(sfVertexArray*) * (game->tile->tabvertex + 1));
    game->tile->states = my_realloc(game->tile->states,
        sizeof(sfRenderStates) * game->tile->tabvertex,
        sizeof(sfRenderStates) * (game->tile->tabvertex + 1));
    game->tile->tilemap[game->tile->tabvertex] = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(game->tile->tilemap[game->tile->tabvertex],
    sfQuads);
    sfVertexArray_resize(game->tile->tilemap[game->tile->tabvertex],
                        (((game->tile->width * game->tile->height)) * 4));
    game->tile->text = sfTexture_createFromFile(tileset, NULL);
    game->tile->states[game->tile->tabvertex] = (sfRenderStates)
                {sfBlendAlpha, sfTransform_Identity, game->tile->text, NULL};
}

void create_vertex(game_t *game, char ***map, sfVector2i tSize)
{
    int tileNumber = 0;
    int tx = 0;
    int ty = 0;

    for (int i = 0; i < game->tile->width; ++i)
        for (int j = 0; j < game->tile->height; ++j) {
            tileNumber = my_getnbr(map[j][i]);
            tx = tileNumber % (sfTexture_getSize(game->tile->text).x/ tSize.x);
            ty = tileNumber / (sfTexture_getSize(game->tile->text).x/ tSize.x);
            sfVertex *quad = sfVertexArray_getVertex(game->tile->tilemap
            [game->tile->tabvertex], (i + j * game->tile->width) * 4);
            quad[0].position = (sfVector2f) {i * tSize.x, j * tSize.y};
            quad[1].position = (sfVector2f) {(i + 1) * tSize.x, j * tSize.y};
            quad[2].position = (sfVector2f){(i + 1) * tSize.x, (j+1)* tSize.y};
            quad[3].position = (sfVector2f) {i * tSize.x, (j + 1) * tSize.y};
            quad[0].texCoords = (sfVector2f) {tx * tSize.x, ty * tSize.y};
            quad[1].texCoords = (sfVector2f) {(tx+1) * tSize.x, ty * tSize.y};
            quad[2].texCoords = (sfVector2f){(tx + 1)*tSize.x, (ty+1)*tSize.y};
            quad[3].texCoords = (sfVector2f) {tx * tSize.x, (ty + 1)* tSize.y};
        }
}