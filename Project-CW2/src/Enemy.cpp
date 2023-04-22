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
	m_collisionCoolDown = -1;
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
	m_collisionCoolDown = -1;

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
	m_collisionCoolDown = -1;
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
	m_collisionCoolDown = -1;
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
	m_nodes = generateNodes(LL->getMaps());	// generate notes for enemy object 
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

	setFirstNode(m_xPos, m_yPos);
	setPlayerNode(m_playerPosition.first, m_playerPosition.second);

	m_lastKnownLocation = std::make_pair(m_xPos, m_yPos);

	m_collisionCoolDown = -1;
}


void Enemy::virtKeyDown(int iKeyCode) {
	// this is here so the enemy does nothing with keyevents.
	// COULD add stuff here so the enemy can read user input for predictions on things (most likely wont do but cool idea)

	// ENABLE THE KEYPRESSES TO TEST THE ENEMY MOVEMENT WITHOUT AI


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


		//case 100:
		//	m_xPos += m_speed;
		//	m_direction = RIGHT;
		//	m_runTimer = 0;
		//	x = m_xPos - 10;
		//	if (canMove(m_levelLoader, x, y, true) || canMove(m_levelLoader, x, y, false)) {
		//		m_xPos = x_copy;
		//		m_yPos = y_copy;
		//	}

		//	break;
		//case 97:
		//	m_xPos -= m_speed;
		//	m_direction = LEFT;
		//	m_runTimer = 0;
		//	x = m_xPos - 20;
		//	if (canMove(m_levelLoader, x, y, true) || canMove(m_levelLoader, x, y, false)) {
		//		{
		//			m_xPos = x_copy;
		//			m_yPos = y_copy;
		//		}
		//		break;
		//case 115:
		//	m_yPos += m_speed;
		//	m_direction = DOWN;
		//	m_runTimer = 0;
		//	y = m_yPos + 20;
		//	x = m_xPos - 10;
		//	if (canMove(m_levelLoader, x, y, true) || canMove(m_levelLoader, x, y, false)) {
		//		m_xPos = x_copy;
		//		m_yPos = y_copy;
		//	}
		//	break;
		//case 119:
		//	m_yPos -= m_speed;
		//	m_direction = UP;
		//	m_runTimer = 0;
		//	y = m_yPos + 30;
		//	if (canMove(m_levelLoader, x, y, true) || canMove(m_levelLoader, x, y, false)) {
		//		m_xPos = x_copy;
		//		m_yPos = y_copy;
		//	}
		//	break;
		//	}
		//}


bool Enemy::internalUpdate() {


	//if (m_runTimer > 5) {
	//	m_xPos += 1;
	//	m_direction = RIGHT;
	//	m_runTimer = 0;
	//
	//}
	//

	m_playerPosition = m_player->getCoords();
	int distance = std::abs(m_xPos - m_playerPosition.first) + std::abs(m_yPos - m_playerPosition.second);
	
	//std::cout << distance << std::endl;
	if (m_runTimer > 10 && distance < 180) {		
		m_runTimer = 0;
		if (m_playerPosition.second > m_yPos) {

			m_yPos += 1;
			m_direction = DOWN;
		}
		else if ((m_playerPosition.second < m_yPos)) {
			m_yPos -= 1;
			m_direction = UP;
		}
		else if (m_playerPosition.first > m_xPos) {
			m_xPos += 1;
			m_direction = RIGHT;
		}
		else if(m_playerPosition.first < m_xPos) {
			m_xPos -= 1;
			m_direction = LEFT;
		}
	}
	else {

	
	}



	m_pEngine->lockBackgroundForDrawing();

	m_pEngine->drawBackgroundRectangle(m_start.x * 32, m_start.y * 32, m_start.x * 32 + 32, m_start.y * 32 + 32, 0xFF0000);

	m_pEngine->drawBackgroundRectangle(m_end.x * 32, m_end.y * 32, m_end.x * 32 + 32, m_end.y * 32 + 32, 0x0000FF);

	
	//m_pEngine->drawBackgroundRectangle(m_start.x*32, m_start.y,m_start.x + 32, m_start.y + 32, 0xFF0000);

	m_pEngine->unlockBackgroundForDrawing();



	djikstra(m_start,m_end);

	return false;

}

