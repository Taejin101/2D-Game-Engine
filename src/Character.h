#ifndef CHARACTER_H
#define CHARACTER_H
#include "GameObject.h"
#include <string>

class character:public gameobject
{
	public:
		character(properties *prop):gameobject(prop){}
		virtual void draw()=0;
		virtual void update(float dt)=0;
		virtual void clean()=0; 
		
	protected:
		std::string m_name;
};
#endif
