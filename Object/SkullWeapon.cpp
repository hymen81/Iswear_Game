#include "SkullWeapon.h"


SkullWeapon::SkullWeapon()
{
	xV = 10;
	yV = 10;
	this->scheduleUpdate();
	this->setTexture("skullWeapon.png");
}


SkullWeapon::~SkullWeapon()
{
}

SkullWeapon* SkullWeapon::create(std::string fileName)
{
	SkullWeapon *sprite = new (std::nothrow) SkullWeapon();
	if (sprite && sprite->initWithFile(fileName) && sprite->init())
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void SkullWeapon::update(float d)
{
	Vec2 pos = this->getPosition();
	pos.x += this->xV;
	pos.y += this->yV;
	yV -= 0.5f;
	attackDetection();
	this->setPosition(pos);
	if (pos.y < -100)
	{
		this->getParent()->removeChild(this);
	//	delete(this);
	}
}

void SkullWeapon::attackDetection()
{
	BaseObject *warrior = (BaseObject *)this->getParent()->getChildByName("Warrior");
	if (this->getBoundingBox().containsPoint(warrior->getPosition()))
	{
		//warrior->setHealth(warrior->getHealth() - 1);
		warrior->setFeelHurt(true);
	}

	if (this->numberOfRunningActions() == 0)
	{
		auto action = RotateBy::create(0.5f, 360);
		action->setTag(1);
		//this->stopAllActions();
		this->runAction(action);
	}
}

void SkullWeapon::attack()
{
	
}
