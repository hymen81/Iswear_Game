#include "Skull.h"


Skull::Skull() : count(0)
{
	this->scheduleUpdate();
	this->setHealth(SKULL_HEATH);
	this->isDead = false;
}


Skull::~Skull()
{
}

Skull* Skull::myCreate(std::string fileName)
{
	Skull *sprite = new (std::nothrow) Skull();
	if (sprite && sprite->initWithFile(fileName))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void Skull::update(float delta)
{
	float x = this->getBoundingBox().getMidX();
	float y = this->getBoundingBox().getMidY();

	int titleX = x / BLOCK_SIZE;
	int titleY = y / BLOCK_SIZE;
	//if (titleMap[titleY][titleX] == 0)
		titleMap[titleY][titleX] = 0;

	this->setColor(Color3B(255, 255, 255));

	if (feelHurt && !isDead)
	{
		if (direction)
			walkV = -HURTING_SPEED;
		else
			walkV = HURTING_SPEED;
		this->setFeelHurt(false);
		this->setHealth(this->getHealth() - 1);
		this->setColor(Color3B(255, 0, 0));
		PLAY_SE("SE/se_maoudamashii_battle17.mp3");
	}

	bool isLRVaild = isLeftRightVaild(x, y);
	bool isUDVaild = isUpDownVaild(x, y);
	
	//change pos
	BaseObject *obj = (BaseObject *)this->getParent()->getChildByName("Warrior");
	float diffX = x - obj->getPositionX();
	if (abs(diffX) < 600 && !isDead)
	{
		if (!isLRVaild)
			jump();
		if (diffX > 0)
		{
			attack(goBack);
			if (abs(diffX) > 40 )
				walk(goBack);
		}
		else
		{
			attack(goForward);
			if (abs(diffX) > 40 )
				walk(goForward);
		}
	}
	//change pos

	titleX = x / BLOCK_SIZE;
	titleY = y / BLOCK_SIZE;
	titleMap[titleY][titleX] = 100;
	this->setPosition(Vec2(x, y));
}

void Skull::die()
{
	if (!isDead){
		PLAY_SE("SE/se_maoudamashii_se_fall02.mp3");
		if (!this->getParent()->getParent()->getActionByTag(20))
			this->getParent()->getParent()->runAction(MyShake::create(0.5f, 30));
		isDead = true;
		Vector<SpriteFrame*> animFrames(3);
		for (int i = 3; i < 6; i++)
		{
			auto frame = SpriteFrame::create("skull.png", Rect(64 * i, 0, 64, 64)); //we assume that the sprites' dimentions are 40*40 rectangles.
			animFrames.pushBack(frame);
		}
		auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
		animate = Animate::create(animation);
		this->stopAllActions();
		this->runAction(animate);
		//this->unscheduleUpdate();
	}
}

void Skull::attack(int direction)
{
	//SkullWeapon *weapon = ((SkullWeapon*)this->weapon);
	//if (weapon->numberOfRunningActions() == 0)
	if (count++%100 == 0)
	{
		auto weapon = SkullWeapon::create("skullWeapon.png");
		this->getParent()->addChild(weapon, 5);
		this->setWeapon(weapon);

		(direction) ?
			weapon->xV = 5 : weapon->xV = -5;
		weapon->yV = 10;
		weapon->setPosition(this->getPosition());

		weapon->attack();
	}

}