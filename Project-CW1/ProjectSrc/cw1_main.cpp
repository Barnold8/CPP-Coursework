#include "../src/header.h"
#include "cw1_main.h"
#include "Bird.h"


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

    // SimpleImage image = ImageManager::loadImage("../src/resources/FBirdMask.png",true);

    // image.renderImageWithMask(
    //         this->getBackgroundSurface(),
    //         0,0,0,400,
    //         image.getWidth(),
    //         image.getHeight(),
    //         0x08ff00
    // );

}


int Main::virtInitialiseObjects(){

     drawableObjectsChanged();
    // Destroy any existing objects
    destroyOldObjects(true);
    // Creates an array big enough for the number of objects that you want.
    createObjectArray(1);
    // You MUST set the array entry after the last one that you create to NULL,
    // so that the system knows when to stop.
    storeObjectInArray(0, new Bird(
        this,50,50,false,
        getForegroundSurface()->getSurfaceWidth()/2-25,
        getForegroundSurface()->getSurfaceHeight()/2-25,
        2,1));

    // NOTE: We also need to destroy the objects, but the method at the
    // top of this function will destroy all objects pointed at by the
    // array elements so we can ignore that here.
    setAllObjectsVisible(true);

    return 0;
}
 

void Main::drawImage(std::string path,int x, int y){

    SimpleImage image = ImageManager::loadImage(path,true);
    image.renderImage(getBackgroundSurface(),x,y,x+100,y+100,200,200);
    std::cout << "X : " << x << " Y: " << y << std::endl;

}


void Main::virtKeyDown(int iKeyCode){
    
    switch (iKeyCode)
    {
        case SDLK_SPACE:
            Bird* bird = dynamic_cast<Bird*>(getDisplayableObject(0));
            bird->applyJump();
            break;

    }

}