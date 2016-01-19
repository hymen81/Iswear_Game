#include "EnemyFactory.h"

BaseObject* EnemyFactory::ctrateObject()
{
	return Skull::myCreate("skull1.png");
}