#ifndef __START_SCENE_H__
#define __START_SCENE_H__

#include "cocos2d.h"
#include "SelectItems.h"

using namespace cocos2d;
class StartMenuScene : public Scene
{
public:
	StartMenuScene();
	~StartMenuScene();
	bool init();

	CREATE_FUNC(StartMenuScene);
};

#endif
