#include "pch.h"
#include "Boss.h"

Boss::Boss(RenderWindow* _window, float _width, float _height, float _posX, float _posY)
	:Entity(_window, _width, _height, _posX, _posY)
{
	this->shape.setFillColor(Color::Red);
	this->hp = 100;
}

Boss::~Boss()
{

}

void Boss::Update()
{
	Entity::Update();

	if (this->hp < 70 && this->hp > 30)
	{
		this->ShockwavesPattern();
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::Numpad1)) //phase 1
		this->hp = 50;

	if (Keyboard::isKeyPressed(Keyboard::Key::Numpad2)) //phase 2
		this->hp = 20;
}

void Boss::Move()
{
	Entity::Move();

	//Follow player
}

void Boss::ShockwavesPattern()
{
	this->shockwaves.push_back(new Shockwave(this->window, 25, 50, this->shape.getPosition().x,
		this->shape.getPosition().y));

	this->shockwaves.push_back(new Shockwave(this->window, 25, 50, this->shape.getPosition().x,
		this->shape.getPosition().y));

	for (int i = 0; i < shockwaves.size(); i++)
	{
		if (i % 2 == 0)
			this->shockwaves.at(i)->Move();
		else
			this->shockwaves.at(i)->MoveInv();
	}
}

void Boss::RenderSockwaves()
{
	for (int i = 0; i < this->shockwaves.size(); i++)
	{
		this->shockwaves.at(i)->Render(*this->window);
	}
}

void Boss::Render(RenderTarget& _target)
{
	Entity::Render(*this->window);
	this->RenderSockwaves();
}
