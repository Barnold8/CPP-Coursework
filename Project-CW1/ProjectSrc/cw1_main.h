#pragma once
#include "../src/BaseEngine.h"
#include "TileMap.h"

class Main: public BaseEngine{

public:

    virtual void virtSetupBackgroundBuffer() override;

    // virtual void virtMouseDown(int button, int iX, int iY) override;

    virtual void virtKeyDown(int iKeyCode) override;

    virtual int virtInitialiseObjects() override;

    void drawImage(std::string path,int x, int y);

    virtual void virtMainLoopStartIteration() override;

protected:

    TileMap m_tile_map;

};