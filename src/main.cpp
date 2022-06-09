#include "engine.h"
#include "Timer.h"
//#include "engine.cpp"

int main(int argc,char *args[])
{
	engine::getInstance()->init();
	while(engine::getInstance()->isRunning())
	{
		engine::getInstance()->Events();
		engine::getInstance()->Update();
		engine::getInstance()->Render();
		timer::getInstance()->tick();
	}
	engine::getInstance()->clean();
}

