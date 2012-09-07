#pragma once
#include "basecomponent.h"
class RenderComponent :
	public BaseComponent
{
public:
	float x;
	float y;
	RenderComponent(void);
	~RenderComponent(void);

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

