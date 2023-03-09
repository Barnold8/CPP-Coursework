#include "../src/header.h"
#include "cw1_main.h"


void Main::virtSetupBackgroundBuffer(){

    int colIndex = 0;
    int colour = 0x478aed;
    int iters = (getWindowHeight()/8)/0x5;
    
    for(int iY = 0; iY < getWindowHeight(); iY++){      
        for(int iX = 0; iX < getWindowWidth(); iX++){   
            setBackgroundPixel(iX,iY,colour);
        }    
        if(iY % iters == 0){colour += 0x010100;}
        
    }


}
 