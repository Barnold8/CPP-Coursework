#pragma once
#include "Entity.h"
#include "Collider.h"
#include <vector>

//NOTE: player running frame per direction is 6

class Person : public Entity, public Collider {


protected:

	std::string m_personName;									 // Allows name above person to be different
	SimpleImage m_personIdle;									 // stores spritesheets for idle anims
	SimpleImage m_personRunning;								 // stores spritesheets for running anims
	SimpleImage m_health;										 // stores spritesheets for health
	Movement	m_direction;									 // enum for the player looking direction
	animState	m_animState;									 // enum for the animation state
	int			m_runTimer;										 // time after last key update
	int			m_runCycle;										 // number counted to tick over next anim frame
	int			m_runTick;										 // number to use in animation frame formula
	int			m_healthAmount;									 // amount of health user has
	int			m_shootTick;									 // Used so players/enemies can only shoot every n ticks
	int			m_spriteOffset;
	int			m_collisionMask;								 // the colour used to say what is a valid pixel for collision
	bool		m_renderHealth;
	

public:

	Person(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running);

	Person(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY);

	Person(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY, std::string name);

	Person(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY, std::string name, int offset);

	Person(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY, std::string name, int offset, bool renderHealth);
	
	Person(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY, std::string name, int offset, bool renderHealth, int collisionMask);

	virtual void isCollided();

	virtual void virtDraw() override;

	void virtKeyDown(int iKeyCode) override;

	int getColAtPixel(int x, int y) override;

	rect getRect() override;


};

