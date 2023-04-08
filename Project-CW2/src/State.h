#pragma once
#include "header.h"
#include "BaseEngine.h"
#include "MenuTilde.h"
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

	virtual void copyAllBackgroundBuffer() = 0;

	virtual void update() = 0; // FORCE SUB STATES TO UPDATE

	virtual void setup() = 0;

	virtual void KeyListener(int keyCode) = 0;

};

class Menu : public State {


private:

	static const int FRAMES = 9;
	int counter = 0;
	int m_menu_select = 1;
	bool Loaded = false;
	DrawingSurface* frames[FRAMES];
	SimpleImage images[FRAMES];

public:

	Menu(BaseEngine* engine);

	~Menu();

	virtual void copyAllBackgroundBuffer() override;

	virtual void update() override;

	void setup();

	virtual void KeyListener(int keyCode) override;

};

class SignAway : public State {

private:

	SimpleImage sign;


public:

	SignAway(BaseEngine* engine);

	virtual void copyAllBackgroundBuffer() override;

	virtual void update() override;

	void setup();

	virtual void KeyListener(int keyCode) override;

};

class Load : public State {

private:

public:

	Load(BaseEngine* engine);

	virtual void copyAllBackgroundBuffer() override;

	virtual void update() override;

	void setup();

	virtual void KeyListener(int keyCode) override;

};

class Game : public State {

public:

	Game(BaseEngine* engine);

	~Game();

	virtual void copyAllBackgroundBuffer() override;

	virtual void update();

	virtual void setup();

	virtual void KeyListener(int keyCode);

};

class Lose : public State {

private:


	SimpleImage m_loseScreen;
	int m_iOffset;
	int m_randChance; // random int between 1-100
	int m_menu_select = 1;

public:

	Lose(BaseEngine* engine);

	~Lose();

	virtual void copyAllBackgroundBuffer() override;

	virtual void update();

	virtual void setup();

	virtual void KeyListener(int keyCode);

};

class Win : public State {

private:

	int m_menu_select = 1;
	int m_iOffset;
	SimpleImage m_winScreen;

public:

	Win(BaseEngine* engine);

	virtual void copyAllBackgroundBuffer() override;

	virtual void update();

	virtual void setup();

	virtual void KeyListener(int keyCode);


};

class State_Master {

private:

	//std::unique_ptr<State> m_state;
	std::shared_ptr<State> m_state;
	BaseEngine* m_pEngine;

public:

	State_Master(BaseEngine* engine);

	void copyAllBackgroundBuffer();

	void setup();

	void changeState(std::shared_ptr<State>state);

	void childUpdate();

	void childKey(int keyCode);

};