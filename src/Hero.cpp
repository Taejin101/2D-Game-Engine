#include "Hero.h"
#include "Graphics.h"
#include "SDL.h"
#include "Inputs.h"
#include "Camera.h"
#include "engine.h"
#include "CollisionHandler.h"
#include "ObjectFactory.h"

static Registrar<hero> registrar("PLAYER");

hero::hero(properties *prop):character(prop)
{ 
	m_JumpTime=JUMP_TIME;
	m_JumpForce=JUMP_FORCE;
	m_AttackTime=ATTACK_TIME;
	
	m_Collider = new Collider();
	m_Collider->SetBuffer(-20,0,0,0);
	
	m_rigidbody = new rigidbody();
	m_rigidbody->set_gravity(3.5f);
	
	m_Animation = new SeqAnimation(true);
	m_Animation->Parse("assets/animation.aml");
	m_Animation->SetCurrSeq("hero_attack");
	m_Animation->SetRepeat(false);
}

void hero::draw()
{
	// textureManager::getInstance()->drawFrame(m_textureid,m_transform->X,m_transform->Y,m_width,m_height,m_row,m_frame,m_flip);
	m_Animation->DrawFrame(m_transform->X,m_transform->Y,0.5,0.5,m_flip);
//	m_Collider->Draw();
}

void hero::update(float dt)
{
//	m_animation->setprops("player_run",0,4,100);			for idle state load here
	m_rigidbody->unset_force();
	
	// for running
	if(input::getInstance()->GetAxisKey(HORIZONTAL)==FORWARD && !m_IsAttacking){
		m_rigidbody->apply_forceX(FORWARD*RUN_FORCE);
		m_flip=SDL_FLIP_NONE;
		m_IsRunning=true;
	}
	
	if(input::getInstance()->GetAxisKey(HORIZONTAL)==BACKWARD && !m_IsAttacking){
		m_rigidbody->apply_forceX(BACKWARD*RUN_FORCE);
		m_flip=SDL_FLIP_HORIZONTAL;
		m_IsRunning=true;
	}
	
	// crouch
	if(input::getInstance()->get_keydown(SDL_SCANCODE_S)){
		m_rigidbody->unset_force();
		m_IsCrouching=true;
	}
	
	// attack
	if(input::getInstance()->get_keydown(SDL_SCANCODE_K)){
		m_rigidbody->unset_force();
		m_IsAttacking=true;
	}
	
	// Jump 
	if(input::getInstance()->get_keydown(SDL_SCANCODE_J)&& m_IsGrounded)
	{
		m_IsJumping=true;
		m_IsGrounded=false;
		m_rigidbody->apply_forceY(UPWARD*m_JumpForce);
	}
	
	if(input::getInstance()->get_keydown(SDL_SCANCODE_J) && m_IsJumping && m_JumpTime>0)
	{
		m_JumpTime-=dt;
		m_rigidbody->apply_forceY(UPWARD*m_JumpForce);
	}
	else
	{
		m_IsJumping=false;
		m_JumpTime=JUMP_TIME;
	}
	
	// fall
	if(m_rigidbody->get_velocity().Y > 0 && !m_IsGrounded){
		m_IsFalling=true;
	}
	else{
		m_IsFalling=false;
	}
	
	// attack time
	if(m_IsAttacking&&m_AttackTime>0){
		m_AttackTime-=dt;
	}   
	else{
		m_IsAttacking=false;
		m_AttackTime=ATTACK_TIME;
	}
	
	m_rigidbody->update(dt);										
	m_LastSafePosition.X=m_transform->X;
	m_transform->X+=m_rigidbody->get_position().X;
	m_Collider->Set(m_transform->X,m_transform->Y, 20, 60);
	
	if(CollisionHandler::GetInstance()->MapCollision(m_Collider->Get()))
		m_transform->X=m_LastSafePosition.X;
	
	m_rigidbody->update(dt);										// updates the position, velocity and acceleration
	m_LastSafePosition.Y=m_transform->Y; 
	m_transform->Y+=m_rigidbody->get_position().Y;
	m_Collider->Set(m_transform->X,m_transform->Y,20,60);
	
	if(CollisionHandler::GetInstance()->MapCollision(m_Collider->Get()))
	{
		m_IsGrounded=true;
		m_transform->Y=m_LastSafePosition.Y;
	}
	else
	{
		m_IsGrounded=false;
	}
		
	
	m_Origin->X=m_transform->X+m_width/2;
	m_Origin->Y=m_transform->Y+m_height/2;
	
	AnimationState();
	m_Animation->Update(dt);											// updates the frame
}

void hero::AnimationState(){										// pending
	
	// idling	
	m_Animation->SetCurrSeq("hero_idle");
	m_Animation->SetRepeat(true);
	
	// running
	if(m_IsRunning){
		m_IsRunning=false;
		m_Animation->SetCurrSeq("hero_run");
	}

//	// crouching
//	if(m_IsCrouching)
//		m_Animation->setprops(m_textureid,0,7,100);
//	
	// jumping
	if(m_IsJumping){
		m_Animation->SetCurrSeq("hero_jump");
	}
	
//	if(m_IsFalling)
//		m_Animation->setprops(m_textureid,0,7,100);
//
	// Attacking		
	if(m_IsAttacking)
	{
		m_Animation->SetCurrSeq("hero_attack");
	}
	
}

void hero::clean()
{
	textureManager::getInstance()->drop(m_textureid);
}
