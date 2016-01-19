#include "Enemy.h"



Enemy::Enemy()
{
	v = 5;
	walkV = 5;
	jumpCount = 0;
	walkSpeed = 1;
	feelHurt = false;
	/*for (int y = 100 - 1; y >= 50; --y){
		int temp[1000];
		memcpy(temp, titleMap[y], sizeof(int) * 1000);
		memcpy(titleMap[y], titleMap[MAX_Y - y], sizeof(int) * 1000);
		memcpy(titleMap[MAX_Y - y], temp, sizeof(int) * 1000);
	}*/
}


Enemy::~Enemy()
{
}

Enemy* Enemy::myCreate(std::string fileName)
{
	Enemy *sprite = new (std::nothrow) Enemy();
	if (sprite && sprite->initWithFile(fileName))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void Enemy::enemyWeakUp(Layer* map)
{
	/////////////////
	this->setName("em");
	this->setPosition(Vec2(0, 0));

	auto array = PointArray::create(20);

	array->addControlPoint(Vec2(0, 0));
	array->addControlPoint(Vec2(400, 400));
	/*array->addControlPoint(Vec2(300, 300));
	array->addControlPoint(Vec2(0, 1010));*/

	auto action = CatmullRomBy::create(3, array);
	auto reverse = action->reverse();

	auto seq = Sequence::create(action, nullptr);

	//this->runAction(seq);

	auto drawNode1 = DrawNode::create();
	drawNode1->setPosition(Vec2(50, 50));
	drawNode1->drawCatmullRom(array, 50, Color4F(1.0, 0.0, 1.0, 1.0));

	//map->addChild(drawNode1);
	this->runAction(seq);
	


	map->addChild(this, 10);

	this->scheduleUpdate();
}

void Enemy::enemyWeakUp2(Layer* map)
{
	/////////////////
	this->setName("em");

	auto array = PointArray::create(20);

	array->addControlPoint(Vec2(400, 400));
	array->addControlPoint(Vec2(400, 0));
	array->addControlPoint(Vec2(0, 400));
	array->addControlPoint(Vec2(-100, 1010));

	auto action = CatmullRomBy::create(3, array);
	auto reverse = action->reverse();

	auto seq = Sequence::create(action, nullptr);

	this->runAction(seq);

	auto drawNode1 = DrawNode::create();
	drawNode1->setPosition(Vec2(50, 50));
	drawNode1->drawCatmullRom(array, 50, Color4F(1.0, 0.0, 1.0, 1.0));

	//map->addChild(drawNode1);

	map->addChild(this, 10);
	this->scheduleUpdate();
}

void Enemy::enemyWeakUp3(Layer* map)
{
	/////////////////
	this->setName("em");

	auto array = PointArray::create(20);

	array->addControlPoint(Vec2(-1000, 1000));
	array->addControlPoint(Vec2(200, 600));
	array->addControlPoint(Vec2(400, 800));
	array->addControlPoint(Vec2(1010, 1010));

	auto action = CatmullRomBy::create(3, array);
	auto reverse = action->reverse();

	auto seq = Sequence::create(action, nullptr);

	this->runAction(seq);

	auto drawNode1 = DrawNode::create();
	drawNode1->setPosition(Vec2(50, 50));
	drawNode1->drawCatmullRom(array, 50, Color4F(1.0, 0.0, 1.0, 1.0));

	//map->addChild(drawNode1);

	map->addChild(this, 10);
}

void Enemy::onFire(Layer* map)
{

}

void Enemy::onFire(Layer* map,MainFly* main)
{
	//map->addChild();
	_map = map;
	_main = main;
}

void Enemy::update(float delta)
{
	static int time = 0;
	if (time++ % 10 == 0)
	{
		//auto bullet = Bullet::myCreate();
//		bullet->normalEnemyFire(this->getPosition(), _main->getPosition());
		//_map->addChild(bullet, 1);

		auto animation = Animation::create();
		for (int i = 1; i <= 4; i++)
		{
			char szName[100] = { 0 };
			sprintf(szName, "em%d.png", i);
			animation->addSpriteFrameWithFile(szName);
		}
		// should last 2.8 seconds. And there are 14 frames.
		animation->setDelayPerUnit(0.3f / 3.0f);
		//animation->setRestoreOriginalFrame(true);

		auto action2 = Animate::create(animation);
		this->runAction(Sequence::create(action2, action2->reverse(), NULL));
	}
	//bullets.push_back
}

bool Enemy::isLeftRightVaild(float &x,float y)
{
	bool vaild = true;
//	log("%f,%f,%f", x, this->getBoundingBox().getMaxX(), this->getBoundingBox().getMinX());
	int titleXR = (x) / BLOCK_SIZE;
	int titleXL = (x + 16) / BLOCK_SIZE;
	int titleY = y / BLOCK_SIZE;

	if (COULD_NOT_BLOCK(titleY, titleXR + 1)){
		if (walkV > 0)
		{
			walkV = 0;
		}
		vaild = false;
	}
	else if (COULD_NOT_BLOCK(titleY, titleXL - 1))
	{
		if (walkV < 0)
		{
			walkV = 0;
		}
		vaild = false;
	}
	if (walkV != 0)
	{
		x += walkV > 0 ? walkV-- : walkV++;
		vaild = true;
	}
	return vaild;
}

bool Enemy::isUpDownVaild(float x,float &y)
{
	bool vaild = true;
	y -= ((v++)*0.2f);
	int titleX = x / BLOCK_SIZE;
	int titleY = (y - 12) / BLOCK_SIZE;
	//log("%d %d V: %d", titleX, titleY, titleMap[titleY][titleX]);
	//人物行為
	if (COULD_NOT_BLOCK(titleY, titleX))
	{
		vaild = false;
		if (v > 0)
		{
			y = (titleY + 1) * BLOCK_SIZE + 12;
			v = 0;
			jumpCount = 0;
		}
		else
		{
			v = -v;
			jumpCount = MAX_JUMP_COUNT + 1;
		}
	}
	return vaild;
}

void Enemy::jump()
{
	if (jumpCount < MAX_JUMP_COUNT)
	{
		auto hasRotateAction = this->getActionByTag(1);
		if (hasRotateAction == nullptr){
			auto action = RotateBy::create(0.4f, 360);
			action->setTag(1);
			this->runAction(action);
		}
		jumpCount++;
		v = -30;
	}
	log("jump: %d", jumpCount);
}

void Enemy::walk(int direction)
{
	this->direction = direction;
	direction ? walkV = walkSpeed : walkV = -walkSpeed;
	walkV == -walkSpeed ? this->setScaleX(-1) : this->setScaleX(1);
	if (this->numberOfRunningActions() == 0 && v == 0){
		Vector<SpriteFrame*> animFrames(4);
		for (int i = 0; i < 4; i++)
		{
			auto frame = SpriteFrame::create("skull.png", Rect(64 * i, 0, 64, 64)); //we assume that the sprites' dimentions are 40*40 rectangles.
			animFrames.pushBack(frame);
		}
		auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
		animate = Animate::create(animation);
		this->runAction(animate);
	}
}

void Enemy::die(){}
void Enemy::attack(){}