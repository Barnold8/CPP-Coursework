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

	State(BaseEngine* engine);

	void set_master(std::shared_ptr<State_Master*> state);

	virtual void update() = 0; // FORCE SUB STATES TO UPDATE

};


class Menu : public State {


private:

	int counter = 0;
	static const int FRAMES = 9;
	DrawingSurface* frames[FRAMES];
	SimpleImage images[FRAMES];

public:

	Menu(BaseEngine* engine);

	~Menu();

	virtual void update() override;
};

class Game : public State {

public:

	Game(BaseEngine* engine);

};


class State_Master {

private:

	//std::unique_ptr<State> m_state;
	std::shared_ptr<State> m_state;
	BaseEngine* m_pEngine;

public:

	State_Master(BaseEngine* engine);

	void changeState(std::shared_ptr<State>state);

	void childUpdate();

};