#pragma once
#include "Entity.h"

class Player: public Entity
{
private:
	RectangleShape shape;


private:
	void InitShape();

public:
	Player();
	~Player(); 

	void Update();
	void UpdateMovement();

	void Render(RenderTarget& _target);
};

