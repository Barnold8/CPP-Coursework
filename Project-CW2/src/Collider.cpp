#include "header.h"
#include "Collider.h"
#include "Entity.h"
#include "DisplayableObject.h"
#include "BaseEngine.h"


rect Collider::rectToRect(rect r1, rect r2){

    rect output = {0,0,0,0};
    rect left = (r1.x > r2.x) ? r2: r1 ;
    rect top = (r1.y > r2.y) ? r2 : r1;

    if (

        r1.x < r2.x + r2.w &&
        r1.x + r1.w > r2.x &&
        r1.y < r2.y + r2.h &&
        r1.h + r1.y > r2.y){
    

        output.x = std::max(r1.x, r2.x);
        output.w = std::min(r1.x + r1.w, r2.x + r2.w) - output.x;
        output.y = std::max(r1.y, r2.y);
        output.h = std::min(r1.y + r1.h, r2.y + r2.h) - output.y ;

    }
 
    return output;

}



//IDEA: get the area of each tile occupied by something that isnt a floor and check for a collision there. Not sure if possible to get the image from the tile itself though

bool Collider::canMove(std::shared_ptr<LevelLoader> LL, int x, int y, bool isFloor) {
    
    std::shared_ptr<TileMap> F = LL->getMaps()[!isFloor];
    int x_t = x / 32 + 1;
    int y_t = y / 32 + 1;
    int tileValue = F->getMapValue(x_t, y_t);
    //std::cout << x / 32 << " " << y / 32 << std::endl;

    //F->setMapValue(x / 32 + 1, y / 32 + 1, 102);
    //F->getTileHeight();
    //F->drawAllTiles(engine,engine->getBackgroundSurface());
    if (isFloor) {
        switch (tileValue) {

        case 104:
            return true;
        case 105:
            return true;
        case 103:
            return true;
            break;
        case 88:
            return true;
        case 87:
            return true;
        case 86:
            return true;
        case 89:
            return true;
        case 13:
            return true;
        case 33:
            return true;
        case 32:
            return true;
        default:
            /*std::cout << F->getMapValue(x_t, y_t) << std::endl*/;
            break;
        }
    }
    else if(tileValue != 0) {
        return true;
    }



    return false;
}

int Collider::isCollided(BaseEngine* engine) { // RETURN THE ID OF THE COLLIDER OBJECT INSTEAD OF A BOOL. with this we can do some object conditional processing

    rect r1 = getRect();

    for (int i = 0; i < engine->getContentCount(); i++) {
        Collider* c = dynamic_cast<Collider*>(engine->getDisplayableObject(i));
        if (c != nullptr && c != this) {
            rect r2 = c->getRect();
            rect area = rectToRect(r1, r2);
            for (int x = area.x; x < area.x + area.w; x++) {

                for (int y = area.y; y < area.y + area.h; y++) {

                    int myPixel = getColAtPixel(x, y);
                    int otherpixel = c->getColAtPixel(x, y);

                    if (myPixel != 0x00FF00 && otherpixel != 0x00FF00) {
                        //engine->rawSetBackgroundPixel(x, y, 0X821ce8);
     
                        return c->ID;
                    }

                }

            }
        }
    }
    
    return false;
}

int Collider::getID() {
    return ID;
}
//
//DisplayableObject* d1;
//DisplayableObject* d2;
//Entity* e1;
//Entity* e2;
//
//int object_count = b->getContentCount();
//
//for (int i = 0; i < object_count; i++) { // WHATS THIS? LIKE O^4
//	d1 = b->getDisplayableObject(i);
//	e1 = dynamic_cast<Entity*>(d1);
//
//	if (d1 != nullptr) { // check if left elem is null or not, if it is not, we can check for collisions
//
//		for (int j = 0; j < object_count; j++) {
//			if (i != j) {
//				d2 = b->getDisplayableObject(j);
//				e2 = dynamic_cast<Entity*>(d2);
//				if (d2 != nullptr) {
//					std::vector<std::pair<int, int>> l_pair = e1->getCoords();
//					std::vector<std::pair<int, int>> r_pair = e2->getCoords();
//
//					for (int a = 0; a < l_pair.size(); a++) {
//
//						for (int b = 0; b < r_pair.size(); b++) {
//							if (l_pair[a] == r_pair[b]) {
//
//								e1->setCollided(true);
//								e2->setCollided(true);
//								break;
//							}
//						}
//					}
//
//				}
//
//			}
//
//		}
//
//	}
//
//}
//
