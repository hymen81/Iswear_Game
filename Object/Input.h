#ifndef __INPUT_H__
#define __INPUT_H__

#include "Object.h"
#include "Warrior.h"


class Input : public BaseObject
{
public:
	bool init();
	static Input* create(std::string, const Rect&);
	void setControllee(BaseObject*);
	void update(float);
	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch*, Event*);
private:
	BaseObject* controllee;
	bool isRight;
	bool isLeft;
	bool isUp;
	bool isAttack;
};

#endif