#ifndef __BULLET_H__
#define __BULLET_H__

#include "cocos2d.h"

using namespace cocos2d;
class Bullet : public Sprite
{
public:
	Bullet();
	~Bullet();
	static Bullet* myCreate();
	void normalFire(Vec2);
	void normalEnemyFire(Vec2, Vec2);
protected:
	int power;
	int speed;

};

#endif
