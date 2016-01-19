#include "Factory.h"

Factory* Factory::factory = NULL;

Factory::Factory()
{
}


Factory::~Factory()
{
}


Factory* Factory::getInstance()
{
	return factory != NULL ? new Factory() : factory;
}

