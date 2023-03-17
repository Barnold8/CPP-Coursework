#include "../src/header.h"
#include "cw1_main.h"
#include "Bird.h"
#include "Pipe.h"
#include "PipePair.h"



// NOTE: make sure that the text is not oblitered by the tilemap

void Psybw7Engine::virtSetupBackgroundBuffer(){

    int colIndex = 0;
    int colour = 0x478aed;
    int iters = (getWindowHeight()/8)/0x5;
    
    for(int iY = 0; iY < getWindowHeight(); iY++){      
        for(int iX = 0; iX < getWindowWidth(); iX++){   
            setBackgroundPixel(iX,iY,colour);
        }    
        if(iY % iters == 0){colour += 0x010100;}
        
    }

    // Clouds
    for(int i = 0; i < 10; i++){
        m_tile_map.drawCloud(this,i*300,100,i);
    }
    
    // Clouds 

    // SUN
    this->drawBackgroundOval(
        -100,
        -100,
        100,
        100,
        0xFFFF00
        );

    // SUN


    // SUN RAYS
    this->drawBackgroundThickLine(
        100,
        100,
        200,
        200,
        0xFFFF00,
        10
    );

    this->drawBackgroundThickLine(
        140,
        50,
        250,
        50,
        0xFFFF00,
        10
    );

    this->drawBackgroundThickLine(
        40,
        120,
        40,
        240,
        0xFFFF00,
        10
    );
    
    // SUN RAYS

    SimpleImage image = ImageManager::loadImage("../src/resources/FB_Funny.png",true);

    image.renderImageWithMask(
            this->getBackgroundSurface(),
            0,0,0,300,
            image.getWidth(),
            image.getHeight(),
            0x000000
    );
    this->drawBackgroundString(this->getBackgroundSurface()->getSurfaceWidth()/3-100,this->getBackgroundSurface()->getSurfaceHeight()/4,bgStrings[strIndex].data(),0xFF0000);
}


int Psybw7Engine::virtInitialiseObjects(){

    const int PAIRAMOUNT = 10;

    drawableObjectsChanged();

    destroyOldObjects(true);

    createObjectArray(PAIRAMOUNT+1);

    storeObjectInArray(0, new Bird(
        this,50,50,false,
        getForegroundSurface()->getSurfaceWidth()/2-25,
        getForegroundSurface()->getSurfaceHeight()/2-25,
        2,1,
        "../src/resources/FBirdMask.png"));


    // GENERATE PIPES IN ARRAY
    int surfWidth = this->getForegroundSurface()->getSurfaceWidth();
    for(int i = 0; i < PAIRAMOUNT;i++){
        
        int y_random_one = -400 + (rand() % 200);
        int y_random_two = (y_random_one+690) + (rand()%(this->getForegroundSurface()->getSurfaceHeight()/2));

        storeObjectInArray(i+1, new PipePair(this,
                100+i*400,           // x1
                y_random_one,        // y1
                100+i*400,           // x2
                y_random_two,        // y2
                100,                 // w1
                100,                 // w2
                500,                 // h1
                600,                 // h2
                0x11AA11,            // col1
                0x11AA11             // col2
        ));
    }
    // GENERATE PIPES IN ARRAY


    // NOTE: We also need to destroy the objects, but the method at the
    // top of this function will destroy all objects pointed at by the
    // array elements so we can ignore that here.
    setAllObjectsVisible(true);

    return 0;
}
 

void Psybw7Engine::drawImage(std::string path,int x, int y){

    SimpleImage image = ImageManager::loadImage(path,true);
    image.renderImage(getBackgroundSurface(),x,y,x+100,y+100,200,200);
    std::cout << "X : " << x << " Y: " << y << std::endl;

}


void Psybw7Engine::virtKeyDown(int iKeyCode){
    
    switch (iKeyCode)
    {
        case SDLK_SPACE:
            Bird* bird = dynamic_cast<Bird*>(getDisplayableObject(0));
            bird->applyJump();
            break;

    }

}


void Psybw7Engine::virtMouseDown(int iButton, int iX, int iY){


    if(iButton == 3){
        std::cout << "X = " << iX << " Y = " << iY << std::endl;
        std::cout << std::hex << m_tile_map.getMapValue(2, 0) << std::endl;
    }

    strIndex = (strIndex >= bgStrings.size()-1) ? 0 : strIndex + 1;
    strIndexY++;
    this->drawBackgroundString(this->getBackgroundSurface()->getSurfaceWidth()/3-100,this->getBackgroundSurface()->getSurfaceHeight()/4+(strIndexY*20),bgStrings[strIndex].data(),0xFF0000);
    

}

void Psybw7Engine::virtMainLoopStartIteration(){

    redrawDisplay();

}

void Psybw7Engine::virtDrawStringsOnTop(){

    drawForegroundString(100,100,foreground_label.data(),0xFF0000);

}