#pragma once

#include "Character.h"
#include "Animation.h"
#include "RigidBody.h"

enum class Direction { Down, Up, Left, Right };

class Warrior: public Character{
public:
	Warrior(Properties* props);

	virtual void Draw();
	virtual void Update(float deltaTime);
	virtual void Clean();

private:
	Animation*  m_Animation;
	RigidBody*  m_RigidBody;
	float       m_Speed;
	bool        m_Moving;
	Direction   m_Direction;
	Direction   m_LastDirection;
};
