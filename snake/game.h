#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
//The whole game structure
typedef struct game {
    //Base Game Parameters
    char * title;
    int w_xpos;
    int w_ypos;
    int w_width;
    int w_height;
    int flags;
    bool running;
    
    //System parameters
    SDL_Window * window;
    SDL_Renderer * renderer;
    SDL_Event event;
    SDL_Surface * surface;

    //Delta time 
    uint64_t now;
    uint64_t last;
    double delta_time; 
} Game;

//Initalize the SDL modules
bool game_init(Game * game, const char * title, int x_pos, int y_pos, int width, int height, int flags);
//Game renderer 
void game_render(Game * game);
//Game update 
void game_update(Game * game);
//Handling events 
void game_handle_events(Game *game);
//Game clean 
void game_clean(Game * game);
//Update the delta time value
void update_delta_time(Game * game);
#endif