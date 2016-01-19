#ifndef __MAINFLY_H__
#define __MAINFLY_H__

#include "cocos2d.h"
#include "Bullet.h"
#include "Object.h"

using namespace cocos2d;
class MainFly : public BaseObject
{
public:
	MainFly();
	~MainFly();
	static MainFly* myCreate(std::string);
	//////action////////
	void onFire(Layer*);
	//////action////////
	


};

#endif