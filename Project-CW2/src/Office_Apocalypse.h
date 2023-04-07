#pragma once
#include "BaseEngine.h"
#include "State.h"

//Note!!! making a new surface pushes the previous one down. its so stupid....


class State_Master;


class Office_Apocalypse : public BaseEngine{

private:
	
	int m_updates = 0;

	DrawingSurface* m_bgSurfaceCopy;
	DrawingSurface* m_fgSurfaceCopy;
	bool m_customRender = false;

	std::shared_ptr<State_Master> m_state_master = std::make_shared<State_Master>(this);;

public:

	Office_Apocalypse();

	void setSurfacesToCopies();

	void setBgSurface(DrawingSurface* newSurface);

	void setFgSurface(DrawingSurface* newSurface);

	DrawingSurface* getBgSurface();

	DrawingSurface* getFgSurface();

	void customRendering(bool setRenderBool) {
		m_customRender = setRenderBool;
	}

	virtual void virtDrawStringsOnTop() override;

	virtual void virtSetupBackgroundBuffer() override;

	virtual void virtMainLoopStartIteration() override;

	virtual int virtInitialiseObjects() override;

	virtual void virtKeyDown(int iKeyCode) override;

	virtual void virtMainLoopDoBeforeUpdate() override;

	virtual void copyAllBackgroundBuffer() override;

	int getUpdates();

	void setUpdates(int updates);

	std::shared_ptr<State_Master> getStateMaster();

};

