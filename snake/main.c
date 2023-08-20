#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "game.h"


int main(int argc, char* argv[]) {
    Game game;
    int i = 0;
    game_init(&game, "Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);

    //Clean up SDL
    while (game.running){
        game_render(&game);
        game_update(&game);
        game_handle_events(&game);
    }
    SDL_DestroyWindow(game.window);
    SDL_Quit();
    return 0;
}


