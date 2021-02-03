#include "pch.h"
#include "Player.h"

Player::Player()
{
}

Player::Player(RenderWindow* _window, float _width, float _height, float _posX, float _posY)
	:Entity(_window, _width, _height, _posX, _posY)
{
	this->shape.setFillColor(Color::Blue);
}

Player::~Player()
{
}

void Player::Move()
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Q))
		this->velocity.x += -this->movementSpeed;
	
	if(Keyboard::isKeyPressed(Keyboard::Key::D))
		this->velocity.x += this->movementSpeed;

	if (Keyboard::isKeyPressed(Keyboard::Key::Space))
		this->velocity.y += -this->movementSpeed;

	Entity::Move();
}