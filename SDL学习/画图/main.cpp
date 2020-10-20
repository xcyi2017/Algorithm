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
    SDL_SetRenderDrawBlendMode(rend, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(rend, 255, 255, 255, 50);
    //SDL_RenderDrawPoint(rend, 100, 100);
    //SDL_RenderDrawLine(rend, 0, 0, 100, 100);
    int x1 = 0;
    int y1 = 0;
    
    SDL_Rect rect = {0, 0, 100, 100};
    SDL_RenderDrawRect(rend, &rect);
    bool quit = false;
    int state = 1; // 0 表示鼠标按下去 1表示鼠标松开
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                quit = true;
            else if (event.type == SDL_MOUSEMOTION) {
                if (state == 0) {
                    int x = event.motion.x;
                    int y = event.motion.y;
                    //SDL_RenderDrawLine(rend, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, x, y);
                    SDL_RenderDrawLine(rend, x1, y1, x, y); 
                    x1 = x;
                    y1 = y;
                }    
               
            } 
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                state = 0;
                int x = event.motion.x;
                int y = event.motion.y;
                x1 = x;
                y1 = y;
            } 
            if (event.type == SDL_MOUSEBUTTONUP) {
                state = 1;
                int x = event.motion.x;
                int y = event.motion.y;
                x1 = x;
                y1 = y;
            }
            
        }
        SDL_RenderPresent(rend);
        SDL_Delay(10);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

