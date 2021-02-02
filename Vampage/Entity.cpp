#include "pch.h"
#include "Entity.h"

void Entity::InitPhysics()
{
	this->velocity = Vector2f(0, 0);
}

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::UpdateGravity()
{
	this->velocity.y += 5.f;

	
}
