#include "pch.h"
#include "Player.h"

Player::Player(RenderWindow* _window, float _width, float _height, float _posX, float _posY)
	:Entity(_window, _width, _height, _posX, _posY)
{

}

Player::~Player()
{
}

void Player::Move()
{
	Entity::Move();

	if (Keyboard::isKeyPressed(Keyboard::Key::Q))
		this->velocity.x -= 0.5f;
	
	if(Keyboard::isKeyPressed(Keyboard::Key::D))
		this->velocity.x += 0.5f;

	/*if (Keyboard::isKeyPressed(Keyboard::Key::Space))
		this->shape.move(0, -50);*/
}