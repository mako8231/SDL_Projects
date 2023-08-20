#include "snake.h"

void snake_draw(Game * g,Snake * snake){
    //Drawing a white rect
    SDL_FRect rect = {snake->x, snake->y, 20, 20}; //x, y, width, height
    SDL_SetRenderDrawColor(g->renderer, 0xff, 0xff, 0xff, 255);
    SDL_RenderFillRectF(g->renderer, &rect);
}

void snake_update(float delta_time, Snake * snake){
    int snake_speed = 2000;
    snake->x += snake_speed * delta_time; 
}