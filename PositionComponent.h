#pragma once

#include "BaseComponent.h"

class PositionComponent : public BaseComponent
{
public:
	float x;
	float y;
	PositionComponent(float x, float y);
	~PositionComponent(void);

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

