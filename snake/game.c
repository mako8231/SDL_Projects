#include "game.h"
#include "snake.h"

Snake g_snake;

//Initalize the SDL modules
bool game_init(Game * game, const char * title, int x_pos, int y_pos, int width, int height, int flags){
    //initialize these values
    game->window = 0; 
    game->renderer = 0;
    game->delta_time = 0.0f;
    game->m_ticks = 0;
    
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

    snake_init(&g_snake);

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
    game->delta_time = (SDL_GetTicks() - game->m_ticks)/1000.0f;
    game->m_ticks = SDL_GetTicks();
    printf("%lf\n", game->delta_time);
}

//Game update 
void game_update(Game * game){
    //set the delta time
    update_delta_time(game);
    snake_update(game, &g_snake);
}

//Handling events 
void game_handle_events(Game *game){
    while (SDL_PollEvent(&game->event)){
        //Keyboard handling
        switch (game->event.type){
            case SDL_KEYDOWN: 
                switch(game->event.key.keysym.sym){
                    case SDLK_LEFT:
                        g_snake.parts[g_snake.top].dir_x = -1;
                        g_snake.parts[g_snake.top].dir_y = 0;
                    break;
                    case SDLK_UP:
                        g_snake.parts[g_snake.top].dir_x = 0;
                        g_snake.parts[g_snake.top].dir_y = -1;
                    break;
                    case SDLK_DOWN:
                        g_snake.parts[g_snake.top].dir_x = 0;
                        g_snake.parts[g_snake.top].dir_y = 1;
                    break;
                    case SDLK_RIGHT:
                        g_snake.parts[g_snake.top].dir_x = 1;
                        g_snake.parts[g_snake.top].dir_y = 0;
                    break;
                    case SDLK_RETURN:
                        snake_part_push(&g_snake);
                    break;
                    default:
                    break;
                }
	    break;
	    case SDL_QUIT:
		game->running = false;
            default: 
            break;
        }
    }
}
//Game clean 
void game_clean(Game * game){

}
