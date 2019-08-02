#include <iostream>
#include "SDL2/SDL.h"

using namespace std;



int main()
{
    int x = 300;
    int y = 300;
    SDL_Surface *screen, *temp, *sprite;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("game", 100, 100, 640, 480, 0);

        if (window == nullptr){
            cout << "window init failed";
        }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == nullptr){
            cout << "renderer init failed";
       
        }
        SDL_bool done = SDL_FALSE;

        while (!done){
            SDL_Event event;
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
            SDL_RenderClear(renderer);
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawLine(renderer, x, y, x+100, y+100);
            SDL_RenderPresent(renderer);

            ++x;
            ++y;
            while(SDL_PollEvent(&event)){
                if(event.type == SDL_QUIT){
                    done = SDL_TRUE;
                }
            }
        }
        if(renderer){
            SDL_DestroyRenderer(renderer);
        }
        if(window){
            SDL_DestroyWindow(window);
        }
 

  
    SDL_Quit();
    return 0;
}