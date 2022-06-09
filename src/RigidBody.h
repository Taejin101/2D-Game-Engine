//#include "Vector2D.h"

#ifndef RIGID_BODY_H
#define RIGID_BODY_H

#define UNIT_MASS 1.0f
#define GRAVITY 9.8f

#define FORWARD 1
#define BACKWARD -1

#define UPWARD -1
#define DOWNWARD 1

class rigidbody{
	public:
			rigidbody()
			{
				m_mass=UNIT_MASS;
				m_gravity=GRAVITY;
			}
			
			// setter for mass & gravity
			inline void set_mass(float mass){m_mass=mass;}
			inline void set_gravity(float gravity){m_gravity=gravity;}
			
			// apply force
			inline void apply_force(vector2D f){m_force=f;}
			inline void apply_forceX(float fx){m_force.X=fx;}
			inline void apply_forceY(float fy){m_force.Y=fy;}
			inline void unset_force(){m_force=vector2D(0,0);}
			
			// apply friction
			inline void apply_friction(vector2D fr){m_friction=fr;}
			inline void unset_friction(){m_friction=vector2D(0,0);}
			
			// getters
			inline float get_mass(){return (m_mass);}
			inline vector2D get_acceleration(){return (m_acceleration);}
			inline vector2D get_velocity(){return (m_velocity);}
			inline vector2D get_position(){return (m_position);}
			
			// update methods
			void update(float dt)
			{
				m_acceleration.X=(m_force.X+m_friction.X)/m_mass;
				m_acceleration.Y=(m_gravity+m_force.Y)/m_mass;
				m_velocity=m_acceleration*dt;
				m_position=m_velocity*dt;
			}
	
	private:
		float m_mass;
		float m_gravity;
		
		vector2D m_force;
		vector2D m_friction;
		
		vector2D m_position;
		vector2D m_velocity;
		vector2D m_acceleration;
};

#endif
