//
// Created by Housseini on 12/04/2024.
//

#ifndef SDL2P1_UTILS_HPP
#define SDL2P1_UTILS_HPP

#include <SDL.h>
namespace utils
{
    inline float hireTimeInSeconds(){
            return SDL_GetTicks()*0.001f;
    }
}
#endif //SDL2P1_UTILS_HPP
