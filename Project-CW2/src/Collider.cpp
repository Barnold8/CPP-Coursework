#include "header.h"
#include "Collider.h"
#include "Entity.h"
#include "DisplayableObject.h"



void Collider::updateObjs(BaseEngine* b) { // WORK ON THIS

	DisplayableObject* d;
	Entity* e;

	for (int i = 0; i < b->getContentCount();i++) {
		d = b->getDisplayableObject(i);
		if (d != nullptr) {
		
			e = dynamic_cast<Entity*>(d);
			std::vector<std::pair<int, int>> p = e->getCoords();
			for (int i = 0; i < p.size(); i++) { // go through all coords and render for testing
				b->lockBackgroundForDrawing();
				//std::cout << "ffff" << std::endl;
				//m_pEngine->rawSetBackgroundPixel(m_collisionCoords[i].first, m_collisionCoords[i].second, 0xFFFFFF);
				b->rawSetBackgroundPixel(p[i].first, p[i].second, 0x00CCFF);
				b->unlockBackgroundForDrawing();
			}
			
		}
	
	}
}

// TESTING

// TESTING