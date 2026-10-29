#pragma once
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Event.h"

class Game
{
private:
	Player player;
	Event v;
	Enemy* enemy; 
	int choice;
	bool playing;


public:
	Game();
	virtual ~Game();
	void InitGame();
	void mainMenu();

	void Travel();

	void SaveGame();
	void LoadGame();
	void NewPlayer();
	void NewEnemy();
	void PrintPlayerStats();

	bool GetPlaying();

};

