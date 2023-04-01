#include "header.h"
#include "BaseEngine.h"
#include "Testimg.h"



void Testimg::virtDraw(){

	

	//image.renderImage(m_pEngine->getForegroundSurface(), 0, 0, 0, 0, 800, 800);
		
	//std::cout << "virtDraw" << std::endl;

}

void Testimg::virtDoUpdate(int iCurrentTime) {

	std::cout << "virtDoUpdate" << std::endl;

	redrawDisplay();

}