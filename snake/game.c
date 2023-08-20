#include "game.h"
#include "snake.h"

Snake g_snake = {10, 20, 0.0f, 1.0f};

//Initalize the SDL modules
bool game_init(Game * game, const char * title, int x_pos, int y_pos, int width, int height, int flags){
    //initialize these values
    game->window = 0; 
    game->renderer = 0;
    game->delta_time = 0.0f;
    game->now = SDL_GetPerformanceCounter();
    game->last = 0;

    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0){
        game->window = SDL_CreateWindow(title, x_pos, y_pos, width, height, flags);
        if (game->window == 0){
            return false; //Something went wrong
        }

        game->renderer = SDL_CreateRenderer(game->window, -1, flags);
        if (game->renderer == 0){
            return false;
        }

        //intialize the surface 
        game->surface = SDL_GetWindowSurface(game->window);
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
    //Draw a snake (square) on the screen
    snake_draw(game, &g_snake);
    //Show the window 
    SDL_RenderPresent(game->renderer);

    
}
void update_delta_time(Game * game){
    game->last = game->now;
    game->now = SDL_GetPerformanceCounter();

    game->delta_time = (double)((game->now - game->last)*1000/(double)SDL_GetPerformanceCounter());   
}

//Game update 
void game_update(Game * game){
    //set the delta time
    update_delta_time(game);
    snake_update(game->delta_time, &g_snake);
}
//Handling events 
void game_handle_events(Game *game){
    while (SDL_PollEvent(&game->event)){
        //Keyboard handling
        switch (game->event.type){
            case SDL_KEYDOWN: 
                switch(game->event.key.keysym.sym){
                    case SDLK_LEFT:
                        g_snake.dir_x = -1;
                        g_snake.dir_y = 0;
                    break;
                    case SDLK_UP:
                        g_snake.dir_x = 0;
                        g_snake.dir_y = -1;
                    break;
                    case SDLK_DOWN:
                        g_snake.dir_x = 0;
                        g_snake.dir_y = 1;
                    break;
                    case SDLK_RIGHT:
                        g_snake.dir_x = 1;
                        g_snake.dir_y = 0;
                    break;
                    default:
                    break;
                }
            default: 
            break;
        }
    }
}
//Game clean 
void game_clean(Game * game){

}
