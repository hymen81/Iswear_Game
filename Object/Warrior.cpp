#include "Warrior.h"


Warrior::Warrior() : jumpCount(0)
{
	v = 5;
	walkV = WARRIOR_MOVE_SPEED;
	isOut = false;
	setFeelHurt(false);
	for (int y = 100 - 1; y >= 50; --y){
		int temp[1000];
		memcpy(temp, titleMap[y], sizeof(int) * 1000);
		memcpy(titleMap[y], titleMap[MAX_Y - y], sizeof(int) * 1000);
		memcpy(titleMap[MAX_Y - y], temp, sizeof(int) * 1000);
	}
}

Warrior::~Warrior()
{
}

Warrior* Warrior::create(std::string fileName)
{
	Warrior *sprite = new (std::nothrow) Warrior();
	if (sprite && sprite->initWithFile(fileName) && sprite->init())
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

/*bool Warrior::init()
{
	
	return true;
}*/

bool Warrior::isInViewPort(Vec2 v)
{
	float viewY = v.y;
	float viewX = v.x;
	if (viewX > MINVIEW_X && viewX < MAXVIEW_X)
	{
		return true;
	}
	else
		return false;
}

inline void Warrior::isLeftRightVaild(float &resX)
{
	/*float y = this->getPosition().y;
	float x = this->getPosition().x;*/

	float viewY = this->getPosition().y;
	float viewX = this->getPosition().x;

	float x = this->getBoundingBox().getMidX();
	float y = this->getBoundingBox().getMidY();
	//log("%f,%f,%f", x, this->getBoundingBox().getMaxX(), this->getBoundingBox().getMinX());
	int titleXR = (x) / BLOCK_SIZE;
	int titleXL = (x+16) / BLOCK_SIZE;
	int titleY = y / BLOCK_SIZE;

	if (COULD_NOT_BLOCK(titleY, titleXR + 1) && titleMap[titleY][titleXR+1] != 99){
		if (walkV > 0)
		{
			//x = (titleX - 1) * BLOCK_SIZE;
			walkV = 0;
		}
	}
	else if (COULD_NOT_BLOCK(titleY, titleXL - 1) && titleMap[titleY][titleXL-1] != 99)
		if (walkV < 0)
		{
			//x = (titleX - 1) * BLOCK_SIZE;
			walkV = 0;
		}
	if (walkV != 0)
	{
		resX += walkV > 0 ? walkV-- : walkV++;
		/*static float preViewX = 0;
		if (isInViewPort(Vec2(viewX, viewY)))
		{
			viewX += walkV > 0 ? walkV-- : walkV++;
			isOut =false;
			if (viewX >= MAXVIEW_X)
			{
				isOut = true;
				viewX = preViewX;
			}
			else if (viewX <= MINVIEW_X)
			{
				isOut = true;
				viewX = preViewX;
			}
			preViewX = viewX;
			log("in port");
		}
		else
		{
			//isOut = true;
		}*/
		//this->setPosition(Vec2(viewX, viewY));
	}
}

bool Warrior::isOutPort()
{
	return isOut;
}

inline void Warrior::isUpDownVaild(float &y)
{
	float x = this->getBoundingBox().getMidX();
	//float y = this->getBoundingBox().getMidY();
	y -= ((v++)*0.2f);
	int titleX = x / BLOCK_SIZE;
	int titleY = (y - 12) / BLOCK_SIZE;
	//log("%d %d V: %d", titleX, titleY, titleMap[titleY][titleX]);
	//人物行為
	if (COULD_NOT_BLOCK(titleY, titleX) && titleMap[titleY][titleX] != 99)
	{
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
}

void Warrior::update(float delta)
{
	float x = this->getBoundingBox().getMidX();
	float y = this->getBoundingBox().getMidY();

	if (feelHurt)
	{
		if (this->direction)
			walkV = -HURTING_SPEED;
		else
			walkV = HURTING_SPEED;
		this->setFeelHurt(false);
		this->setHealth(this->getHealth() - 1);
		this->setColor(Color3B(255, 0, 0));
		////shake screen
		if (!this->getParent()->getParent()->getActionByTag(20))
			this->getParent()->getParent()->runAction(MyShake::create(0.5f, 30));
	}
	else
	{
		this->setColor(Color3B(255, 255, 255));
	}

	isLeftRightVaild(x);
	isUpDownVaild(y);

	this->setPosition(Vec2(x,y));
	if (weapon)
		if (direction)
		{
			weapon->setPosition(Vec2(x + 68, y + 32));
			weapon->setScaleX(1);
		}
		else
		{
			weapon->setPosition(Vec2(x-68 , y+32 ));
			weapon->setScaleX(-1);
		}
	
//	setWorldPosition(Vec2(x, y));

}

void Warrior::setWorldPosition(Vec2 v)
{
	this->PosX = v.x;
	this->PosY = v.y;
}

Vec2 Warrior::getWorldPosition()
{
	return Vec2(PosX, PosY);
}

void Warrior::jump()
{
	if (jumpCount < MAX_JUMP_COUNT)
	{
		auto hasRotateAction = this->getActionByTag(1);
		if (hasRotateAction == nullptr){
			this->setTexture("warrior_rotate.png");
			auto action = RotateBy::create(0.4f, 360);
			action->setTag(1);
			this->stopAllActions();
			this->runAction(action);
		}
		jumpCount++;
		v = -WARRIOR_JUMP_POWER;
	}
	log("jump: %d",jumpCount);
}



void Warrior::walk(int direction)
{
	this->direction = direction;
	direction ? walkV = WARRIOR_MOVE_SPEED : walkV = -WARRIOR_MOVE_SPEED;
	walkV == -WARRIOR_MOVE_SPEED ? this->setScaleX(-1) : this->setScaleX(1);
	if (this->getActionByTag(1) == nullptr && this->getActionByTag(2) == nullptr&& v == 0){
		Vector<SpriteFrame*> animFrames(4);
		for (int i = 0; i < 4; i++)
		{
			auto frame = SpriteFrame::create("warrior.png", Rect(64 * i, 0, 64, 64));
			animFrames.pushBack(frame);
		}
		auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
		animate = Animate::create(animation);
		animate->setTag(2);
		this->stopAllActions();
		this->runAction(animate);
	}
}

void Warrior::attackDetection()
{
	auto map = this->getParent();
	Vector<Node*> garbege;
	for (int i = 0; i < map->getChildren().size(); i++)
	{
		auto sprite = map->getChildren().at(i);
		if (sprite->getName() != "skull")
			continue;
		if (weapon->getBoundingBox().containsPoint(Vec2(sprite->getBoundingBox().getMidX(), sprite->getBoundingBox().getMidY())))
		{
			((BaseObject*)sprite)->setFeelHurt(true);
			if (((BaseObject*)sprite)->getHealth() == 0)
				((BaseObject*)sprite)->die();
				//garbege.pushBack(sprite);
		}
	}
	for (int i = 0; i < garbege.size(); i++)
	{
		map->removeChild(garbege.at(i));
	}
}

void Warrior::attack()
{
	if (weapon && this->getActionByTag(3) == nullptr)
	{
		attackDetection();
		((Weapon*)this->weapon)->attack();
		Vector<SpriteFrame*> animFrames(4);
		for (int i = 4; i < 8; i++)
		{
			auto frame = SpriteFrame::create("warrior.png", Rect(64 * i, 0, 64, 64));
			animFrames.pushBack(frame);
		}
		auto animation = Animation::createWithSpriteFrames(animFrames, WARRIOR_SPEED);
		animate = Animate::create(animation);
		animate->setTag(3);
		this->runAction(animate);
	}
}

