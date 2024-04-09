#include "RenderWindow.hpp"
#include "Entity.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#define groundImagePath "..\\resources\\gfx\\ground_grass_1.png" \
//relative to exe location


// You must include the command line parameters for your main function
// to be recognized by SDL as a WinMain prototype's  impl
// do it or SDL_windows_main.c:80: undefined reference to `SDL_main', I tested
// you can only have one definition of SDL_main in the CMake project
int main(int argc, char* argv[]){
    //initialisation
    if(SDL_Init(SDL_INIT_VIDEO)>0){
        LOG("SDL_Init has failed");
        LOG(SDL_GetError());
    }
    if(!(IMG_Init(IMG_INIT_PNG))){
        LOG("IMG_Init has failed");
        LOG(SDL_GetError());
    }
    RenderWindow window("Game v1.0",640,480);
    //textures loading, use logic to load what you need only
    SDL_Texture* grassTexture = window.loadTexture(groundImagePath);


    Entity entities[3] = {
    Entity(0,48,grassTexture),
    Entity(32,48,grassTexture),
    Entity(64,48,grassTexture)
    };

    bool gameRunning = true;
    SDL_Event event;
    while(gameRunning)
    {
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT)
                gameRunning = false;
            // Handle Events, Call game loop callables
        }
        window.clear();
//        window.render(grassTexture); // window.render(world,CULLING_ENABLED)
        for(Entity entity: entities){
            window.renderEntity(entity);
        }
        window.display();
    }
    window.CleanUp();
    SDL_Quit();
    return(0);
}