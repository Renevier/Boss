#include "pch.h"
#include "Player.h"

void Player::InitShape()
{
	this->shape.setPosition(Vector2f(100.f, 100.f));
	this->shape.setSize(Vector2f(50.f, 50.f));
}

Player::Player()
{
	this->InitShape();
	this->InitPhysics();
}

Player::~Player()
{
}

void Player::Update()
{
	this->UpdateMovement();
	this->UpdateGravity();

	this->shape.setPosition(Vector2f(this->velocity.x, this->velocity.y));
}

void Player::UpdateMovement()
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Q))
		this->velocity.x += -5.f;
	else if(Keyboard::isKeyPressed(Keyboard::Key::D))
		this->velocity.x += 5.f;
}

void Player::Render(RenderTarget& _target)
{
	_target.draw(this->shape);
}
