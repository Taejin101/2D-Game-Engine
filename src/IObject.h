/* it is an abstract class which needs not to define the functions 
   Abstract classes can only have pointers and references of theirs we cannot make objects of abstract class */

#ifndef IOOBJECT_H
#define IOOBJECT_H

class IObject{								// Interface object - it is the parent class for all objects in the game
	public:
		virtual void draw()=0;				// every child class must override these three functions
		virtual void update(float dt)=0;
		virtual void clean()=0;
};

#endif
