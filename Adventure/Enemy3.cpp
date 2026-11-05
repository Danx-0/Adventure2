#include "Enemy3.h"

Enemy3::Enemy3(int level)
{
    InitCharacter("Golem");
    SetLevel(level);
    SetHp(level * 12);
    SetDamageMin(level);
    SetDamageMax(level + 3);
    SetDefence(level * 2);
    SetExp(level * 20);
}

Enemy3::~Enemy3()
{
}
