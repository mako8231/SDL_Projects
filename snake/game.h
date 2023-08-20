#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct game {
    char * game_title;
    int w_xpos;
    int w_ypos;
    int w_width;
    int w_height;
    int flags;
    bool running;
} Game;

bool game_init(Game * game, const char * title, int x_pos, int y_pos, int width, int height, int flags);


#endif