#ifndef __LOADING_SCENE_H__
#define __LOADING_SCENE_H__

#include "cocos2d.h"
#include "Stage1.h"

extern float oriX;
extern float oriY;

using namespace cocos2d;
class LoadingScene : public Scene
{
public:
	LoadingScene();
	~LoadingScene();
	void loadingsStep(float dt);
	bool init();
	CREATE_FUNC(LoadingScene);
private:
	Stage1 *stage1;
};

#endif