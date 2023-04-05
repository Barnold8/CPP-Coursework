#include "header.h"
#include "State.h"
#include "Office_Apocalypse.h"



void Menu::update() {

	Office_Apocalypse* M = dynamic_cast<Office_Apocalypse*>(m_pEngine);

	// TEXT DRAWING - For some reason we draw to the background and not some specific 
	M->lockBackgroundForDrawing();
	M->drawBackgroundString(30, -60, "Office Apocalypse!", 0xF1F1F1, M->getFont("resources/Wizard.otf", 101));
	M->drawBackgroundString(30,-60, "Office Apocalypse!", 0x3F2832, M->getFont("resources/Wizard.otf", 100));

	// TITLE
	M->drawBackgroundString(105, 80, "Main menu", 0x3F2832, M->getFont("resources/Wizard.otf", 75));
	M->drawBackgroundString(103, 80, "Main menu", 0xF1F1F1, M->getFont("resources/Wizard.otf", 78));

	// MENU OPTIONS
	M->drawBackgroundString(155, 250, "Start new.", 0x3F2832, M->getFont("resources/Wizard.otf", 50));
	M->drawBackgroundString(155, 320, "Load game.", 0x3F2832, M->getFont("resources/Wizard.otf", 50));
	M->drawBackgroundString(215, 390, "Exit.", 0x3F2832, M->getFont("resources/Wizard.otf", 50));

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
		m_pEngine->storeObjectInArray(0, new MenuTilde(m_pEngine, 800, 800, true, 800, 800)); // <- this gives a subscript error, and it makes no sense
		for (int i = 0; i < FRAMES; i++) {

			frames[i]->mySDLLockSurface();
			images[i].renderImage(frames[i], 0, 0, 0, 0, 800, 800);
			frames[i]->mySDLUnlockSurface();

		}
		Loaded = true;
	}
	//m_pEngine->drawBackgroundOval(100, 100, 200, 200, 0xFF0000);
	
}

void Menu::setup() {} // Not needed


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
			std::cout << "menu select " << m_menu_select << std::endl;
			switch (m_menu_select) {
				case 1:
					M->getStateMaster()->changeState(std::make_shared<Game>(m_pEngine)); // <--- THIS needs to work to change the state to game state or some other state depending on what m_menu_select is 
				break;
				case 2:
					//std::cout << "IMPLEMENT Loading save data brandon!!!" << std::endl;
					M->getStateMaster()->changeState(std::make_shared<Lose>(m_pEngine));
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

State::State(BaseEngine* engine) {
	m_pEngine = engine;
}


void State::set_master(std::shared_ptr<State_Master*> state) { // Changes 
	m_state_master = state;
}

void State::newSurfaces() {
	
	Office_Apocalypse* M = dynamic_cast<Office_Apocalypse*>(m_pEngine);
	foregroundSurface = new DrawingSurface(m_pEngine);
	backgroundSurface = new DrawingSurface(m_pEngine);

	foregroundSurface->createSurface(800, 800);
	backgroundSurface->createSurface(800, 800);

	M->setBgSurface(backgroundSurface);
	M->setFgSurface(foregroundSurface);

}

void State::delSurfaces() {

	delete foregroundSurface;
	delete backgroundSurface;

}

Menu::Menu(BaseEngine* engine) : State(engine) {

	for (int i = 0; i < FRAMES;i++) {
		frames[i] = new DrawingSurface(m_pEngine);
		frames[i]->createSurface(800, 800);
		images[i] = ImageManager::loadImage("resources/Menu/MenuFrame" + std::to_string(i + 1) + ".png", true);

	}

	m_pEngine->notifyObjectsAboutKeys(true);

}

Menu::~Menu() {

	for (int i = 0; i < FRAMES;i++) { // Deleting these frames leads to access violation
		delete frames[i];
	}

	m_pEngine->destroyOldObjects(true); // used to remove the selector bar
	
	std::cout << "Clearing Menu from memory" << std::endl;

}

Game::Game(BaseEngine* engine) : State(engine) { // Wont let me access clear public methods of state master class object
	

	newSurfaces();

}

Game::~Game() { // needed since changing surface for engine takes DrawingSurface* so i cant use smart pointers

	delSurfaces();
}

void Game::update() {}

void Game::setup() {}

void Game::KeyListener(int keyCode) {}



Lose::Lose(BaseEngine* engine) : State(engine) {

	newSurfaces();
	m_loseScreen = ImageManager::loadImage("resources/Menu/Lose.png",true);
}

void Lose::setup() {

}

void Lose::update() {

	m_loseScreen.renderImage(backgroundSurface, 0, 0, 1000, 800, 800, 800);

}

void Lose::KeyListener(int keyCode) {

	std::cout << "Lose key " << keyCode << std::endl;
}


Lose::~Lose() {

	delSurfaces();

}


State_Master::State_Master(BaseEngine* engine) {

	m_pEngine = engine;
	m_state = std::make_shared<Menu>(m_pEngine);

}

void State_Master::changeState(std::shared_ptr<State>state) { // May produce read access violation
	m_state = state;
}



void State_Master::childUpdate() { m_state->update(); }

void State_Master::setup() { m_state->setup(); }

void State_Master::childKey(int keyCode) { m_state->KeyListener(keyCode); }