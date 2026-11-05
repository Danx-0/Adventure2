#include "Game.h"

Game::Game()
{
	this->playing = true;

}

Game::~Game()
{
}

void Game::InitGame()
{
	std::cout << "Starting the Game" << std::endl;	
	NewPlayer();
}

void Game::mainMenu()
{
	std::cout << "----------MAIN MENU----------" << std::endl;	
	std::cout << "0: QuitGame" << std::endl;
	std::cout << "1: Player Stats" << std::endl;
	std::cout << "2: New Enemy" << std::endl;
	std::cout << "3: Travel" << std::endl;
	std::cout << "4: Level Up" << std::endl;
	std::cout << "5: Skill Up" << std::endl;
	std::cout << "6: Save Player" << std::endl;
	std::cout << "7: Load Player" << std::endl;

	
	std::cout << "Enter Choice" << std::endl;	
	std::cin >> choice;

	switch (choice)
	{
	case 0:
		this->playing = false;
		break;
	case 1:
		PrintPlayerStats();
		break;
	case 2:
		NewEnemy();
		break;
	case 3:
		Travel();
		break;
	case 4:
		LevelUp();
		break;
	case 5:
		SkillUp();
		break;
	case 6:
		SavePlayer();
		break;
	case 7:
		LoadPlayer();
		break;

	default:
		std::cout << "Invalid Option" << std::endl;
		break;

	}
}

void Game::Travel()
{
	this->v.GenerateEvent(player);

}

void Game::SaveGame()
{
}

void Game::SavePlayer()
{
	std::string fileName = "savePlayer.txt";
	std::ofstream outFile(fileName);
	if (outFile.is_open())
	{
		outFile << player.SaveStats() << " ";
	}
	else
	{
		std::cout << "Cant save Game" << std::endl;
	}
	outFile.close();
	std::cout << "Is saved" << std::endl;
}

void Game::LoadPlayer()
{
	std::string fileName = "savePlayer.txt";
	player.LoadStats(fileName);
}

void Game::NewPlayer()
{
	player.InitPlayer("PacoOoOo");
}

void Game::NewEnemy()
{
	srand(static_cast<unsigned int>(time(0)));
	std::string name = "smile";
	int level = 10;
	int damage = 10;
	int hp = 1;
	int exp = 1;
	int defence = 10;
	enemy = new Enemy(name, level, hp, damage, defence, exp);//importa el orden en el que se esta colocando en la clase de "Enemy" en la partde  de public 
	enemy->PrintEnemyStats();

}

void Game::PrintPlayerStats()
{
	player.PrintPlayerStats();
 
}

bool Game::GetPlaying()
{
	return this->playing;
}
void Game::SkillUp()
{
	while (player.GetSkillPoints() > 0)
	{
		std::cout << "You have " << player.GetSkillPoints() << " Skill points to use" << std::endl;
		std::cout << "-_-_-_-Stats-_-_-_-" << std::endl;
		std::cout << "1: Strength" << std::endl;
		std::cout << "2: Agility" << std::endl;
		std::cout << "3: Dexterity" << std::endl;
		std::cout << "4: Intelligence" << std::endl;
		std::cout << "5: Luck" << std::endl;
		std::cin >> choice;
		player.AddStats(choice, 1);
	}
	if (player.GetSkillPoints() <= 0)
	{
		std::cout << "Not enough Skill points" << std::endl;
	}
}
void Game::LevelUp()
{
	player.LevelUp();
}