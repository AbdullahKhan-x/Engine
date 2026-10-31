#pragma once

#include"SDL.h"
#include"../Core/Engine.h"
#include<string>
#include<map>


class TextureManager{
public:
    static TextureManager* Get();

    bool Load(std::string id, std::string filename);
    void Drop(std::string id);
    void Clean();

	void Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void DrawFrame(std::string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);
private:
    TextureManager();
	std::map<std::string, SDL_Texture*> m_TextureMap;
    static TextureManager* s_instance;
};
