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
	//m_imgDist = std::make_shared<ImageDistorter>(m_pEngine, pX,pY);

}

void Projectile::virtDraw() {

	m_projectileSprite.renderImageWithMask(m_pEngine->getForegroundSurface(), 0, 0, m_xPos, m_yPos, m_projectileSprite.getWidth(), m_projectileSprite.getHeight(),0x00FF00);
	
	internalUpdate();

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


//int Projectile::getColAtPixel(int x, int y) {
//
//	return m_projectileSprite.getPixelColour(x + m_xPos, y + m_yPos);
//}

