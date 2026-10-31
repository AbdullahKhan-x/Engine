#pragma once
#include"SDL.h"

class Input{
	public:
		static Input* Get();
		
		void Listen();
		bool GetKeyDown(SDL_Scancode key);
		bool GetKeyUp(SDL_Scancode key);


	private:
		Input();
		void KeyUp();
		void KeyDown();

		const Uint8* m_KeyStates;
		static Input* s_Instance;
};
