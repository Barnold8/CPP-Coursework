#pragma once

#include "DisplayableObject.h"
#include "Image.h"				// Image in here so we dont have to worry about including it later on for sub classes
#include <vector>

enum Movement {

	RIGHT,
	UP,
	LEFT,
	DOWN,

};

enum animState {

	IDLE,
	RUNNING,

};


class Entity : public DisplayableObject {

protected:

	int m_xPos;
	int m_yPos;
	int m_speed;
	bool m_collided; // May not even be used lol
	int	 m_collisionCoolDown;

public:


	Entity(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY);

	virtual void virtDraw() override;

	virtual void virtKeyDown(int iKeyCode) override;

	virtual bool internalUpdate();

	void setCollided(bool c);

};

