#include "header.h"
#include "Main_Menu.h"
#include "Office_Apocalypse.h"
//#include "State.h"

void Office_Apocalypse::virtSetupBackgroundBuffer()
{

	SimpleImage background = ImageManager::loadImage("resources/Background.png");
	SimpleImage player = ImageManager::loadImage("resources/AdamPhoneSprites.png");

	background.renderImage(getBackgroundSurface(), 0, 0, 0, 0, 800, 800);	


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

	m_state_master->changeState(new Game());

}