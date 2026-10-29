#include "Player.h"

Player::Player()
{
	this->strenght = 5;
	this->agility = 5;
	this->intelligence = 5;
	this->luck = 5;
	this->dexterity = 5;
	this->MaxXp = 10;
}

void Player::InitPlayer(std::string name)
{
	InitCharacter(name);
	SetLevel(1);
	SetExp(0);
	SetHp((this->intelligence*2) / (this->dexterity-2));
	SetDamageMin(this->strenght - 2);
	SetDamageMax(this->strenght * 2);
	SetDefence((this->agility * 2) / (this->luck - 3));

}

Player::~Player()
{

}

void Player::PrintPlayerStats()
{
	PrintStats();
	std::cout << "_____________________________: " << std::endl;
	std::cout << "Strenght: " << this->strenght << std::endl;
	std::cout << "Agility: " << this->agility << std::endl;
	std::cout << "Intelligence: " << this->intelligence << std::endl;
	std::cout << "luck: " << this->luck << std::endl;
	std::cout << "Dexterity: " << this->dexterity << std::endl;
}

void Player::LevelUp()
{
}

void Player::AddStats(int stat, int value)
{
}

void Player::UpdateValues()
{
	SetHp((this->intelligence * 2) / (this->dexterity - 2));
	SetDamageMin(this->strenght - 2);
	SetDamageMax(this->strenght * 2);
	SetDefence((this->agility * 2) / (this->luck - 2));
}

void Player::LoadStats(const std::string& filename)
{
	std::ifstream inFile(filename);
	if (!inFile.is_open())
	{
		std::cerr << "ERROR: Cant open file" << filename
			<< std::endl;
		return;
	}
	std::string name = "";
	int l;
	int hp;
	int xp;
	int dmin;
	int dmax;
	int d;
	//std::getline(inFile, name);
	inFile >> name
		>> l
		>> xp
		>> MaxXp
		>> skillsPoints
		>> hp
		>> dmin
		>> dmax
		>> d
		>> strenght
		>> agility
		>> intelligence
		>> luck
		>> dexterity;
	inFile.close();

	SetName(name);
	SetLevel(l);
	SetHp(hp);
	SetExp(xp);
	SetDamageMin(dmin);
	SetDamageMax(dmax);
	SetDefence(d);

}

std::string Player::SaveStats()
{
	return this->GetName() + "" +
		std::to_string(this->GetLevel()) + " " +
		std::to_string(this->GetExp()) + " " +
		std::to_string(this->GetHP()) + " " +
		std::to_string(this->GetDamageMin()) + " " +
		std::to_string(this->GetDamageMax()) + " " +
		std::to_string(this->GetDefence()) + " " +
		std::to_string(this->strenght) + " " +
		std::to_string(this->agility) + " " +
		std::to_string(this->intelligence) + " " +
		std::to_string(this->luck) + " " +
		std::to_string(this->dexterity);
}

int Player::GetLuck()
{
	return this->luck;
}

void Player::SetLuck(int x)
{
	luck = x;
}

int Player::GetStrenght()
{
	return 0;
}

void Player::SetStrenght(int s)
{
}

int Player::GetAgility()
{
	return 0;
}

void Player::SetAgility(int a)
{
}

int Player::GetIntelligence()
{
	return 0;
}

void Player::SetIntelligence(int w)
{
}

int Player::GetDexterity()
{
	return 0;
}

void Player::SetDexterity(int r)
{
}
