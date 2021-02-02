#include "pch.h"
#include "Entity.h"

void Entity::InitShape(float _width, float _height, float _posX, float _posY)
{
	this->pos = Vector2f(_posX, _posY);

	this->shape.setSize(Vector2f(_width, _height));
	this->shape.setPosition(Vector2f(this->pos));
}

void Entity::InitPhysics()
{
	this->velocity = Vector2f(0, 0);
}

Entity::Entity(RenderWindow* _window, float _width, float _height, float _posX, float _posY)
{
	this->window = _window;

	this->InitShape(_width, _height, _posX, _posY);
	this->InitPhysics();
}

Entity::~Entity()
{
}

void Entity::Update()
{
	this->Move();
	this->UpdateGravity();
}

void Entity::Move()
{
	this->pos += this->velocity;
	this->shape.setPosition(Vector2f(this->pos));
}

void Entity::UpdateGravity()
{
	this->velocity += Vector2f(0.f, 0.1f);

	if (this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height > this->window->getSize().y)
	{
		this->velocity.y = 0.f;
		this->shape.setPosition(
			this->shape.getGlobalBounds().left,
			this->window->getSize().y - this->shape.getGlobalBounds().height
		);
	}
	/*if (this->shape.getPosition().x >= this->window->getSize().x - this->shape.getGlobalBounds().width)
		this->velocity.x = 0.f;

	if (this->shape.getPosition().x <= 0)
		this->velocity.x = 0.f;*/
}

void Entity::Render(RenderTarget& _target)
{
	_target.draw(this->shape);
}
