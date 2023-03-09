#include "header.h"
#include "DemoA.h"
#include "ImageManager.h"
#include "MyObject.h"


void DemoA::virtSetupBackgroundBuffer(){

    int colIndex = 0;
    int colour = 0;
    int iters = (getWindowHeight()/8)/0xF;
    
    for(int iY = 0; iY < getWindowHeight(); iY++){      
        for(int iX = 0; iX < getWindowWidth(); iX++){   
            setBackgroundPixel(iX,iY,colour);
        }    
        if(iY % iters == 0){colour += 0x010101;}
         
    }


    for (int i = 0; i < 15; i++) 
        for (int j = 0; j < 15; j++) 
            tm.setMapValue(i, j, rand()); 
            tm.setTopLeftPositionOnScreen(10,10); 
            tm.drawAllTiles( this, getBackgroundSurface() );

    this->drawImage("demo.jpg",100,10);
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
        if (tm.isValidTilePosition(iX, iY)) // Clicked within tiles?
        {
            int mapX = tm.getMapXForScreenX(iX); // Which column?
            int mapY = tm.getMapYForScreenY(iY); // Which row?
            int value = tm.getMapValue(mapX, mapY); // Current value?
            tm.setAndRedrawMapValueAt(mapX, mapY, value+rand(), this, getBackgroundSurface() );
            redrawDisplay(); // Force background to be redrawn to foreground
        }

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
            virtSetupBackgroundBuffer();
            redrawDisplay();
            std::cout << "Pressed space " << std::endl;
        break;
    }
 
}


void DemoA::drawImage(std::string path,int x, int y){


    SimpleImage image = ImageManager::loadImage(path,true);
    image.renderImage(getBackgroundSurface(),x,y,x+100,y+100,200,200);
    std::cout << "X : " << x << " Y: " << y << std::endl;


}

int DemoA::virtInitialiseObjects(){

    // Record the fact that we are about to change the array
    // so it doesn't get used elsewhere without reloading it
    drawableObjectsChanged();
    // Destroy any existing objects
    destroyOldObjects(true);
    // Creates an array big enough for the number of objects that you want.
    createObjectArray(5);
    // You MUST set the array entry after the last one that you create to NULL,
    // so that the system knows when to stop.
    storeObjectInArray(0, new MyObject(this,100,100,false,100,100));
    storeObjectInArray(1, new MyObject(this,100,100,false,200,200));
    storeObjectInArray(2, new MyObject(this,100,100,false,300,300));
    storeObjectInArray(3, new MyObject(this,100,100,false,400,400));
    storeObjectInArray(4, new MyObject(this,100,100,false,500,500));
    // NOTE: We also need to destroy the objects, but the method at the
    // top of this function will destroy all objects pointed at by the
    // array elements so we can ignore that here.
    setAllObjectsVisible(true);


    return 0;
}