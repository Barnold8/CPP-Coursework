#pragma once
#include "BaseEngine.h"
#include "State.h"


class Office_Apocalypse : public BaseEngine{

private:

	int FPS;
	
	std::unique_ptr<State_Master> m_state_master;

public:

	Office_Apocalypse() {
	
		m_state_master.reset(new State_Master(this));

	}

	virtual void virtSetupBackgroundBuffer() override;

	virtual void virtMainLoopStartIteration() override;

	virtual int virtInitialiseObjects() override;

	virtual void virtKeyDown(int iKeyCode) override;
};

