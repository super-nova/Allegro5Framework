#pragma once

#include "World.h"

typedef unsigned __int16 uint_16;

typedef uint_16 componentId;

class BaseComponent
{
	
public:
	BaseComponent(void);
	~BaseComponent(void);

	virtual void setTypeId(componentId id)=0;
	virtual componentId getTypeId()=0;

};

