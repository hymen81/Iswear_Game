#ifndef __SKULL_H__
#define __SKULL_H__

#include "Enemy.h"
#include "SkullWeapon.h"



class Skull : public Enemy
{
public:
	Skull();
	~Skull();
	static Skull* myCreate(std::string);
	void update(float delta);
	void die();
	void attack(int direction);
private:
	bool isDead;
	int count;
};

#endif