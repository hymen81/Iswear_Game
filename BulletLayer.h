#ifndef __BULLET_LAYER_H__
#define __BULLET_LAYER_H__

#include "cocos2d.h"
#include "Object/MainFly.h"
#include "Object/Enemy.h"
#include "MyHelper.h"

using namespace cocos2d;

class BulletLayer : public Layer
{
public:
	BulletLayer();
	~BulletLayer();
	void update(float);
};

#endif