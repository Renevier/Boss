#pragma once
#include "Entity.h"
#include "Player.h"
#include "Shockwave.h"
#include "Ray.h"

class Boss :
    public Entity
{
    vector<unique_ptr<Shockwave>> shockwaves;
    vector<Ray*> rayVector;

    Clock clockWaves;
    Time timeBeetwenWaves;

    Clock clockRay;
    Time timeBeetwenRay;

    const Vector2f* playerPos;

    Vector2f direction;
    Vector2f normailizeDir;

public:
    Boss(RenderWindow* _window, float _width, float _height, float _posX, float _posY, const Vector2f* _playerPos);
    ~Boss();

    virtual void Update();
    virtual void Move();
    void Follow();

    void UpdateShockwaves();
    void ShockwavesPattern();

    void UpdateRay();
    void RayPattern();

    void RenderSockwaves();
    void RenderRay();
    virtual void Render(RenderTarget& _target);
};