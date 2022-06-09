#ifndef CAMERA_H
#define CAMERA_H

#include "engine.h"
#include "Point.h"
#include "Vector2D.h"
#include <SDL.h>

class Camera{
	public:
		void Update(float dt);
		inline static Camera* GetInstance(){return s_Instance=(s_Instance!=nullptr)?s_Instance:new Camera();}
		inline SDL_Rect GetViewBox(){return m_ViewBox;}
		inline vector2D GetPosition(){return m_Position;}
		inline void SetTarget(Point *target){m_Target=target;}
		inline void SetSceneLimit(int w,int h){m_SceneWidth=w; m_SceneHeight=h;}
		
	private:
		Camera(){m_ViewBox = {0,0,WIDTH,HEIGHT};}					// constructor
		Point* m_Target;
		vector2D m_Position;
		SDL_Rect m_ViewBox;
		
		static Camera *s_Instance;
		int m_SceneWidth,m_SceneHeight;
		
};

#endif
