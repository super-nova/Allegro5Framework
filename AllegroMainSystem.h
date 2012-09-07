#pragma once

#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>

using namespace std;

class AllegroMainSystem
{
	ALLEGRO_DISPLAY *display;

	ALLEGRO_EVENT_QUEUE *event_queue;

	ALLEGRO_TIMER *timerFrame;

	ALLEGRO_TIMER *timerGame;

	bool draw;

	bool ok; // init olduðunda true shutdown da false

	ALLEGRO_COLOR _bgcolor;
public:
	AllegroMainSystem(void);
	~AllegroMainSystem(void);

	int Init(int width, int height, double framespeed, double gamespeed);

	void Start(ALLEGRO_COLOR bgcolor = al_map_rgb(0,0,0) );

	int UpdateEvents();
};

