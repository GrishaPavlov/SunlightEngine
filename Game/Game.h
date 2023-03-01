#ifndef PROJECT_NAME_GAME_H
#define PROJECT_NAME_GAME_H
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>


class Game {
public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();

    static SDL_Renderer *renderer;
    static SDL_Event event;

    bool running() { return isRunning;}

private:
    int cntr = 0;
    bool isRunning{};
    SDL_Window *window{};
    SDL_Surface *surface{};
};


#endif //PROJECT_NAME_GAME_H
