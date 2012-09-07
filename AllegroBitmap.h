#pragma once

#include <iostream>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>

class AllegroBitmap
{
	ALLEGRO_BITMAP *bmp;	//bitmap
	//------
	float x,y;				//position
	//------
	float sx, sy, sw, sh;	//region
	//------
	ALLEGRO_COLOR tint;		//tint color
	//------
	float cx, cy;			//center x-y
	//------
	float xscale, yscale;	//scaling factor
	//------
	float angle;			//rotation angle


public:
	AllegroBitmap(void);
	~AllegroBitmap(void);

	void LoadFromFile(const char* filename)
	{
		bmp = al_load_bitmap(filename);
	}

	void Draw()
	{
		al_draw_tinted_scaled_rotated_bitmap_region(	bmp,
														sx,sy,sw,sh,
														tint,
														cx,cy,
														x,y,
														xscale,yscale,
														angle,
														0	);
	}

	void SetPosition(

};

