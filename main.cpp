#include <iostream>
#include "SDL2/SDL.h"

using namespace std;

int Init_SDL(){
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

    string imagePath = "flower.bmp";
    SDL_Surface *bmp = SDL_LoadBMP(imagePath.c_str());
    if(bmp == nullptr){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        cout << "error initializing image exiting..." << SDL_GetError() << endl;
        return 0;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, bmp);
    SDL_FreeSurface(bmp);

    for(int i=0; i < 3;  ++i){
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
        SDL_Delay(1000);
    }
}

int main()
{
    Init_SDL();
    return 0;
}