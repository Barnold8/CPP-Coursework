#pragma once
#include "header.h"
#include "BaseEngine.h"
#include <memory>


class State_Master;


class State
{
	
protected:

	std::shared_ptr<State_Master*> m_state_master;
	BaseEngine* m_pEngine;

private:


public:

	State(BaseEngine* engine) {
		m_pEngine = engine;
	}

	void set_master(std::shared_ptr<State_Master*> state) { // Changes 
		m_state_master = state;
	}

	virtual void update() = 0; // FORCE SUB STATES TO UPDATE

};


class Menu : public State {


private:

	int counter = 0;
	static const int FRAMES = 4;
	DrawingSurface* frames[FRAMES];
	SimpleImage images[FRAMES];

public:

	Menu(BaseEngine* engine): State(engine) {
		for (int i = 0; i < FRAMES;i++) {
			frames[i] = new DrawingSurface(m_pEngine);
			frames[i]->createSurface(800, 800);
			images[i] = ImageManager::loadImage("resources/Test/Test" + std::to_string(i + 1) + ".png",true);
		}
	}

	~Menu() {

		for (int i = 0; i < FRAMES;i++) {
			delete frames[i];
		}
	
	}

	virtual void update() override;
};

class Game : public State {

public:

	Game(BaseEngine* engine) : State(engine) { // Wont let me access clear public methods of state master class object

		std::cout << "Game init" << std::endl;

	}

};


class State_Master {

private:

	//std::unique_ptr<State> m_state;
	std::shared_ptr<State> m_state;
	BaseEngine* m_pEngine;

public:

	State_Master(BaseEngine* engine) {

		m_pEngine = engine;
		m_state = std::make_shared<Menu>(m_pEngine);

	}

	void changeState(std::shared_ptr<State>state) { // May produce read access violation
		m_state = state; 
	}

	void childUpdate() { m_state->update(); }

};