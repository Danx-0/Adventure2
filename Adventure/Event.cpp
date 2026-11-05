#include "Event.h"
#include "Enemy2.h"
#include "Enemy3.h"

Event::Event()
{
	baseEnemy = nullptr;
	numOffEvents = 0;
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

	int level = p.GetLevel(); //se supone que el enemigo depende del nivel del jugador
	if (level <= 2)
	{
		baseEnemy = new Enemy2(level);  
	}
	else if (level <= 4)
	{
		// Orden: name, level, hp, damage, defence, exp
		baseEnemy = new Enemy("Smile", level, level * 3, level * 2, 0, level * 12); 
	}
	else
	{
		baseEnemy = new Enemy3(level);  
	}
	baseEnemy->PrintStats();
	std::cout << "A wild " << baseEnemy->GetName() << " appears!" << std::endl;



	while (!playerDefeated && !enemyDefeated && !escape)
	{
			int scapeRand = 0;
			int attackRoll = 0;


		if (playerTurn)
		{
			std::cout << "Choose your action" << std::endl;
			std::cout << "0: Scape" << std::endl;
			std::cout << "1: Attack" << std::endl;
			std::cout << "2: Defend" << std::endl;
			std::cout << "3: Player Sheet" << std::endl;
			std::cout << "4: Show Enemy Stats" << std::endl;

			std::cin >> choice;

			
			switch (choice) //dentro de un swich no puedo poner int 
			{
			case 0:
				scapeRand = (rand() % 100) + (p.GetLuck() + p.GetAgility()) / 2;
					if (scapeRand > 25)
					{
						std::cout << "Escaped...." << std::endl;
						escape = true;
					}
				break;
			case 1:
				std::system("cls");
				attackRoll = rand() % 100 + 1;
				if (attackRoll > 50 - (p.GetStrenght() + p.GetDexterity()))
				{
					int dmg = p.DoDamage();
					baseEnemy->TakeDamge(dmg);
					std::cout << "Player hits " << baseEnemy->GetName() << " for " << dmg << std::endl;
					std::cout << baseEnemy->GetName() << " HP left: " << baseEnemy->GetHP() << std::endl;
				}
				else
				{
					std::cout << "Player misses!" << std::endl;
				}
				break;
			case 2:
				PlayerDefending = true;
				break;
			case 3:
				p.PrintPlayerStats();
				break;
			case 4:
				baseEnemy->PrintStats();
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
				std::cout << "----------------------" << std::endl;
				std::cout << baseEnemy->GetName() << " Defeated" << std::endl;
				std::cout << "Exp: " << baseEnemy->GetExp() << std::endl;
				p.AddExp(baseEnemy->GetExp());
				p.LevelUp();  
				std::cout << "Level: " << p.GetLevel() << std::endl;
			

			}
			else
			{
				int enemyAttackRoll = rand() % 100 + 1 - p.GetLuck();
				if (PlayerDefending)
				{
					if (enemyAttackRoll > 75)
					{
						std::cout << "Enemy hits player" << std::endl;
						p.TakeDamge(baseEnemy->DoDamage());
					}
					else
					{
						std::cout << "Enemy misses!" << std::endl;

					}
				}
				else
				{
					if (enemyAttackRoll > 45)
					{
						std::cout << "Enemy hits player" << std::endl;
						p.TakeDamge(baseEnemy->DoDamage());
					}
					else
					{
						std::cout << "Enemy misses!" << std::endl;
					}
				}
			}
			playerTurn = true;
		}
	}
	delete baseEnemy;
	baseEnemy = nullptr;
}

void Event::PuzzleEncounter(Player& p)
{
}


