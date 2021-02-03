#include "pch.h"
#include "Entity.h"

void Entity::InitShape(float _width, float _height, float _posX, float _posY)
{
	this->shape.setSize(Vector2f(_width, _height));
	this->shape.setPosition(Vector2f(_posX, _posY));

	this->shape.setOrigin(this->shape.getGlobalBounds().width / 2,
		this->shape.getGlobalBounds().height / 2);
}

void Entity::InitPhysics()
{
	this->movementSpeed = 0.f;
	this->velocity = Vector2f(0, 0);
}

Entity::Entity()
{
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
	this->shape.move(velocity);
}

void Entity::UpdateGravity()
{
	this->velocity += Vector2f(0.f, 0.1f);

	//Bot
	if (this->shape.getPosition().y + this->shape.getGlobalBounds().height / 2 > this->window->getSize().y)
	{
		this->shape.setPosition(
			this->shape.getPosition().x,
			this->window->getSize().y - this->shape.getGlobalBounds().height / 2
		);
		
		this->velocity.y = 0;
	}

	//Right
	if (this->shape.getPosition().x + this->shape.getGlobalBounds().width > this->window->getSize().x)
	{
		this->shape.setPosition(
			this->window->getSize().x - this->shape.getGlobalBounds().width,
			this->shape.getPosition().y
		);
	}

	if (this->shape.getPosition().x <= 0.f)
	{
		this->shape.setPosition(
			0,
			this->shape.getPosition().y
		);
	}
}

void Entity::Render(RenderTarget& _target)
{
	_target.draw(this->shape);
}
