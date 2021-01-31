#include "pch.h"
#include "Game.h"

void Game::InitWindow()
{
	this->window.create(VideoMode(800, 600), "Boss");
	this->window.setFramerateLimit(144);
}

void Game::InitPlayer()
{
	this->player = new Player();
}

Game::Game()
{
	this->InitWindow();
	this->InitPlayer();
}

Game::~Game()
{
	delete this->player;
}

void Game::Update()
{
	while (this->window.pollEvent(this->event))
	{
		if (this->event.type == Event::Closed)
			this->window.close();
		else if(this->event.type == Event::KeyPressed && this->event.key.code == Keyboard::Escape)
			this->window.close();
	}

	this->UpdatePlayer();
}

void Game::UpdatePlayer()
{
	this->player->Update();
}

void Game::Render()
{
	this->window.clear();


	this->RenderPlayer();


	this->window.display();
}

void Game::RenderPlayer()
{
	this->player->Render(this->window);
}
