#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#define LOG(x) std::cout << x << std::endl;


class RenderWindow
{
public:
	RenderWindow(const char* p_title, int p_w, int p_h);
	SDL_Texture* loadTexture(const char* p_filePath); 
	void CleanUp();
	void clear();
	void render(SDL_Texture* p_tex);
	void display();
	
private:
	SDL_Window* window;
	SDL_Renderer* renderer;	
};
