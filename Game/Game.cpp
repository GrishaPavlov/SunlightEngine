#include "Game.h"
#include "TextureLoader.h"
#include "Map.h"
#include "ESC/Components.h"
#include "Vector2D.h"

Map* map;
Manager manager;
SDL_Event Game::event;


SDL_Renderer* Game::renderer = nullptr;

auto& player(manager.addEntity());

Game::Game() = default;

Game::~Game() = default;

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    if (fullscreen)
        flags = SDL_WINDOW_FULLSCREEN;
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

        if (IMG_Init(IMG_INIT_PNG) == 0) {
            std::cout << "Error SDL2_image Initialization";
        }

        std::cout << "Subsystems Initialised!..." << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
            std::cout << "Window Created!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer Created!" << std::endl;
        }

        isRunning = true;
    } else {
        isRunning = false;
    }

    map = new Map();
    player.addComponent<TransformComponent>(10, 10);
    player.addComponent<SpriteComponent>("assets/player.png");
    player.addComponent<KeyboardContoller>();


}

void Game::handleEvents() {

    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update() {
    cntr++;

    manager.refresh();
    manager.update();
    if (player.getComponent<TransformComponent>().position.x > 100)
    {
        player.getComponent<SpriteComponent>().setTex("assets/enemy.png");
    }
}

void Game::render() {

    SDL_RenderClear(renderer);
    // this is where we would add stuff to render
    map->DrawMap();
    manager.draw();
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}