#include "Input.h"


Input* Input::create(std::string fileName, const Rect& rect)
{
	Input *sprite = new (std::nothrow) Input();
	if (sprite && sprite->initWithFile(fileName,rect) && sprite->init())
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

bool Input::init()
{
	/*auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(Input::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(Input::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);*/
	this->scheduleUpdate();
	isRight = false;
	isLeft = false;
	isAttack = false;
	return true;
}


void Input::update(float d)
{
	//Vec2 controlleePos = controllee->getPosition();
	if (isRight)
		((Warrior*)controllee)->walk(1);
	else if (isLeft)
	{
		((Warrior*)controllee)->walk(0);
	}
	else if (isUp)
	{
		((Warrior*)controllee)->jump();
		isUp = false;
	}
	else if (isAttack)
		((Warrior*)controllee)->attack();
		
	//controllee->setPosition(controlleePos);
}

void Input::setControllee(BaseObject * controllee)
{
	this->controllee = controllee;
}

bool Input::onTouchBegan(Touch* touch, Event* event)
{
	if (controllee == nullptr)
	{
		log("Error! Controllee dose not be set....");
		return true;
	}
	//log("tag %d ", this->getTag());
	switch (this->getTag())
	{
	case rightArrow:
		if (this->getBoundingBox().containsPoint(touch->getLocation()))
		isRight = true;
		break;
	case leftArrow:
		if (this->getBoundingBox().containsPoint(touch->getLocation()))
		isLeft = true;
		break;
	case upArrow:
		if (this->getBoundingBox().containsPoint(touch->getLocation()))
		isUp = true;
		break;
	case attackButton:
		if (this->getBoundingBox().containsPoint(touch->getLocation()))
			isAttack = true;
		break;

	}

	/*if (controllee == nullptr)
	{
		log("Error!  controllee do not set....");
		return false;
	}
	Vec2 controlleePos = controllee->getPosition();
	switch (this->getTag())
	{
	case rightArrow:
		log("right~~~~");
		controlleePos.x += 20;
		break;
	}

	controllee->setPosition(controlleePos);*/
	return true;
}

void Input::onTouchEnded(Touch* touch, Event* event)
{
	/*if (controllee == nullptr)
	{
	log("Error!  controllee do not set....");
	return false;
	}
	Vec2 controlleePos = controllee->getPosition();
	switch (this->getTag())
	{
	case rightArrow:
	log("right~~~~");
	controlleePos.x += 20;
	break;
	}
	controllee->setPosition(controlleePos);*/
	isRight = false;
	isLeft = false;
	isUp = false;
	isAttack = false;
}

//bool Input::ont

void Input::onTouchMoved(Touch* touch, Event* event)
{

	
	
}