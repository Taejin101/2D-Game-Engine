#ifndef INPUT_H
#define INPUT_H

#include "SDL.h"

enum Axis{HORIZONTAL, VERTICAL};

class input{
	public:
		static input* getInstance()
		{
			return (s_instance=(s_instance!=nullptr)?s_instance:new input);
		}
		
		void listen();
		bool get_keydown(SDL_Scancode key);
		
		int GetAxisKey(Axis axis);
		
	private:
		input();
		void key_up();
		void key_down();
		const Uint8 *m_keystate;
		static input *s_instance;
};

#endif
