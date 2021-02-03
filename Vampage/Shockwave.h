#pragma once
#include "Entity.h"

class Shockwave:
	public Entity
{
private:
	
public:
	Shockwave(RenderWindow* _window, float _width, float _height, float _posX, float _posY);
	~Shockwave();

	virtual void Move();
	virtual void MoveInv();

	inline const FloatRect& GetPos() const { return this->shape.getGlobalBounds(); }
};