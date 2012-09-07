#pragma once

class Entity;
class BaseComponent;


#include "Entity.h"
#include "BaseComponent.h"
#include <vector>

#include <boost/multi_array.hpp>



using std::vector;

typedef unsigned __int16 uint_16;


typedef uint_16 entityId;

typedef uint_16 componentId;



class World
{
	entityId lastid;

	componentId lastCompTypeId;

	vector<Entity*> ents;

	boost::multi_array<BaseComponent*,2> *map;

public:
	World(void);
	~World(void);

	BaseComponent* GetComponent( Entity *ent , componentId id);

	void AddComponent( Entity* ent, BaseComponent* comp );

	entityId createEntity()
	{
		return ++lastid;
	}

	static World& GetInstance()
	{
		static World w;
		return w;
	}
};

