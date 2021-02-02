#pragma once
#include "Entity.h"
class Boss :
    public Entity
{
protected:

public:
    Boss(RenderWindow* _window, float _width, float _height, float _posX, float _posY);
    ~Boss();

    virtual void Move();

};

