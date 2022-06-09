#include "Graphics.h"
#include "engine.h"
#include <iostream>
#include "Camera.h"
#include "tinyxml.h"

textureManager* textureManager::s_instance=nullptr;				// static variables inside class needs to be defined outside

bool textureManager::load(std::string id,std::string filename) 
{
	SDL_Surface *image=IMG_Load(filename.c_str());
	if(image==nullptr)
	{
		return false;
	}
	
	SDL_Texture *texture=SDL_CreateTextureFromSurface(engine::getInstance()->getRenderer(),image);
	if(texture==nullptr)
	{
		return false;
	}
	
	m_texturemap[id]=texture;
	return true;
}

void textureManager::draw(std::string id,int x,int y,int w,int h,SDL_RendererFlip flip,float scaleX,float scaleY,float rotation, float speedRatio)		// draws static images
{
	SDL_Rect srcrect={0,0,w,h};
	vector2D cam = Camera::GetInstance()->GetPosition()*speedRatio;
	
	SDL_Rect desrect={x-cam.X,y-cam.Y,w*scaleX,h*scaleY};
	SDL_RenderCopyEx(engine::getInstance()->getRenderer(),m_texturemap[id],&srcrect,&desrect,rotation,nullptr,flip);		
}

void textureManager::drawFrame(std::string id,int x,int y,int w,int h,int row,int frame,SDL_RendererFlip flip,float scaleX,float scaleY,float rotation, float speedRatio)	// draws animated images
{
	SDL_Rect srcrect={w*frame,h*row,w,h};
	vector2D cam = Camera::GetInstance()->GetPosition();
	
	SDL_Rect desrect={x-cam.X,y-cam.Y,40,60};
	SDL_RenderCopyEx(engine::getInstance()->getRenderer(),m_texturemap[id],&srcrect,&desrect,rotation,nullptr,flip);                                                                                   
}

void textureManager::drawTile(std::string tilesetID,int tileSize,int x,int y,int row,int frame,float speedRatio)
{
	SDL_Rect srcrect={tileSize*frame,tileSize*row,tileSize,tileSize};
	vector2D cam = Camera::GetInstance()->GetPosition()*speedRatio;
	SDL_Rect desrect={x-cam.X,y-cam.Y,tileSize,tileSize};
	SDL_RenderCopyEx(engine::getInstance()->getRenderer(),m_texturemap[tilesetID],&srcrect,&desrect,0,nullptr,SDL_FLIP_NONE);  
}

bool textureManager::ParseTextures(std::string source)
{
	TiXmlDocument xml;
	xml.LoadFile(source);
	if(xml.Error()){
		std::cout<<"Failed to load: "<<source<<std::endl;
		return false;
	}
	
	TiXmlElement *root=xml.RootElement();
	for(TiXmlElement *e=root->FirstChildElement();e!=nullptr;e=e->NextSiblingElement()){
		if(e->Value()==std::string("texture")){
			std::string id = e->Attribute("id");
			std::string src = e->Attribute("source");
			load(id,src);
		}
	}
	
	return true;
}

void textureManager::drop(std::string id)
{
	SDL_DestroyTexture(m_texturemap[id]);
	m_texturemap.erase(id);
}


void textureManager::clean()
{
	std::map <std::string,SDL_Texture *>::iterator it;
	for(it=m_texturemap.begin();it!=m_texturemap.end();it++)
	{
		SDL_DestroyTexture(it->second);
	}
	m_texturemap.clear();
}


