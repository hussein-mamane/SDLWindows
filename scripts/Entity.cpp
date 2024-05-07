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


/*void Entity::setCurrentFrame(const SDL_Rect &currentFrame) {
    Entity::currentFrame = currentFrame;
}*/

void Entity::setTex(SDL_Texture *tex) {
    Entity::tex = tex;
}

const Vector2f &Entity::getPos() const {
    return pos;
}

void Entity::setPos(const Vector2f &pos) {
    Entity::pos = pos;
}

/*
 * from a big image of multiple frames
 **/
void Entity::setCurrentFrame(int imgRow, int imgCol, int width,int height) {
    /*if(nbImgRow>nbImgCol){
        // index of rows and cols start at 0
        //even indexes are on a column basis
        currentFrame.w=width;
        currentFrame.h=height;
        currentFrame.x=(imgIndex-nbImgRow)*height;
        currentFrame.y=(nbImgRow*height)+height;//
    }
    else if (nbImgCol<nbImgRow){

        //odd indexes are on a column basis
    }
    else{
        if(width%2==0){
            //even indexes are on a column basis
        }
        else{
            //example of a 3*3 Matrix of frames
        }
    }*/
    currentFrame.w=width;
    currentFrame.h=height;
    currentFrame.x=imgCol*width;
    currentFrame.y=imgRow*height;
}

//void
//Entity::MakeFrameArray(const RenderWindow& window, const std::string &frameTilesPath, int frameWidth, int frameHeight) {
//
//}


void Entity::MakeFrameArray(const std::string &frameTilesPath,char* animationName,int frameWidth, int frameHeight, int nbRows, int nbCols) {
    for(int i = 0; i < nbRows;++i){
        for(int j = 0; j < nbCols;++j){
            // crop the frame
            setCurrentFrame(i,j,frameWidth,frameHeight);
            // add the frame to the animationName entry of the map
        }
    }
}

