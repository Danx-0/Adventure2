#include "Event.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include <vector>
#include <cctype> //para toupper (convertir letras a mayuscula)

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
	case 4:
	case 5:
		std::cout << "Puzzle Encounter" << std::endl;
		PuzzleEncounter(p);
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

				PlayerDefending = false;  

				if (!p.IsAlive()) 
				{
					playerDefeated = true;
					std::cout << "---------------" << std::endl;
					std::cout << "   " << p.GetName() << " Has Died..." << std::endl;
					std::cout << "---..-.-.-..-.-.-..---" << std::endl;
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
	std::system("cls");

	std::vector<std::string> words;
	words.push_back("SWORD");
	words.push_back("DRAGON");
	words.push_back("ADVENTURE");
	words.push_back("MONSTER");
	words.push_back("POCOYO");

	const std::string theWord = words[rand() % words.size()];
	std::string wordToGuess(theWord.size(), '_');
	std::string used = "";  
	int lifes = 6;

	std::cout << "_________________HANGMAN_______________" << std::endl;
	std::cout << "A mysterious door is locked. Guess the word letter by letter!" << std::endl;
	std::cout << "You have 6 lives. Each wrong letter costs one life." << std::endl;

	while (wordToGuess != theWord && lifes > 0)
	{
		std::cout << std::endl;
		std::cout << "Word: " << wordToGuess << std::endl;
		std::cout << "Lives: " << lifes << std::endl;
		std::cout << "Used letters: " << used << std::endl;
		std::cout << "Enter a letter: ";

		char letterToGuess;
		std::cin >> letterToGuess;
		letterToGuess = static_cast<char>(std::toupper(letterToGuess));

		
		if (used.find(letterToGuess) != std::string::npos)//SI ya ocupe una letra, ya no cuenta despues 
		{
			std::cout << "You already used that letter!" << std::endl;
			continue;
		}
		used += letterToGuess;

		if (theWord.find(letterToGuess) != std::string::npos)
		{
			// si la letra esta en la palabra, la revelara en todas sus posiciones
			for (int i = 0; i < theWord.size(); ++i)
			{
				if (theWord[i] == letterToGuess)
				{
					wordToGuess[i] = letterToGuess;
				}
			}
			std::cout << "Correct!" << std::endl;
		}
		else
		{
			lifes--;
			std::cout << "Incorrect!" << std::endl;
		}
	}

	
	if (wordToGuess == theWord)
	{
		int expReward = p.GetLevel() * 10 + lifes * 2;   // bonus por vidas sobrantes
		std::cout << "_________________________" << std::endl;
		std::cout << "   " << theWord << "! The door opens..." << std::endl;
		std::cout << "_________________________" << std::endl;
		std::cout << "Exp: " << expReward << std::endl;
		p.AddExp(expReward);
		p.LevelUp();
		std::cout << "Level: " << p.GetLevel() << std::endl;
	}
	else
	{
		std::cout << "________________________" << std::endl;
		std::cout << "   The word was: " << theWord << std::endl;
		std::cout << "------------------------" << std::endl;
		std::cout << "The door stays locked. No exp this time." << std::endl;
	}
}


