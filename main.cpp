#include <iostream>
#include <SDL2/SDL.h>
#include <cstdio>
#include "Classes/Checks/checks.h"
#include "Classes/Controls/controls.h"
#include <windows.h>

const int fps = 60;
const int minimumFrameTime = 1000 / fps;

bool gameLoop = false;
bool controller = false;
bool success = false;

int screenWidth = 640;
int screenHeight = 480;


int main(int argc, char* argv[]) {

    SDL_Window *window;
    SDL_Surface *screenSurface;
    SDL_Renderer *renderer;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {

        printf("Window creation failed: %s\n", SDL_GetError());
        success = false;
        return 1;

    } else {
        gameLoop = true;
        controls::defineControls();

        window = SDL_CreateWindow(
                "Test",
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                screenWidth,
                screenHeight,
                SDL_WINDOW_OPENGL
        );

        if (window == NULL) {
            printf("Window creation failed: %s\n", SDL_GetError());
            return 1;
        } else {
            screenSurface = SDL_GetWindowSurface( window );
            renderer = SDL_CreateRenderer(window, -1, 0);
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);

        }

        while(gameLoop){

            SDL_Event event;
            while (SDL_PollEvent(&event)){

                if(event.type == SDL_KEYDOWN){
                    controls::sendButton(SDL_GetKeyName(event.key.keysym.sym));
                    std::string key = SDL_GetKeyName(event.key.keysym.sym);

                    if(key == "Escape"){
                        gameLoop = false;
                    }
                }

                if(event.type == SDL_KEYUP){
                    std::string key = SDL_GetKeyName(event.key.keysym.sym);

                    if(key == "Left" || key == "Right") {
                        controls::move(0);
                    }
                }

            }

            //do app stuff here

        }
        
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
    }

    return 0;
}