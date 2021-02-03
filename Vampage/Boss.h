#pragma once
#include "Entity.h"
#include "Player.h"
#include "Shockwave.h"
#include "Ray.h"

class Boss :
    public Entity
{
    vector<unique_ptr<Shockwave>> shockwaves;
    vector<unique_ptr<Ray>> rayVector;

    Clock clock;
    Time timeBeetwenWaves;

public:
    Boss(RenderWindow* _window, float _width, float _height, float _posX, float _posY);
    ~Boss();

    void UpdateShockwaves();
    virtual void Update();
    virtual void Move();

    void ShockwavesPattern();
    void RayPattern();

    void RenderSockwaves();
    void RenderRay();
    virtual void Render(RenderTarget& _target);
};