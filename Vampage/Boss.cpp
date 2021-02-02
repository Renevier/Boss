#include "pch.h"
#include "Boss.h"

Boss::Boss(RenderWindow* _window, float _width, float _height, float _posX, float _posY)
	:Entity(_window, _width, _height, _posX, _posY)
{
}

Boss::~Boss()
{
}

void Boss::Move()
{
	Entity::Move();
}
