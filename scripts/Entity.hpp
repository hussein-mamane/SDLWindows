#pragma once
#include<SDL.h>
#include<iostream>
#include<SDL_image.h>
#include "Math.h"
#include "utils.hpp"
//#include "RenderWindow.hpp" // error, Entity has not been declared(because of mirror include and pragma once)
#include <vector>
#include <array>
#include <map>
class Entity
{
public:
	Entity(Vector2f,SDL_Texture*);
    SDL_Texture * getTex();
    SDL_Rect getCurrentFrame();


    //void setCurrentFrame(const SDL_Rect &currentFrame);

    void setTex(SDL_Texture *tex);
    const Vector2f &getPos() const;
    void setPos(const Vector2f &pos);


    //void setCurrentFrame(int nbImgWidth, int nbImgHeight, int imgIndex, int width, int height);
    void setCurrentFrame(int frameRow, int frameCol, int frameWidth,int frameHeight);
    void chooseCurrentFrame(int frameIndex);
    void MakeFrameArray(const std::string &frameTilesPath,const char* animationName,int frameWidth, int frameHeight, int nbRows, int nbCols);
//    void MakeFrameArray(const RenderWindow& window, const std::string& frameTilesPath,int frameWidth,int frameHeight);
    // there are other ways to do this, but this is very simple
    std::vector<SDL_Rect> frameArray;
//    std::map<std::string,utils::Interval> animationStatesFramesBoundaries; //for the state pattern of frames in the vector
    std::map<std::string,std::array<int,2>> animationStatesFramesBoundaries; //for the state pattern of frames in the vector

private:
	Vector2f pos;
	SDL_Rect currentFrame;
	SDL_Texture* tex{};
/*
     //possibles states enumeration
    enum possibleState{
        IDLE=0,
        WALKING=1
    };
     */
};
