#pragma once
#include "Player.h"

class Game
{
private:
	RenderWindow window;
	Event event;

	Player* player;

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

