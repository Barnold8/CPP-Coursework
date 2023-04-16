
#include "header.h"
#include "Entity.h"
#include "BaseEngine.h"
#include "Office_Apocalypse.h"


Entity::Entity(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY) : DisplayableObject(pEngine, iWidth, iHeight, useTopLeftFor00) {

	m_xPos = 100;
	m_yPos = 100;
	m_speed = 10;

}


void Entity::virtDraw() {
	m_pEngine->drawForegroundRectangle(m_xPos, m_yPos, m_xPos+100, m_yPos+100, 0xFF0000);
}

void Entity::virtKeyDown(int iKeyCode) {
	

}

void Entity::internalUpdate() {


}

void Entity::setCollided(bool c) {
	m_collided = c;
}



