#include "header.h"
#include "Main_Menu.h"
#include "Office_Apocalypse.h"
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"

//#include "State.h"

void Office_Apocalypse::virtSetupBackgroundBuffer() // func has no effect if called after program starts first state
{

	//m_state_master->setup(); 

}

void Office_Apocalypse::virtMainLoopStartIteration() {
	redrawDisplay();
}

int Office_Apocalypse::virtInitialiseObjects() {

    const int PAIRAMOUNT = 10;

    drawableObjectsChanged();

    destroyOldObjects(true);

	createObjectArray(255);

	setAllObjectsVisible(true);

	return 0;

}

void Office_Apocalypse::virtKeyDown(int iKeyCode) {

	m_state_master->childKey(iKeyCode);

}

void Office_Apocalypse::virtMainLoopDoBeforeUpdate() {

	m_state_master->childUpdate();

}

Office_Apocalypse::Office_Apocalypse() {

	m_fgSurfaceCopy = getFgSurface();
	m_bgSurfaceCopy = getBgSurface();
}

void Office_Apocalypse::setSurfacesToCopies() { // Acts as a reset to original surfaces

	setBgSurface(m_bgSurfaceCopy);
	setFgSurface(m_fgSurfaceCopy);
	m_bgSurfaceCopy->createSurface(800, 800);
	m_bgSurfaceCopy->createSurface(800, 800);
	
}

void Office_Apocalypse::copyAllBackgroundBuffer() {

	if (m_customRender) {
		m_state_master->copyAllBackgroundBuffer();
	}
	else {
		m_pForegroundSurface->copyEntireSurface(m_pBackgroundSurface);
	}

}

void Office_Apocalypse::virtDrawStringsOnTop() { // This needs to be used due to the flow of the engine... overriding this ensures that the body inside is drawn last, thus on top...
												 // Why you wouldnt have an override for other things on top i dont know...



}

void Office_Apocalypse::customRendering(bool setRenderBool) {
	m_customRender = setRenderBool;
}

void Office_Apocalypse::objectClearer() {

	for (int i = 0; i < getContentCount(); i++) {

		DisplayableObject* d = getDisplayableObject(i);

		while (d != nullptr) {
			removeDisplayableObject(d);
			delete d;
			d = getDisplayableObject(i);
		}

	}

}

void Office_Apocalypse::setBgSurface(DrawingSurface* newSurface) { this->m_pBackgroundSurface = newSurface; }

void Office_Apocalypse::setFgSurface(DrawingSurface* newSurface) { this->m_pForegroundSurface = newSurface; }

DrawingSurface* Office_Apocalypse::getBgSurface() { return this->m_pBackgroundSurface; }

DrawingSurface* Office_Apocalypse::getFgSurface() { return this->m_pForegroundSurface; }

int Office_Apocalypse::getUpdates() { return m_updates; }

void Office_Apocalypse::setUpdates(int updates) { m_updates = updates; }

std::shared_ptr<State_Master> Office_Apocalypse::getStateMaster() { return m_state_master; }

std::string Office_Apocalypse::getUserName() { return m_userName; }

void Office_Apocalypse::setUserName(std::string name) { m_userName = name; }


void Office_Apocalypse::saveGame() {

	Player* player;
	Projectile* projectile;
	Enemy* enemy;
	bool write = true;

	if (FileIO::isFile("resources/SaveData/SAVE.DAT")) {
		std::cout << "Are you sure you want to overwrite?" << std::endl;  // << add proper implementation for this 
	}

	if (write) {

		std::string equals = "===============================\n";

		FileIO::writeToFile(false, "resources/SaveData/SAVE.DAT", "Level: " + std::to_string(m_currentLevel) +"\n"+equals);

		FileIO::writeToFile(true, "resources/SaveData/SAVE.DAT", "Save: " + getUserName() + "\n" + equals);

		for (int i = 0; i < m_vecDisplayableObjects.size();i++) { // deffo could just check for nullptr on dynamic cast rather than just nulptr THEN dynamic cast but oh well

			if (i == 0 && m_vecDisplayableObjects[i] != nullptr) { // player

				if ((player = dynamic_cast<Player*>(m_vecDisplayableObjects[i])) != nullptr) {
					DATA player_DAT = player->getData();


					FileIO::writeToFile(true, "resources/SaveData/SAVE.DAT", DATAstr(player_DAT,0));

				}
				else {
					std::cout << "FATAL ERROR: PLAYER NON EXISTANT. NULLPTR AT PLAYER OBJ " << i << std::endl;
				}
			}
			else if (i > 0 && i < 12 && m_vecDisplayableObjects[i] != nullptr) { // projectile
				if ((projectile = dynamic_cast<Projectile*>(m_vecDisplayableObjects[i])) != nullptr) {
					DATA projectile_DAT = projectile->getData();
					FileIO::writeToFile(true, "resources/SaveData/SAVE.DAT", DATAstr(projectile_DAT, 1));
					std::cout << i << "is projectile" << std::endl;
				}
				else {
					std::cout << "FATAL ERROR: PROJECTILE NON EXISTANT. NULLPTR AT PLAYER OBJ " << i << std::endl;

				}

			}
			else if (m_vecDisplayableObjects[i] != nullptr) { // enemy
				if ((enemy = dynamic_cast<Enemy*>(m_vecDisplayableObjects[i])) != nullptr) {
					DATA enemy_DAT = enemy->getData();
					FileIO::writeToFile(true, "resources/SaveData/SAVE.DAT", DATAstr(enemy_DAT, 0));
				}
				else {
					std::cout << "FATAL ERROR: ENEMY NON EXISTANT. NULLPTR AT PLAYER OBJ " << i << std::endl;
				}
			}
		}
		FileIO::writeToFile(true, "resources/SaveData/SAVE.DAT", "EOF");
	}
}

//struct DATA {
//
//	// BOTH
//	int _m_xPos;
//	int _m_yPos;
//	int _m_speed;
//	bool _m_collided; // May not even be used lol
//	int	 _m_collisionCoolDown;
//	// BOTH
//
//	// Person
//	std::string _m_personName;									 // Allows name above person to be different
//	Movement	_m_direction;									 // enum for the player looking direction
//	animState	_m_animState;									 // enum for the animation state
//	int			_m_runTimer;										 // time after last key update
//	int			_m_runCycle;										 // number counted to tick over next anim frame
//	int			_m_runTick;										 // number to use in animation frame formula
//	int			_m_healthAmount;									 // amount of health user has
//	int			_m_spriteOffset;
//	int			_m_collisionMask;								 // the colour used to say what is a valid pixel for collision
//	bool		_m_renderHealth;
//	// Person
//
//	// Projectile
//	Projectile* _m_prev; // cant reference this, ignore it 
//	int			_m_tick;
//	// Projectile
//};

std::string Office_Apocalypse::DATAstr(DATA data, int type) {

	std::string fileData = "";
	std::string equals = "===============================\n";

	fileData += "Type: " + std::to_string(type) + "\n";
	fileData += "xPos: " + std::to_string(data._m_xPos) + "\n";
	fileData += "yPos: " + std::to_string(data._m_yPos) + "\n";
	fileData += "speed: " + std::to_string(data._m_speed) + "\n";
	fileData += "collided: " + std::to_string(data._m_collided) + "\n";
	fileData += "collisionCoolDown: " + std::to_string(data._m_collisionCoolDown) + "\n";

	switch (type) {
	
	case 0:
		if (data._m_personName.size() < 1) {
			fileData += "Name: Enemy\n";
		}
		else {
			fileData += "Name: " + data._m_personName + "\n";
		}
		//	std::string _m_personName;									 // Allows name above person to be different
		fileData += "Direction: " + std::to_string(data._m_direction) + "\n";
		//	Movement	_m_direction;									 // enum for the player looking direction
		fileData += "animState: " + std::to_string(data._m_animState) + "\n";
		//	animState	_m_animState;									 // enum for the animation state
		fileData += "RunTimer: " + std::to_string(data._m_runTimer) + "\n";
		//	int			_m_runTimer;										 // time after last key update
		fileData += "RunCycle: " + std::to_string(data._m_runCycle) + "\n";
		//	int			_m_runCycle;										 // number counted to tick over next anim frame
		fileData += "RunTick: " + std::to_string(data._m_runTick) + "\n";
		//	int			_m_runTick;										 // number to use in animation frame formula
		fileData += "HealthAmount: " + std::to_string(data._m_healthAmount) + "\n";
		//	int			_m_healthAmount;									 // amount of health user has
		fileData += "SpriteOffset: " + std::to_string(data._m_spriteOffset) + "\n";
		//	int			_m_spriteOffset;
		fileData += "CollisionMask: " + std::to_string(data._m_collisionMask) + "\n";
		//	int			_m_collisionMask;								 // the colour used to say what is a valid pixel for collision
		fileData += "RenderHealth: " + std::to_string(data._m_renderHealth) + "\n";
		//	bool		_m_renderHealth;
		fileData += "DeathCount: " + std::to_string(data._m_deathCount) + "\n";


		break;

	case 1:
		fileData += "tick: " + std::to_string(data._m_tick) + "\n";
		fileData += "Direction: " + std::to_string(data._m_direction) + "\n";
		break;
	default:

		break;
	
	}

	fileData += equals;




	return fileData;
}



void Office_Apocalypse::changeLevel(int level) {

	m_currentLevel = level;

}


int Office_Apocalypse::getLevel() { return m_currentLevel; }