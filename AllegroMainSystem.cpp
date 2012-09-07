#include "AllegroMainSystem.h"

#include "AllegroGlobalEnvironment.h"

AllegroMainSystem::AllegroMainSystem(void)
{
	draw = false;
	timerFrame = 0;
	timerGame = 0;
	display = 0;
	event_queue = 0;
	ok = false;
}



AllegroMainSystem::~AllegroMainSystem(void)
{
	
}

int AllegroMainSystem::Init(int width, int height, double framespeed, double gamespeed)
{
	if( !al_init() )
	{
		cout<<"Allegro Yüklenemedi!"<<endl;
		return 0;
	}

	display = al_create_display(640,480);

	if( !display )
	{
		cout<<"Display Yüklenemedi!"<<endl;
		return 0;
	}

	al_init_primitives_addon();
	al_init_image_addon();

	al_install_keyboard();
	al_install_mouse();

	al_init_font_addon();

	event_queue = al_create_event_queue(); // olay kuyruðunu oluþturduk

	if(!event_queue)
	{
		cout<<"Olay kuyruðu Yaratýlamadý!"<<endl;
		return 0;
	}

	timerFrame = al_create_timer(framespeed);

	timerGame = al_create_timer(gamespeed);

	if(!timerFrame || !timerGame)
	{
		cout<<"Zamanlayýcý Oluþturulamadý!"<<endl;
		return 0;
	}

	al_register_event_source(event_queue , al_get_display_event_source( display ) );

	al_register_event_source(event_queue , al_get_timer_event_source( timerFrame ) );

	al_register_event_source(event_queue , al_get_timer_event_source( timerGame ) );

	al_register_event_source(event_queue , al_get_keyboard_event_source() );

	al_register_event_source(event_queue , al_get_mouse_event_source() );


	ok = true;

	return 1;
}


void AllegroMainSystem::Start(ALLEGRO_COLOR bgcolor)
{
	al_start_timer(timerFrame);
	al_start_timer(timerGame);
	this->_bgcolor = bgcolor;
}

int AllegroMainSystem::UpdateEvents()
{
	ALLEGRO_EVENT e;
	al_wait_for_event(event_queue, &e);

	if( e.type == ALLEGRO_EVENT_DISPLAY_CLOSE )
	{
		return 0;
	}
	else if( e.type == ALLEGRO_EVENT_TIMER )
	{
		if( e.timer.source == timerFrame )
		{
			draw = true;
		}
		else if( e.timer.source == timerGame )
		{
			$GE.EventSystem().onUpdate();
		}
	}
	else if(e.type == ALLEGRO_EVENT_KEY_DOWN            ||
			e.type == ALLEGRO_EVENT_KEY_UP              ||
			e.type == ALLEGRO_EVENT_KEY_CHAR            ||
			e.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN   ||
			e.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP     ||
			e.type == ALLEGRO_EVENT_MOUSE_AXES          ||
			e.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY ||
			e.type == ALLEGRO_EVENT_MOUSE_LEAVE_DISPLAY ||
			e.type == ALLEGRO_EVENT_MOUSE_WARPED)
	{
		$GE.EventSystem().onInputEvent(e);
	}

	if( draw && al_is_event_queue_empty(event_queue) )
	{
		al_clear_to_color( _bgcolor );
		$GE.EventSystem().onDraw();
		al_flip_display();
	}

	return 1;
}
