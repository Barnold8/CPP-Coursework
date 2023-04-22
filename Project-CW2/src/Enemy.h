#pragma once
#include "Person.h"
#include "AI.h"


class Enemy : public Person, public AI {

private:

	Player* m_player; // needed so AI can track player

	std::pair<int, int> m_lastKnownLocation;

public:

	Enemy(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running);

	Enemy(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY);

	Enemy(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY, std::string name);

	Enemy(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY, std::string name, int offset);

	Enemy(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string idle, std::string running, int pX, int pY, std::string name, int offset, std::shared_ptr<LevelLoader> LL, Player* player);

	void virtKeyDown(int iKeyCode) override;
	
	bool internalUpdate() override;
};

