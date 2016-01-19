#include "WarriorFactory.h"

BaseObject* WarriorFactory::ctrateObject()
{
	return Warrior::create("sprite_1.png");
}