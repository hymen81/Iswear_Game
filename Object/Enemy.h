#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "cocos2d.h"
#include "MainFly.h"

using namespace cocos2d;
class Enemy : public BaseObject
{
public:
	Enemy();
	~Enemy();
	static Enemy* myCreate(std::string);
	void enemyWeakUp(Layer*);
	void enemyWeakUp2(Layer*);
	void enemyWeakUp3(Layer*);
	void onFire(Layer*,MainFly*);
	void onFire(Layer*);
	virtual void jump();
	virtual void walk(int direction);
	virtual void die();
	virtual void attack();
	virtual void update(float delta);
	 bool isLeftRightVaild(float &x,float y);
	 bool isUpDownVaild(float x, float &y);
private:
	Layer* _map;
	MainFly* _main;
protected:
	float v;
	float walkV;
	int jumpCount;
	float PosX;
	float PosY;
	float walkSpeed;
	Animate* animate;
};

#endif