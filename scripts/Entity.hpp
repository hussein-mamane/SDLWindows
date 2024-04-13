#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include "Math.h"
class Entity
{
public:
	Entity(Vector2f,SDL_Texture*);
    SDL_Texture * getTex();
    SDL_Rect getCurrentFrame();

    void setCurrentFrame(const SDL_Rect &currentFrame);

    void setTex(SDL_Texture *tex);
    const Vector2f &getPos() const;
    void setPos(const Vector2f &pos);

    void setCurrentFrame(int nbImgWidth, int nbImgHeight, int imgIndex, int width, int height);

private:
	Vector2f pos;
	SDL_Rect currentFrame;
	SDL_Texture* tex{};

};