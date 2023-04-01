#pragma once
#include "header.h"
#include <memory>
#include "BaseEngine.h"


class State_Master;

class State
{
	
protected:

	std::unique_ptr<State_Master*> m_state_master;

private:


public:

	State() {
	}

	void set_master(State_Master* master) { // Changes 
		m_state_master.reset(&master);

	}


};


class Menu : public State {

public:

	Menu() {

		std::cout << "Menu init" << std::endl;

	}


};

class Game : public State {

public:

	Game() {

		std::cout << "Game init" << std::endl;
		
	}


};


class State_Master {

private:

	std::unique_ptr<State> m_state;
	std::unique_ptr<BaseEngine*> m_pEngine;

public:

	State_Master(BaseEngine* engine) {
	
		m_state.reset(new Menu());
		m_pEngine.reset(&engine);
		
	}


	void changeState(State* state) { m_state.reset(state); }


};



