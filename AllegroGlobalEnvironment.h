#pragma once

#include "AllegroMainSystem.h"
#include "AllegroEventSystem.h"

#define $GE AllegroGlobalEnvironment::GetInstance()

class AllegroMainSystem;
class AllegroEventSystem;

class AllegroGlobalEnvironment
{
public:
	AllegroGlobalEnvironment(void)
	{
	}
	~AllegroGlobalEnvironment(void)
	{
	}

	static AllegroGlobalEnvironment& GetInstance()
	{
		static AllegroGlobalEnvironment ge;
		return ge;
	}

	AllegroMainSystem& MainSystem()
	{
		static AllegroMainSystem ms;
		return ms;
	}

	AllegroEventSystem& EventSystem()
	{
		static AllegroEventSystem es;
		return es;
	}
};

