#include "header.h"
#include "State.h"
#include "Office_Apocalypse.h"
#include "Image.h"
#include "Text.h"
#include "Player.h"
#include "Person.h"
#include "Enemy.h"
#include "Plate.h"



//NOTE: displayable object container vector has a hissy fit if i destroy all objects on menu destructor. 


// MENU
Menu::Menu(BaseEngine* engine) : State(engine) {

	for (int i = 0; i < FRAMES;i++) {
		frames[i] = new DrawingSurface(m_pEngine);
		frames[i]->createSurface(800, 800);
		images[i] = ImageManager::loadImage("resources/Menu/MenuFrame" + std::to_string(i + 1) + ".png", true);
	}

	Office_Apocalypse* M = dynamic_cast<Office_Apocalypse*>(m_pEngine);

	M->customRendering(false);
	m_pEngine->notifyObjectsAboutKeys(true);

}

void Menu::update() {

	Office_Apocalypse* M = dynamic_cast<Office_Apocalypse*>(m_pEngine);

	// TEXT DRAWING - For some reason we draw to the background and not some specific 
	M->lockBackgroundForDrawing();
	M->drawBackgroundString(30, -60, "Office Apocalypse!", 0xF1F1F1, M->getFont("resources/Fonts/Wizard.otf", 101));
	M->drawBackgroundString(30,-60, "Office Apocalypse!", 0x3F2832, M->getFont("resources/Fonts/Wizard.otf", 100));

	// TITLE
	M->drawBackgroundString(105, 80, "Main menu", 0x3F2832, M->getFont("resources/Fonts/Wizard.otf", 75));
	M->drawBackgroundString(103, 80, "Main menu", 0xF1F1F1, M->getFont("resources/Fonts/Wizard.otf", 78));

	// MENU OPTIONS
	M->drawBackgroundString(155, 250, "Start new.", 0x3F2832, M->getFont("resources/Fonts/Wizard.otf", 50));
	M->drawBackgroundString(155, 320, "Load game.", 0x3F2832, M->getFont("resources/Fonts/Wizard.otf", 50));
	M->drawBackgroundString(215, 390, "Exit.", 0x3F2832, M->getFont("resources/Fonts/Wizard.otf", 50));

	M->unlockBackgroundForDrawing();
	// TEXT DRAWING

	if (Loaded) {

		if (M->getUpdates() % 10 == 0) {
			counter++;
			if (counter >= FRAMES) {
				counter = 0;
			}
		}
		M->setUpdates(M->getUpdates() + 1);
		M->setBgSurface(frames[counter]);
	}
	else { // Used to force the engine to cooperate with loading assets onto surfaces...
		M->objectClearer();
		m_pEngine->storeObjectInArray(0, new MenuTilde(m_pEngine, 800, 800, true, 800, 800));
		for (int i = 0; i < FRAMES; i++) {

			frames[i]->mySDLLockSurface();
			images[i].renderImage(frames[i], 0, 0, 0, 0, 800, 800);
			frames[i]->mySDLUnlockSurface();
		}
		Loaded = true;
	}
	
}

void Menu::setup() {} 

void Menu::KeyListener(int keyCode) {

	Office_Apocalypse* M = dynamic_cast<Office_Apocalypse*>(m_pEngine);

	switch (keyCode) {// What is up with these awful keycodes?
	
		case 1073741906: // UP ARROW
			m_menu_select--;
			if (m_menu_select < 1) {
				m_menu_select = 3;
			}
			break;

		case 1073741905: // DOWN ARROW

			m_menu_select++;
			if (m_menu_select > 3) {
				m_menu_select = 1;
			}
			break;
		case 13:

			switch (m_menu_select) {
				case 1:
					M->getStateMaster()->changeState(std::make_shared<SignAway>(m_pEngine));
				break;
				case 2:
					//std::cout << "IMPLEMENT Loading save data brandon!!!" << std::endl;
					M->getStateMaster()->changeState(std::make_shared<Load>(m_pEngine));
					break;
				case 3:
					m_pEngine->setExitWithCode(0);
					break;
				default:
					break;
			}
			
			break;
		default:
			break;
	}

	//std::cout << "menu select: " << m_menu_select << std::endl;
}

void Menu::copyAllBackgroundBuffer() {


}

Menu::~Menu() { // NOTE: due to the weirdness of this engine, i need to remove the menutilde from the menu when transitioning into any new state from the menu

	for (int i = 0; i < FRAMES;i++) { // Deleting these frames leads to access violation
		delete frames[i];
	}

}
// MENU

// SIGN AWAY
SignAway::SignAway(BaseEngine* engine) : State(engine){

	Office_Apocalypse* M = dynamic_cast<Office_Apocalypse*>(m_pEngine);
	M->objectClearer();
	M->setSurfacesToCopies();

	sign = ImageManager::loadImage("resources/Menu/StartGame.png");

	m_pEngine->lockBackgroundForDrawing();
	sign.renderImage(M->getBgSurface(), 0,0,0,0, 800, 800);
	m_pEngine->unlockBackgroundForDrawing();

	//Text(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string text, int x, int y, int s, bool editable)

	m_pEngine->storeObjectInArray(0, new Text(m_pEngine, 800, 800, true, 800, 800," ",300,650,30,12,true)); // space to stop weird read access violation. thanks engine :)

}

void SignAway::copyAllBackgroundBuffer() {}

void SignAway::update() {}

void SignAway::setup() {}

void SignAway::KeyListener(int keyCode) {

	Text* t = dynamic_cast<Text*>(m_pEngine->getDisplayableObject(0));
	Office_Apocalypse* M = dynamic_cast<Office_Apocalypse*>(m_pEngine);

	if (keyCode == 13) {
		if (t->getText().size() < 2) {
			m_pEngine->storeObjectInArray(1, new Text(m_pEngine, 800, 800, true, 300, 830, "You need to enter your name, employee!!", 150, 600, 24, 12, false));
		}
		else {
			M->setUserName(t->getText());
			M->getStateMaster()->changeState(std::make_shared<Game>(m_pEngine));
			
		}
	}
}
// SIGN AWAY

// LOAD

Load::Load(BaseEngine* engine) : State(engine) {
	Office_Apocalypse* M = dynamic_cast<Office_Apocalypse*>(m_pEngine);

	M->objectClearer();
	M->setSurfacesToCopies();
	M->customRendering(false);

	SimpleImage x = ImageManager::loadImage("resources/Test/Test1.png");

	m_pEngine->lockBackgroundForDrawing();
	x.renderImage(M->getBgSurface(), 0, 0, 0, 0, 800, 800);
	m_pEngine->unlockBackgroundForDrawing();

}

void Load::copyAllBackgroundBuffer() {}

void Load::update() {

}

void Load::setup() {}

void Load::KeyListener(int keyCode) {


}

// LOAD

// STATE 
State::State(BaseEngine* engine) {
	m_pEngine = engine;
}

void State::set_master(std::shared_ptr<State_Master*> state) { // Changes 
	m_state_master = state;
}
// STATE

// GAME
Game::Game(BaseEngine* engine) : State(engine) { // Wont let me access clear public methods of state master class object
	
	Office_Apocalypse* M = dynamic_cast<Office_Apocalypse*>(m_pEngine);

	//std::vector<std::string> 

	M->objectClearer();
	M->setSurfacesToCopies();

	std::vector<std::string> sPaths = { "resources/LevelImages/walls_and_floor.png","resources/LevelImages/furniture.png" };

	m_level_loader = std::make_shared<LevelLoader>(m_pEngine,sPaths,"resources/Levels/Level1.tmj", 32, 32, 800, 800);

	m_pEngine->storeObjectInArray(0, new Player(m_pEngine, 800, 800, true, 800, 800,"resources/PlayerSprites/Idle.png", "resources/PlayerSprites/Run.png",100,100,M->getUserName()));
	//m_pEngine->storeObjectInArray(15, new Enemy(m_pEngine, 800, 800, true, 800, 800, "resources/PlayerSprites/Enemy_Idle.png", "resources/PlayerSprites/Enemy_Run.png",0,100,"ENEMY",5));

	setup();
}

void Game::copyAllBackgroundBuffer() {


}

Game::~Game() { // needed since changing surface for engine takes DrawingSurface* so i cant use smart pointers

	// delete level loader here
	
}

void Game::update() {

	Office_Apocalypse* M = dynamic_cast<Office_Apocalypse*>(m_pEngine);

	M->setUpdates(M->getUpdates() + 1);
	

}

void Game::setup() {

	m_level_loader->drawTiles();
	std::cout << "Game setup" << std::endl;
}

void Game::KeyListener(int keyCode) {}
// GAME


// LOSE
Lose::Lose(BaseEngine* engine) : State(engine) {

	int x[3] = { 300,300,340 };
	int y[3] = { 350,430,510 };
	int z[3] = { 200,200,100 };

	Office_Apocalypse* M = dynamic_cast<Office_Apocalypse*>(m_pEngine);

	M->objectClearer();
	M->setSurfacesToCopies();
	M->customRendering(true);
	m_loseScreen = ImageManager::loadImage("resources/Menu/Lose.png");

	m_pEngine->lockBackgroundForDrawing();
	m_loseScreen.renderImage(M->getBgSurface(), -2, -2, -2,-2, 1000, 800);
	m_pEngine->unlockBackgroundForDrawing();
	m_randChance = rand() % 100 + 1;

	m_pEngine->storeObjectInArray(1, new MenuTilde(m_pEngine, 800, 800, true, 800, 800,x,y,z));
	m_pEngine->storeObjectInArray(0, new Plate(m_pEngine, 800, 800, true, 800, 800,"resources/Menu/Plate.png","YOU LOSE!"));

}

void Lose::setup() {

}

void Lose::update() {


}

void Lose::KeyListener(int keyCode) {

	Office_Apocalypse* M = dynamic_cast<Office_Apocalypse*>(m_pEngine);
	switch (keyCode) {// What is up with these awful keycodes?

	case 1073741906: // UP ARROW
		m_menu_select--;
		if (m_menu_select < 1) {
			m_menu_select = 3;
		}
		break;

	case 1073741905: // DOWN ARROW

		m_menu_select++;
		if (m_menu_select > 3) {
			m_menu_select = 1;
		}
		break;
	case 13:
		
		switch (m_menu_select) {
		case 1:
			M->getStateMaster()->changeState(std::make_shared<Menu>(m_pEngine)); // <--- THIS needs to work to change the state to game state or some other state depending on what m_menu_select is 
			break;
		case 2:
			M->getStateMaster()->changeState(std::make_shared<Load>(m_pEngine));
			break;
		case 3:
			m_pEngine->setExitWithCode(0);
			break;
		default:
			break;
		}

		break;
	default:
		break;
	}
}

void Lose::copyAllBackgroundBuffer() {

	Office_Apocalypse* M = dynamic_cast<Office_Apocalypse*>(m_pEngine);


	if (M->getUpdates() % 10 == 0 || true) { // using or true to make it always true since the plate object slows this state down to a nice speed (REMOVE TRUE IF PERFORMANCE IS TOO QUICK)
		m_iOffset = (m_iOffset + 1) % m_pEngine->getWindowWidth();

		DrawingSurface* m_pForegroundSurface = m_pEngine->getForegroundSurface();
		DrawingSurface* m_pBackgroundSurface = m_pEngine->getBackgroundSurface();

		if (m_randChance > 80) { // 20% chance of seeing this special end screen :O
			m_pForegroundSurface->copyRectangleFrom(m_pBackgroundSurface, 0, 0, m_pEngine->getWindowWidth(), m_pEngine->getWindowHeight(), m_iOffset, 0);
			m_pForegroundSurface->copyRectangleFrom(m_pBackgroundSurface, 0, 0, m_pEngine->getWindowWidth(), m_pEngine->getWindowHeight(), m_iOffset, 0);
			m_pForegroundSurface->copyRectangleFrom(m_pBackgroundSurface, m_pEngine->getWindowWidth() - m_iOffset, 0, m_pEngine->getWindowWidth(), m_pEngine->getWindowHeight(), m_iOffset - m_pEngine->getWindowWidth(), 0);
			m_pForegroundSurface->copyRectangleFrom(m_pBackgroundSurface, 0, m_pEngine->getWindowWidth() - m_iOffset, m_pEngine->getWindowHeight(), m_pEngine->getWindowWidth(), 0, m_iOffset - m_pEngine->getWindowWidth());

		}
		else {
			m_pForegroundSurface->copyRectangleFrom(m_pBackgroundSurface, 0, 0, m_pEngine->getWindowWidth(), m_pEngine->getWindowHeight(), m_iOffset, 0);
			m_pForegroundSurface->copyRectangleFrom(m_pBackgroundSurface, m_pEngine->getWindowWidth() - m_iOffset, 0, m_pEngine->getWindowWidth(), m_pEngine->getWindowHeight(), m_iOffset - m_pEngine->getWindowWidth(), 0);
		}
		
		//m_pEngine->redrawDisplay();

	}
	M->setUpdates(M->getUpdates() + 1);
}

Lose::~Lose() {

}
// LOSE

// WIN
Win::Win(BaseEngine* engine) : State(engine) {

	int x[3] = { 300,300,340 };
	int y[3] = { 350,430,510 }; // Code duplication :O not so OOP of me
	int z[3] = { 200,200,100 };

	Office_Apocalypse* M = dynamic_cast<Office_Apocalypse*>(m_pEngine);

	M->objectClearer();
	M->setSurfacesToCopies();
	M->customRendering(true);


	m_winScreen = ImageManager::loadImage("resources/Menu/Win.png");

	m_pEngine->lockBackgroundForDrawing();
	m_winScreen.renderImage(M->getBgSurface(), -2, -2, -2, -2, 1000, 800);
	m_pEngine->unlockBackgroundForDrawing();

	m_pEngine->storeObjectInArray(1, new MenuTilde(m_pEngine, 800, 800, true, 800, 800, x, y, z));
	m_pEngine->storeObjectInArray(0, new Plate(m_pEngine, 800, 800, true, 800, 800, "resources/Menu/Plate.png","YOU WIN!"));

	
}

void Win::setup() {

}

void Win::update() {


}

void Win::KeyListener(int keyCode) {


	Office_Apocalypse* M = dynamic_cast<Office_Apocalypse*>(m_pEngine);
	switch (keyCode) {// What is up with these awful keycodes?

	case 1073741906: // UP ARROW
		m_menu_select--;
		if (m_menu_select < 1) {
			m_menu_select = 3;
		}
		break;

	case 1073741905: // DOWN ARROW

		m_menu_select++;
		if (m_menu_select > 3) {
			m_menu_select = 1;
		}
		break;
	case 13:
		std::cout << "menu select " << m_menu_select << std::endl;
		switch (m_menu_select) {
		case 1:
			M->getStateMaster()->changeState(std::make_shared<Menu>(m_pEngine)); // <--- THIS needs to work to change the state to game state or some other state depending on what m_menu_select is 
			break;
		case 2:
			M->getStateMaster()->changeState(std::make_shared<Load>(m_pEngine));
			break;
		case 3:
			m_pEngine->setExitWithCode(0);
			break;
		default:
			break;
		}

		break;
	default:
		break;
	}
}

void Win::copyAllBackgroundBuffer() { // code from here is nothing different from starfield demo really. Look at my copy all background for the Lose state to tick off this related requirement (scrolling background)

	Office_Apocalypse* M = dynamic_cast<Office_Apocalypse*>(m_pEngine);


	if (M->getUpdates() % 10 == 0 || true) { // using or true to make it always true since the plate object slows this state down to a nice speed (REMOVE TRUE IF PERFORMANCE IS TOO QUICK)
		m_iOffset = (m_iOffset + 1) % m_pEngine->getWindowWidth();;

		DrawingSurface* m_pForegroundSurface = m_pEngine->getForegroundSurface();
		DrawingSurface* m_pBackgroundSurface = m_pEngine->getBackgroundSurface();

		m_pForegroundSurface->copyRectangleFrom(m_pBackgroundSurface, 0, 0, M->getWindowWidth(), M->getWindowHeight(), 0, m_iOffset);
		m_pForegroundSurface->copyRectangleFrom(m_pBackgroundSurface, 0, M->getWindowHeight() - m_iOffset, M->getWindowWidth(), M->getWindowHeight(), 0, m_iOffset - M->getWindowHeight());

		//m_pEngine->redrawDisplay();

	}
	M->setUpdates(M->getUpdates() + 1);
}
// WIN



// STATE MASTER
State_Master::State_Master(BaseEngine* engine) {

	m_pEngine = engine;
	m_state = std::make_shared<Menu>(m_pEngine);

}

void State_Master::copyAllBackgroundBuffer() {

	m_state->copyAllBackgroundBuffer();
}

void State_Master::changeState(std::shared_ptr<State>state) { // May produce read access violation
	m_state = state;
}

void State_Master::childUpdate() { m_state->update(); }

void State_Master::setup() { m_state->setup(); }

void State_Master::childKey(int keyCode) { m_state->KeyListener(keyCode); }
// STATE MASTER