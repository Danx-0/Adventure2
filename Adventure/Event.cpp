#include "Event.h"

Event::Event()
{
}

Event::~Event()
{
}

void Event::GenerateEvent(Player& p)
{
	srand(static_cast<unsigned int> (time(0)));
	int i = rand() % 10;
	switch (i)
	{
	case 7:
		std::cout << "Keep Traveling..." << std::endl;
		break;

	case 5:
		std::cout << "Puzzle Encounter" << std::endl;
		break;

	default:
		std::cout << "Enemy Encounter" << std::endl;
		EnemyEncounter(p);

		break;
	}
}

void Event::EnemyEncounter(Player& p)
{
	std::system("cls");
	int choice = 0;
	bool playerDefeated = false;
	bool enemyDefeated = false; 
	bool escape = false;
	bool playerTurn = false; 
	bool PlayerDefending = false;
	int firstTurn = rand() % 100 + 1;
	if (firstTurn >= 50 - p.GetLuck())
	{
		playerTurn = true;
	}
	else
	{
		playerTurn = false;
	}
	std::cout << "------New Enemy Encounter------" << std::endl;

	int level = p.GetLevel();
	int hp = level * 10;
	int damageMin = rand() % level + 1;
	int damageMax = (rand() % level +1)* 2;
	int currentDamage = rand() / (damageMax - damageMin + 1);
	int defence = rand() % level;
	int exp = level * 10;
	baseEnemy = new Enemy("Pato", level, hp, currentDamage, defence, exp);

	while (!playerDefeated || !enemyDefeated || !escape)
	{
			int scapeRand = 0;
			int attackRoll = 0;


		if (playerTurn)
		{
			std::cout << "Choose your action" << std::endl;
			std::cout << "1: Attack" << std::endl;
			std::cout << "2: Defend" << std::endl;
			std::cout << "3: Player Sheet" << std::endl;
			std::cout << "4: Show Enemy Stats" << std::endl;
			std::cout << "0: Scape" << std::endl;

			std::cin >> choice;

			
			switch (choice) //dentro de un swich no puedo poner int 
			{
			case 0:
				scapeRand = (rand() % 100) + p.GetLuck();
					if (scapeRand > 25)
					{
						std::cout << "Escaped...." << std::endl;
						escape = true;
					}
				break;
			case 1:
				std::system("cls");
				attackRoll = rand() % 100 + 1;
				if (attackRoll > (50 - p.GetAgility()))
				{
					std::cout << "Player hit Enemy" << std::endl;
					baseEnemy->TakeDamge(p.DoDamage());
				}
				break;
			case 2:
				PlayerDefending = true;
				break;
			case 3:
				p.PrintPlayerStats();
				break;
			case 4:
				baseEnemy->PrintEnemyStats();
				break;
			default:
				std::cout << "Invalid Option " << std::endl;
				break;
			}
			playerTurn = false;
		}
		else
		{
			std::cout << "-------ENEMY TURN-------" << std::endl;
			if (!baseEnemy->IsAlive())
			{
				enemyDefeated = true;
				std::cout << "Enemy Defeated" << std::endl;
				std::cout << "Exp: " << baseEnemy->GetExp() << std::endl;
			}
			else
			{
				attackRoll = rand() % 100 + 1;
				if (PlayerDefending)
				{
					if (attackRoll > 75)
					{
						std::cout << "Enemy hit player" << std::endl;
						p.TakeDamge(baseEnemy->DoDamage());
					}
					else
					{
						std::cout << "Enemy miss player" << std::endl;

					}
				}
				else
				{
					if (attackRoll > 45)
					{
						std::cout << "Enemy hit player" << std::endl;
						p.TakeDamge(baseEnemy->DoDamage());
					}
					else
					{
						std::cout << "Enemy miss player" << std::endl;
					}
				}
			}
			playerTurn = true;
		}
	}
}

void Event::PuzzleEncounter(Player& p)
{
}


