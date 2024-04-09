#include "RenderWindow.hpp"
#include "Entity.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
	:window(nullptr),renderer(nullptr)
{
	window=SDL_CreateWindow(p_title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
                            p_w,p_h,SDL_WINDOW_SHOWN);
    if (window != nullptr) {}
    else {
        LOG("Window initialisation failed");
        LOG(SDL_GetError());
    }
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = nullptr;
	texture = IMG_LoadTexture(renderer,p_filePath);
	if(texture==nullptr){
		LOG("texture loading SDL_GetError");
		LOG("SDL_GetError");
	}
	return texture;
}

void RenderWindow::CleanUp(){
	SDL_DestroyWindow(window);
}
void RenderWindow::clear(){
	SDL_RenderClear(renderer);
}
void RenderWindow::renderTexture(SDL_Texture* p_tex){
	SDL_Rect src,dst;
	src.x =src.y=dst.x = dst.y =0;//a rect to cut and a rect to past
	src.w =src.h=dst.h = dst.w =32;
	SDL_RenderCopy(renderer,p_tex,&src,&dst);
}

void RenderWindow::renderEntity(Entity& p_ent){
    SDL_Rect src,dst;
    int scale = 2;
    src.x = p_ent.getCurrentFrame().x;
    src.y = p_ent.getCurrentFrame().y;
    src.w = p_ent.getCurrentFrame().w;
    src.h = p_ent.getCurrentFrame().h;

    dst.x = p_ent.getX() * scale;
    dst.y = p_ent.getY() * scale;

    dst.w = p_ent.getCurrentFrame().w*scale;
    dst.h = p_ent.getCurrentFrame().h*scale;
    SDL_RenderCopy(renderer,p_ent.getTex(),&src,&dst);
}
void RenderWindow::display(){
	SDL_RenderPresent(renderer);
}