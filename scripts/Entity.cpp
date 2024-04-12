#include "Entity.hpp"

Entity::Entity(Vector2f _pos, SDL_Texture *_tex)
:pos(_pos),tex(_tex)
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


void Entity::setCurrentFrame(const SDL_Rect &currentFrame) {
    Entity::currentFrame = currentFrame;
}

void Entity::setTex(SDL_Texture *tex) {
    Entity::tex = tex;
}

const Vector2f &Entity::getPos() const {
    return pos;
}

void Entity::setPos(const Vector2f &pos) {
    Entity::pos = pos;
}
