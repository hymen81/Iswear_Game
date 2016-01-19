#include "StartMenuScene.h"


StartMenuScene::StartMenuScene()
{
	
}

StartMenuScene::~StartMenuScene()
{
}

bool StartMenuScene::init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto items = SelectItems::create();
	this->addChild(items);
	return true;
}