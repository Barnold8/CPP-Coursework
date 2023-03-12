
#include "../src/header.h"
#include "PipePair.h"
#include "../src/BaseEngine.h"


void PipePair::virtDraw(){

    const int retract = 5;
    
    int p_1[4] = {
        m_top_pipe->getX(),
        m_top_pipe->getY(),
        m_top_pipe->get_Width(),
        m_top_pipe->get_Height()
    };
    int p_2[4] = {
        m_bottom_pipe->getX(),
        m_bottom_pipe->getY(),
        m_bottom_pipe->get_Width(),
        m_bottom_pipe->get_Height()
    };

    // Pipe 1

    getEngine()->drawForegroundRectangle(
        p_1[0], p_1[1],
        p_1[0] + p_1[2] - 1,
        p_1[1] + p_1[3] - 1,
    0x000000);

    getEngine()->drawForegroundRectangle(
        p_1[0]+(retract/2), p_1[1]+(retract/2)+1,
        p_1[0]+(retract/2) + p_1[2] - 1- retract,
        p_1[1]+(retract/2) + p_1[3] - 1- retract,
        m_top_pipe->get_Colour()

    );

    // Pipe 1


    // Pipe 2

    getEngine()->drawForegroundRectangle(
        p_2[0],  p_2[1],
        p_2[0] + p_2[2] - 1,
        p_2[1] + p_2[3] - 1,
    0x000000);

    getEngine()->drawForegroundRectangle(
        p_2[0]+(retract/2),  p_2[1]+(retract/2)+1,
        p_2[0]+(retract/2) + p_2[2] - 1- retract,
        p_2[1]+(retract/2) + p_2[3] - 1- retract,
    m_bottom_pipe->get_Colour());
    // Pipe 2

} 

void PipePair::virtDoUpdate(int iCurrentTime){
  
    const int OFFSET = 100;
    const int pipe_speed = 2;
    const int outside_region = 4000;
    // std::cout << "X: " <<  m_top_pipe->getX()  << " Mem address : " << this <<std::endl;
    
    if(m_top_pipe->getX() < 0 - OFFSET){

        m_top_pipe->setX(outside_region);
        m_bottom_pipe->setX(outside_region);
       
    }else{
        m_bottom_pipe->addX(-pipe_speed);
        m_top_pipe->addX(-pipe_speed);
    }

}