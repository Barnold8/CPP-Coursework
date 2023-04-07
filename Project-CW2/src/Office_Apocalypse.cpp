#include "header.h"
#include "Main_Menu.h"
#include "Office_Apocalypse.h"
//#include "State.h"

void Office_Apocalypse::virtSetupBackgroundBuffer()
{

	m_state_master->setup();

}


void Office_Apocalypse::virtMainLoopStartIteration() {
	redrawDisplay();

}

int Office_Apocalypse::virtInitialiseObjects() {

    const int PAIRAMOUNT = 10;

    drawableObjectsChanged();

    destroyOldObjects(true);

	createObjectArray(255);

	setAllObjectsVisible(true);

	return 0;

}

void Office_Apocalypse::virtKeyDown(int iKeyCode) {

	m_state_master->childKey(iKeyCode);

}

void Office_Apocalypse::virtMainLoopDoBeforeUpdate() {

	m_state_master->childUpdate();

}

Office_Apocalypse::Office_Apocalypse() {

	m_fgSurfaceCopy = getFgSurface();
	m_bgSurfaceCopy = getBgSurface();

}

void Office_Apocalypse::setSurfacesToCopies() { // Acts as a reset to original surfaces

	setBgSurface(m_bgSurfaceCopy);
	setFgSurface(m_fgSurfaceCopy);
	m_bgSurfaceCopy->createSurface(800, 800);
	m_bgSurfaceCopy->createSurface(800, 800);
	
}

void Office_Apocalypse::copyAllBackgroundBuffer() {

	if (m_customRender) {
		m_state_master->copyAllBackgroundBuffer();
	}
	else {
		m_pForegroundSurface->copyEntireSurface(m_pBackgroundSurface);
	}

}

void Office_Apocalypse::virtDrawStringsOnTop() { // This needs to be used due to the flow of the engine... overriding this ensures that the body inside is drawn last, thus on top...
												 // Why you wouldnt have an override for other things on top i dont know...

	drawForegroundRectangle(100, 100, 200, 200, 0xFF0000);

}

void Office_Apocalypse::setBgSurface(DrawingSurface* newSurface) { this->m_pBackgroundSurface = newSurface; }

void Office_Apocalypse::setFgSurface(DrawingSurface* newSurface) { this->m_pForegroundSurface = newSurface; }

DrawingSurface* Office_Apocalypse::getBgSurface() { return this->m_pBackgroundSurface; }

DrawingSurface* Office_Apocalypse::getFgSurface() { return this->m_pForegroundSurface; }

int Office_Apocalypse::getUpdates() { return m_updates; }

void Office_Apocalypse::setUpdates(int updates) { m_updates = updates; }

std::shared_ptr<State_Master> Office_Apocalypse::getStateMaster() { return m_state_master; }