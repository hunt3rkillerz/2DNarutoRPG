#pragma once
#include <Windows.h>
class GameTime
{
	public:
		float elapsedGameTime, totalGameTime;
		GameTime();
		~GameTime();
		bool Initialize();
		void Update();
	private:
		LONGLONG start;
		float freqSecond;

};

