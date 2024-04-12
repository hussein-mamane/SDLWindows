//
// Created by Housseini on 11/04/2024.
//

#ifndef SDL2P1_MATH_H
#define SDL2P1_MATH_H


class Vector2f {

public:
    Vector2f(float _x,float _y):x(_x),y(_y)
    {}
    Vector2f():x(0.0f),y(0.0f)
    {}

    float x;
    float y;
};


#endif //SDL2P1_MATH_H
