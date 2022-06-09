#include "Timer.h"
#include <SDL.h>

timer* timer::s_instance=nullptr;

void timer::tick()
{
	m_deltatime=(SDL_GetTicks()-m_LastTime)*(TARGET_FPS/1000.0f);
	
	if(m_deltatime>TARGET_DELTATIME)
	{
		m_deltatime=TARGET_DELTATIME;
	}
	
	m_LastTime=SDL_GetTicks();
}
