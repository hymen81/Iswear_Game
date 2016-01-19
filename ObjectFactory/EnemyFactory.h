#ifndef __ENEMY_FACTORY_H__
#define __ENEMY_FACTORY_H__

#include "FactoryInterface.h"
#include "../Object/Skull.h"

class EnemyFactory : public FactoryInterface
{
public:
	BaseObject* ctrateObject() override;
};

#endif

