#pragma once

#include "BaseEngine.h"


class DemoA : public BaseEngine
{
    virtual void virtSetupBackgroundBuffer() override;

    virtual void virtMouseDown(int button, int iX, int iY) override;

    virtual void virtKeyDown(int iKeyCode);


    void drawImage(std::string path,int x, int y);

};
