#pragma once
#include "../src/BaseEngine.h"
#include "TileMap.h"

class Psybw7Engine: public BaseEngine{


private: 

    std::string foreground_label; // used as a workaround for virtDrawStringsOnTop()
    std::vector<std::string> bgStrings = {
        "Don't click",
        "Please dont"
    };
    int strIndex = 0;
    int strIndexY = 0;
    

public:
    
    Psybw7TileManager m_tile_map;
    
    virtual void virtSetupBackgroundBuffer() override;

    // virtual void virtMouseDown(int button, int iX, int iY) override;

    virtual void virtKeyDown(int iKeyCode) override;

    virtual int virtInitialiseObjects() override;

    void drawImage(std::string path,int x, int y);

    virtual void virtMainLoopStartIteration() override;

    virtual void virtDrawStringsOnTop() override;

    void setLabel(std::string string){foreground_label = string;}

    virtual void virtMouseDown(int iButton, int iX, int iY) override;


};