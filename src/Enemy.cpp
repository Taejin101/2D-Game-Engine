#include "Enemy.h"

Enemy::Enemy (properties *props):character(props){
	m_RigidBody = new rigidbody();
	m_RigidBody->set_gravity(3.5);
	m_Collider=new Collider();
	
	m_Animation=new SeqAnimation(false);
	m_Animation->Parse("assets/enemy.aml");
	m_Animation->SetCurrSeq("boss_appear");
}

void Enemy::draw(){
	m_Animation->DrawFrame(m_transform->X, m_transform->Y, 0.3f,0.3f,m_flip);
}

void Enemy::update(float dt){
	m_RigidBody->update(dt);
	m_LastSafePosition.X=m_transform->X;
	m_transform->X += m_RigidBody->get_position().X;
	m_Collider->Set(m_transform->X, m_transform->Y,140,100);
	
	if(CollisionHandler::GetInstance()->MapCollision(m_Collider->Get())){
		m_transform->X=m_LastSafePosition.X;
	}
	
	m_RigidBody->update(dt);
	m_LastSafePosition.Y=m_transform->Y;
	m_transform->Y += m_RigidBody->get_position().Y;
	m_Collider->Set(m_transform->X, m_transform->Y,140,100);
	
	if(CollisionHandler::GetInstance()->MapCollision(m_Collider->Get())){
		m_transform->Y=m_LastSafePosition.Y;
	}
	
	m_Animation->Update(dt);
	
	if(m_Animation->IsEnded()){
		m_Animation->SetRepeat(true);
		m_Animation->SetCurrSeq("boss_idle");
	}
}

void Enemy::clean(){
}


