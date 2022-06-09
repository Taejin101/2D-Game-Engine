#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SDL.h"
#include "IObject.h"
#include "Transform.h"
#include "Point.h"

struct properties{			// since there are lots of parameters to be passed in constructor we declared and defined a structure for all
	public:
		properties(std::string Textureid,int x,int y,int w,int h,SDL_RendererFlip Flip=SDL_FLIP_NONE)
		{
			textureid=Textureid;
			X=x;
			Y=y;
			width=w;
			height=h;
			flip=Flip;
		}
	
	public:
		std::string textureid;
		float X,Y;
		int width,height;
		SDL_RendererFlip flip;
};

class gameobject:public IObject
{
	protected:
		transform *m_transform;
		int m_width,m_height;
		std::string m_textureid;
		SDL_RendererFlip m_flip;
		Point *m_Origin;
		
	public:
		// initializes every member of gameobject with constructor provided values
	 	gameobject(properties *props):m_width(props->width),m_height(props->height),m_textureid(props->textureid),m_flip(props->flip)
		{
			m_transform=new transform(props->X,props->Y);
			
			float px=props->X + props->width/2;
			float py=props->Y + props->height/2;
			m_Origin=new Point(px,py);
		}
		inline Point* GetOrigin(){return m_Origin;}
		virtual void draw()=0;
		virtual void update(float dt)=0;
		virtual void clean()=0; 
};

#endif
