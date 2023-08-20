#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#define TRUE 1 
#define FALSE 0 

u_int8_t init();
void render();
void update();
void handleEvents();
void clean();

SDL_Window * g_pWindow = 0;
SDL_Renderer * g_pRenderer = 0;
u_int8_t g_bRunning = FALSE; 

int main(int argc, char* argv[]) {
    if (init()){
        g_bRunning = TRUE;
    } else {
        return 1; 
    }

    while(g_bRunning){
        handleEvents();
        update();
        render();
    }

    //Clean up SDL 

    SDL_Quit();

    return 0;
}

u_int8_t init(){
    //Initialize SDL 
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0){
        //If SDL modules started correctly, create a window 
        g_pWindow = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

        //if the window was succefully created, create a renderer now 
        if (g_pWindow != 0){
            g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
        }
        
    } else {
        printf("Error intializing SDL\n");
        return FALSE; //something went terribly wrong :(
    }

    return TRUE;
}

void render(){
    //Set to black
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

    //Clear the window to black
    SDL_RenderClear(g_pRenderer);

    //Show the window 
    SDL_RenderPresent(g_pRenderer);
}

void update(){

}

void handleEvents(){

}

void clean(){

}
