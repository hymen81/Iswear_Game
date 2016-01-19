#include "Bullet.h"


Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}

Bullet* Bullet::myCreate()
{
	Bullet *sprite = new (std::nothrow) Bullet();
	if (sprite && sprite->initWithFile("bullet.png"))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void Bullet::normalFire(Vec2 pos)
{
	//bullet = Sprite::create("bullet.png");
	this->setName("bullet");
	this->setPosition(pos);
	this->runAction(MoveTo::create(2, Vec2(pos.x, pos.y + 1000)));
}

void Bullet::normalEnemyFire(Vec2 pos,Vec2 mainPos)
{
	//bullet = Sprite::create("bullet.png");
	this->setName("bullet");
	this->setPosition(pos);
	this->runAction(MoveTo::create(2, Vec2(mainPos.x, mainPos.y-1000)));
}