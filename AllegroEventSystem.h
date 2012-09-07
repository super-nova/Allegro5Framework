#pragma once

#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>

class AllegroEventSystem
{
public:
	AllegroEventSystem(void);
	~AllegroEventSystem(void);

	int onInputEvent(ALLEGRO_EVENT &ev);

	int onUpdate();

	int onDraw();

	int onCustomTimer(ALLEGRO_TIMER *timer);
};

