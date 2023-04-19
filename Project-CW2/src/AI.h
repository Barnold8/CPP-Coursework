#pragma once
#include <memory>
#include "LevelLoader.h"
#include "Player.h"


// https://www.youtube.com/watch?v=aKYlikFAV4k&list=TLPQMTgwNDIwMjOo2ID2vI-p4A
// https://www.youtube.com/watch?v=EaZxUCWAjb0&list=TLPQMTgwNDIwMjOo2ID2vI-p4A

// f(n) = g(n) + h(n) 


struct Node {

	int f; // f(n) = g(n) + h(n) 
	int g; // g(n) is the cost of the path from the start node to n
	int h; // hueristic (estimates the cost of the cheapest path from n to the goal)
	int x; // literal x position of node
	int y; // literal y position of node
	bool valid; // says if tile can be walked on or not 


};


class AI
{

protected:

	std::vector<std::vector<Node>> m_nodes; // <- this is the set of nodes for the tilemap but in the context of a* (maybe change this since tilemap has x and y)


public:


	void AIProc(std::shared_ptr<LevelLoader> LL); // ai processing

	std::vector<std::vector<Node>> generateNodes(std::vector<std::shared_ptr<TileMap>> TM);


};

