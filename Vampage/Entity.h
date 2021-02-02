#pragma once
class Entity
{
protected:
	RenderWindow* window;

	Vector2f pos;
	Vector2f velocity;
	RectangleShape shape;

protected:
	void InitShape(float _width, float _height, float _posX, float _posY);
	void InitPhysics();

public:
	Entity(RenderWindow* _window, float _width, float _height, float _posX, float _posY);
	~Entity();

	virtual void Update();
	virtual void Move();
	void UpdateGravity();

	void Render(RenderTarget& _target);
};