#ifndef __SKULL_WEAPON_H__
#define __SKULL_WEAPON_H__


#include "Weapon.h"

class SkullWeapon : public Weapon
{
public:
	SkullWeapon();
	~SkullWeapon();
	static SkullWeapon* create(std::string fileName);
	void attackDetection();
	void attack();
	void update(float);
	float yV;
	float xV;
};

#endif