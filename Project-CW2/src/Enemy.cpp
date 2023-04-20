#include "header.h"
#include "Enemy.h"
#include "BaseEngine.h"
#include "Office_Apocalypse.h"

Enemy::Enemy(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running) : Person(pEngine, iWidth, iHeight, useTopLeftFor00, objX, objY, idle, running) {

	m_personIdle = ImageManager::loadImage("resources/PlayerSprites/Idle.png", true);
	m_personRunning = ImageManager::loadImage("resources/PlayerSprites/Run.png", true);
	m_direction = RIGHT;
	m_animState = RUNNING;
	m_runTimer = 0;
	m_runCycle = 0;
	m_runTick = 0;
	m_personName = "None";
	m_spriteOffset = 6;
	ID = 2;
}


Enemy::Enemy(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY) : Person(pEngine, iWidth, iHeight, useTopLeftFor00, objX, objY, idle, running, pX, pY) {

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
	m_spriteOffset = 6;
	ID = 2;

}

Enemy::Enemy(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY, std::string name) : Person(pEngine, iWidth, iHeight, useTopLeftFor00, objX, objY, idle, running, pX, pY) {

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
	m_spriteOffset = 6;
	ID = 2;
}

Enemy::Enemy(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY, std::string name, int offset) : Person(pEngine, iWidth, iHeight, useTopLeftFor00, objX, objY, idle, running, pX, pY) {
	
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
	m_spriteOffset = offset;
	ID = 2;

}

Enemy::Enemy(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY, std::string name, int offset, std::shared_ptr<LevelLoader> LL, Player* player) : Person(pEngine, iWidth, iHeight, useTopLeftFor00, objX, objY, idle, running, pX, pY) {

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
	m_spriteOffset = offset;
	ID = 2;
	m_levelLoader = LL;
	m_player = player;
	m_nodes = generateNodes(LL->getMaps(), m_pEngine);	// generate notes for enemy object 
	// (might be a good idea to generate this 
	// at startup of game state so each enemy 
	// can have a pointer of this and not have to generate it on creation)

	// add neighbour nodes to parent node 
	for (int i = 0; i < m_h - 1; i++) {
		for (int j = 0; j < m_w - 1; j++) {

			addNeighbourNodes(m_nodes[i][j].neighbour_nodes, m_nodes[i][j] ); 
		}
	}
	// add neighbour nodes to parent node 
	m_playerPosition = m_player->getCoords();

	setFirstOpenNode(m_xPos, m_yPos, pEngine);
	setPlayerNode(m_playerPosition.first, m_playerPosition.second, m_pEngine);


}


void Enemy::virtKeyDown(int iKeyCode) {
	// this is here so the enemy does nothing with keyevents.
	// COULD add stuff here so the enemy can read user input for predictions on things (most likely wont do but cool idea)

	// ENABLE THE KEYPRESSES TO TEST THE ENEMY MOVEMENT WITHOUT AI
	//setFirstOpenNode(m_xPos, m_yPos, m_pEngine);

	setPlayerNode(m_player->getCoords().first, m_player->getCoords().second, m_pEngine);
	
	//AIProc();

	switch (iKeyCode) {

	case SDLK_RIGHT:
		m_xPos += m_speed;
		m_direction = RIGHT;
		m_runTimer = 0;
		break;
	case SDLK_LEFT:
		m_xPos -= m_speed;
		m_direction = LEFT;
		m_runTimer = 0;
		break;
	case SDLK_DOWN:
		m_yPos += m_speed;
		m_direction = DOWN;
		m_runTimer = 0;
		break;
	case SDLK_UP:
		m_yPos -= m_speed;
		m_direction = UP;
		m_runTimer = 0;
		break;

	case SDLK_1:
		
		break;

	default:
		break;
	}


}


bool Enemy::internalUpdate() {


	//if (m_runTimer > 5) {
	//	m_xPos += 1;
	//	m_direction = RIGHT;
	//	m_runTimer = 0;
	//
	//}
	//
	if (AIProc()) { std::cout << "ENDDDD" << std::endl; };
	//m_openSet.clear();
	//m_closedSet.clear();

	return false;

}

