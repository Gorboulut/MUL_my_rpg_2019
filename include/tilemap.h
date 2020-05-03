/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** tilemap.h
*/

#ifndef TILEMAP_H
#define TILEMAP_H

typedef struct tilemap_s {
    char **malloc;
    char ***map;
    int width;
    int height;
    int tabvertex;
    sfVertexArray **tilemap;
    sfTexture *text;
    sfRenderStates *states;
} tilemap_t;

#endif /*TILEMAP_H */