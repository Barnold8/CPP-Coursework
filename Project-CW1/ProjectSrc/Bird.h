#pragma once

#include "../src/DisplayableObject.h"

// TODO: add function which looks at all pipes and checks for collisions between

class Bird: public DisplayableObject{


private:

    int m_yVel, m_grav;


public:

    Bird(BaseEngine* pEngine): DisplayableObject(pEngine){

        m_iCurrentScreenX = 100;
        m_iCurrentScreenY = 300;
        m_iDrawWidth = 100; // Width of drawing area
        m_iDrawHeight = 200; 
        m_yVel = 4;
        m_grav = 2;
    }

    Bird(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00,int objX, int objY): DisplayableObject( pEngine, iWidth, iHeight, useTopLeftFor00){
        //BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00
        m_iCurrentScreenX = objX;
        m_iCurrentScreenY = objY;
        m_iDrawWidth = iWidth; // Width of drawing area
        m_iDrawHeight = iHeight; 
        m_yVel = 4;
        m_grav = 2;
    }

    Bird(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00,int objX, int objY,int velocity, int gravity): DisplayableObject( pEngine, iWidth, iHeight, useTopLeftFor00){
        //BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00
        m_iCurrentScreenX = objX;
        m_iCurrentScreenY = objY;
        m_iDrawWidth = iWidth; // Width of drawing area
        m_iDrawHeight = iHeight; 
        m_yVel = velocity;
        m_grav = gravity;
    }


    virtual void virtDraw() override;

    virtual void virtDoUpdate(int iCurrentTime) override;

    void applyVelocity();

    void applyJump();


};