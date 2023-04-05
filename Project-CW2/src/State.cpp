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
			//M->getStateMaster()->changeState(std::make_shared<Game>(m_pEngine)); <--- THIS needs to work to change the state to game state or some other state depending on what m_menu_select is 
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


Menu::Menu(BaseEngine* engine) : State(engine) {

	for (int i = 0; i < FRAMES;i++) {
		frames[i] = new DrawingSurface(m_pEngine);
		frames[i]->createSurface(800, 800);
		images[i] = ImageManager::loadImage("resources/Menu/MenuFrame" + std::to_string(i + 1) + ".png", true);

	}

	m_pEngine->notifyObjectsAboutKeys(true);

}

Menu::~Menu() {

	for (int i = 0; i < FRAMES;i++) {
		delete frames[i];
	}

	//delete m_menuTilde; // For some reason this is automatically deleted even though its a member of Menu?

}

Game::Game(BaseEngine* engine) : State(engine) { // Wont let me access clear public methods of state master class object

	std::cout << "Game init" << std::endl;

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