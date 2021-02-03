#include "pch.h"
#include "Boss.h"

Boss::Boss(RenderWindow* _window, float _width, float _height, float _posX, float _posY)
	:Entity(_window, _width, _height, _posX, _posY)
{
	this->shape.setFillColor(Color::Red);
	this->hp = 50;
}

Boss::~Boss()
{

}

void Boss::Update()
{
	this->time = clock.getElapsedTime();

	Entity::Update();

	if (this->hp < 70 && this->hp > 30 && time.asSeconds() >= 1.f)
		this->ShockwavesPattern();

	for (int i = 0; i < shockwaves.size(); i++)
	{
		if (i % 2 == 0)
			this->shockwaves.at(i)->Move();
		else
			this->shockwaves.at(i)->MoveInv();

		if (this->shockwaves.at(i)->GetPos().left <= 0 ||
			this->shockwaves.at(i)->GetPos().left + this->shockwaves.at(i)->GetPos().width / 2 >= this->window->getSize().x)
			this->shockwaves.erase(this->shockwaves.begin() + i);
	}

	if (this->hp <= 30)
	{
		this->shockwaves.clear();
		this->RayPattern();
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
	if (this->shockwaves.size() < 10)
	{
		this->time = clock.restart();

		this->shockwaves.push_back(make_unique<Shockwave>(this->window, 100, 50, this->shape.getPosition().x,
			this->window->getSize().y - 25));

		this->shockwaves.push_back(make_unique<Shockwave>(this->window, 100, 50, this->shape.getPosition().x,
			this->window->getSize().y - 25));
	}
}

void Boss::RayPattern()
{
	if (rayVector.size() < 4)
	{
		this->rayVector.push_back(make_unique<Ray>(this->window, 50, 5, this->shape.getPosition().x,
			this->window->getSize().y - 2.5));

		for (int i = 0; i < this->rayVector.size(); i++)
		{
			if (i % 2 == 0)
				this->rayVector.at(i)->Move();
			else
				this->rayVector.at(i)->MoveInv();
		}
	}
}

void Boss::RenderSockwaves()
{
	for (int i = 0; i < this->shockwaves.size(); i++)
		this->shockwaves.at(i)->Render(*this->window);
}

void Boss::RenderRay()
{
	for (int i = 0; i < this->rayVector.size(); i++)
		this->rayVector.at(i)->Render(*this->window);
}

void Boss::Render(RenderTarget& _target)
{
	this->RenderSockwaves();
	this->RenderRay();
	Entity::Render(*this->window);
}
