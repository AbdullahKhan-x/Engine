# Engine
A small 2D game engine in C++ (SDL2, CMake), built as a static library for my OOP course project.
It provides a game loop, texture management, sprite animation, keyboard input, frame timing and basic rigid-body physics (vectors, transforms, forces).
Builds on Linux with `scripts/linux.sh` (SDL2 is bundled in `vendor/`); Windows support is being reworked.

The demos in `demos/` (Textures, Animations, Physics2D) are rough for now. More features, including tile maps, are planned.
