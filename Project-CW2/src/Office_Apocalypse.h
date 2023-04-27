#pragma once
#include "BaseEngine.h"
#include "State.h"

//Note!!! making a new surface pushes the previous one down. its so stupid....
//TODO: make a cleanup function for the engine. This will clean the object array we got given which for some reason gives memory access violations if you do anything in a state destructor. 

class State_Master; 

struct DATA;

class Office_Apocalypse : public BaseEngine{

private:
	
	int m_updates = 0;

	DrawingSurface* m_bgSurfaceCopy;
	DrawingSurface* m_fgSurfaceCopy;
	std::string m_userName;
	bool m_customRender = false;

	std::shared_ptr<State_Master> m_state_master = std::make_shared<State_Master>(this);

	int m_currentLevel = -1; // <--- needed for what current level we are on for save data (-1 means no current level)

public:

	Office_Apocalypse();


	DrawingSurface* getBgSurface();

	DrawingSurface* getFgSurface();

	std::string getUserName();

	void setSurfacesToCopies();

	void setBgSurface(DrawingSurface* newSurface);

	void setFgSurface(DrawingSurface* newSurface);

	void setUpdates(int updates);

	void customRendering(bool setRenderBool);

	void objectClearer();

	void setUserName(std::string name);

	virtual void virtDrawStringsOnTop() override;

	virtual void virtSetupBackgroundBuffer() override;

	virtual void virtMainLoopStartIteration() override;

	virtual int virtInitialiseObjects() override;

	virtual void virtKeyDown(int iKeyCode) override;

	virtual void virtMainLoopDoBeforeUpdate() override;

	virtual void copyAllBackgroundBuffer() override;

	int getUpdates();

	void saveGame();

	std::string DATAstr(DATA data, int type);

	std::shared_ptr<State_Master> getStateMaster();

	void changeLevel(int level);

	int getLevel();

};
 
