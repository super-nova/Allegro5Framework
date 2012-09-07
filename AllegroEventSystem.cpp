#include "AllegroEventSystem.h"


AllegroEventSystem::AllegroEventSystem(void)
{
}


AllegroEventSystem::~AllegroEventSystem(void)
{
}

int AllegroEventSystem::onInputEvent(ALLEGRO_EVENT &ev)
{
	return 1;
}

int AllegroEventSystem::onUpdate()
{
	return 1;
}

int AllegroEventSystem::onDraw()
{
	return 1;

}

int AllegroEventSystem::onCustomTimer(ALLEGRO_TIMER *timer)
{
	return 1;
}
