#include "snake.h"

void snake_part_draw(Game * g,SnakeBody * snake){
    //Drawing a white rect
    SDL_FRect rect = {snake->x, snake->y, 20, 20}; //x, y, width, height
    SDL_SetRenderDrawColor(g->renderer, 0xff, 0xff, 0xff, 255);
    SDL_RenderFillRectF(g->renderer, &rect);
}

void snake_init(Snake * snake){
    snake->parts[0].dir_x = 1.0f;
    snake->parts[0].dir_y = 0.0f;
    snake->parts[0].x = 200;
    snake->parts[0].y = 200;
    snake->top = 0; 
    snake->size = 1;  
}

void snake_part_update(float delta_time, SnakeBody * snake){
    float snake_speed = 120.0f;
    snake->x += snake_speed * snake->dir_x * delta_time; 
    snake->y += snake_speed * snake->dir_y * delta_time;
}

void snake_part_push(Snake * snake){
    //push the snake part into the body
    SnakeBody part; 
    part.x = snake->parts[snake->top].x;

    part.dir_x = 1;
    part.dir_y = 0;

    snake->parts[snake->top+1] = part;
    snake->top += 1;
    snake->size += 1;
}

void snake_draw(Game * g, Snake * snake){
    for (int i = 0; i<snake->size; i++){
        snake_part_draw(g, &snake->parts[i]);
    }
}

void snake_update(Game * g, Snake * snake){
    for (int i = 0; i<snake->size; i++){
        snake_part_update(g->delta_time, &snake->parts[i]);
    }
}