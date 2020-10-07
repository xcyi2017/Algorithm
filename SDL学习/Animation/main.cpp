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
    SDL_Surface *image = IMG_Load("/home/xcy/CLionProjects/Agorithm/SDL学习/Animation/youxi.jpg");
    //    SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 225, 225, 0)); // 将图片某一颜色设置成透明
    SDL_Texture *cat = SDL_CreateTextureFromSurface(rend, image);

    int i;
    int imgWidth = image->w / 5;
    int imgHeight = image->h;
    SDL_Rect rect = {0, 0, imgWidth, imgHeight};

    SDL_Rect clips[5];
    for (i = 0; i < 5; ++i) {
        clips[i].x = i * imgWidth;
        clips[i].y = 0;
        clips[i].w = imgWidth;
        clips[i].h = imgHeight;
    }
    bool quit = false;
    SDL_Event event;
    i = 0;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                quit = true;
        }
        i = (i + 1) % 5;
        SDL_RenderClear(rend);
        SDL_RenderCopy(rend, cat, &clips[i], &rect);
        rect.x++;
        SDL_RenderPresent(rend);
        SDL_Delay(50);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}