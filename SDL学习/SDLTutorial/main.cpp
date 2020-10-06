#include <cstdio>
#include <cstring>
#include <cerrno>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//int main(int argc, char **argv) {
//
//    SDL_Init(SDL_INIT_VIDEO);
//    SDL_Window *window = SDL_CreateWindow("SDL Tutorial1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
//                                          800, 600,
//                                          SDL_WINDOW_SHOWN);
//    SDL_Rect rect={100,100};
//    SDL_Surface *surface = SDL_GetWindowSurface(window);
//    SDL_Surface *image = SDL_LoadBMP("/home/xcy/CLionProjects/Agorithm/SDL学习/SDLTutorial/sample.bmp");
//    if (image == NULL) printf("出错\n");
//    SDL_BlitSurface(image, NULL, surface, &rect);
//    SDL_UpdateWindowSurface(window);
//    SDL_Delay(3000);
//    SDL_DestroyWindow(window);
//    SDL_Quit();
//    return 0;
//}

//int main(int argc, char **argv) {
//    SDL_Init(SDL_INIT_VIDEO);
//    SDL_Window *window = SDL_CreateWindow("SDL Tutorial2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
//                                          800, 600,
//                                          SDL_WINDOW_SHOWN);
//    SDL_Surface *surface = SDL_GetWindowSurface(window);
//    // 窗口显示很多个图片
//    SDL_Rect rect;
//    rect.x = 0;
//    rect.y = 0;
//    SDL_Surface *image = IMG_Load("/home/xcy/CLionProjects/Agorithm/SDL学习/SDLTutorial/钱币.png");
//    if (image == nullptr) printf("出错！, %s\n", strerror(errno));
//    for (int i =0; i<10; ++i, rect.x += 50)
//        SDL_BlitSurface(image, nullptr, surface, &rect);
//    SDL_UpdateWindowSurface(window);
//    SDL_Delay(5000);
//    SDL_FreeSurface(image);
//    SDL_FreeSurface(surface);
//    SDL_DestroyWindow(window);
//    SDL_Quit();
//    return 0;
//}

//int main(int argc, char **argv) {
//    SDL_Init(SDL_INIT_VIDEO);
//    SDL_Window *window = SDL_CreateWindow("SDL Tutorial3", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
//                                          800, 600,
//                                          SDL_WINDOW_SHOWN);
//    SDL_Surface *surface = SDL_GetWindowSurface(window);
//
//    SDL_Surface *img1 = IMG_Load("/home/xcy/CLionProjects/Agorithm/SDL学习/SDLTutorial/笑脸.png");
//    SDL_Surface *img2 = IMG_Load("/home/xcy/CLionProjects/Agorithm/SDL学习/SDLTutorial/鬼脸.png");
//    SDL_Surface *current = img1;
//    // 事件控制
//    SDL_Rect rect = {0, 0};
//    SDL_Event event;
//    bool quit = false;
//    while (!quit) {
//        while (SDL_PollEvent(&event)) {
//            if (event.type == SDL_QUIT) quit = true; // 关闭窗口
//            else if (event.type == SDL_MOUSEBUTTONDOWN) {
//                if (event.button.button == SDL_BUTTON_LEFT) {
//                    SDL_BlitSurface(img1, nullptr, surface, &rect);
//                    current = img1;
//                } else if (event.button.button == SDL_BUTTON_RIGHT) {
//                    SDL_BlitSurface(img2, nullptr, surface, &rect);
//                    current = img2;
//                }
//            } else if (event.type == SDL_KEYDOWN) {
//                switch (event.key.keysym.sym) {
//                    case SDLK_DOWN:
//                        rect.y += 10;
//                        printf("下\n");
//                        break;
//                    case SDLK_UP:
//                        rect.y -= 10;
//                        printf("上\n");
//                        break;
//                    case SDLK_LEFT:
//                        rect.x -= 10;
//                        printf("左\n");
//                        break;
//                    case SDLK_RIGHT:
//                        rect.x += 10;
//                        printf("右\n");
//                        break;
//                    default:
//                        break;
//                }
//                SDL_FillRect(surface, nullptr, 0);
//                SDL_BlitSurface(current, nullptr, surface, &rect);
//            }
//        }
//        SDL_UpdateWindowSurface(window);
//    }
//    SDL_FreeSurface(surface);
//    SDL_DestroyWindow(window);
//    SDL_Quit();
//    return 0;
//}
//

//int main(int argc, char **argv) {
//    SDL_Init(SDL_INIT_VIDEO);
//    SDL_Window *window = SDL_CreateWindow("SDL Tutorial4", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
//                                          800, 600,
//                                          SDL_WINDOW_SHOWN);
//    SDL_Surface *surface = SDL_GetWindowSurface(window);
//    // renderer
//    // texture
//
//    SDL_Surface *cat = IMG_Load("/home/xcy/CLionProjects/Agorithm/SDL学习/SDLTutorial/猫.png");
//    SDL_Event event;
//    bool quit = false;
//    SDL_Rect rect = {0, 0};
//    while (!quit) {
//        while (SDL_PollEvent(&event)) {
//            if (event.type == SDL_QUIT) quit = true;
//            else if (event.type == SDL_MOUSEMOTION) {
//                printf("hello world，当前位置(%d,%d)\n", event.motion.x, event.motion.y);
//
//                rect.x = event.motion.x - cat->w / 2;
//                rect.y = event.motion.y - cat->h / 2;
//                SDL_FillRect(surface, nullptr, 0); // 覆盖整个屏 导致闪烁
//                SDL_BlitSurface(cat, nullptr, surface, &rect);
//                SDL_UpdateWindowSurface(window);
//            }
//        }
//    }
//    SDL_DestroyWindow(window);
//    SDL_Quit();
//    return 0;
//}

//int main(int argc, char **argv) {
//    SDL_Init(SDL_INIT_VIDEO);
//    SDL_Window *window = SDL_CreateWindow("SDL Tutorial4_p", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
//                                          800, 600,
//                                          SDL_WINDOW_SHOWN);
//    SDL_Renderer *rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//
//    SDL_Surface *catSurface = IMG_Load("/home/xcy/CLionProjects/Agorithm/SDL学习/SDLTutorial/猫.png");
//    SDL_Texture *cat = SDL_CreateTextureFromSurface(rend, catSurface);
//    SDL_Event event;
//    bool quit = false;
//    SDL_Rect rect = {0, 0, catSurface->w, catSurface->h};
//    while (!quit) {
//        while (SDL_PollEvent(&event)) {
//            if (event.type == SDL_QUIT) quit = true;
//            else if (event.type == SDL_MOUSEMOTION) {
//                printf("hello world，当前位置(%d,%d)\n", event.motion.x, event.motion.y);
//
//                rect.x = event.motion.x - catSurface->w / 2;
//                rect.y = event.motion.y - catSurface->h / 2;
//                SDL_RenderClear(rend);
//                SDL_RenderCopy(rend, cat, nullptr, &rect);
//                SDL_RenderPresent(rend);
//            }
//        }
//        SDL_Delay(5);
//    }
//    SDL_DestroyWindow(window);
//    SDL_Quit();
//    return 0;
//}


// 碰撞测试

#define WINDOW_WIDTH 300
#define WINDOW_HEIGHT 600

SDL_Rect rect = {0, 0, 100, 100};
bool moveRight = true;
bool moveDown = true;

void updatePosition() {
    if (moveRight) {
        rect.x++;
        if (rect.x + rect.w >= WINDOW_WIDTH) moveRight = false;
    } else {
        rect.x--;
        if (rect.x <= 0) moveRight = true;
    }
    if (moveDown) {
        rect.y++;
        if (rect.y + rect.h >= WINDOW_HEIGHT) moveDown = false;
    } else {
        rect.y--;
        if (rect.y <= 0) moveDown = true;
    }
}

int main(int argc, char **argv) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("SDL Tutorial4_p", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          WINDOW_WIDTH, WINDOW_HEIGHT,
                                          SDL_WINDOW_SHOWN);
    SDL_Renderer *rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Surface *catSurface = IMG_Load("/home/xcy/CLionProjects/Agorithm/SDL学习/SDLTutorial/猫.png");
    if (catSurface == nullptr) printf("出错:%s\n", strerror(errno));
    SDL_Texture *cat = SDL_CreateTextureFromSurface(rend, catSurface);
    SDL_Event event;
    bool quit = false;
//    SDL_Rect rect = {0, 0, catSurface->w, catSurface->h};
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) quit = true;
//            else if (event.type == SDL_MOUSEMOTION) {
//                printf("hello world，当前位置(%d,%d)\n", event.motion.x, event.motion.y);
//
//
//            }

        }
        updatePosition();
        SDL_Delay(5);
        SDL_RenderClear(rend);
        SDL_RenderCopy(rend, cat, nullptr, &rect);
        SDL_RenderPresent(rend);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}