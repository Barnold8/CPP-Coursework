#include "../src/header.h"
#include "../src/BaseEngine.h"
#include "../src/SimpleImage.h"
#include "PipePair.h"
#include "../src/UtilCollisionDetection.h"


#include "Bird.h"

void Bird::virtDraw(){

    const int scoreDebuff = 100;
    std::string score = "Score: " + std::to_string(getScore()/scoreDebuff);

    //collider box
    getEngine()->drawForegroundRectangle(
            m_iCurrentScreenX+100,
            m_iCurrentScreenY+100,
            m_iCurrentScreenX+(m_image.getWidth()/2),
            m_iCurrentScreenY+(m_image.getHeight()/2),
    0x9803fc);
    //collider box

    // std::cout << m_iCurrentScreenX+100 << " | " << m_iCurrentScreenX+(m_image.getWidth()/2) << std::endl;

    m_image.renderImageWithMask(
            m_pEngine->getForegroundSurface(),
            0,
            0,
            m_iCurrentScreenX+(m_image.getWidth()/4),
            m_iCurrentScreenY+(m_image.getHeight()/4),
            m_image.getWidth(),
            m_image.getHeight(),
            0x08ff00
    );
    m_pEngine->drawForegroundString(
        100,
        // m_pEngine->getForegroundSurface()->getSurfaceHeight()/2,
        100,
        score.data(),
        0
        );

}

bool Bird::checkCollisions(){

    for(int i = 1; i < m_pEngine->getNonNullObjectContentCount()-1; i++){

        PipePair* pair = dynamic_cast<PipePair*>( m_pEngine->getDisplayableObject(i));
        //Pipe 1
        bool collidedTop = CollisionDetection::checkRectangles(
            pair->getTopPipe()->getX() - 50,
            pair->getTopPipe()->getX()+  pair->getTopPipe()->get_Width() - 50,
            pair->getTopPipe()->getY(),
            pair->getTopPipe()->getY() +  pair->getTopPipe()->get_Height() - 50,
            
            m_iCurrentScreenX,
            m_iCurrentScreenX + m_image.getWidth()/2,
            m_iCurrentScreenY,
            m_iCurrentScreenY + m_image.getHeight()/2
            );
        //Pipe 1

        bool collidedBottom = CollisionDetection::checkRectangles(
            pair->getBottomPipe()->getX() - 50,
            pair->getBottomPipe()->getX() +  pair->getBottomPipe()->get_Width() - 50,
            pair->getBottomPipe()->getY(),
            pair->getBottomPipe()->getY() +  pair->getBottomPipe()->get_Height() - 50,
            
            m_iCurrentScreenX,
            m_iCurrentScreenX + m_image.getWidth()/2,
            m_iCurrentScreenY,
            m_iCurrentScreenY + m_image.getHeight()
            );
        //Pipe 2

        if(collidedBottom || collidedTop){
            m_iCurrentScreenX = 650;
            m_iCurrentScreenY = 400;
            m_score = 0;
        }

    }
    // std::cout << "Count:  " << m_pEngine->getNonNullObjectContentCount() << std::endl;

    return false;
}


void Bird::virtDoUpdate(int iCurrentTime){

    applyVelocity();
    m_score++;
    checkCollisions();
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

    const int spring = 18;

    this->m_yVel -= this->m_yVel + spring;
}


