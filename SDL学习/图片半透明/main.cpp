#include <cstdio>
#include <cstring>
#include <cerrno>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600


int main(int argc, char **argv) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("SDL Tutorial4_p", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          WINDOW_WIDTH, WINDOW_HEIGHT,
                                          SDL_WINDOW_SHOWN);

    SDL_Renderer *rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Surface *image = IMG_Load("/home/xcy/CLionProjects/Agorithm/SDL学习/图片半透明/猫.png");
    SDL_Texture *cat = SDL_CreateTextureFromSurface(rend, image);
    SDL_SetTextureBlendMode(cat, SDL_BLENDMODE_BLEND);

    int alpha = 255;
    bool direction = true;
    SDL_Rect rect = {0, 0,image->w, image->h};
    bool quit = false;
        SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                quit = true;
        }
        if (direction) {
            alpha--;
            if (alpha == 0) direction = false;
        } else {
            alpha++;
            if (alpha == 255) direction = true;
        }
        SDL_RenderClear(rend);
        SDL_RenderCopy(rend, cat, nullptr, &rect);
        SDL_RenderPresent(rend);
        SDL_SetTextureAlphaMod(cat, alpha);
        SDL_Delay(10);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
