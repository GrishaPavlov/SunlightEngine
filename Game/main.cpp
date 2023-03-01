#include "Game.h"

Game *game = nullptr;

int main(int argv, char **args) {
    const int fps = 120;
    const int frameDelay = 1000 / fps;

    uint32_t frameStart;
    int frameTime;

    game = new Game();
    std::cout << "About to create a window" << std::endl;
    game->init("GameEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    while (game->running()) {
        frameStart = SDL_GetTicks();
        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay >= frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();

    return 0;
}