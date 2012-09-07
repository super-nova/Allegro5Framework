#ifndef TIMER_H_DEF
#define TIMER_H_DEF

#undef PLATFORM_WINDOWS
#undef PLATFORM_MAC
#undef PLATFORM_UNIX

#if defined(_WIN32)
#define PLATFORM_WINDOWS
#define WIN32
#elif defined(__APPLE__)
#define PLATFORM_MAC
#define OSX
#define MAC
#else
#define PLATFORM_UNIX
#define LINUX
#endif

#ifdef WIN32   // Windows system specific
#include <windows.h>
#else          // Unix based system specific
#include <sys/time.h>
#endif


class CrossPlatformTimer
{
public:
	CrossPlatformTimer();                                    // default constructor
	~CrossPlatformTimer();                                   // default destructor

	void   start();                             // start timer
	void   stop();                              // stop the timer
	double getElapsedTime();                    // get elapsed time in second
	double getElapsedTimeInSec();               // get elapsed time in second (same as getElapsedTime)
	double getElapsedTimeInMilliSec();          // get elapsed time in milli-second
	double getElapsedTimeInMicroSec();          // get elapsed time in micro-second

private:
	double startTimeInMicroSec;                 // starting time in micro-second
	double endTimeInMicroSec;                   // ending time in micro-second
	int    stopped;                             // stop flag 
#ifdef WIN32
	LARGE_INTEGER frequency;                    // ticks per second
	LARGE_INTEGER startCount;                   //
	LARGE_INTEGER endCount;                     //
#else
	timeval startCount;                         //
	timeval endCount;                           //
#endif
};

#endif // TIMER_H_DEF

