#include "header.h"
#include "DemoA.h"



void DemoA::virtSetupBackgroundBuffer(){

    int colIndex = 0;
    int colours[12] = {0xFF0000,0x00FF00,0x000FF};
    int indexMAX = 0;
    
    // for(int iY = 0; iY < getWindowHeight(); iY++){      
    //     for(int iX = 0; iX < getWindowWidth(); iX++){   
    //         if(iX % (22*4) == 0){
    //             colIndex = (colIndex > 3) ? 0 : colIndex + 1;
    //         }
    //         setBackgroundPixel(iX,iY,0x000000+indexMAX);
    //     }    
    //     indexMAX += 0x010101 + rand()%1;
    // }
}


void DemoA::virtMouseDown(int button, int iX, int iY){


    // std::vector<int> Xpositions = {};
    // std::vector<int> Ypositions = {};

    // int xRange = 10; // size of rect width
    // int yRange = 10; // size of rect height
    // int xStart = iX - xRange;
    // int yStart = iY - xRange;

    // for(int i = 0; i < xRange; i++){
    //     for(int y = 0; y < yRange;y++){
    //         setBackgroundPixel((xStart+i)+xRange/2,(yStart+y)+yRange/2,0xFF0000);
    //     }   
    // }

    // redrawDisplay();

    // drawBackgroundRectangle(iX - 10, iY - 10, iX + 10, iY + 10, 0xff0000);
    // // redrawDisplay();

    if (button == SDL_BUTTON_LEFT)
    {
        lockBackgroundForDrawing();
        drawBackgroundRectangle(iX - 10, iY - 10, iX + 10, iY + 10, 0xff0000);
        unlockBackgroundForDrawing();
        redrawDisplay(); // Force background to be redrawn to foreground
    }
    else if (button == SDL_BUTTON_RIGHT)
    {
        lockBackgroundForDrawing();
        drawBackgroundOval(iX - 10, iY - 10, iX + 10, iY + 10, 0x0000ff);
        unlockBackgroundForDrawing();
        redrawDisplay(); // Force background to be redrawn to foreground
    }


}


void DemoA::virtKeyDown(int iKeyCode){


    switch (iKeyCode)
    {
        case SDLK_SPACE:
            lockBackgroundForDrawing();
            virtSetupBackgroundBuffer();
            unlockBackgroundForDrawing();
            this->virtSetupBackgroundBuffer();
            redrawDisplay();
            std::cout << "Pressed space " << std::endl;
        break;
    }
 
}