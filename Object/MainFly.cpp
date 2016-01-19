#include "MainFly.h"


MainFly::MainFly()
{
	shootSpeed = 4;
}


MainFly::~MainFly()
{
}

MainFly* MainFly::myCreate(std::string fileName)
{
	MainFly *sprite = new (std::nothrow) MainFly();
	if (sprite && sprite->initWithFile(fileName))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void MainFly::onFire(Layer* layer)
{
	//map->addChild();
	auto bullet = Bullet::myCreate();
	bullet->normalFire(this->getPosition());
	//bullets.push_back
	layer->addChild(bullet, 1);
}


