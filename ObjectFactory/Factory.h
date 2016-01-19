#ifndef __FACTORY_H__
#define __FACTORY_H__

#include "cocos2d.h"

using namespace cocos2d;

class Factory
{
public:
	Factory();
	~Factory();
	static Factory* getInstance();
	//Bullet* 
private:
	static Factory *factory;

};

#endif