#include "Entity.hpp"

Entity::Entity(Vector2f _pos, SDL_Texture *_tex)
:pos(_pos),tex(_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 128;
    currentFrame.h = 64;
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

void Entity::setCurrentFrame(int nbImgWidth, int nbImgHeight, int imgIndex, int width,int height) {
    if(nbImgHeight>nbImgWidth){
        //even indexes are on a column basis
        currentFrame.w=width;
        currentFrame.h=height;
        currentFrame.x=(imgIndex-nbImgWidth)*height;
        currentFrame.y=((imgIndex-nbImgWidth)*height)+height;
    }
    else if (nbImgHeight<nbImgWidth){

        //odd indexes are on a column basis
    }
    else{
        if(width%2==0){
            //even indexes are on a column basis
        }
        else{
            //example of a 3*3 Matrix of frames
        }
    }

}
