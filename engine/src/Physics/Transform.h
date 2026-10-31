#pragma once
#include<iostream>
#include"Vector2D.h"

class Transform{
	public:
		Transform(float x = 0, float y = 0): X(x), Y(y){}
		void Log(std::string msg){
			std::cout<<msg<<" (X, Y) = (" <<X<<" "<<Y<<")"<<std::endl;
		}

		inline float  GetX() const {return X;}
		inline float  GetY() const {return Y;}


		inline void TranslateX(float x) {X += x;}
		inline void TranslateY(float y) {Y += y;}
		inline void Translate(const Vector2D& v) {X += v.GetX();
											Y += v.GetY();}
	private:
		float X, Y;


};
