#ifndef TRANSFORM_H
#define TRANSFORM_H
#include"vector2D.h"

class transform{
	public:
		float X,Y;
		inline void log(std::string mag="")
		{
			std::cout<<mag<<"(X,Y)=("<<X<<","<<Y<<")"<<std::endl;
		}
		// constructor
		transform(float x=0,float y=0):X(x),Y(y){}
	public:
		inline void translateX(float x){X+=x;}
		inline void translateY(float y){Y+=y;}
		inline void translate(vector2D v){X+=v.X;Y+=v.Y;}
};

#endif
