const int TARGET_FPS = 60;
const float TARGET_DELTATIME = 1.5f; 

class timer{
	public:
		void tick();
		inline float GetDeltaTime(){return m_deltatime;}
		inline static timer* getInstance(){return (s_instance=(s_instance!=nullptr)?s_instance:new timer());}
	private:
		timer(){};
		static timer *s_instance;
		float m_deltatime;
		float m_LastTime;
};
