#include "engine.h"
#include "Inputs.h"
#include <iostream>

input* input::s_instance=nullptr;

input::input()
{
	m_keystate=SDL_GetKeyboardState(nullptr);
}

void input::listen()
{
	SDL_Event event;
	
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT:	
						engine::getInstance()->quit();
						break;
			case SDL_KEYDOWN:
						key_down();
						break;
			case SDL_KEYUP:
						key_up();
						break;
		}
	}
}

bool input::get_keydown(SDL_Scancode key)
{
	if(m_keystate[key]==1)
		return true;
	return false;
}

void input::key_up()
{
	m_keystate=SDL_GetKeyboardState(nullptr);
}

void input::key_down()
{
	m_keystate=SDL_GetKeyboardState(nullptr);
}

// returns 1 or -1 according to the direction of key pressed
int input::GetAxisKey(Axis axis)
{
	switch(axis)
	{
		case HORIZONTAL:
			if(get_keydown(SDL_SCANCODE_D)||get_keydown(SDL_SCANCODE_RIGHT))
				return 1;
			if(get_keydown(SDL_SCANCODE_A)||get_keydown(SDL_SCANCODE_LEFT))
				return -1;
			break;
		
		case VERTICAL:
			if(get_keydown(SDL_SCANCODE_W)||get_keydown(SDL_SCANCODE_UP))
				return 1;
			if(get_keydown(SDL_SCANCODE_S)||get_keydown(SDL_SCANCODE_DOWN))
				return -1;
			break;
		
		default:
			return 0;
	}
}
