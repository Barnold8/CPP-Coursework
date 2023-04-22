#pragma once

#include "DisplayableObject.h"
#include "Image.h"				// Image in here so we dont have to worry about including it later on for sub classes
#include <vector>


class Projectile; // avoids circular dependency in DATA struct


enum Movement {

	RIGHT,
	UP,
	LEFT,
	DOWN,
	NONE,

};

enum animState {

	IDLE,
	RUNNING,

};

struct DATA {

	// BOTH
	int _m_xPos;
	int _m_yPos;
	int _m_speed;
	bool _m_collided; // May not even be used lol
	int	 _m_collisionCoolDown;
	// BOTH

	// Person
	std::string _m_personName;									 // Allows name above person to be different
	Movement	_m_direction;									 // enum for the player looking direction
	animState	_m_animState;									 // enum for the animation state
	int			_m_runTimer;										 // time after last key update
	int			_m_runCycle;										 // number counted to tick over next anim frame
	int			_m_runTick;										 // number to use in animation frame formula
	int			_m_healthAmount;									 // amount of health user has
	int			_m_spriteOffset;
	int			_m_collisionMask;								 // the colour used to say what is a valid pixel for collision
	bool		_m_renderHealth;
	// Person

	// Projectile
	Projectile* _m_prev;
	int			_m_tick;
	// Projectile
};



class Entity : public DisplayableObject {

protected:

	int m_xPos;
	int m_yPos;
	int m_speed;
	bool m_collided; // May not even be used lol
	int	 m_collisionCoolDown;

public:


	Entity(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY);

	virtual void virtDraw() override;

	virtual void virtKeyDown(int iKeyCode) override;

	virtual bool internalUpdate();

	virtual DATA getData() = 0;

	void setCollided(bool c);

};

