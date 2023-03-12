#pragma once
#include "../src/BaseEngine.h"
#include "TileMap.h"

class psybw7Engine: public BaseEngine{


private: 

    std::string foreground_label; // used as a workaround for virtDrawStringsOnTop()
    std::vector<std::string> bgStrings = {
        "Don't click",
        "Seriously don't click",
        "You can't follow simple instructions can you?",
        "Who even clicks in flappy bird!!?!?!?",
        "Oh yeah, you...",
        "I will tell your parents",
        "You honestly don't care?",
        "This should be a crime",
        "Oh come on now",
        "I",
        "Hate",
        "You", 
        "<--- I will make him chase you",
        "STILL?!?!? I'd be terrified of him",
        "The person below me is a loser |",
        "                                 V",
        "OH CRAP!",
        "I hope youre enjoying this cluttered screen",
        "It's not going to clear you know",
        "What even are you??",
        "You smelly smelly player",
        "Who put the click prompt here in the first place?!?!?",
        "It was the developer wasn't it!",
        ">:(",
        "Stinky player and developer -> O.o",
        "Still going?",
        "Ill stop the game!",
        "Okay fine, I cant do that",
        "YOU WIN!!!!",
        "AHHAHAH bet you fell for it"
    };

    int strIndex = 0;
    int strIndexY = 0;
    

public:
    
    psybw7TileManager m_tile_map;
    
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