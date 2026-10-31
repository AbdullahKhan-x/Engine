// main.cpp
#include "Engine.h"


int main(){
    Engine::Get()->Init("Texture Demo", 960, 640);

    while(Engine::Get()->IsRunning()){
        Engine::Get()->Events();

        Engine::Get()->BeginRender(30, 30, 30, 255);

        Engine::Get()->EndRender();
    }
    Engine::Get()->Clean();
    return 0;
}
