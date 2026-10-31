#include "Engine.h"
#include "TextureManager.h"
#include "Animation.h"
#include "SDL.h"

int main(){
	Engine::Get()->Init("Animation Demo", 960, 640);

	TextureManager::Get()->Load("warrior", "assets/warrior_final.png");
	TextureManager::Get()->Load("plant",   "assets/plant_monster.png");

	Animation* plantAnim = new Animation();
	plantAnim->SetProps("plant", 1, 8, 100);

	float wx = 430, wy = 250;
	float speed = 4.0f;
	bool moving = false;
	int frame = 0;
	Uint32 lastFrameTime = 0;

	while (Engine::Get()->IsRunning()){
		Engine::Get()->Events();

		moving = false;
		if (Engine::Get()->IsKeyDown(SDL_SCANCODE_W) || Engine::Get()->IsKeyDown(SDL_SCANCODE_UP))
		{ wy -= speed; moving = true; }
		if (Engine::Get()->IsKeyDown(SDL_SCANCODE_S) || Engine::Get()->IsKeyDown(SDL_SCANCODE_DOWN))
		{ wy += speed; moving = true; }
		if (Engine::Get()->IsKeyDown(SDL_SCANCODE_A) || Engine::Get()->IsKeyDown(SDL_SCANCODE_LEFT))
		{ wx -= speed; moving = true; }
		if (Engine::Get()->IsKeyDown(SDL_SCANCODE_D) || Engine::Get()->IsKeyDown(SDL_SCANCODE_RIGHT))
		{ wx += speed; moving = true; }

		// Manual frame advance every 150ms, only when moving
		if (moving && SDL_GetTicks() - lastFrameTime > 150){
			frame = (frame + 1) % 5;
			lastFrameTime = SDL_GetTicks();
		}
		if (!moving) frame = 0;

		plantAnim->Update();

		Engine::Get()->BeginRender(100, 180, 80, 255);

		plantAnim->Draw(150, 200, 96, 96);
		plantAnim->Draw(650, 300, 96, 96);
		plantAnim->Draw(380, 100, 96, 96);

		// Draw correct frame manually using DrawFrame directly
		TextureManager::Get()->DrawFrame("warrior", (int)wx, (int)wy, 96, 96, 1, frame);

		Engine::Get()->EndRender();
	}

	Engine::Get()->Clean();
	return 0;
}
