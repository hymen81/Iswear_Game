#ifndef __S1_SCENE_H__
#define __S1_SCENE_H__

#include "cocos2d.h"
#include "MapLayer.h"
#include "BulletLayer.h"
#include "Object/Warrior.h"
#include "Object/Weapon.h"
#include "Object/SkullWeapon.h"
#include "Object/Skull.h"
#include "Object/Input.h"

#include "ObjectFactory\FactoryInterface.h"
#include "ObjectFactory\WarriorFactory.h"
#include "ObjectFactory\EnemyFactory.h"
#include "ObjectFactory\UIFactory.h"

#include "SystemConfig.h"

#include "EffectSprite\LightEffect.h"

using namespace cocos2d;
class Stage1 : public Scene
{
public:
	Stage1();
	~Stage1();
	void loadingsStep(float dt);
	bool init();
	void update(float);
	bool onTouchBegan(Touch*, Event*);
	void onTouchEnded(Touch*, Event*);
	void onTouchMoved(Touch*, Event*);
	CREATE_FUNC(Stage1);
public:
	MainFly *main;
	Warrior *warrior;
	Vec2 mainPos;
	MapLayer *map;
	Layer *bulletLayer;
	Sprite* map1;
	Sprite* trees;

	bool isTouchEnd;
	
};

#endif