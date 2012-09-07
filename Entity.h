#pragma once

#include "World.h"

typedef unsigned __int16 uint_16;


typedef uint_16 entityId;

typedef uint_16 componentId;


class Entity
{
public:
	Entity(void);
	~Entity(void);

	entityId id;
};

