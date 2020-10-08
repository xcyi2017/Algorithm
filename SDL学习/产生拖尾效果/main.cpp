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
    SDL_Surface *image = IMG_Load("/home/xcy/CLionProjects/Agorithm/SDL学习/产生拖尾效果/猫.png");
    SDL_Surface *black_ = IMG_Load("/home/xcy/CLionProjects/Agorithm/SDL学习/产生拖尾效果/black.png");

    SDL_Texture *cat = SDL_CreateTextureFromSurface(rend, image);
    SDL_Texture *black = SDL_CreateTextureFromSurface(rend, black_);

    SDL_SetTextureBlendMode(cat, SDL_BLENDMODE_BLEND);
    SDL_SetTextureBlendMode(black, SDL_BLENDMODE_BLEND);
    SDL_SetTextureAlphaMod(black, 10);
    int alpha = 255;
    SDL_Rect rect = {0, 0,image->w, image->h};
    SDL_Rect rectWindow = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

    bool quit = false;
        SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                quit = true;
            else if (event.type == SDL_MOUSEMOTION) {
                rect.x = event.motion.x - rect.w/2;
                rect.y = event.motion.y - rect.h/2;
            }
        }      
        SDL_RenderCopy(rend, cat, nullptr, &rect);
        SDL_RenderCopy(rend, black, nullptr, &rectWindow);
        SDL_RenderPresent(rend);
        SDL_SetTextureAlphaMod(cat, alpha);
        SDL_Delay(50);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
