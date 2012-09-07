#pragma once
#include "basecomponent.h"
class SpriteComponent :
	public BaseComponent
{
public:

	

	SpriteComponent(void);
	~SpriteComponent(void);

	static componentId compTypeId;

	virtual componentId getTypeId()
	{
		return compTypeId;
	}

	virtual void setTypeId(componentId id)
	{
		compTypeId = id;
	}
};

