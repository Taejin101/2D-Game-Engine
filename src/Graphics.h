#ifndef GRAPHICS_H
#define GRAPHICS_H

#include"SDL.h"
#include<string>
#include<map>
#include <iostream>


class textureManager{
	private:
		textureManager(){}
		static textureManager *s_instance;
		std::map <std::string,SDL_Texture*> m_texturemap;
	
	public:
		static textureManager* getInstance(){
			return (s_instance=(s_instance!=nullptr)?s_instance:new textureManager);
		}
		
		bool load(std::string id,std::string filename);
		bool ParseTextures(std::string source);
		void drop(std::string id);
		void clean();
		
		void draw(std::string id,int x,int y,int w,int h,SDL_RendererFlip flip=SDL_FLIP_NONE,float scaleX=1.0f,float scaleY=1.0f,float rotation=0.0f, float speedRatio=1.0f);										// draws static images 
		void drawFrame(std::string id,int x,int y,int w,int h,int row,int frame,SDL_RendererFlip flip=SDL_FLIP_NONE,float scaleX=1.0f,float scaleY=1.0f,float rotation=0.0f, float speedRatio=1.0f); // draws animated images
		void drawTile(std::string tilesetID,int tileSize,int x,int y,int row,int frame,float speedRatio=1.0f);
		
		SDL_Texture* GetTexture(std::string id){return m_texturemap[id];}
};

#endif
