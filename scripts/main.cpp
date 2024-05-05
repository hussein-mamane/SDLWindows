#include "RenderWindow.hpp"
#include "Entity.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include "utils.hpp"

#define groundImagePath "..\\resources\\gfx\\ground_grass_1.png"
#define knightImagePath "..\\resources\\gfx\\run_knight.png"
//relative to exe location


// You must include the command line parameters for your main function
// to be recognized by SDL as a WinMain prototype's  impl
// do it or SDL_windows_main.c:80: undefined reference to `SDL_main'
// you can only have one definition of SDL_main in the CMake project
int main(int argc, char* argv[]){
    //initialisation
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER)>0){
        LOG("SDL_Init has failed");
        LOG(SDL_GetError());
    }
    if(!(IMG_Init(IMG_INIT_PNG))){
        LOG("IMG_Init has failed");
        LOG(SDL_GetError());
    }
    RenderWindow window("Game v1.0",640,480);
    //textures loading, use logic to load what you need only
//    SDL_Surface* surf = IMG_Load(groundImagePath);
//    SDL_Texture* tex = SDL_CreateTextureFromSurface(window.getRenderer(),surf);
//    SDL_RenderCopy(
//
//            )
//    SDL_FreeSurface(surf);
    SDL_Texture* grassTexture = window.loadTexture(groundImagePath);
    SDL_Texture* runTexture = window.loadTexture(knightImagePath);
    std::vector<Entity> entitiesVector = {
            Entity(Vector2f(0,48),grassTexture),
            Entity(Vector2f(32,48),grassTexture),
            Entity(Vector2f(64,48),grassTexture)
    };
    //scope to get deletion

        Entity newOne = Entity(Vector2f(0,0),runTexture);
        entitiesVector.push_back(newOne);



    bool gameRunning = true;
    SDL_Event event;
    const float timeStep = 0.01f;
    float currentTime = utils::hireTimeInSeconds();
    float accumulator = 0.0f;
    while(gameRunning)
    {
        float newTime = utils::hireTimeInSeconds();
        uint32_t startTicks = SDL_GetTicks();
        float frameTime = newTime - currentTime;
        currentTime = newTime; // next iteration
        accumulator+=frameTime;//TODO:explain freezes when I remove this line

        while (accumulator>=timeStep)
        {
            while(SDL_PollEvent(&event)){
                if(event.type == SDL_QUIT)
                    gameRunning = false;
                // Handle Events, Call game loop callables
                if(event.type == SDL_KEYDOWN){
                    entitiesVector[1].setPos(Vector2f(entitiesVector[1].getPos().x+0.25,entitiesVector[1].getPos().y));
                }
            }
            accumulator-=timeStep  ;//fps varies according to speed of processing
        }

        //linear interpolation for physics state
        const float alpha = accumulator/timeStep;// percentage of the timeStep that got realised, to guess physics movement between 2 updates

        window.clear();
        // window.render(grassTexture); // window.render(world,CULLING_ENABLED)
        // Entity or Entity& or auto
        for(Entity& entity: entitiesVector){
//            window.renderEntity(entity);

        }
        newOne.setCurrentFrame(3,1,128,64);
        window.renderEntity(newOne);
        window.display();

        uint32_t endTicks = SDL_GetTicks()-startTicks;
        if(endTicks<1000/window.getRefreshRate()){//faster than refresh rate
            SDL_Delay(1000/window.getRefreshRate()-endTicks);//wait
        }
    }
    window.CleanUp();
    SDL_Quit();
    return(0);
}