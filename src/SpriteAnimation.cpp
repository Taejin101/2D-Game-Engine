#include "SpriteAnimation.h"
#include "Graphics.h"

void SpriteAnimation::Update(float dt)
{
		m_CurrentFrame=(SDL_GetTicks()/m_Speed)%m_FrameCount;				// renders the frame for m_animspeed milliseconds on the screen
}

void SpriteAnimation::Draw(float x,float y,int width,int height,float xScale,float yScale,SDL_RendererFlip flip)
{
		textureManager::getInstance()->drawFrame(m_TextureID,x,y,width,height,m_SpriteRow,m_CurrentFrame,flip);
}

void SpriteAnimation::Setprops(std::string textureid,int spriterow,int framecount,int speed)
{
	m_Speed=speed;
	m_TextureID=textureid;
	m_SpriteRow=spriterow;
	m_FrameCount=framecount;
}
