#pragma once
#include"Vector2D.h"

#define UNIT_MASS 1.0f
#define GRAVITY 9.8f

#define FORWARD 1
#define BACKWORD -1

#define UPWARD 1
#define DOWNWARD -1

class RigidBody{
	public:
		RigidBody(){
			m_Mass = UNIT_MASS;
			m_Gravity = GRAVITY;
	}

	// Setters for Gravity and Mass.
	inline void SetMass(float mass) {m_Mass = mass;}
	inline void SetGravity(float gravity) {m_Gravity = gravity;}

	// Force.
	inline void ApplyForce(Vector2D F) {m_Force = F;}
	inline void ApplyForceX(float Fx) {m_Force.SetX(Fx);}
	inline void ApplyForceY(float Fy) {m_Force.SetY(Fy);}
	inline void UnsetForce() {m_Force = Vector2D{0,0};}

	// Friction.
	inline void ApplyFriction(Vector2D Fr) {m_Friction = Fr;}
	inline void UnsetFriction(){m_Friction = Vector2D{0,0};}


	// Getter Functions.
	inline float GetMass() {return m_Mass;}
	inline Vector2D GetPosition() {return m_Position;}
	inline Vector2D GetVelocity() {return m_Velocity;}
	inline Vector2D GetAcceleration() {return m_Acceleration;}

	void Update(float deltaTime){
		m_Acceleration.SetX((m_Force.GetX() + m_Friction.GetX())/m_Mass);
		m_Acceleration.SetY(m_Gravity + m_Force.GetY()/m_Mass);
		m_Velocity.SetX(m_Velocity.GetX() + m_Acceleration.GetX() * deltaTime);
		m_Velocity.SetY(m_Velocity.GetY() + m_Acceleration.GetY() * deltaTime);
		m_Position.SetX(m_Position.GetX() + m_Velocity.GetX() * deltaTime);
		m_Position.SetY(m_Position.GetY() + m_Velocity.GetY() * deltaTime);
	}

	private:
		float m_Mass;	
		float m_Gravity;

		Vector2D m_Force;
		Vector2D m_Friction;

		Vector2D m_Position;
		Vector2D m_Velocity;
		Vector2D m_Acceleration;
};
