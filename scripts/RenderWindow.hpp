#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Entity.hpp"

#define LOG(x) std::cout << x << stderr << std::endl;


class RenderWindow
{
public:
	RenderWindow(const char* p_title, int p_w, int p_h);
	SDL_Texture* loadTexture(const char* p_filePath);


	void CleanUp();
	void clear();
	void display();
    void renderTexture(SDL_Texture *p_tex);
    void renderEntity(Entity& p_ent,int scale);
    int getRefreshRate();

    SDL_Renderer *getRenderer() const;

private:
	SDL_Window* window;
	SDL_Renderer* renderer;


};
