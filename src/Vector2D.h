#ifndef VECTOR2D_H
#define VECTOR2D_H

#include<iostream>

class vector2D{
	public:
		float X,Y;
		
	public:
		// constructor
		vector2D(float x=0,float y=0):X(x), Y(y){}
	public:
		// + operator overloading
		inline vector2D operator+(const vector2D& v) const
		{
			return vector2D(X+v.X,Y+v.Y);
		}
		// - operator overloading
		inline vector2D operator-(const vector2D& v) const
		{
			return vector2D(X+v.X,Y+v.Y);
		}
		
		inline vector2D operator*(const float scalar) const
		{
			return vector2D(X*scalar,Y*scalar);
		}
		
		inline void log(std::string mag="")
		{
			std::cout<<mag<<"(X,Y)=("<<X<<","<<Y<<")"<<std::endl;
		}
};

#endif
