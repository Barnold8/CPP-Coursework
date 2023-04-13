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
	m_imgDist = new ImageDistorter(m_pEngine);

}

void Projectile::virtDraw() {

	m_projectileSprite.renderImage(m_pEngine->getForegroundSurface(), 0, 0, m_xPos, m_yPos, m_projectileSprite.getWidth(), m_projectileSprite.getHeight());
	
	if (m_tick % 200 == 0) {
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

	double x = 10.0;
	double y = 10.0;

	m_imgDist->mapCoordinates(x, y, m_projectileSprite);

	
}