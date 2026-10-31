#include "Ball.h"
#include "Engine.h"
#include <cmath>

Ball::Ball(BallProps props)
: GameObject(new Properties("", props.x, props.y, props.size * 2, props.size * 2)),
m_Size(props.size),
m_Color(props.color),
m_VelocityX(props.vx),
m_VelocityY(props.vy)
{
    m_RigidBody = new RigidBody();
    m_RigidBody->SetMass(props.mass);
}

void Ball::Update(float deltaTime) {
    m_RigidBody->UnsetForce();
    m_RigidBody->Update(deltaTime);

    m_VelocityX += m_RigidBody->GetAcceleration().GetX() * deltaTime;
    m_VelocityY += m_RigidBody->GetAcceleration().GetY() * deltaTime;

    m_Transform->TranslateX(m_VelocityX * deltaTime);
    m_Transform->TranslateY(m_VelocityY * deltaTime);

    HandleWallCollision(Engine::Get()->GetWidth(), Engine::Get()->GetHeight());
}

void DrawFilledCircle(SDL_Renderer* renderer, int cx, int cy, int radius) {
    for (int y = -radius; y <= radius; y++) {
        int dx = (int)sqrt((double)(radius * radius - y * y));
        SDL_RenderDrawLine(renderer, cx - dx, cy + y, cx + dx, cy + y);
    }
}

void Ball::Draw() {
    SDL_Renderer* renderer = Engine::Get()->GetRenderer();

    // Filled circle
    SDL_SetRenderDrawColor(renderer, m_Color.r, m_Color.g, m_Color.b, m_Color.a);
    DrawFilledCircle(renderer,
                     (int)m_Transform->GetX() + m_Size,
                     (int)m_Transform->GetY() + m_Size,
                     m_Size);

    // Darker outline
    SDL_SetRenderDrawColor(renderer,
                           (Uint8)(m_Color.r * 0.5f),
                           (Uint8)(m_Color.g * 0.5f),
                           (Uint8)(m_Color.b * 0.5f),
                           255);
    for (int angle = 0; angle < 360; angle++) {
        double rad = angle * 3.14159 / 180.0;
        int x = (int)(m_Transform->GetX() + m_Size + m_Size * cos(rad));
        int y = (int)(m_Transform->GetY() + m_Size + m_Size * sin(rad));
        SDL_RenderDrawPoint(renderer, x, y);
    }
}

void Ball::Clean() {
    delete m_RigidBody;
}

void Ball::HandleWallCollision(int screenW, int screenH) {
    float x = m_Transform->GetX() + m_Size;
    float y = m_Transform->GetY() + m_Size;

    if (x + m_Size >= screenW) {
        m_Transform->TranslateX(screenW - (x + m_Size));
        m_VelocityX *= -0.85f;
    }
    if (x - m_Size <= 0) {
        m_Transform->TranslateX(-(x - m_Size));
        m_VelocityX *= -0.85f;
    }
    if (y + m_Size >= screenH) {
        m_Transform->TranslateY(screenH - (y + m_Size));
        m_VelocityY *= -0.85f;
        m_VelocityX *= 0.98f;
    }
    if (y - m_Size <= 0) {
        m_Transform->TranslateY(-(y - m_Size));
        m_VelocityY *= -0.85f;
    }
}
