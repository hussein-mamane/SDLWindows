#include "Entity.hpp"

Entity::Entity(float _x, float _y, SDL_Texture *_tex)
:x(_x),y(_y),tex(_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
}

SDL_Rect Entity::getCurrentFrame() {
    return currentFrame;
}

SDL_Texture* Entity::getTex() {
    return tex;
}


float Entity::getX() const {
    return x;
}

void Entity::setX(float x) {
    Entity::x = x;
}

float Entity::getY() const {
    return y;
}

void Entity::setY(float y) {
    Entity::y = y;
}

void Entity::setCurrentFrame(const SDL_Rect &currentFrame) {
    Entity::currentFrame = currentFrame;
}

void Entity::setTex(SDL_Texture *tex) {
    Entity::tex = tex;
}
