#include "MyShake.h"


MyShake::MyShake()
{
	this->setTag(20);
}


MyShake::~MyShake()
{
}

MyShake *MyShake::create(float d, float strength)
{
	// call other construction method with twice the same strength  
	return createWithStrength(d, strength, strength);
}

MyShake *MyShake::createWithStrength(float duration, float strength_x, float strength_y)
{
	MyShake *pRet = new MyShake();

	if (pRet && pRet->initWithDuration(duration, strength_x, strength_y))
	{
		pRet->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pRet);
	}


	return pRet;
}

bool MyShake::initWithDuration(float duration, float strength_x, float strength_y)
{
	if (ActionInterval::initWithDuration(duration))
	{
		m_strength_x = strength_x;
		m_strength_y = strength_y;
		return true;
	}

	return false;
}

// Helper function. I included it here so that you can compile the whole file  
// it returns a random value between min and max included  
static float fgRangeRand(float min, float max)
{
	float rnd = ((float)rand() / (float)RAND_MAX);
	return rnd * (max - min) + min;
}

void MyShake::update(float dt)
{
	float randx = fgRangeRand(-m_strength_x, m_strength_x) * dt;
	float randy = fgRangeRand(-m_strength_y, m_strength_y) * dt;

	// move the target to a shaked position  
	_target->setPosition(ccpAdd(m_StartPosition, ccp(randx, randy)));
}

void MyShake::startWithTarget(Node *pTarget)
{
	ActionInterval::startWithTarget(pTarget);

	// save the initial position  
	m_StartPosition = pTarget->getPosition();
}

void MyShake::stop(void)
{
	// Action is done, reset clip position  
	this->getTarget()->setPosition(m_StartPosition);

	ActionInterval::stop();
}