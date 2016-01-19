#include "UIFactory.h"

BaseObject* UpButtonFactory::ctrateObject()
{
	BaseObject *baseObject = Input::create("arr.png", Rect(0 * 96, 0, 96, 96));
	return baseObject;
}

BaseObject* LeftButtonFactory::ctrateObject()
{
	return Input::create("arr.png", Rect(1 * 96, 0, 96, 96));
}

BaseObject* RightButtonFactory::ctrateObject()
{
	return Input::create("arr.png", Rect(2 * 96, 0, 96, 96));
}

BaseObject* AttackButtonFactory::ctrateObject()
{
	return Input::create("arr.png", Rect(3 * 96, 0, 96, 96));
}