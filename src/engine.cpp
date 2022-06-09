#include "ObjectFactory.h"
#include "engine.h"
#include <iostream>
#include "Graphics.h"
#include "Hero.h"
#include "Inputs.h"
#include "Timer.h"
#include "MapParser.h"
#include "Camera.h"


engine* engine::s_instance = nullptr;
hero* player1=nullptr;

bool engine::init()
{
	if(SDL_Init(SDL_INIT_EVERYTHING)!=0)
	{
		std::cout<<"Some error occured "<<SDL_GetError();
		return false;
	}
	
	SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE|SDL_WINDOW_ALLOW_HIGHDPI);
	
	win=SDL_CreateWindow("RPG Window",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WIDTH,HEIGHT,window_flags);
	if(win==nullptr)
	{
		std::cout<<"Failed to create window "<<SDL_GetError();
		return false;
	}
	
	screen=SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	if(screen==nullptr)
	{
		std::cout<<"Failed to create renderer "<<SDL_GetError();
		return false;
	}
	
	if(!MapParser::GetInstance()->Load())
	{
		std::cout<<"Failed to load map"<<std::endl;
	}
	
	// maps and loads the file image with id in texture manager takes id and path of image
	m_LevelMap = MapParser::GetInstance()->GetMap("MAP");
	tilelayer* collisionLayer=(tilelayer*)m_LevelMap->GetMapLayers().back();
	
	int tilesize=collisionLayer->GetTileSize();
	int width=collisionLayer->GetWidth()*tilesize;
	int height=collisionLayer->GetHeight()*tilesize;
	
	Camera::GetInstance()->SetSceneLimit(width,height);

	// load all the player animation here
	textureManager::getInstance()->ParseTextures("assets/texture.tml");

	properties* props = new properties("hero_idle",100,200,126,137);
	
	gameobject* player= ObjectFactory::GetInstance()->CreateObject("PLAYER",props);
	if(player==nullptr){
		std::cout<<"Player cannot be build"<<std::endl;
	}
	
	m_GameObjects.push_back(player);
	
	Camera::GetInstance()->SetTarget(player->GetOrigin());
	
	return (m_running=true);
}

SDL_Renderer* engine::getRenderer()					// returns renderer since it is private we can't access renderer without this
{
	return screen;
}

bool engine::isRunning() 
{
	return (m_running);
}

void engine::Render()								  
{
	SDL_SetRenderDrawColor(screen,124,218,254,255);
	SDL_RenderClear(screen);
	//textureManager::getInstance()->draw("untitled",100,100,46,60,SDL_FLIP_NONE);
	textureManager::getInstance()->draw("bg",0,0,1920,1080,SDL_FLIP_NONE,1,1,0,0.45);
	m_LevelMap->Render();

	for(unsigned int i=0;i<m_GameObjects.size();++i){
		m_GameObjects[i]->draw();
	}
	// player1->draw();
	SDL_RenderPresent(screen);
}

void engine::Update()								// updates the properties after every loop and calls to other update function
{
	float dt=timer::getInstance()->GetDeltaTime();
	m_LevelMap->Update();
	// player1->update(dt);
	
	for(unsigned int i=0;i<m_GameObjects.size();++i){
		m_GameObjects[i]->update(dt);
	}
	Camera::GetInstance()->Update(dt);
}

void engine::Events()								// handles the input events
{
	input::getInstance()->listen();
}

bool engine::clean()							// destroys window renderer and call to other clean functions
{
	for(unsigned int i=0;i<m_GameObjects.size();++i){
		m_GameObjects[i]->clean();
	}
	textureManager::getInstance()->clean();
	MapParser::GetInstance()->Clean();
	SDL_DestroyRenderer(screen);
	SDL_DestroyWindow(win);
	IMG_Quit();
	SDL_Quit();
}

void engine::quit()
{
	m_running=false;
}
