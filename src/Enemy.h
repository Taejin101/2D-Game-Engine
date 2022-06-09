#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include "RigidBody.h"
#include "Collider.h"
#include "CollisionHandler.h"
#include "SeqAnimation.h"
#include "SpriteAnimation.h"

class Enemy: public character{
	
	public:
		Enemy (properties *props);
		
		virtual void draw();
		virtual void clean();
		virtual void update(float dt);
		
	private:
		Collider *m_Collider;
		rigidbody *m_RigidBody;
		SeqAnimation *m_Animation;
		vector2D m_LastSafePosition;
};

#endif
