#include "pch.h"
#include "Game.h"

void Game::InitWindow()
{
	this->window = new RenderWindow(VideoMode(800, 600), "Boss");
	this->window->setFramerateLimit(144);
}

void Game::InitPlayer()
{
	this->player = make_unique<Player>(this->window, 50, 50, 100, 100);
}

void Game::InitBoss()
{
	this->boss = make_unique<Boss>(this->window, 100, 100, 350, 200);
}

Game::Game()
{
	this->InitWindow();
	this->InitPlayer();
	this->InitBoss();
}

Game::~Game()
{
	delete this->window;
}

void Game::Update()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == Event::Closed)
			this->window->close();
		else if(this->event.type == Event::KeyPressed && this->event.key.code == Keyboard::Escape)
			this->window->close();
	}

	this->UpdatePlayer();
	this->UpdateBoss();
}

void Game::UpdatePlayer()
{
	this->player->Update();
}

void Game::UpdateBoss()
{
	this->boss->Update();
}

void Game::Render()
{
	this->window->clear();


	this->RenderPlayer();
	this->RenderBoss();


	this->window->display();
}

void Game::RenderPlayer()
{
	this->player->Render(*this->window);
}

void Game::RenderBoss()
{
	this->boss->Render(*this->window);
}
