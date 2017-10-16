#include "GameTime.h"



GameTime::GameTime()
{
}


GameTime::~GameTime()
{
}

bool GameTime::Initialize()
{
	LARGE_INTEGER i;

	//Get freq from counter
	if (!QueryPerformanceFrequency(&i))
	{
		return false;
	}
	
	freqSecond = (float)i.QuadPart;

	//Get counter val
	QueryPerformanceCounter(&i);
	start = i.QuadPart;
	totalGameTime = 0;
	elapsedGameTime = 0;

	return true;
}

void GameTime::Update()
{
	LARGE_INTEGER i;

	QueryPerformanceCounter(&i);
	elapsedGameTime = (float)(i.QuadPart - start) / freqSecond;

	start = i.QuadPart;
	totalGameTime += elapsedGameTime;
}
