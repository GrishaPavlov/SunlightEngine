#pragma once

#include "Components.h"
#include "SDL.h"

class SpriteComponent : public Component
{
private:
    TransformComponent *transform;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;

public:
    SpriteComponent() = default;
    SpriteComponent(const char * path)
    {
        setTex(path);
    }

    void init() override
    {
        std::cout << "Created sprite renderer" << std::endl;
        transform = &entity->getComponent<TransformComponent>();

        srcRect.x = srcRect.y = 0;
        srcRect.w = srcRect.h = 32;
        destRect.w = destRect.h = 64;
    }

    void update() override
    {
        destRect.x = (int)transform->position.x;
        destRect.y = (int)transform->position.y;
    }

    void draw() override
    {
        TextureLoader::Draw(texture, srcRect, destRect);
//        std::cout << "Drawing" << std::endl;
    }

    void setTex(const char* path)
    {
        texture = TextureLoader::LoadTexture(path);
    }
};
