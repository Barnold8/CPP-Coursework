#include "header.h"
#include "Person.h"
#include "BaseEngine.h"
#include "Office_Apocalypse.h"

Person::Person(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running) : Entity(pEngine, iWidth, iHeight, useTopLeftFor00, objX, objY) {

	m_personIdle = ImageManager::loadImage(idle, true);
	m_personRunning = ImageManager::loadImage(running, true);
	m_direction = RIGHT;
	m_animState = RUNNING;
	m_runTimer = 0;
	m_runCycle = 0;
	m_runTick = 0;
}

Person::Person(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY) : Entity(pEngine, iWidth, iHeight, useTopLeftFor00, objX, objY) {
	
	m_personIdle = ImageManager::loadImage(idle, true);
	m_personRunning = ImageManager::loadImage(running, true);
	m_direction = RIGHT;
	m_animState = RUNNING;
	m_runTimer = 0;
	m_runCycle = 0;
	m_runTick = 0;
	m_xPos = pX;
	m_yPos = pY;

}

Person::Person(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY, std::string name) : Entity(pEngine, iWidth, iHeight, useTopLeftFor00, objX, objY) {

	m_personIdle = ImageManager::loadImage(idle, true);
	m_personRunning = ImageManager::loadImage(running, true);
	m_direction = RIGHT;
	m_animState = RUNNING;
	m_runTimer = 0;
	m_runCycle = 0;
	m_runTick = 0;
	m_xPos = pX;
	m_yPos = pY;

}

void Person::virtDraw() {


	Office_Apocalypse* M = dynamic_cast<Office_Apocalypse*>(m_pEngine);


	if (m_animState == IDLE) {

		m_personIdle.renderImageWithMask(
			m_pEngine->getForegroundSurface(),
			32 * m_direction,
			1,
			m_xPos,
			m_yPos,
			31, 64,
			0x000000
		);

	}
	else if (m_animState == RUNNING) {

		m_personRunning.renderImageWithMask(
			m_pEngine->getForegroundSurface(),
			((32 * m_direction) * 6) + (m_runTick * 32),
			1,
			m_xPos,
			m_yPos,
			31, 64,
			0x000000
		);

	}
	m_runTimer += 1;


	m_pEngine->drawForegroundString(m_xPos - m_personName.length() * 6, m_yPos - 20, m_personName.c_str(), 0xFFFFFF, M->getFont("resources/Fonts/Monocraft.ttf", 24));
	if (m_runTimer > 200) {
		m_animState = IDLE;
		m_runCycle = 0;
		m_runTick = 0;
	}
	else {
		m_animState = RUNNING;
		m_runCycle += 1;
		if (m_runCycle % 200 == 0) {
			m_runTick += 1;
		}
		if (m_runTick >= 6) {
			m_runTick = 0;
		}

	}

	//std::cout << "animState : " << m_animState << " | RunCycle: " << m_runCycle << " | Runtick: " << m_runTick << std::endl;

}


void Person::virtKeyDown(int iKeyCode) {

	switch (iKeyCode) {

	case 100:
		m_xPos += m_speed;
		m_direction = RIGHT;
		m_runTimer = 0;
		break;
	case 97:
		m_xPos -= m_speed;
		m_direction = LEFT;
		m_runTimer = 0;
		break;
	case 115:
		m_yPos += m_speed;
		m_direction = DOWN;
		m_runTimer = 0;
		break;
	case 119:
		m_yPos -= m_speed;
		m_direction = UP;
		m_runTimer = 0;
		break;
	default:
		break;
	}


}