#include "../src/header.h"
#include "../src/BaseEngine.h"
#include "../src/SimpleImage.h"

#include "Bird.h"

void Bird::virtDraw(){

    SimpleImage image = ImageManager::loadImage("../src/resources/FBirdMask.png",true);

    image.renderImageWithMask(
            m_pEngine->getForegroundSurface(),
            0,
            0,
            m_iCurrentScreenX+(image.getWidth()/4),
            m_iCurrentScreenY+(image.getHeight()/4),
            image.getWidth(),
            image.getHeight(),
            0x08ff00
    );
    

}

void Bird::virtDoUpdate(int iCurrentTime){

    applyVelocity();
    redrawDisplay();

}

void Bird::applyVelocity(){

    const int MAXVELOCITY = 7;

    this->m_yVel += this->m_grav;
    if(this->m_yVel >= MAXVELOCITY){
        this->m_yVel = MAXVELOCITY;
    }

    this->m_iCurrentScreenY += this->m_yVel;

}


void Bird::applyJump(){

    const int spring = 20;

    this->m_yVel -= this->m_yVel + spring;
}


