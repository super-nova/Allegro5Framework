#include "AllegroBitmap.h"


AllegroBitmap::AllegroBitmap(void)
{
	bmp=0;							//bitmap
	//------
	x=0;
	y=0;							//position
	//------
	sx=0;
	sy=0;
	sw=0;
	sh=0;							//region
	//------
	tint = al_map_rgb(255,255,255);	//tint color
	//------
	cx=0;
	cy=0;							//center x-y
	//------
	xscale=1;
	yscale=1;						//scaling factor
	//------
	angle=0;						//rotation angle
}


AllegroBitmap::~AllegroBitmap(void)
{
}
