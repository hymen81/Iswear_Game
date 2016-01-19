#include "Weapon.h"


Weapon::Weapon()
{
}


Weapon::~Weapon()
{
}

Weapon* Weapon::create(std::string fileName)
{
	Weapon *sprite = new (std::nothrow) Weapon();
	if (sprite && sprite->initWithFile(fileName) && sprite->init())
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void Weapon::attack()
{
	Vector<SpriteFrame*> animFrames(4);
	for (int i = 0; i < 4; i++)
	{
		auto frame = SpriteFrame::create("weapon.png", Rect(128 * i, 0, 128, 128));
		animFrames.pushBack(frame);
	}
	auto animation = Animation::createWithSpriteFrames(animFrames, WARRIOR_SPEED);
	auto animate = Animate::create(animation);
	this->runAction(animate);
}
