#pragma once
#include "Entity.h"
class Ray :
    public Entity
{
private:

public:
    Ray();
    Ray(RenderWindow* _window, float _width, float _height, float _posX, float _posY);
    ~Ray();

    virtual void Move();
    virtual void MoveInv();

    inline const FloatRect& GetBounds() const { return this->shape.getGlobalBounds(); }
};

