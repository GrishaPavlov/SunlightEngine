#include "TextureLoader.h"

SDL_Texture* TextureLoader::LoadTexture(const char *fileName)
{
    SDL_Surface* tempSurface = IMG_Load(fileName);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    if (tex == nullptr)
        std::cout<< "Couldn't import image: " << SDL_GetError() << std::endl;
    SDL_FreeSurface(tempSurface);

    return tex;
}

void TextureLoader::Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest) {
    SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}
