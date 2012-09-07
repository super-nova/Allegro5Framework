#include "AllegroGlobalEnvironment.h"

#include "World.h"

#include "PositionComponent.h"

#include "SpriteComponent.h"

int main()
{
	//------------------

	$GE.MainSystem().Init(1024 , 768 , 1.0 / 60 , 1.0 / 60 );

	//------------------

	World world = World::GetInstance();

	Entity *ent = new Entity();

	world.AddComponent( ent , new PositionComponent(100,100) );

	world.AddComponent( ent , new SpriteComponent() );

	PositionComponent *pc = (PositionComponent*)world.GetComponent(ent, PositionComponent::compTypeId);

	SpriteComponent *rc = (SpriteComponent*)world.GetComponent(ent, SpriteComponent::compTypeId);

	if( pc ) std::cout << pc->x << std::endl << pc->y << std::endl;

	if( rc ) std::cout << rc->x << std::endl << rc->y << std::endl;

	//------------------

	$GE.MainSystem().Start( al_map_rgb(255,255,255) );

	while( $GE.MainSystem().UpdateEvents() )
	{
		
	}

	return 0;
}