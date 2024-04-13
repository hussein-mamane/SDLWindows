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
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
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
    SDL_SetRenderDrawColor(renderer,255,255,255,0);//white
    SDL_RenderClear(renderer);
}
void RenderWindow::renderTexture(SDL_Texture* p_tex){
	SDL_Rect src,dst;
    //SDL_QueryTexture can get the destination rect ready
	src.x =src.y=dst.x = dst.y =0;//a rect to cut and a rect to past
	src.w =src.h=dst.h = dst.w =64;
	SDL_RenderCopy(renderer,p_tex,&src,&dst);
}

void RenderWindow::renderEntity(Entity& p_ent){
    SDL_Rect src,dst;
    int scale = 1;
    // SDL_RenderCopy ?
    src.x = p_ent.getCurrentFrame().x;
    src.y = p_ent.getCurrentFrame().y;
    src.w = p_ent.getCurrentFrame().w;
    src.h = p_ent.getCurrentFrame().h;

    dst.x = p_ent.getPos().x * scale;
    dst.y = p_ent.getPos().y * scale;

    dst.w = p_ent.getCurrentFrame().w*scale;
    dst.h = p_ent.getCurrentFrame().h*scale;
    SDL_RenderCopy(renderer,p_ent.getTex(),&src,&dst);
}
void RenderWindow::display(){
	SDL_RenderPresent(renderer);
}

int RenderWindow::getRefreshRate() {
    int displayIndex= SDL_GetWindowDisplayIndex(window);
    SDL_DisplayMode  displayMode;
    SDL_GetDisplayMode(displayIndex,0,&displayMode);//modeIndex=0 give the highest Hz the screen can do
    return displayMode.refresh_rate;
}

SDL_Renderer *RenderWindow::getRenderer() const {
    return renderer;
}



// animation in one long image: clip the good rectangle in SDL_RenderCopy
// or
// Clip and create frames in textures array
typedef struct  {
    uint8_t x;
    uint8_t y;
    uint8_t w;
    uint8_t h;

//    void setOrigin(uint8_t _x,uint8_t _y){
//
//    }
} FrameClipLimit;