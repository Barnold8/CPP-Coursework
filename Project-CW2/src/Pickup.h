#pragma once

#include "Entity.h"

class Pickup : public Entity
{

private:

	int m_subID; // clarifies the type of pickup for collision detection
	SimpleImage m_asset;


public:

	Pickup(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string asset);


};

