#ifndef __SELECT_LAYER_H__
#define __SELECT_LAYER_H__

#include "cocos2d.h"
#include "LoadingScene.h"
//#include "StartMenuScene.h"

const int MAXITEMS = 5;

using namespace cocos2d;
class SelectItems :public Layer
{
public:
	SelectItems();
	~SelectItems();
	bool init();
	void menuCloseCallback(cocos2d::Ref* pSender);
	bool onTouchBegan(Touch* touch, Event* event);
	void update(float delta);


	CREATE_FUNC(SelectItems);
private:
	MenuItemImage* createItem(std::string, std::string, std::string);
	Animate* action2;
	Sprite* bird;
};

#endif