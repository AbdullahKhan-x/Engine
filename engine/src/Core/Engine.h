#pragma once


#include"SDL.h"
#include"SDL_image.h"
#include"Clock.h"
#include <string>




class Engine {
public:
    static Engine* Get();
    bool Init(const char* title = "Game", int width = 960, int height = 640);
    void Clean();
    void Quit();

    void Update();
    void Render();
    void Events();

	void BeginRender(int r = 0, int g = 0, int b = 0,int a = 255);
	void EndRender();

	inline bool IsRunning() {return m_IsRunning;};
	inline SDL_Renderer* GetRenderer() {return m_Renderer;}

	inline int GetWidth()  { return m_Width; }
	inline int GetHeight() { return m_Height; }

	inline float GetDeltaTime() { return Clock::Get()->GetDeltaTime(); }


	void LoadTexture(std::string id, std::string path);
    void DrawTexture(std::string id, int x, int y, int w, int h);
    void DrawTextureFrame(std::string id, int x, int y, int w, int h, int row, int frame);
    void DropTexture(std::string id);

    bool IsKeyDown(SDL_Scancode key);
    bool IsKeyUp(SDL_Scancode key);
private:
    Engine();
	bool m_IsRunning;

	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
    static Engine* s_instance;

    int m_Width;
    int m_Height;
};
