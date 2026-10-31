#include "Engine.h"
#include"TextureManager.h"
#include"Input.h"
#include"Clock.h"

#include"SDL.h"

Engine* Engine::s_instance = nullptr;

bool Engine::Init(const char* title, int width, int height){
	if(SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) !=0) {
		SDL_Log("Failed to Initialize SDL: %s", SDL_GetError());
		return false;

}
	m_Width = width;
	m_Height = height;

	m_Window = SDL_CreateWindow(title,
								SDL_WINDOWPOS_CENTERED, 
								SDL_WINDOWPOS_CENTERED, 
								m_Width, m_Height, 0);

	if(m_Window == nullptr){
		SDL_Log("Failed to Create Window: %s", SDL_GetError());
		return false;
	
}

	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_Renderer == nullptr){
		SDL_Log("Failed to Create Renderer: %s", SDL_GetError());
		return false;
	
}

	m_IsRunning = true;

	
	return m_IsRunning;
}

Engine::Engine(){}

void Engine::Clean(){
	TextureManager::Get()->Clean();
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	IMG_Quit();
	SDL_Quit();
}

void Engine::Quit(){
	m_IsRunning = false;
}

void Engine::Update(){
	float deltaTime = Clock::Get()->GetDeltaTime();
	if(Input::Get()->GetKeyDown(SDL_SCANCODE_A)){
		SDL_Log("Key A pushed!");
}
}

void Engine::Render(){

}

void Engine::Events(){
	Clock::Get()->Tick();
	Input::Get()->Listen();
}

Engine* Engine::Get(){
	if(s_instance != nullptr) return s_instance;

	else {
		s_instance = new Engine();
		return s_instance;
	}
}


void Engine::BeginRender(int r, int g, int b, int a){
	//Set a BackGround Color
	SDL_SetRenderDrawColor(m_Renderer, r, g, b, a);
	// Present The renderer like basically draw something inside the buffer..
	SDL_RenderClear(m_Renderer);
}

void Engine::EndRender(){
	SDL_RenderPresent(m_Renderer);
}


void Engine::LoadTexture(std::string id, std::string path){
	TextureManager::Get()->Load(id, path);
}
bool Engine::IsKeyDown(SDL_Scancode key){
	return Input::Get()->GetKeyDown(key);
}
