#pragma once
#include "Entity.h"


//NOTE: player running frame per direction is 6

class Person : public Entity {


protected:

	std::string m_personName;		// Allows name above person to be different
	SimpleImage m_personIdle;
	SimpleImage m_personRunning;
	Movement	m_direction;
	animState	m_animState;
	int			m_runTimer;			// time after last key update
	int			m_runCycle;			// number counted to tick over next anim frame
	int			m_runTick;			// nunber to use in animation frame formula
	int			m_healthAmount;
	int			m_shootTick;		// Used so players/enemies can only shoot every n ticks
	int			m_spriteOffset;


public:

	Person(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running);

	Person(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY);

	Person(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY, std::string name);

	Person(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY, std::string name, int offset);

	virtual void virtDraw() override;

	void virtKeyDown(int iKeyCode) override;

};

