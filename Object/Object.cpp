#include "Object.h"


BaseObject* BaseObject::create(std::string fileName)
{
	BaseObject *sprite = new (std::nothrow) BaseObject();
	if (sprite && sprite->initWithFile(fileName) && sprite->init())
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

BaseObject* BaseObject::create(const std::string& filename, const Rect& rect)
{
	BaseObject *sprite = new (std::nothrow) BaseObject();
	if (sprite && sprite->initWithFile(filename, rect))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

bool BaseObject::init()
{
	//¨¾§b
	log("BaseObject Init! Maybe you must be override the init() in your class!");
	return true;
}

bool BaseObject::EACH_BLOCK(int y, int x){
	for (int i = 0; i < CAN_MOVE_BLOCK_SIZE; i++)
		if (titleMap[y][x] != canMoveBlock[i])
			return true;
	return false;
}

void BaseObject::setFeelHurt(bool isFeelHurt)
{
	this->feelHurt = isFeelHurt;
}

void BaseObject::die(){}

void BaseObject::setWeapon(BaseObject* weapon)
{
	this->weapon = weapon;
}