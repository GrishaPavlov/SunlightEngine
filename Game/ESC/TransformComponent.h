#pragma once

#include "Components.h"
#include "ESC.h"
#include "../Vector2D.h"

class TransformComponent : public Component {

public:
    Vector2D position;
    Vector2D velocity;

    int speed = 3;

    int height = 32;
    int width = 32;
    int scale = 1;

    TransformComponent() {
        position.x = 0.0f;
        position.y = 0.0f;
    }

    TransformComponent(float x, float y) {
        position.x = x;
        position.y = y;
    }

    void init() override {
        velocity.x = 0.0f;
        velocity.y = 0.0f;
    }

    void update() override {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }

};