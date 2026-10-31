#pragma once

#include "GameObject.h"
#include "RigidBody.h"
#include "SDL.h"

// Free function — draws a filled circle using SDL line primitives
// Declared here so Ball.cpp can use it at file scope
void DrawFilledCircle(SDL_Renderer* renderer, int cx, int cy, int radius);

struct BallProps {
    float x, y;        // starting position
    float vx, vy;      // starting velocity
    float mass;        // heavier = falls faster
    int   size;        // radius in pixels
    SDL_Color color;
};

class Ball : public GameObject {
public:
    Ball(BallProps props);

    virtual void Draw()                  override;
    virtual void Update(float deltaTime) override;
    virtual void Clean()                 override;

    void HandleWallCollision(int screenW, int screenH);

private:
    RigidBody* m_RigidBody;
    int        m_Size;
    SDL_Color  m_Color;
    float      m_VelocityX;
    float      m_VelocityY;
};
