#pragma once

#include "DisplayableObject.h"



class MyObject : public DisplayableObject{

public:

    MyObject(BaseEngine* pEngine): DisplayableObject(pEngine){

        m_iCurrentScreenX = 100;
        m_iCurrentScreenY = 300;
        m_iDrawWidth = 100; // Width of drawing area
        m_iDrawHeight = 200; 
    }


    MyObject(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00,int objX, int objY): DisplayableObject( pEngine, iWidth, iHeight, useTopLeftFor00){
        //BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00
        m_iCurrentScreenX = objX;
        m_iCurrentScreenY = objY;
        m_iDrawWidth = iWidth; // Width of drawing area
        m_iDrawHeight = iHeight; 
    }

    virtual void virtDraw() override;

    virtual void virtDoUpdate(int iCurrentTime) override;
};