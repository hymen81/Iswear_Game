#ifndef __MAPLAYER_H__
#define __MAPLAYER_H__

#include "cocos2d.h"
#include "Object/MainFly.h"
#include "Object/Enemy.h"
#include "Object/Door.h"
#include "SystemConfig.h"
#include "EffectSprite\LightEffect.h"

using namespace cocos2d;
class MapLayer : public Layer
{
public:
	MapLayer();
	~MapLayer();
	bool init();
	void update(float);
	void initTileMap();
	void setEffect(LightEffect *effect, const std::string &normalMapFilename);
	void setLightPos(Vec3);
	CREATE_FUNC(MapLayer);
private:
	Sprite *map1, *map2;
	Vec2 map1Pos, map2Pos;
	
	int mapHeight;
	MainFly *a;
	//for test
	Sprite *bullet;
	std::vector<Sprite *> bullets;


	cocos2d::Texture2D *_normalmap = nullptr;
	//LightEffect* _effect;
	
};

#endif