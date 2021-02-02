#pragma once
#include "Player.h"
#include <memory>

class Game
{
private:
	RenderWindow window;
	Event event;

	unique_ptr<Player> player;

private:
	void InitWindow();
	void InitPlayer();

public:
	Game();
	~Game();


	void Update();
	void UpdatePlayer();

	void Render();
	void RenderPlayer();

	inline const RenderWindow& GetWindow() const { return this->window; }
};

