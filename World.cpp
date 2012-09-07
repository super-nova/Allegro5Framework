#include "World.h"

#include <iostream>

#include "PositionComponent.h"

typedef BaseComponent* PBaseComponent;



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

/*void World::AddComponent( Entity* ent, BaseComponent *comp )
{
	for(componentId i=0; i < comp_types.size(); i++)
	{
		if( comp_types[i] == typeid(comp).name() )//if component type already registered
		{
			comp->id = i; //set components id as component type's id.

			(*map)[i][ent->id] = comp; // add this entity to component type's array

			return;
		}
	}

	//else if component type not registered

	comp_types.push_back( typeid(comp).name() ); //add this type to comp_types arr.

	comp->id = comp_types.size() - 1; //set components type

	(*map)[comp->id][ent->id] = comp; // add this entity to component type's array
}*/
