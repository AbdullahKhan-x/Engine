#pragma once
#include<iostream>

class Vector2D{
public:
	Vector2D(float x=0, float y=0): X(x), Y(y){}

	Vector2D operator+(const Vector2D& v2){
		return Vector2D(this ->X + v2.X, this->Y + v2.Y);
	}

	Vector2D operator-(const Vector2D& v2){
		return Vector2D(this->X - v2.X, this->Y- v2.Y);
	}

	Vector2D operator*(const float scalar){
		return Vector2D(X* scalar, Y* scalar);
	}

	void Log(std::string msg = ""){
		std::cout<<msg<<" (X, Y) = (" <<X<<" "<<Y<<")"<<std::endl;
	}
	
	Vector2D GetPosition(const Vector2D& vector){
		return vector;
	}

	inline float GetX() const {return X;}
	inline float GetY() const {return Y;}

	inline void SetX(float x) {X = x;}
	inline void SetY(float y) {Y = y;}

private:
	float X, Y;
};
