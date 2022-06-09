#ifndef HERO_H
#define HERO_H

#include "Character.h"
#include "Animation.h"
#include "RigidBody.h"
#include "Collider.h"
#include "Vector2D.h"
#include "SeqAnimation.h"

#define JUMP_TIME 15.0f
#define JUMP_FORCE 12.4f

#define RUN_FORCE 4.0f
#define ATTACK_TIME 20.0f

class hero:public character
{
	public:
		hero(properties *prop);
		virtual void draw();
		virtual void update(float dt);
		virtual void clean(); 
		
	private:
		void AnimationState();
		
	private:
		// int m_row,m_frame,m_framecount;
		// int m_animspeed;					// millisecond time for which 1st frame will be on the screen
		bool m_IsRunning=false;
		bool m_IsJumping=false;
		bool m_IsFalling=false;
		bool m_IsGrounded=false;
		bool m_IsAttacking=false;
		bool m_IsCrouching=false;
		
		float m_JumpTime;
		float m_JumpForce;
		float m_AttackTime;
		
		Collider *m_Collider;
		SeqAnimation *m_Animation;
		rigidbody *m_rigidbody;
		vector2D m_LastSafePosition;
};

#endif
