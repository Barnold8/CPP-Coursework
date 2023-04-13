#include "header.h"
#include "Player.h"
#include "BaseEngine.h"
#include "Office_Apocalypse.h"
#include "Projectile.h"

Player::Player(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running) : Person(pEngine,  iWidth,iHeight, useTopLeftFor00, objX,  objY, idle, running){

    m_personIdle = ImageManager::loadImage("resources/PlayerSprites/Idle.png", true);
	m_personRunning = ImageManager::loadImage("resources/PlayerSprites/Run.png", true);
	m_direction = RIGHT;
	m_animState = RUNNING;
	m_runTimer  = 0; 
	m_runCycle  = 0;
	m_runTick   = 0;
	m_personName = "None";
	m_projSize = 0;
}


Player::Player(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY) : Person(pEngine, iWidth, iHeight, useTopLeftFor00, objX, objY, idle, running ,pX,pY) {

	m_personIdle = ImageManager::loadImage(idle, true);
	m_personRunning = ImageManager::loadImage(running, true);
	m_direction = RIGHT;
	m_animState = RUNNING;
	m_runTimer = 0;
	m_runCycle = 0;
	m_runTick = 0;
	m_xPos = pX;
	m_yPos = pY;
	m_personName = "None";
	m_projSize = 0;

}

Player::Player(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY, std::string name) : Person(pEngine, iWidth, iHeight, useTopLeftFor00, objX, objY, idle, running, pX, pY) {

	m_personIdle = ImageManager::loadImage(idle, true);
	m_personRunning = ImageManager::loadImage(running, true);
	m_direction = RIGHT;
	m_animState = RUNNING;
	m_runTimer = 0;
	m_runCycle = 0;
	m_runTick = 0;
	m_xPos = pX;
	m_yPos = pY;
	m_personName = name;
	m_projSize = 0;

}

Player::Player(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY, std::string name, int health) : Person(pEngine, iWidth, iHeight, useTopLeftFor00, objX, objY, idle, running, pX, pY) {

	m_personIdle = ImageManager::loadImage(idle, true);
	m_personRunning = ImageManager::loadImage(running, true);
	m_direction = RIGHT;
	m_animState = RUNNING;
	m_runTimer = 0;
	m_runCycle = 0;
	m_runTick = 0;
	m_xPos = pX;
	m_yPos = pY;
	m_personName = name;
	m_healthAmount = health;
	m_projSize = 0;

}

void Player::virtKeyDown(int iKeyCode) { // error occurs when obj count goes > 255

	std::cout << "Non null objs " << m_pEngine->getNonNullObjectContentCount() << std::endl;;

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

		//Projectile(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string sprite, Movement dir, int pX, int pY, int speed);
	case 1073741903:
		m_pEngine->storeObjectInArray(m_pEngine->getNonNullObjectContentCount(),new Projectile(m_pEngine, 800, 800, true, 0, 0, "resources/Projectiles/Keyboard3.png", RIGHT, m_xPos, m_yPos, 1));
		break;

	case 1073741905:
		m_pEngine->storeObjectInArray(m_pEngine->getNonNullObjectContentCount(), new Projectile(m_pEngine, 800, 800, true, 0, 0, "resources/Projectiles/Keyboard3.png", DOWN, m_xPos, m_yPos, 1));
		break;

	case 1073741904:
		m_pEngine->storeObjectInArray(m_pEngine->getNonNullObjectContentCount(), new Projectile(m_pEngine, 800, 800, true, 0, 0, "resources/Projectiles/Keyboard3.png", LEFT, m_xPos, m_yPos, 1));
		break;

	case 1073741906:
		m_pEngine->storeObjectInArray(m_pEngine->getNonNullObjectContentCount(), new Projectile(m_pEngine, 800, 800, true, 0, 0, "resources/Projectiles/Keyboard3.png", UP, m_xPos, m_yPos, 1));
		break;
	default:
		break;
	}


}
