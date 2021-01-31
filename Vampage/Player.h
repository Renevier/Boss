#pragma once
class Player
{
private:
	RectangleShape shape;

	Vector2f velocity;

private:
	void InitShape();
	void InitPhysics();

public:
	Player();
	~Player(); 

	void Update();
	void UpdateMovement();
	void UpdateGravity();

	void Render(RenderTarget& _target);
};

