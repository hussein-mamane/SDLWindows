#pragma once
#include<SDL.h>
#include<SDL_image.h>

class Entity
{
public:
	Entity(float _x, float _y,SDL_Texture* _tex);
    SDL_Texture * getTex();
    SDL_Rect getCurrentFrame();

    void setCurrentFrame(const SDL_Rect &currentFrame);

    void setTex(SDL_Texture *tex);

    float getX() const;

    void setX(float x);

    float getY() const;

    void setY(float y);

private:
	float x,y;
	SDL_Rect currentFrame{};
	SDL_Texture* tex{};
};