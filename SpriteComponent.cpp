#include "SpriteComponent.h"

componentId SpriteComponent::compTypeId;

SpriteComponent::SpriteComponent(void)
{
	compTypeId = 300;
	x=85;
	y=85;
}


SpriteComponent::~SpriteComponent(void)
{
}
