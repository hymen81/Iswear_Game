#include "Door.h"


Door::Door()
{
}


Door::~Door()
{
}

Door* Door::create(std::string fileName)
{
	Door *sprite = new (std::nothrow) Door();
	if (sprite && sprite->initWithFile(fileName) && sprite->init())
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}


void Door::open()
{
	Vector<SpriteFrame*> animFrames(4);
	for (int i = 0; i < 4; i++)
	{
		auto frame = SpriteFrame::create("iron_door_animation.png", Rect(32 * i, 0, 32, 64));
		animFrames.pushBack(frame);
	}
	auto animation = Animation::createWithSpriteFrames(animFrames, WARRIOR_SPEED);
	auto animate = Animate::create(animation);
	this->runAction(animate);
}

void Door::close()
{
	int x = this->getPositionX() - this->getContentSize().width / 2;
	int y = this->getPositionY() - this->getContentSize().height / 2;

	titleMap[(int)(y / 32) + 1][(int)(x / 32)] = 256;
	titleMap[(int)(y / 32)][(int)(x / 32)] = 256;
	Vector<SpriteFrame*> animFrames(4);
	for (int i = 4; i >= 0; i--)
	{
		auto frame = SpriteFrame::create("iron_door_animation.png", Rect(32 * i, 0, 32, 64));
		animFrames.pushBack(frame);
	}
	auto animation = Animation::createWithSpriteFrames(animFrames, WARRIOR_SPEED);
	auto animate = Animate::create(animation);
	this->runAction(animate);
}