#ifndef COLLISION_H
#define COLLISION_H	

#include <SDL.h>
#include <vector>
#include "TileLayer.h"
#include "TileMap.h"

class CollisionHandler{
	public:
		bool CheckCollision(SDL_Rect a,SDL_Rect b);
		bool MapCollision(SDL_Rect a);
		
		inline static CollisionHandler* GetInstance(){return s_Instance=(s_Instance!=nullptr)?s_Instance:new CollisionHandler();}
		
	private:
		CollisionHandler();
		TileMatrix m_CollisionTilemap;
		tilelayer* m_CollisionLayer;
		static CollisionHandler* s_Instance;	
};

#endif
