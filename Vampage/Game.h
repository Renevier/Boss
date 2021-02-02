#pragma once
#include "Player.h"
#include "Boss.h"

class Game
{
private:
	RenderWindow* window;
	Event event;

	unique_ptr<Player> player;
	unique_ptr<Boss> boss;

private:
	void InitWindow();
	void InitPlayer();
	void InitBoss();

public:
	Game();
	~Game();


	void Update();
	void UpdatePlayer();
	void UpdateBoss();

	void Render();
	void RenderPlayer();
	void RenderBoss();

	inline const RenderWindow& GetWindow() const { return *this->window; }
};

