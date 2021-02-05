#include "pch.h"
#include "Shockwave.h"

Shockwave::Shockwave(RenderWindow* _window, float _width, float _height, float _posX, float _posY)
	:Entity(_window, _width, _height, _posX, _posY)
{}

Shockwave::~Shockwave()
{
}

void Shockwave::Move()
{
	this->velocity += Vector2f(.2f, 0.f);
	this->shape.move(velocity);
}

void Shockwave::MoveInv()
{
	this->velocity -= Vector2f(.2f, 0.f);

	Entity::Move();
}
