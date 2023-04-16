#include "header.h"
#include "Collider.h"
#include "Entity.h"
#include "DisplayableObject.h"


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
