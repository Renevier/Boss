#pragma once
class Entity
{
protected:
	RenderWindow* window;

	float movementSpeed;
	Vector2f velocity;
	RectangleShape shape;

	int hp;

protected:
	void InitShape(float _width, float _height, float _posX, float _posY);
	void InitPhysics();

public:
	Entity(RenderWindow* _window, float _width, float _height, float _posX, float _posY);
	~Entity();

	virtual void Update();
	virtual void Move();
	virtual void UpdateGravity();

	virtual void Render(RenderTarget& _target);
};