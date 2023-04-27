#include "header.h"
#include "Enemy.h"
#include "BaseEngine.h"
#include "Office_Apocalypse.h"
#include "State.h"

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
	m_healthAmount = 3;
	m_collisionCoolDown = -1;
	m_collisionMask = 0x00FF00;
	m_xPosCOPY = m_xPos;
	m_deathCount = 0;
	m_yPosCOPY = m_yPos;
	m_expression = "????";
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
	m_healthAmount = 3;
	m_collisionMask = 0x00FF00;
	m_xPosCOPY = m_xPos;
	m_deathCount = 0;
	m_yPosCOPY = m_yPos;
	m_expression = "????";
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
	m_healthAmount = 3;
	m_collisionMask = 0x00FF00;
	m_xPosCOPY = m_xPos;
	m_deathCount = 0;
	m_yPosCOPY = m_yPos;
	m_expression = "????";
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
	m_healthAmount = 3;
	m_collisionMask = 0x00FF00;
	m_xPosCOPY = m_xPos;
	m_deathCount = 0;
	m_yPosCOPY = m_yPos;
	m_expression = "????";
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
	m_healthAmount = 3;
	m_collisionMask = 0x00FF00;
	m_nodes = generateNodes(LL->getMaps());	// generate notes for enemy object 
	// (might be a good idea to generate this 
	// at startup of game state so each enemy 
	// can have a pointer of this and not have to generate it on creation)

	// add neighbour nodes to parent node 
	for (int i = 0; i < m_h - 1; i++) {
		for (int j = 0; j < m_w - 1; j++) {

			addNeighbourNodes(m_nodes[i][j].neighbour_nodes, m_nodes[i][j]);
		}
	}
	// add neighbour nodes to parent node 
	m_playerPosition = m_player->getCoords();

	setFirstNode(m_xPos, m_yPos);
	setPlayerNode(m_playerPosition.first, m_playerPosition.second);

	m_xPosCOPY = m_xPos;

	m_yPosCOPY = m_yPos;
	m_deathCount = 0;
	m_collisionCoolDown = -1;
	m_expression = "????";
}

Enemy::Enemy(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY, std::string name, int offset, std::shared_ptr<LevelLoader> LL, Player* player, int index, Game* game) : Person(pEngine, iWidth, iHeight, useTopLeftFor00, objX, objY, idle, running, pX, pY) {

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
	m_healthAmount = 3;
	m_collisionMask = 0x00FF00;
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

	m_collisionCoolDown = -1;

	m_game = game;

	m_xPosCOPY = m_xPos;

	m_yPosCOPY = m_yPos;

	m_deathCount = 0;

	m_expression = "????";
}




void Enemy::virtKeyDown(int iKeyCode) {
	// this is here so the enemy does nothing with keyevents.
	// COULD add stuff here so the enemy can read user input for predictions on things (most likely wont do but cool idea)

	// ENABLE THE KEYPRESSES TO TEST THE ENEMY MOVEMENT WITHOUT AI

	std::vector<std::pair<int, int>> f;

	switch (iKeyCode) {

	//case SDLK_RIGHT:
	//	m_xPos += m_speed;
	//	m_direction = RIGHT;
	//	m_runTimer = 0;
	//	break;
	//case SDLK_LEFT:
	//	m_xPos -= m_speed;
	//	m_direction = LEFT;
	//	m_runTimer = 0;
	//	break;
	//case SDLK_DOWN:
	//	m_yPos += m_speed;
	//	m_direction = DOWN;
	//	m_runTimer = 0;
	//	break;
	//case SDLK_UP:
	//	m_yPos -= m_speed;
	//	m_direction = UP;
	//	m_runTimer = 0;
	//	break;

	case SDLK_1:
		//f = pathing(m_start, m_end);
		//std::reverse(f.begin(),f.end());
		//if (f[0].first == -100) {
		//	std::cout << "asdasdasdasdasdasdasdgAAAAAAAAAAAAAAA " << std::endl;
		//}
		//else {
		//	for (int i = 0; i < f.size(); i++) {

		//		m_pEngine->drawBackgroundRectangle(f[i].first * 32, f[i].second * 32, f[i].first * 32 + 32, f[i].second * 32 + 32, 0xFF0000);

		//	}
		//}
		break;

	default:
		break;
	}


}




bool Enemy::internalUpdate() {

	int x_copy = m_xPos;
	int y_copy = m_yPos;
	int x = m_xPos;
	int y = m_yPos;
	std::vector<std::pair<int, int>> f;

	m_playerPosition = m_player->getCoords();
	int distance = std::abs(m_xPos - m_playerPosition.first) + std::abs(m_yPos - m_playerPosition.second);

	m_playerPosition = m_player->getCoords();

	if (distance > 100) {
		setFirstNode(m_xPos, m_yPos);
		setPlayerNode(m_playerPosition.first, m_playerPosition.second);
		
	}
	if (distance > 500) {
		m_expression = "????";


		int randomDIR = rand() % 4 + 0;
		if (m_runTimer % 10 == 0) {
			switch (m_direction) {

			case RIGHT:
				m_xPos += 1;
				m_runTimer = 0;
				x = m_xPos - 10;
				if (canMove(m_levelLoader, x, y, true) || canMove(m_levelLoader, x, y, false)) {
					m_xPos = x_copy;
					m_yPos = y_copy;
					//m_direction = Movement(randomDIR);
				}

				break;
			case LEFT:
				m_xPos -= 1;
				m_runTimer = 0;
				x = m_xPos - 10;
				if (canMove(m_levelLoader, x, y, true) || canMove(m_levelLoader, x, y, false)) {
					m_xPos = x_copy;
					m_yPos = y_copy;
					//m_direction = Movement(randomDIR);
				}

				break;
			case DOWN:
				m_yPos += 1;
				m_runTimer = 0;
				x = m_xPos - 10;
				if (canMove(m_levelLoader, x, y, true) || canMove(m_levelLoader, x, y, false)) {
					m_xPos = x_copy;
					m_yPos = y_copy;
					m_direction = Movement(randomDIR);
				}

				break;

			case UP:
				m_yPos -= 1;
				m_runTimer = 0;
				x = m_xPos - 10;
				if (canMove(m_levelLoader, x, y, true) || canMove(m_levelLoader, x, y, false)) {
					m_xPos = x_copy;
					m_yPos = y_copy;
					m_direction = Movement(randomDIR);
				}

				break;

			default:

				break;

			}

		}

	}

	f = pathing(m_start, m_end);
	std::reverse(f.begin(), f.end());
	

	int collidedID = isCollided(m_pEngine);

	if (collidedID == 3) {
		m_healthAmount -= 1;
	}

	if (m_healthAmount <= 0) {
		
		if (m_deathCount == 3) {
			m_xPos = 30000;
			m_isDead = true;
			return false;
		}else{
			m_healthAmount = 3;
			m_xPos = m_xPosCOPY;
			m_yPos = m_yPosCOPY;
			m_deathCount += 1;
		}

	}

	if (f[0].first == -100) {
		
		
		
	}
	else {
		if (m_runTimer > 10 && distance > 50 && distance < 500) { // in certain distance, stop using pathing and use basic ruleset
			
			m_expression = "!!!!";

			m_runTimer = 0;

			if (f[0].first > m_start.x) {
				m_xPos += 1;
				m_direction = RIGHT;
			}
			else if (f[0].first < m_start.x) {
				m_xPos -= 1;
				m_direction = LEFT;
			}
			else if (f[0].second > m_start.y) {
				m_yPos += 1;
				m_direction = DOWN;
			}
			else if (f[0].second < m_start.y) {
				m_yPos -= 1;
				m_direction = UP;
			}
		}
		else {

			m_speed = (m_healthAmount > 2) ? 2 : 1 ;
			if (m_runTimer > 10 && distance < 200) {
				m_runTimer = 0;
				m_expression = "XXXXX";

				if (m_playerPosition.second > m_yPos) {
					m_yPos += m_speed;
					m_direction = DOWN;
				}
				else if ((m_playerPosition.second < m_yPos)) {
					m_yPos -= m_speed;
					m_direction = UP;
				}
				else if (m_playerPosition.first > m_xPos) {
					m_xPos += m_speed;
					m_direction = RIGHT;
				}
				else if (m_playerPosition.first < m_xPos) {
					m_xPos -= m_speed;
					m_direction = LEFT;

				}
			}

		}
		

		return false;

	}
}


void Enemy::setDeathCount(int death) { m_deathCount = death;}

int Enemy::getDeathCount() { return m_deathCount; }

bool Enemy::getIsDead() { return m_isDead; }