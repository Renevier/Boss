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

	inline const Vector2f& GetPos() const { return this->shape.getPosition(); }
	inline const FloatRect& GetBounds() const { return this->shape.getGlobalBounds(); }
};