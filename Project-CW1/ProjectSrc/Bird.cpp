#include "../src/header.h"
#include "../src/BaseEngine.h"

#include "Bird.h"

void Bird::virtDraw(){

    const int retract = 5;

    getEngine()->drawForegroundRectangle(
        m_iCurrentScreenX, m_iCurrentScreenY,
        m_iCurrentScreenX + m_iDrawWidth - 1,
        m_iCurrentScreenY + m_iDrawHeight - 1,
    0x000000);

    getEngine()->drawForegroundRectangle(
        m_iCurrentScreenX+(retract/2)+1, m_iCurrentScreenY+(retract/2)+1,
        m_iCurrentScreenX+(retract/2) + m_iDrawWidth - 1- retract,
        m_iCurrentScreenY+(retract/2) + m_iDrawHeight - 1 - retract,
    0x99CC00);
}

void Bird::virtDoUpdate(int iCurrentTime){

    applyVelocity();
    redrawDisplay();

}

void Bird::applyVelocity(){

    const int MAXVELOCITY = 4;

    this->m_yVel += this->m_grav;
    if(this->m_yVel >= MAXVELOCITY){
        this->m_yVel = MAXVELOCITY;
    }

    this->m_iCurrentScreenY += this->m_yVel;

}


void Bird::applyJump(){

    const int spring = 5;

    this->m_yVel -= this->m_yVel + spring;

}
