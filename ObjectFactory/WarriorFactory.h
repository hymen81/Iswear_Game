#ifndef __WARRIOR_FACTORY_H__
#define __WARRIOR_FACTORY_H__

#include "FactoryInterface.h"
#include "../Object/Warrior.h"

class WarriorFactory : public FactoryInterface
{
public:
	BaseObject* ctrateObject() override;
};

#endif

