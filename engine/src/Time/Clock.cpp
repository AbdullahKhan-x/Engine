#include"Clock.h"
#include"SDL.h"

Clock* Clock::s_Instance = nullptr;

Clock* Clock::Get(){
	if (s_Instance != nullptr) return s_Instance;

	else {
		s_Instance = new Clock();
		return s_Instance;
	}
}
void Clock::Tick() {
	m_DeltaTime = (SDL_GetTicks() - m_LastTime) * (TARGET_FPS/1000.0f);

	if (m_DeltaTime > TARGET_DELTATIME) m_DeltaTime = TARGET_DELTATIME;

	m_LastTime = SDL_GetTicks();
	
}
