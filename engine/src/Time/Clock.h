#pragma once
#include"SDL.h"

const int TARGET_FPS = 60;
const float TARGET_DELTATIME = 1.5;


class Clock{
	public:
		void Tick();
		inline float GetDeltaTime() {return m_DeltaTime;}
		static Clock* Get();
	private:
		Clock() {m_LastTime = 0; m_DeltaTime = 0;}
		static Clock* s_Instance;
		float m_DeltaTime;
		Uint32 m_LastTime;
};
