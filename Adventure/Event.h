#pragma once
#include <iostream>
#include "Enemy.h"
#include "Player.h"
class Event
{
private:
	int numOffEvents;
	Character* baseEnemy;

public:
	Event();
	~Event();


	void GenerateEvent(Player& p);
	void EnemyEncounter(Player& p);
	void PuzzleEncounter(Player& p);
};

