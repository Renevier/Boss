#include "pch.h"
#include "Boss.h"

Boss::Boss(RenderWindow* _window, float _width, float _height, float _posX, float _posY, const Vector2f* _playerPos)
	:Entity(_window, _width, _height, _posX, _posY)
{
	this->shape.setFillColor(Color::Red);
	this->hp = 100;
	this->playerPos = _playerPos;
	this->movementSpeed = .5f;
}

Boss::~Boss()
{

}

void Boss::Update()
{
	this->Move();

	this->timeBeetwenWaves = clockWaves.getElapsedTime();
	this->timeBeetwenRay = clockRay.getElapsedTime();

	this->UpdateShockwaves();
	this->UpdateRay();

	if (this->hp <= 30 && this->timeBeetwenRay.asSeconds() >= 2.f)
		this->RayPattern();

	if (this->hp < 70 && timeBeetwenWaves.asSeconds() >= 1.f)
		this->ShockwavesPattern();

	if (Keyboard::isKeyPressed(Keyboard::Key::Numpad1)) //phase 1
		this->hp = 50;

	if (Keyboard::isKeyPressed(Keyboard::Key::Numpad2)) //phase 2
		this->hp = 20;
}

void Boss::Move()
{
	this->Follow();

	Entity::Move();
}

void Boss::Follow()
{
	this->direction = *this->playerPos - this->shape.getPosition();

	this->normailizeDir.x = this->direction.x / sqrt(pow(this->direction.x, 2) + pow(this->direction.y, 2));
	this->normailizeDir.y = 0;

	this->velocity = this->normailizeDir * movementSpeed;
}

void Boss::ShockwavesPattern()
{
	if (this->shockwaves.size() == 0)
	{
		this->timeBeetwenWaves = clockWaves.restart();

		this->shockwaves.push_back(make_unique<Shockwave>(this->window, 100, 50, this->shape.getPosition().x,
			this->window->getSize().y - 25));

		this->shockwaves.push_back(make_unique<Shockwave>(this->window, 100, 50, this->shape.getPosition().x,
			this->window->getSize().y - 25));
	}
}

void Boss::UpdateShockwaves()
{
	for (int i = 0; i < shockwaves.size(); i++)
	{
		if (i % 2 == 0)
			this->shockwaves.at(i)->Move();
		else
			this->shockwaves.at(i)->MoveInv();

		if (this->shockwaves.at(i)->GetPos().x - this->shockwaves.at(i)->GetBounds().width / 2 <= 0 ||
			this->shockwaves.at(i)->GetPos().x + this->shockwaves.at(i)->GetBounds().width / 2 >= this->window->getSize().x)
			this->shockwaves.erase(this->shockwaves.begin() + i);
	}
}

void Boss::RayPattern()
{
	Ray* temp = new Ray();

	if (rayVector.size() == 0)
	{
		this->rayVector.push_back(new Ray(this->window, 100, 5,
			this->shape.getPosition().x + this->shape.getGlobalBounds().width + temp->GetBounds().width + 1,
			this->window->getSize().y - 2.5));

		this->rayVector.push_back(new Ray(this->window, 100, 5,
			this->shape.getPosition().x - this->shape.getGlobalBounds().width - temp->GetBounds().width - 1,
			this->window->getSize().y - 2.5));

		this->rayVector.push_back(new Ray(this->window, 100, 5,
			this->playerPos->x,
			this->window->getSize().y - 2.5));
	}

	delete temp;
}

void Boss::UpdateRay()
{
	if (this->timeBeetwenRay.asSeconds() >= 6.f)
	{
		this->rayVector.clear();
		this->clockRay.restart();
	}

	for (int i = 0; i < this->rayVector.size(); i++)
	{
		if (this->timeBeetwenRay.asSeconds() >= 4.f)
			this->rayVector[i]->Update();
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
