#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "../SystemConfig.h"
#include "../MyHelper.h"
#include "Object.h"

class Weapon : public BaseObject
{
public:
	Weapon();
	~Weapon();
	static Weapon* create(std::string fileName);
	void attack();
};

#endif