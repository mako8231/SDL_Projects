#include "game.h"

//Initalize the SDL modules
bool game_init(Game * game, const char * title, int x_pos, int y_pos, int width, int height, int flags){
    //initialize these values
    game->window = 0; 
    game->renderer = 0;

    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0){
        game->window = SDL_CreateWindow(title, x_pos, y_pos, width, height, flags);
        if (game->window == 0){
            return false; //Something went wrong
        }

        game->renderer = SDL_CreateRenderer(game->window, -1, flags);
        if (game->renderer == 0){
            return false;
        }

        game->running = true; 

    } else {
        return false; //error intialize SDL
    }

    return true;
}
//Game renderer 
void game_render(Game * game){
    //Set to black
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);

    //Clear the window to black
    SDL_RenderClear(game->renderer);

    //Show the window 
    SDL_RenderPresent(game->renderer);
}
//Game update 
void game_update(Game * game){

}
//Handling events 
void game_handle_events(Game *game){

}
//Game clean 
void game_clean(Game * game){

}
