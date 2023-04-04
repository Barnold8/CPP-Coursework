#include "header.h"
#include "Main_Menu.h"
#include "Office_Apocalypse.h"
//#include "State.h"

void Office_Apocalypse::virtSetupBackgroundBuffer()
{

}


void Office_Apocalypse::virtMainLoopStartIteration() {
	redrawDisplay();

}

int Office_Apocalypse::virtInitialiseObjects() {

    const int PAIRAMOUNT = 10;

    drawableObjectsChanged();

    destroyOldObjects(true);

    createObjectArray(1);

	return 0;

}

void Office_Apocalypse::virtKeyDown(int iKeyCode) {

	//m_state_master->changeState(new Game(this));

}

void Office_Apocalypse::virtMainLoopDoBeforeUpdate() {

	m_state_master->childUpdate();

}

void Office_Apocalypse::setBgSurface(DrawingSurface* newSurface) { this->m_pBackgroundSurface = newSurface; }


int Office_Apocalypse::getUpdates() { return m_updates; }

void Office_Apocalypse::setUpdates(int updates) { m_updates = updates; }