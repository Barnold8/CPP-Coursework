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

	if (!(m_pEngine->isPaused())) {
		

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
		m_pEngine->drawForegroundString(m_xPos - m_expression.length() * 6, m_yPos - 60, m_expression.c_str(), 0x3b3a3a, M->getFont("resources/Fonts/Monocraft.ttf", 28));
		m_pEngine->drawForegroundString(m_xPos - m_expression.length() * 6, m_yPos - 60, m_expression.c_str(), 0x242222, M->getFont("resources/Fonts/Monocraft.ttf", 30));
		m_pEngine->drawForegroundString(m_xPos - m_expression.length() * 6, m_yPos - 60, m_expression.c_str(), 0xc92d18, M->getFont("resources/Fonts/Monocraft.ttf", 24));


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
			if (m_runTick >= m_spriteOffset) {
				m_runTick = 0;
			}

		}

		if (m_renderHealth == true) {
			//m_healthAmount

			int w2 = m_pEngine->getBackgroundSurface()->getSurfaceWidth() / 2 - m_pEngine->getBackgroundSurface()->getSurfaceWidth() / 4;

			for (int i = 0; i < m_healthAmount; i++) {

				m_health.renderImageWithMask(
					m_pEngine->getForegroundSurface(),
					0, 0, w2 + i * 40, 10, 32, 30, 0x00FF00
				);

			}
			if (m_healthAmount <= 0) { // if you keep starting a new game/load game state it will alloc more and more memory lol

				M->getStateMaster()->changeState(std::make_shared<Lose>(m_pEngine));
				return;
			}

			if (m_charged == false) {
				m_sprintIcon.renderImageWithMask(
					m_pEngine->getForegroundSurface(),
					0, 0, 100, 10, 50, m_sprintTimer / 100, 0x00FF00
				);

			}
			else {
				m_sprintIcon.renderImageWithMask(
					m_pEngine->getForegroundSurface(),
					0, 0, 100, 10, 50, 50, 0x00FF00
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
	else {
	
		if (m_pEngine->isPaused()) {
			
			m_pEngine->lockForegroundForDrawing();
			m_pEngine->drawForegroundString(260, 380, "PAUSED", 0xFFFFFF, m_pEngine->getFont("resources/Fonts/Monocraft.ttf", 64));
			m_pEngine->drawForegroundString(200, 580, "Press esc to unpause", 0xFFFFFF, m_pEngine->getFont("resources/Fonts/Monocraft.ttf", 32));
			m_pEngine->drawForegroundString(230, 740, "Press S to save...", 0xFFFFFF, m_pEngine->getFont("resources/Fonts/Monocraft.ttf", 32));
			m_pEngine->unlockForegroundForDrawing();

		}
	
	}


}

bool Person::internalUpdate() { return false; }

void Person::virtKeyDown(int iKeyCode) {

	if (!(m_pEngine->isPaused())) {
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



}

void Person::virtMouseDown(int iButton, int iX, int iY) {


}


int Person::getColAtPixel(int x, int y) {

	
	return (m_animState == IDLE) ? m_personIdle.getPixelColour(x-m_xPos,y-m_yPos) : m_personRunning.getPixelColour(x - m_xPos, y - m_yPos);


}

rect Person::getRect() {

	return rect{ m_xPos,m_yPos,32,64};

}




DATA Person::getData() {

	DATA d = {

		m_xPos,
		m_yPos,
		m_speed,
		m_collided,
		m_collisionCoolDown, 
		m_personName,
		m_direction,
		m_animState,
		m_runTimer,
		m_runCycle,
		m_runTick,
		m_healthAmount,
		m_spriteOffset,
		m_collisionMask,
		m_renderHealth,
		m_deathCount,
		nullptr,
		0


	};
	return d;


}


void Person::setDirection(Movement dir) { m_direction = dir; }

void Person::setAnimState(animState animstate) { m_animState = animstate; }

void Person::setRunTimer(int timer) { m_runTimer = timer; }

void Person::setRunCycle(int cycle) { m_runCycle = cycle; }

void Person::setRunTick(int tick) { m_runTick = tick; }

void Person::setHealth(int health) { m_healthAmount = health; }

void Person::setSpeed(int speed) { m_speed = speed; }

void Person::setCollCoolDown(int cooldown) { m_collisionCoolDown = cooldown; }