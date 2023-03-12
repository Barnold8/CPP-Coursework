#include "../src/header.h"
#include "../src/BaseEngine.h"
#include "../src/SimpleImage.h"
#include "PipePair.h"
#include "../src/UtilCollisionDetection.h"
#include "cw1_main.h"


#include "Bird.h"

void Bird::virtDraw(){

    
    //collider box - used for debugging collisions
    // getEngine()->drawForegroundRectangle(
    //         m_iCurrentScreenX+100,
    //         m_iCurrentScreenY+100,
    //         m_iCurrentScreenX+(m_image.getWidth()/2),
    //         m_iCurrentScreenY+(m_image.getHeight()/2),
    // 0x9803fc);
    //collider box - used for debugging collisions

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

    // m_pEngine->virtDrawStringsOnTop(
    //     100,
    //     // m_pEngine->getForegroundSurface()->getSurfaceHeight()/2,
    //     100,
    //     score.data(),
    //     0
    //     );

}

bool Bird::checkCollisions(){

    psybw7Engine* main = dynamic_cast<psybw7Engine*>(m_pEngine);

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

    if(m_iCurrentScreenY > m_pEngine->getForegroundSurface()->getSurfaceHeight()){
            m_iCurrentScreenX = 650;
            m_iCurrentScreenY = 400;
            m_score = 0;
    }
    if(m_iCurrentScreenY < - (m_iCurrentScreenY + m_image.getHeight())){
            m_iCurrentScreenX = 650;
            m_iCurrentScreenY = 400;
            m_score = 0;
    }
    // std::cout << "Count:  " << m_pEngine->getNonNullObjectContentCount() << std::endl;

    return false;
}


void Bird::virtDoUpdate(int iCurrentTime){

    const int scoreDebuff = 100;
    std::string score = "Score: " + std::to_string(getScore()/scoreDebuff);
    psybw7Engine* main = dynamic_cast<psybw7Engine*>(m_pEngine);
    m_score++;

    int x = main->m_tile_map.getMapXForScreenX(m_iCurrentScreenX+60);
    int y = main->m_tile_map.getMapYForScreenY(m_iCurrentScreenY+60); 

    for(int i = 0;i < 10;i++){ //reset tile to some blue value
        main->m_tile_map.setAndRedrawMapValueAt(x, y-1,0x3492eb-(m_iCurrentScreenY/50), main, main->getBackgroundSurface() );
    }
    //
    main->m_tile_map.setAndRedrawMapValueAt(x, y, 0xEEE32F, main, main->getBackgroundSurface() );

    applyVelocity();
    main->setLabel(score);
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
    psybw7Engine* main = dynamic_cast<psybw7Engine*>(m_pEngine);

    main->m_tile_map.setMapValue(0,0,0xFF0000);
    // main->m_tile_map.drawAllTiles(main,main->getForegroundSurface());
    main->m_tile_map.setAndRedrawMapValueAt(0,0,0xFF0000,main,main->getForegroundSurface());

}


