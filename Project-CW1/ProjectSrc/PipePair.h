#pragma once

#include "../src/DisplayableObject.h"
#include "Pipe.h"

class PipePair : public DisplayableObject{

private:

    Pipe* m_top_pipe;
    Pipe* m_bottom_pipe;


public:

    PipePair(BaseEngine* pEngine): DisplayableObject(pEngine){

        m_top_pipe    = new Pipe();
        m_bottom_pipe = new Pipe();

    }

    PipePair(BaseEngine* pEngine, int x1, int y1, int x2, int y2, int w1, int w2, int h1, int h2,int col1, int col2): DisplayableObject(pEngine){

        m_top_pipe    = new Pipe(x1,y1,w1,h1,col1);
        m_bottom_pipe = new Pipe(x2,y2,w2,h2,col2);

    }



    virtual void virtDraw() override;    

    virtual void virtDoUpdate(int iCurrentTime) override;
  
};