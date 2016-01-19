#ifndef __SHAKE_H__  
#define __SHAKE_H__  


#include "cocos2d.h"  
USING_NS_CC;

class MyShake : public ActionInterval
{
public:
	MyShake();
	~MyShake();
	static MyShake *create(float d, float strength);
	static MyShake *createWithStrength(float d, float strength_x, float strength_y);
	bool initWithDuration(float d, float strength_x, float strength_y);

protected:
	void startWithTarget(cocos2d::CCNode *pTarget);
	void update(float time);
	void stop(void);
	Point m_StartPosition;
	// Strength of the action  
	float m_strength_x, m_strength_y;
};

#endif