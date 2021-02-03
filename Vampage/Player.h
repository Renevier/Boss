#pragma once
#include "Entity.h"

class Player: public Entity
{
private:

private:

public:
	Player();
	Player(RenderWindow* _window, float _width, float _height, float _posX, float _posY);
	~Player(); 

	virtual void Move();

	inline const Vector2f& GetPos() const { return this->shape.getPosition(); }
};

