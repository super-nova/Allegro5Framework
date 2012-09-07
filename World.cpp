#include "World.h"

#include <iostream>

World::World(void)
{
	lastid = 0;

	lastCompTypeId = 0;

	int max = std::numeric_limits<componentId>::max();
	
	map = new boost::multi_array<BaseComponent* , 2>( boost::extents[256][max] );
}


World::~World(void)
{
}

void World::AddComponent( Entity* ent, BaseComponent* comp )
{
	if( comp->getTypeId() == 300 )
	{
		comp->setTypeId( lastCompTypeId );
		lastCompTypeId ++;
	}
	(*map)[comp->getTypeId()][ent->id] = comp; // add this entity to component type's array
}

BaseComponent* World::GetComponent( Entity *ent , componentId id)
{
	return (*map)[id][ent->id];
}