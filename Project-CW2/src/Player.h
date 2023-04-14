#pragma once
#include "Person.h"


class Player : public Person {


private:

	int m_projCap;
	int m_projStart;
	int m_projSize;
	bool m_replace;		// Used to say if the objects in the object array are replaced in memory. 

public:

	Player(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running);

	Player(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY);

	Player(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY, std::string name);

	Player(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY, std::string name, int health);
	
	void virtKeyDown(int iKeyCode) override;

	void addProjectile(Movement direction);



};

