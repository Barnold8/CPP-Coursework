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
	m_spriteOffset = 6;

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
	m_spriteOffset = 6;
	m_renderHealth = false;

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
	m_spriteOffset = 6;
	m_renderHealth = false;
}

Person::Person(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY, std::string name, int offset) : Entity(pEngine, iWidth, iHeight, useTopLeftFor00, objX, objY) {
	m_personIdle = ImageManager::loadImage(idle, true);
	m_personRunning = ImageManager::loadImage(running, true);
	m_direction = RIGHT;
	m_animState = RUNNING;
	m_runTimer = 0;
	m_runCycle = 0;
	m_runTick = 0;
	m_xPos = pX;
	m_yPos = pY;
	m_spriteOffset = offset;
	m_renderHealth = false;

}

Person::Person(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY, std::string name, int offset, bool renderHealth) : Entity(pEngine, iWidth, iHeight, useTopLeftFor00, objX, objY) {
	m_personIdle = ImageManager::loadImage(idle, true);
	m_personRunning = ImageManager::loadImage(running, true);
	m_health = ImageManager::loadImage("resources/PlayerSprites/heart.png", true);
	m_direction = RIGHT;
	m_animState = RUNNING;
	m_runTimer = 0;
	m_runCycle = 0;
	m_runTick = 0;
	m_xPos = pX;
	m_yPos = pY;
	m_spriteOffset = offset;
	m_renderHealth = m_renderHealth;
	

}

Person::Person(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY, std::string name, int offset, bool renderHealth, int collisionMask) : Entity(pEngine, iWidth, iHeight, useTopLeftFor00, objX, objY) {
	m_personIdle = ImageManager::loadImage(idle, true);
	m_personRunning = ImageManager::loadImage(running, true);
	m_health = ImageManager::loadImage("resources/PlayerSprites/heart.png", true);
	m_direction = RIGHT;
	m_animState = RUNNING;
	m_runTimer = 0;
	m_runCycle = 0;
	m_runTick = 0;
	m_xPos = pX;
	m_yPos = pY;
	m_spriteOffset = offset;
	m_renderHealth = m_renderHealth;
	m_collisionMask = collisionMask;
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
			0x00FF00
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
			0x00FF00
		);

	}

	internalUpdate();

	m_runTimer += 1;
	m_shootTick += 10;


	m_pEngine->drawForegroundString(m_xPos - m_personName.length() * 6, m_yPos - 20, m_personName.c_str(), 0xFFFFFF, M->getFont("resources/Fonts/Monocraft.ttf", 24));
	if (m_runTimer > 200) {
		m_animState = IDLE;
		m_runCycle = 0;
		m_runTick = 0;
	}
	else {
		m_animState = RUNNING;
		m_runCycle += 1;
		if (m_runCycle % 100 == 0) {
			m_runTick += 1;
		}
		if (m_runTick >= m_spriteOffset) {
			m_runTick = 0;
		}

	}

	if (m_renderHealth == true) {
		//m_healthAmount

		int w2 = m_pEngine->getBackgroundSurface()->getSurfaceWidth() / 2 - m_pEngine->getBackgroundSurface()->getSurfaceWidth() / 4;

		for (int i = 0; i < m_healthAmount ; i++) {

			m_health.renderImageWithMask(
				m_pEngine->getForegroundSurface(),
				0,0,w2 + i*40, 10,32,30,0x00FF00
				);

		}

	}


	if (m_xPos > m_pEngine->getBackgroundSurface()->getSurfaceWidth() + 10) {
		m_xPos = -10;
	}
	else if (m_xPos < -30) {
		m_xPos = m_pEngine->getBackgroundSurface()->getSurfaceWidth() + 10;
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


void Person::setCollisionCoords() { // need a way to make sure the collider map lines up properly 

	SimpleImage img = (m_animState == IDLE) ? m_personIdle : m_personRunning;
	int offset = (m_animState == IDLE) ? 1 : 6;
	int a = (m_animState == IDLE) ? 32 * m_direction : ((32 * m_direction) * 6) + (m_runTick * 32);
	std::vector<std::pair<int, int>> pairs;


	for (int i = a; i < (a)+32; i++) {
		for (int y = 1; y < 64; y++) {
			if (img.getPixelColour(i, y) != 0x00FF00) {

				pairs.push_back(std::make_pair(i, y + m_yPos));
			}
		}
	}
	m_collisionCoords = pairs;

	//

	 //TESTING
	//for (int i = 0; i < getCoords().size(); i++) { // go through all coords and render for testing
	//	m_pEngine->lockBackgroundForDrawing();
	//	//m_pEngine->rawSetBackgroundPixel(m_collisionCoords[i].first, m_collisionCoords[i].second, 0xFFFFFF);
	//	m_pEngine->rawSetForegroundPixel((m_collisionCoords[i].first + m_xPos - ((32 * m_direction) * offset) + (m_runTick * 32))
	//		- (32 * m_runTick) - 32 * m_runTick,


	//		m_collisionCoords[i].second, 0x00CCFF);
	//	m_pEngine->unlockBackgroundForDrawing();
	//}
	 //TESTING

}

//
//std::vector<std::pair<int, int>> Person::getCoords() { return m_collisionCoords; }


void Person::internalUpdate() {

	setCollisionCoords(); // this may be causing frame stuttering? See entity definition for more details on overall impact
}
