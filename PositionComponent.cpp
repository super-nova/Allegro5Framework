#include "PositionComponent.h"

componentId PositionComponent::compTypeId;

PositionComponent::PositionComponent(float x, float y)
{
	compTypeId = 300;
	this->x = x;
	this->y = y;
}


PositionComponent::~PositionComponent(void)
{
}
