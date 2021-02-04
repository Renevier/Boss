#include "pch.h"
#include "Ray.h"

Ray::Ray()
{
}

Ray::Ray(RenderWindow* _window, float _width, float _height, float _posX, float _posY)
	:Entity(_window, _width, _height, _posX, _posY)
{}

Ray::~Ray()
{
}

void Ray::Move()
{
	this->velocity += Vector2f(10.f, 0.f);

	Entity::Move();
}

void Ray::MoveInv()
{
	this->velocity -= Vector2f(10.f, 0.f);

	Entity::Move();
}
