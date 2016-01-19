#ifndef __WARRIOR_H__
#define __WARRIOR_H__

#include "Object.h"
#include "Weapon.h"

class Warrior : public BaseObject
{
public:
	Warrior();
	~Warrior();
	//bool init();
	static Warrior* create(std::string);
	void update(float delta);
	void jump();
	void walk(int direction);
	void attack();
	inline void isLeftRightVaild(float &x);
	inline void isUpDownVaild(float &y);
	void setWorldPosition(Vec2);
	Vec2 getWorldPosition();
	bool isInViewPort(Vec2);
	bool isOutPort();
	void attackDetection();

private:
	float v;
	float walkV;
	int jumpCount;
	float PosX;
	float PosY;
	bool isOut;
	
	Animate* animate;
};

#endif