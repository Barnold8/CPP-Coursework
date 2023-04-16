#include "header.h"
#include "Player.h"
#include "BaseEngine.h"
#include "Office_Apocalypse.h"
#include "Projectile.h"
#include <vector>

Player::Player(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running) : Person(pEngine,  iWidth,iHeight, useTopLeftFor00, objX,  objY, idle, running){

    m_personIdle = ImageManager::loadImage("resources/PlayerSprites/Idle.png", true);
	m_personRunning = ImageManager::loadImage("resources/PlayerSprites/Run.png", true);
	m_direction = RIGHT;
	m_animState = RUNNING;
	m_runTimer  = 0; 
	m_runCycle  = 0;
	m_runTick   = 0;
	m_personName = "None";
	m_projCap = 10;	// 10 projectiles from the player
	m_projStart = 1; // players projectiles start from 1 in object array
	m_projSize = 0;
	m_replace = false;
	m_shootTick = 0;
	m_renderHealth = false;
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
	m_projCap = 10;	// 10 projectiles from the player
	m_projStart = 1; // players projectiles start from 1 in object array
	m_projSize = 0;
	m_replace = false;
	m_shootTick = 0;
	m_renderHealth = false;
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
	m_projCap = 10;	// 10 projectiles from the player
	m_projStart = 1; // players projectiles start from 1 in object array
	m_projSize = 0;
	m_replace = false;
	m_shootTick = 0;
	m_renderHealth = false;

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
	m_projCap = 10;	// 10 projectiles from the player
	m_projStart = 1; // players projectiles start from 1 in object array
	m_projSize = 0;
	m_replace = false;
	m_shootTick = 0;
	m_renderHealth = false;

}

Player::Player(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY, std::string name, int health, bool renderHealth) : Person(pEngine, iWidth, iHeight, useTopLeftFor00, objX, objY, idle, running, pX, pY) {

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
	m_personName = name;
	m_healthAmount = health;
	m_projCap = 10;	// 10 projectiles from the player
	m_projStart = 1; // players projectiles start from 1 in object array
	m_projSize = 0;
	m_replace = false;
	m_shootTick = 0;
	m_renderHealth = renderHealth;

}

Player::Player(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY, std::string name, int health, int offset, bool renderHealth) : Person(pEngine, iWidth, iHeight, useTopLeftFor00, objX, objY, idle, running, pX, pY) {

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
	m_personName = name;
	m_healthAmount = health;
	m_projCap = 10;	// 10 projectiles from the player
	m_projStart = 1; // players projectiles start from 1 in object array
	m_projSize = 0;
	m_replace = false;
	m_shootTick = 0;
	m_renderHealth = renderHealth;



}
void Player::virtKeyDown(int iKeyCode) { // error occurs when obj count goes > 255
	

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
	}

	//Projectile(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string sprite, Movement dir, int pX, int pY, int speed);

	switch (iKeyCode) {

	case SDLK_1:
		setHealth(getHealth() - 1);
		break;

	case SDLK_2:
		setHealth(getHealth() + 1);
		break;

	case SDLK_3:
		isCollided();
		break;

	case SDLK_4:
		/*std::cout << getImgXY().first << " " << getImgXY().second << std::endl;*/
		break;

	case 1073741903:
		addProjectile(RIGHT);
		break;

	case 1073741905:
		addProjectile(DOWN);
		break;

	case 1073741904:
		addProjectile(LEFT);
		break;

	case 1073741906:
		addProjectile(UP);
		break;
	default:
		break;
	}

}

void Player::addProjectile( Movement direction) { // Need to have switch case for directions so spawn location for keyboards makes sense

	int distance = -1;

	if (m_projSize != 0) { // gets distance of previous object
		DisplayableObject* d = m_pEngine->getDisplayableObject(m_projStart + m_projSize - 1);
		Projectile* p = dynamic_cast<Projectile*>(d);
		distance = p->distance(m_xPos, m_yPos);

		d = m_pEngine->getDisplayableObject(m_projStart + m_projSize);

		if (distance > 100){
			if (d != nullptr) {
				delete d;
			}
			
			m_pEngine->storeObjectInArray(m_projStart + m_projSize, new Projectile(m_pEngine, 800, 800, true, 0, 0, "resources/Projectiles/Keyboard.png", direction, m_xPos, m_yPos, 5));

			m_projSize++;

			if (m_projSize > m_projCap) { m_projSize = 0;}
		}
		
	}
	else { // first shot overlaps last shot :(

		DisplayableObject* d  = m_pEngine->getDisplayableObject(m_projStart + m_projSize);

		if (d != nullptr) {
			delete d;
		}

		m_pEngine->storeObjectInArray(m_projStart + m_projSize, new Projectile(m_pEngine, 800, 800, true, 0, 0, "resources/Projectiles/Keyboard.png", direction, m_xPos, m_yPos, 5));

		m_projSize++;

		if (m_projSize > m_projCap) { m_projSize = 0; }
	
	}


}


void Player::setHealth(int h) {

	m_healthAmount = h;

}

int	Player::getHealth() {
	
	return m_healthAmount;

}
















// DONT GO DOWN THERE........... :(

































//void Player::setCollisionCoords() { // need a way to make sure the collider map lines up properly 
//
//	SimpleImage img = (m_animState == IDLE) ? m_personIdle : m_personRunning;
//	int offset = (m_animState == IDLE) ? 1 : 6;
//	int a = (m_animState == IDLE) ? 32 * m_direction : ((32 * m_direction) * 6) + (m_runTick * 32);
//	std::vector<std::pair<int, int>> pairs;
//
//	//std::cout << "X: " << ((32 * m_direction) * offset) + (m_runTick * 32) << " | Y: " << 64 << std::endl;
//
//	//if (m_animState == IDLE) {
//
//	//	m_personIdle.renderImageWithMask(
//	//		m_pEngine->getForegroundSurface(),
//	//		32 * m_direction,
//	//		1,
//	//		m_xPos,
//	//		m_yPos,
//	//		31, 64,
//	//		0x00FF00
//	//	);
//
//	//}
//	//else if (m_animState == RUNNING) {
//
//	//	m_personRunning.renderImageWithMask(
//	//		m_pEngine->getForegroundSurface(),
//	//		((32 * m_direction) * 6) + (m_runTick * 32),
//	//		1,
//	//		m_xPos,
//	//		m_yPos,
//	//		31, 64,
//	//		0x00FF00
//	//	);
//
//	//}
//	//((32 * m_direction) * 6) + (m_runTick * 32)
//
//	for (int i = a; i < (a) + 32; i++) {
//		for (int y = 1; y < 64; y++) {
//			if (img.getPixelColour(i, y) != 0x00FF00) {
//			
//				pairs.push_back(std::make_pair(i, y+m_yPos));
//			}	
//		}
//	}
//	m_collisionCoords = pairs;
//
//	//
//
//	// TESTING
//	for (int i = 0; i < m_collisionCoords.size(); i++) { // go through all coords and render for testing
//		m_pEngine->lockBackgroundForDrawing();
//		//m_pEngine->rawSetBackgroundPixel(m_collisionCoords[i].first, m_collisionCoords[i].second, 0xFFFFFF);
//		m_pEngine->rawSetForegroundPixel((m_collisionCoords[i].first + m_xPos - ((32 * m_direction) * offset) + (m_runTick * 32))
//			- (32 * m_runTick) - 32 * m_runTick,
//			
//			
//			m_collisionCoords[i].second, 0x00CCFF);
//		m_pEngine->unlockBackgroundForDrawing();
//	}
//	// TESTING
//		
//}
//
//
//void Player::internalUpdate() {
//
//	setCollisionCoords(); // this may be causing frame stuttering? See entity definition for more details on overall impact
//}




//int sprite = 96 / 3;

//std::cout << "FFF" << std::endl;

//std::vector<std::vector<std::vector<std::pair<int, int>>>> validSpriteSheet;

//for (int sp = 0; sp < 4; sp++) { // 4 sprites for idle animation
//	std::vector<std::vector<std::pair<int, int>>> validSprite;

//	for (int i = 96 / 3 * sp; i < m_personIdle.getWidth(); i++) {
//		std::vector<std::pair<int, int>> validCoords;
//		for (int y = 0; y < m_personIdle.getHeight(); y++)
//		{
//			if (m_personIdle.getPixelColour(i, y) == m_collisionMask) {

//				
//				validCoords.push_back(std::make_pair(i,y));

//			}
//		}
//		validSprite.push_back(validCoords);

//	}
//	validSpriteSheet.push_back(validSprite);
//	m_validPixels.push_back(validSprite);
//}