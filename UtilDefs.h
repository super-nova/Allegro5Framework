#undef PLATFORM_WINDOWS
#undef PLATFORM_MAC
#undef PLATFORM_UNIX

#if defined(_WIN32)
#define PLATFORM_WINDOWS
#elif defined(__APPLE__)
#define PLATFORM_MAC
#else
#define PLATFORM_UNIX
#endif


#ifdef PLATFORM_WINDOWS

#include <WinSock.h>

#endif

#include <iostream>
#include <cmath>
#include <ctime>

#include "CrossPlatformTimer.h"


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifndef ALLEGRO_PI
#define ALLEGRO_PI 3.14159265358979323846
#endif

typedef double radian;
typedef float degree;

#define MIN(x,y) (x < y ? x : y)
#define MAX(x,y) (x > y ? x : y)
#define INSIDE 1
#define OUTSIDE 0

typedef CrossPlatformTimer timer;




