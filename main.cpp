#include <iostream>
#include "SDL2/SDL.h"

using namespace std;

int main()
{
    
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        cout << "Error initializing" << SDL_GetError() << endl;
        return 0;
    };
    cout << "init completed" << endl;

    SDL_Window *window = SDL_CreateWindow("testing", 100, 100, 640, 480, SDL_WINDOW_SHOWN );
    if (window == nullptr){
        cout << "error initializing window exiting..." << SDL_GetError() << endl;
        SDL_Quit();
        return 0;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr){
        SDL_DestroyWindow(window);
        cout << "error initializing renderer exiting..." << SDL_GetError() << endl;
        SDL_Quit();
        return 0;
    }

    getchar();

    return 0;
}