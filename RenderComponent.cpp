#include "RenderComponent.h"

componentId RenderComponent::compTypeId;

RenderComponent::RenderComponent(void)
{
	compTypeId = 300;
	x=85;
	y=85;
}


RenderComponent::~RenderComponent(void)
{
}
