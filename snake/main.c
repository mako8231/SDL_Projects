#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "game.h"



int main(int argc, char* argv[]) {
    Game game;

    game_init(&game, "Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    
    game_render(&game);
    SDL_Delay(5000);
    //Clean up SDL
    SDL_DestroyWindow(game.window);
    SDL_Quit();
    return 0;
}


