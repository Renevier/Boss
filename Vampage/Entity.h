#pragma once
class Entity
{
protected:
	Vector2f velocity;

protected:
	void InitPhysics();

public:
	Entity();
	~Entity();

	void UpdateGravity();
};

