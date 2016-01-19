#ifndef __FACTORY_INTERFACE_H__
#define __FACTORY_INTERFACE_H__

#include "cocos2d.h"
#include "../Object/Object.h"

using namespace cocos2d;

//
//��H���u�t Abstract factory pattern
//
class FactoryInterface
{
public:
	virtual BaseObject* ctrateObject() = 0;	
};

#endif

