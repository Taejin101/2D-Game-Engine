#ifndef SPRITEANIMATION_H
#define SPRITEANIMATION_H

#include <string>
#include <SDL.h>
#include "Animation.h"

class SpriteAnimation : public Animation{
	
	public:
		SpriteAnimation(bool repeat=true);
		
		virtual void Update(float dt);
		void Draw(float x,float y,int spritewidth,int spriteheight,float xScale=1,float yScale=1,SDL_RendererFlip Flip=SDL_FLIP_NONE);
		void Setprops(std::string textureid,int spriterow,int framecount,int speed);
		
		int GetCurrFrame(){return m_CurrentFrame;}
		
		int GetCurrSpriteRow(){return m_SpriteRow;}
		void SetSpriteRow(int row){m_SpriteRow=row;}
		void IncrSpriteRow(){m_SpriteRow++;}
		void DecrSpriteRow(){m_SpriteRow--;}
		
	private:
		int m_Speed;
		int m_SpriteRow;
		int m_FrameCount;
		std::string m_TextureID;
};

#endif
