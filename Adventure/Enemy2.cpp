#include "Enemy2.h"

Enemy2::Enemy2(int level)
{
    InitCharacter("Pato");
    SetLevel(level);
    SetHp(level * 6);
    SetDamageMin(level);
    SetDamageMax(level + 4);
    SetDefence(level);
    SetExp(level * 10);
}

Enemy2::~Enemy2()
{
}
