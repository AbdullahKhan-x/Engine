#include "Engine.h"
#include "Ball.h"
#include <vector>
#include <cstdlib>
#include <ctime>

// ─────────────────────────────────────────────
//  Physics2D Demo — Particle Simulator
//
//  Spawns 30 balls with randomized:
//    - starting position
//    - starting velocity
//    - mass (affects how fast gravity pulls them)
//    - size
//    - color
//
//  Each ball uses the engine's RigidBody system for gravity
//  and bounces off screen edges with energy loss.
//
//  The "chaos" emerges naturally — tiny differences in mass
//  and velocity compound over time into unpredictable patterns.
// ─────────────────────────────────────────────

// A small set of vivid colors so balls are visually distinct
static SDL_Color PALETTE[] = {
    {255,  80,  80, 255},   // red
    {255, 160,  40, 255},   // orange
    {255, 220,  40, 255},   // yellow
    { 80, 220,  80, 255},   // green
    { 40, 180, 255, 255},   // cyan
    {140,  80, 255, 255},   // purple
    {255,  80, 180, 255},   // pink
    {255, 255, 255, 255},   // white
};
static const int PALETTE_SIZE = 8;
static const int BALL_COUNT   = 30;

float randomFloat(float lo, float hi) {
    return lo + (float)rand() / (float)RAND_MAX * (hi - lo);
}

int main() {
    srand((unsigned)time(nullptr));

    Engine::Get()->Init("Physics Demo", 960, 640);

    // Spawn balls with randomized properties
    std::vector<Ball*> balls;
    balls.reserve(BALL_COUNT);

    for (int i = 0; i < BALL_COUNT; i++) {
        BallProps props;
        props.x     = randomFloat(20.0f, Engine::Get()->GetWidth()  - 40.0f);
        props.y     = randomFloat(20.0f, Engine::Get()->GetHeight() / 2.0f);   // start in top half
        props.vx    = randomFloat(-200.0f, 200.0f);
        props.vy    = randomFloat(-150.0f,  50.0f);
        props.mass  = randomFloat(0.5f,  3.0f);                    // varied mass = varied fall speed
        props.size  = (int)randomFloat(6.0f, 18.0f);
        props.color = PALETTE[i % PALETTE_SIZE];

        balls.push_back(new Ball(props));
    }

    // Fixed timestep so physics is consistent regardless of framerate
    const float DELTA_TIME = 0.016f;  // ~60fps step

    while (Engine::Get()->IsRunning()) {
        Engine::Get()->Events();

        // Update all balls
        for (Ball* ball : balls) {
            ball->Update(DELTA_TIME);
        }

        // Render
        Engine::Get()->BeginRender(15, 15, 25, 255);  // dark navy background

        for (Ball* ball : balls) {
            ball->Draw();
        }

        Engine::Get()->EndRender();
    }

    // Cleanup
    for (Ball* ball : balls) {
        ball->Clean();
        delete ball;
    }

    Engine::Get()->Clean();
    return 0;
}
