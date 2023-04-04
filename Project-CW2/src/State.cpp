#include "State.h"
#include "Office_Apocalypse.h"



void Menu::update() {

	Office_Apocalypse* M = dynamic_cast<Office_Apocalypse*>(m_pEngine);

	frames[counter]->mySDLLockSurface();
	images[counter].renderImage(frames[counter], 0, 0, 0, 0, 800, 800);
	frames[counter]->mySDLUnlockSurface();
	if (M->getUpdates() % 16 == 0) {
		counter++;
		if (counter >= FRAMES) {
			counter = 0;
		}
	}

	M->setUpdates(M->getUpdates() + 1);
	M->setBgSurface(frames[counter]);

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


	//for (int i = 0; i < FRAMES;i++) { // engine refuses to accept this for some reason. Not sure why

	//	frames[i]->mySDLLockSurface();
	//	images[i].renderImage(frames[counter], 0, 0, 0, 0, 800, 800);
	//	frames[i]->mySDLUnlockSurface();
	//}


}

Menu::~Menu() {

	for (int i = 0; i < FRAMES;i++) {
		delete frames[i];
	}

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