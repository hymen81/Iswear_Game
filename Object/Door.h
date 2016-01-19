#ifndef __DOOR_H__
#define __DOOR_H__

#include "Object.h"

class Door : public BaseObject
{
public:
	Door();
	~Door();
	static Door* create(std::string);
	void open();
	void close();
};

#endif