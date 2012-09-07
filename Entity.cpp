#include "Entity.h"


Entity::Entity(void)
{
	this->id = World::GetInstance().createEntity();
}


Entity::~Entity(void)
{
}