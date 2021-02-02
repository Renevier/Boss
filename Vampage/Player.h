#pragma once
#include "Entity.h"

class Player: public Entity
{
private:

private:

public:
	Player(RenderWindow* _window, float _width, float _height, float _posX, float _posY);
	~Player(); 

	virtual void Move();

};

