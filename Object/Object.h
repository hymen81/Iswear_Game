#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "cocos2d.h"
#include "../SystemConfig.h"
#include "../MyHelper.h"
#include "../EffectSprite\EffectSprite.h"

using namespace cocos2d;

//
//基本的物件  定義武器,敵人,主角....的基本行為
//
class BaseObject :public Sprite
{
public:
	virtual bool init();
	static BaseObject* create(std::string);
	static BaseObject* create(const std::string& filename, const Rect& rect);
	void setHealth(int value){ health = value; }
	int  getHealth(){ return health; }
	void setshootSpeed(int value){ shootSpeed = value; }
	int  getshootSpeed(){ return shootSpeed; }
	bool EACH_BLOCK(int y, int x);
	void setFeelHurt(bool);
	virtual void die();
	virtual void setWeapon(BaseObject*);
protected:
	int health;
	int lives;
	int power;
	int shootSpeed;
	bool feelHurt;
	BaseObject *weapon;
	int direction;
};

#endif

