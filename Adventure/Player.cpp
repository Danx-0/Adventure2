#include "Player.h"

Player::Player()
{
	this->strenght = 5;
	this->agility = 5;
	this->intelligence = 5;
	this->luck = 5;
	this->dexterity = 5;
	
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
