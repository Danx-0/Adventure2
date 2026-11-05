#include "Player.h"
#include "Game.h"

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
	SetHp((this->intelligence*2) / (this->dexterity-3));
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
	std::cout << "Exp required to level up: " << this->MaxXp << std::endl;
}

void Player::LevelUp()
{
	while (GetExp() >= MaxXp)
	{
		SetExp(GetExp() - MaxXp);
		SetLevel(GetLevel() + 1);
		MaxXp = GetLevel() * 10;
		skillPoints++;
	}
}



void Player::AddStats(int stat, int value)
{
	if (skillPoints < value)
	{
		std::cout << "Not Enough Points" << std::endl;
	}
	else
	{
		switch (stat)
		{
		case 1:
			this->strenght += value;
			skillPoints -= value;
			UpdateValues();
			break;
		case 2:
			this->agility += value;
			skillPoints -= value;
			UpdateValues();
			break;
		case 3:
			this->dexterity += value;
			skillPoints -= value;
			UpdateValues();
			break;
		case 4:
			this->intelligence += value;
			skillPoints -= value;
			UpdateValues();
			break;
		case 5:
			this->luck += value;
			skillPoints -= value;
			UpdateValues();
			break;
		default:
			std::cout << "This stat does not exist" << std::endl;
			break;
		}
	}
}

void Player::UpdateValues()
{
	SetHp((this->intelligence * 2) / (this->dexterity - 3));
	SetDamageMin(this->strenght - 2);
	SetDamageMax(this->strenght * 2);
	SetDefence((this->agility * 2) / (this->luck - 3));
}

void Player::LoadStats(const std::string& filename)
{
	std::ifstream inFile(filename);
	if (!inFile.is_open())
	{
		std::cerr << "ERROR: Cant open file" << filename << std::endl;
		return;
	}
	std::string name = "";
	int l;
	int hp;
	int xp;
	int dmin;
	int dmax;
	int d;
	int sp;
	//std::getline(inFile, name);
	inFile 
		>> name
		>> l
		>> xp
		>> MaxXp
		>> skillPoints
		>> hp
		>> dmin
		>> dmax
		>> d
		>> strenght
		>> agility
		>> intelligence
		>> luck
		>> dexterity
	    >> sp;
	inFile.close();

	SetName(name);
	SetLevel(l);
	SetHp(hp);
	SetExp(xp);
	SetDamageMin(dmin);
	SetDamageMax(dmax);
	SetDefence(d);
	SetSkillPoints(sp);

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
		std::to_string(this->GetStrenght()) + " " +
		std::to_string(this->GetAgility()) + " " +
		std::to_string(this->GetIntelligence()) + " " +
		std::to_string(this->GetLuck()) + " " +
		std::to_string(this->GetDexterity()) + " " +
	    std::to_string(this->GetSkillPoints());
}

//int Player::GetLuck()
//{
//	return this->luck;
//}
//
//void Player::SetLuck(int x)
//{
//	luck = x;
//}
//
//int Player::GetStrenght()
//{
//	return 0;
//}
//
//void Player::SetStrenght(int s)
//{
//}
//
//int Player::GetAgility()
//{
//	return 0;
//}
//
//void Player::SetAgility(int a)
//{
//}
//
//int Player::GetIntelligence()
//{
//	return 0;
//}
//
//void Player::SetIntelligence(int w)
//{
//}
//
//int Player::GetDexterity()
//{
//	return 0;
//}
//
//void Player::SetDexterity(int r)
//{
//}
