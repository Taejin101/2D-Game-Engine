#ifndef ENGINE_H
#define ENGINE_H

#include<SDL.h>
#include<SDL_image.h>
#include "GameMap.h"
#include "GameObject.h"
#include "CollisionHandler.h"

#define WIDTH 960
#define HEIGHT 640
using namespace std;

class engine{								// singleton class - can only have one object
	private:
		engine(){}
		static engine* s_instance;
		SDL_Window *win;
		SDL_Renderer *screen;
		bool m_running=true;
		TileMap *m_LevelMap;
		
		std::vector<gameobject*> m_GameObjects;
	
	public:
		
		static engine* getInstance()
		{
			return (s_instance=(s_instance!=nullptr)?s_instance:new engine);
		}
		
		bool init();						// creater window, renderer and loads image if any
		bool clean();						// destroys window, renderer and calls to other clean functions
		void quit();
		
		void Update();
		void Render();
		void Events();
		
		SDL_Renderer* getRenderer();
		
		inline TileMap* GetMap(){return m_LevelMap;}
		bool isRunning();
};

#endif

