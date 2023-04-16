#pragma once
#include "Entity.h"
#include "ImageDistorter.h"
#include "Collider.h"
// this class is used to make projectiles. 

// any subclass of this will be used for different kinds of projectiles 

class Projectile : public Entity {

protected:

	SimpleImage m_projectileSprite;
	Projectile* m_prev; 
	Movement	m_direction;
	int			m_tick;

public:

	Projectile(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string sprite, Movement dir, int pX, int pY, int speed);

	virtual void virtDraw() override;

	int getX();

	int getY();

	int distance(int x, int y);

	void setPrevious(Projectile* p);

	void setXY(int x, int y);

	//int getColAtPixel(int x, int y) override;

};

