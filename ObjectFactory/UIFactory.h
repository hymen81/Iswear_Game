#ifndef __UI_FACTORY_H__
#define __UI_FACTORY_H__

#include "FactoryInterface.h"
#include "../Object/Input.h"

class UpButtonFactory : public FactoryInterface
{
public:
	BaseObject* ctrateObject() override;
};

class LeftButtonFactory : public FactoryInterface
{
public:
	BaseObject* ctrateObject() override;
};

class RightButtonFactory : public FactoryInterface
{
public:
	BaseObject* ctrateObject() override;
};

class AttackButtonFactory : public FactoryInterface
{
public:
	BaseObject* ctrateObject() override;
};

#endif

