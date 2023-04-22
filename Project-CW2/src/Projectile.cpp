#include "header.h"
#include "Projectile.h"
#include "BaseEngine.h"

Projectile::Projectile(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string sprite, Movement dir, int pX, int pY, int speed) : Entity(pEngine, iWidth, iHeight, useTopLeftFor00, objX, objY) {

	m_projectileSprite = ImageManager::loadImage(sprite, true);
	m_direction = dir;
	m_xPos  = pX;
	m_yPos  = pY;
	m_speed = speed;
	m_tick  = 0;
	ID = 3;
	//m_imgDist = std::make_shared<ImageDistorter>(m_pEngine, pX,pY);

}

void Projectile::virtDraw() {

	Office_Apocalypse* M = dynamic_cast<Office_Apocalypse*>(m_pEngine);

	if (!(M->isPaused())) {


		m_projectileSprite.renderImageWithMask(m_pEngine->getForegroundSurface(), 0, 0, m_xPos, m_yPos, m_projectileSprite.getWidth(), m_projectileSprite.getHeight(), 0x00FF00);

		internalUpdate();

		if (isCollided(m_pEngine) == 2 || isCollided(m_pEngine) == 3) {

			setVisible(false);
			m_xPos = m_pEngine->getBackgroundSurface()->getSurfaceWidth() * 2; // hide the element and put it out of screen until its overwritten
			m_speed = 0;
		}

		if (m_tick % 100 == 0) {

			switch (m_direction) {

			case RIGHT:
				m_xPos += m_speed;
				break;

			case LEFT:
				m_xPos -= m_speed;
				break;

			case UP:
				m_yPos -= m_speed;
				break;

			case DOWN:
				m_yPos += m_speed;
				break;

			default:
				break;
			}
		}
		m_tick += 10;


		//m_imgDist->setX(m_xPos);
		//m_imgDist->setY(m_yPos);

	}
}


int  Projectile::getX() { return m_xPos; }

int  Projectile::getY()  { return m_yPos; }

int Projectile::distance(int x, int y) {
	return std::abs((m_xPos + m_yPos) - (x + y));
}


void Projectile::setPrevious(Projectile* p) {
	m_prev = p;
}


void Projectile::setXY(int x, int y) {
	m_xPos = x;
	m_yPos = y;
}


int Projectile::getColAtPixel(int x, int y) {

	return m_projectileSprite.getPixelColour(x - m_xPos, y - m_yPos);
}


rect Projectile::getRect() {

	return rect{ m_xPos,m_yPos,m_projectileSprite.getWidth(),m_projectileSprite.getHeight()};
}



//struct DATA {
//
//	// BOTH
//	int _m_xPos;
//	int _m_yPos;
//	int _m_speed;
//	bool _m_collided; // May not even be used lol
//	int	 _m_collisionCoolDown;
//	// BOTH
//
//	// Person
//	std::string _m_personName;									 // Allows name above person to be different
//	Movement	_m_direction;									 // enum for the player looking direction
//	animState	_m_animState;									 // enum for the animation state
//	int			_m_runTimer;										 // time after last key update
//	int			_m_runCycle;										 // number counted to tick over next anim frame
//	int			_m_runTick;										 // number to use in animation frame formula
//	int			_m_healthAmount;									 // amount of health user has
//	int			_m_spriteOffset;
//	int			_m_collisionMask;								 // the colour used to say what is a valid pixel for collision
//	bool		_m_renderHealth;
//	// Person
//
//	// Projectile
//	Projectile* _m_prev;
//	int			_m_tick;
//	// Projectile
//};


DATA Projectile::getData() {
	
	DATA d = {
		
		m_xPos,
		m_yPos,
		m_speed,
		m_collided,
		m_collisionCoolDown,
		"",
		NONE,
		IDLE,
		0,0,0,0,0,0,0,
		m_prev,
		m_tick
		

	};
	return d;
}