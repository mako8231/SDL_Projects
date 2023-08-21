#ifndef SNAKE_H
#define SNAKE_H

#include "game.h"

typedef struct snake_body{
    float x;
    float y;
    float dir_x;
    float dir_y; 
} SnakeBody;

typedef struct snake {
    SnakeBody parts[307200];
    int top;
    int size;
} Snake;

void snake_part_draw(Game * g, SnakeBody * snake_p);
void snake_part_update(float delta_time, SnakeBody * snake_p);
void snake_init(Snake * snake);
void snake_part_push(Snake * snake);
void snake_draw(Game * g, Snake * snake);
void snake_update(Game * g, Snake * snake);


#endif