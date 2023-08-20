#ifndef SNAKE_H
#define SNAKE_H

#include "game.h"

typedef struct snake{
    float x;
    float y;
    float dir_x;
    float dir_y; 
} Snake;

void snake_draw(Game * g, Snake * snake);
void snake_update(float delta_time, Snake * snake);

#endif