#pragma once
#include "BaseEngine.h"
#include "State.h"

//Note!!! making a new surface pushes the previous one down. its so stupid....

class State_Master;


class Office_Apocalypse : public BaseEngine{

private:
	
	std::shared_ptr<State_Master> m_state_master = std::make_shared<State_Master>(this);;

public:

	void setBgSurface(DrawingSurface* newSurface) { this->m_pBackgroundSurface = newSurface; }

	virtual void virtSetupBackgroundBuffer() override;

	virtual void virtMainLoopStartIteration() override;

	virtual int virtInitialiseObjects() override;

	virtual void virtKeyDown(int iKeyCode) override;

	virtual void virtMainLoopDoBeforeUpdate() override;
};

