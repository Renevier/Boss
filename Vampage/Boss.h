#pragma once
#include "Entity.h"
#include "Shockwave.h"

class Boss :
    public Entity
{
    vector<Shockwave*> shockwaves;

    Clock clock;

public:
    Boss(RenderWindow* _window, float _width, float _height, float _posX, float _posY);
    ~Boss();

    virtual void Update();
    virtual void Move();
    void ShockwavesPattern();

    void RenderSockwaves();
    virtual void Render(RenderTarget& _target);
};