#include "header.h"
#include "Person.h"
#include "BaseEngine.h"
#include "Office_Apocalypse.h"

Person::Person(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running) : Entity(pEngine, iWidth, iHeight, useTopLeftFor00, objX, objY) {

	m_personIdle = ImageManager::loadImage(idle, true);
	m_personRunning = ImageManager::loadImage(running, true);
	m_shield = ImageManager::loadImage("resources/PlayeSprites/Shield.png", true);
	m_direction = RIGHT;
	m_animState = RUNNING;
	m_runTimer = 0;
	m_runCycle = 0;
	m_runTick = 0;
	m_collisionCoolDown = 0;
	m_spriteOffset = 6;
	m_collided = false;



}

Person::Person(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY) : Entity(pEngine, iWidth, iHeight, useTopLeftFor00, objX, objY) {
	
	m_personIdle = ImageManager::loadImage(idle, true);
	m_personRunning = ImageManager::loadImage(running, true);
	m_shield = ImageManager::loadImage("resources/PlayerSprites/Shield.png", true);
	m_direction = RIGHT;
	m_animState = RUNNING;
	m_runTimer = 0;
	m_runCycle = 0;
	m_runTick = 0;
	m_collisionCoolDown = 0;
	m_xPos = pX;
	m_yPos = pY;
	m_spriteOffset = 6;
	m_renderHealth = false;
	m_collided = false;

}

Person::Person(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY, std::string name) : Entity(pEngine, iWidth, iHeight, useTopLeftFor00, objX, objY) {

	m_personIdle = ImageManager::loadImage(idle, true);
	m_personRunning = ImageManager::loadImage(running, true);
	m_shield = ImageManager::loadImage("resources/PlayerSprites/Shield.png", true);
	m_direction = RIGHT;
	m_animState = RUNNING;
	m_runTimer = 0;
	m_runCycle = 0;
	m_runTick = 0;
	m_collisionCoolDown = 0;
	m_xPos = pX;
	m_yPos = pY;
	m_spriteOffset = 6;
	m_renderHealth = false;
	m_collided = false;
}

Person::Person(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY, std::string name, int offset) : Entity(pEngine, iWidth, iHeight, useTopLeftFor00, objX, objY) {
	m_personIdle = ImageManager::loadImage(idle, true);
	m_personRunning = ImageManager::loadImage(running, true);
	m_shield = ImageManager::loadImage("resources/PlayerSprites/Shield.png", true);
	m_direction = RIGHT;
	m_animState = RUNNING;
	m_runTimer = 0;
	m_runCycle = 0;
	m_runTick = 0;
	m_collisionCoolDown = 0;
	m_xPos = pX;
	m_yPos = pY;
	m_spriteOffset = offset;
	m_renderHealth = false;
	m_collided = false;

}

Person::Person(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY, std::string name, int offset, bool renderHealth) : Entity(pEngine, iWidth, iHeight, useTopLeftFor00, objX, objY) {
	m_personIdle = ImageManager::loadImage(idle, true);
	m_personRunning = ImageManager::loadImage(running, true);
	m_health = ImageManager::loadImage("resources/PlayerSprites/heart.png", true);
	m_shield = ImageManager::loadImage("resources/PlayerSprites/Shield.png", true);
	m_direction = RIGHT;
	m_animState = RUNNING;
	m_runTimer = 0;
	m_runCycle = 0;
	m_runTick = 0;
	m_collisionCoolDown = 0;
	m_xPos = pX;
	m_yPos = pY;
	m_spriteOffset = offset;
	m_renderHealth = m_renderHealth;
	m_collided = false;
	

}

Person::Person(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY, std::string name, int offset, bool renderHealth, int collisionMask) : Entity(pEngine, iWidth, iHeight, useTopLeftFor00, objX, objY) {
	m_personIdle = ImageManager::loadImage(idle, true);
	m_personRunning = ImageManager::loadImage(running, true);
	m_health = ImageManager::loadImage("resources/PlayerSprites/heart.png", true);
	m_shield = ImageManager::loadImage("resources/PlayerSprites/Shield.png", true);
	m_direction = RIGHT;
	m_animState = RUNNING;
	m_runTimer = 0;
	m_runCycle = 0;
	m_runTick = 0;
	m_collisionCoolDown = 0;
	m_xPos = pX;
	m_yPos = pY;
	m_spriteOffset = offset;
	m_renderHealth = m_renderHealth;
	m_collisionMask = collisionMask;
	m_collided = false;
}

void Person::virtDraw() {


	Office_Apocalypse* M = dynamic_cast<Office_Apocalypse*>(m_pEngine);
	
	internalUpdate();

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

	// collidedID is true whenever an ID > 0 since 1 is boolean true, thus the value can have two uses


	m_runTimer += 1;
	m_collisionCoolDown += 1;

	m_pEngine->drawForegroundString(m_xPos - m_personName.length() * 6, m_yPos - 20, m_personName.c_str(), 0xFFFFFF, M->getFont("resources/Fonts/Monocraft.ttf", 24));
	if (m_runTimer > 200) {
		m_animState = IDLE;
		m_runCycle = 0;
		m_runTick = 0;
	}
	else {
		m_animState = RUNNING;
		m_runCycle += 1;
		if (m_runCycle % 200 == 0 ) {
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

bool Person::internalUpdate() { return false; }

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

int Person::getColAtPixel(int x, int y) {

	
	return (m_animState == IDLE) ? m_personIdle.getPixelColour(x-m_xPos,y-m_yPos) : m_personRunning.getPixelColour(x - m_xPos, y - m_yPos);


}

rect Person::getRect() {

	return rect{ m_xPos,m_yPos,32,64};

}