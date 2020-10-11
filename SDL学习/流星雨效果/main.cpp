#include <cstdio>
#include <cstring>
#include <cerrno>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define SPOTSNUM 100

struct Spot {
    int x;
    int y;
    int w;
    int h;
    int speed;
    int alpha;
};
void drawSpot(Spot *spot, SDL_Renderer* rend, SDL_Texture* rain) {
    SDL_Rect rect = {spot->x, spot->y, spot->w, spot->h};
    SDL_SetTextureAlphaMod(rain, spot->alpha);
    SDL_RenderCopy(rend, rain, nullptr, &rect);
}

void moveSpot(Spot* spot) {
    spot->y += spot->speed;
    if (spot->y > WINDOW_HEIGHT) spot->y = 0;
}

int main(int argc, char **argv) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("SDL Tutorial4_p", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          WINDOW_WIDTH, WINDOW_HEIGHT,
                                          SDL_WINDOW_SHOWN);

    SDL_Renderer *rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Surface *image = IMG_Load("/home/xcy/CLionProjects/Agorithm/SDL学习/流星雨效果/猫.png");
    SDL_Surface *black_ = IMG_Load("/home/xcy/CLionProjects/Agorithm/SDL学习/流星雨效果/black.png");

    SDL_Texture *cat = SDL_CreateTextureFromSurface(rend, image);
    SDL_Texture *black = SDL_CreateTextureFromSurface(rend, black_);
    SDL_SetTextureBlendMode(cat, SDL_BLENDMODE_BLEND);
    SDL_SetTextureBlendMode(black, SDL_BLENDMODE_BLEND);
    SDL_SetTextureAlphaMod(black, 10);
    SDL_SetTextureColorMod(cat, 255, 20, 90);


    SDL_Rect background_rect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
    Spot spots[SPOTSNUM];
    for (int i = 0; i < 50; i++) {
        spots[i].x = rand() % WINDOW_WIDTH;
        spots[i].y = rand() % WINDOW_HEIGHT;
        spots[i].w = image->w/100;
        spots[i].h = image->h/100;
        spots[i].speed = rand() % 5 + 1;
        spots[i].alpha = rand() % 255 + 1;
    }
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                quit = true;
        }
        SDL_RenderCopy(rend, black, nullptr, &background_rect);
        for (int i = 0; i < SPOTSNUM; ++ i) {
            drawSpot(&spots[i], rend, cat);
            moveSpot(&spots[i]);
        }
        SDL_RenderPresent(rend);
        
        SDL_Delay(50);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
