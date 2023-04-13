#pragma once
#include "Entity.h"
#include "ImageDistorter.h"
// this class is used to make projectiles. 

// any subclass of this will be used for different kinds of projectiles 

class Projectile : public Entity {

protected:

	SimpleImage m_projectileSprite;
	ImageDistorter* m_imgDist;
	Movement	m_direction;
	int			m_tick;

public:

	Projectile(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string sprite, Movement dir, int pX, int pY, int speed);

	virtual void virtDraw() override;

};

