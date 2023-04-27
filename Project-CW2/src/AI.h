#pragma once
#include <memory>
#include "LevelLoader.h"
#include "Player.h"


// https://www.youtube.com/watch?v=aKYlikFAV4k&list=TLPQMTgwNDIwMjOo2ID2vI-p4A
// https://www.youtube.com/watch?v=EaZxUCWAjb0&list=TLPQMTgwNDIwMjOo2ID2vI-p4A

// f(n) = g(n) + h(n) 

struct leeNode {

	int x;
	int y;
	int distance; 
};


struct Node {

	//int f; // f(n) = g(n) + h(n) 
	//int g; // g(n) is the cost of the path from the start node to n
	//int h; // hueristic (estimates the cost of the cheapest path from n to the goal)
	int x; // literal x position of node
	int y; // literal y position of node
	int dist;
	bool visited;
	bool valid; // says if tile can be walked on or not

	Node* previous;

	std::vector<Node> neighbour_nodes;

};


class AI
{

protected:

	std::vector<std::vector<Node>> m_nodes; // <- this is the set of nodes for the tilemap but in the context of a* (maybe change this since tilemap has x and y)

	std::vector<Node> m_openSet;

	std::vector<Node> m_closedSet;

	Node m_start; //start < -where enemy is currently

	Node m_end;	  // end   <- where player is 

	std::pair<int, int> m_playerPosition;

	// grid is 25x25, for better code, this would want to be set via some function
	const int m_w = 25;
	const int m_h = 25;

public:


	std::vector<std::vector<Node>> generateNodes(std::vector<std::shared_ptr<TileMap>> TM);

	void setFirstNode(int x, int y);

	void setPlayerNode(int x, int y);

	void addNeighbourNodes(std::vector<Node>& nodes, Node self);

	void removeNode(Node node, std::vector<Node> nodes);

	std::vector<std::pair<int, int>> pathing(Node start, Node end);

};

