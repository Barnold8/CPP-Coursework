#include "header.h"
#include "BaseEngine.h"
#include "MyObject.h"




void MyObject::virtDraw(){

    std::cout << "Virt draw called" << std::endl;

    getEngine()->drawForegroundRectangle(
        m_iCurrentScreenX, m_iCurrentScreenY,
        m_iCurrentScreenX + m_iDrawWidth - 1,
        m_iCurrentScreenY + m_iDrawHeight - 1,
    0x00ff00);



}

void MyObject::virtDoUpdate(int iCurrentTime){

    m_iCurrentScreenX += 1;

    redrawDisplay();

}
