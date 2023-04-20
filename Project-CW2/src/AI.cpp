#include "AI.h"
#include <algorithm>
#include <cstdlib>


bool operator==(const Node& lhs, const Node& rhs) // check equivalence between nodes
{

    return (
        lhs.f == rhs.f          &&
        lhs.g == rhs.g          &&
        lhs.h == rhs.h          &&
        lhs.x == rhs.x          &&
        lhs.y == rhs.y          &&
        lhs.valid == rhs.valid  &&
        lhs.neighbour_nodes == rhs.neighbour_nodes
        );
}

bool AI::AIProc() {

    int x = 0;
    bool found = false; // states whether the alogrithm found a route. Should always be true due to the nature of the maps but this metric makes a good tool for debugging
    std::vector<Node*> path;

    while (m_openSet.size() > 0) {

        int lowest = 0;

        for (size_t i = 0; i < m_openSet.size(); i++)
        {   
            if (m_openSet[i].f < m_openSet[lowest].f) {
                lowest = i;
            }

        }

        Node current = m_openSet[lowest];



        if(current == m_end){

            found = true;

            //while(current.previous != nullptr){
            //    path.push_back(current.previous);
            //    current = *current.previous;
            //    std::cout << "ff" << std::endl;
            //}

            std::cout << "Endd" << std::endl;

            break;
        }
        
        removeNode(current, m_openSet);
        m_closedSet.push_back(current);
       
        std::vector<Node> neighbours = current.neighbour_nodes;

        for (size_t i = 0; i < neighbours.size(); i++)
        {
            Node neighbour = neighbours[i];

             //if neighbour not in closed set
            if (!(std::find(m_closedSet.begin(), m_closedSet.end(), neighbour) != m_closedSet.end()) ) {
                int tentativeG = current.g + 1;
                // if neighbour in openset 
                if (std::find(m_openSet.begin(), m_openSet.end(), neighbour) != m_openSet.end()) {
                    if (tentativeG < neighbour.g) {
                        neighbour.g = tentativeG;
                    }
                    else {
                        neighbour.g = tentativeG;
                        m_openSet.push_back(neighbour);
                    }
                
                }
                neighbour.h = hueristic(neighbour, m_end);
                neighbour.f = neighbour.g + neighbour.h;
                neighbour.previous = &current;
            }
            
        }

        std::cout << "Open set " << m_openSet.size() << std::endl;

    }
    //std::cout << "asdasd" << std::endl;


    return found;
}

bool AI::AIProc(BaseEngine* engine) {

    int x = 0;
    bool found = false; // states whether the alogrithm found a route. Should always be true due to the nature of the maps but this metric makes a good tool for debugging
    std::vector<Node*> path;

    while (m_openSet.size() > 0) {

        int lowest = 0;

        for (size_t i = 0; i < m_openSet.size(); i++)
        {
            if (m_openSet[i].f < m_openSet[lowest].f) {
                lowest = i;
            }

        }

        Node current = m_openSet[lowest];

        engine->lockBackgroundForDrawing();
        engine->drawBackgroundRectangle(current.x, current.y, current.x * 32, current.y * 32, 0x00FF00);
        engine->unlockBackgroundForDrawing();


        if (current == m_end) {

            found = true;

            //while(current.previous != nullptr){
            //    path.push_back(current.previous);
            //    current = *current.previous;
            //    std::cout << "ff" << std::endl;
            //}

            std::cout << "Endd" << std::endl;

            break;
        }

        removeNode(current, m_openSet);
        m_closedSet.push_back(current);

        std::vector<Node> neighbours = current.neighbour_nodes;

        for (size_t i = 0; i < neighbours.size(); i++)
        {
            Node neighbour = neighbours[i];

            //if neighbour not in closed set
            if (!(std::find(m_closedSet.begin(), m_closedSet.end(), neighbour) != m_closedSet.end())) {
                int tentativeG = current.g + 1;
                // if neighbour in openset 
                if (std::find(m_openSet.begin(), m_openSet.end(), neighbour) != m_openSet.end()) {
                    if (tentativeG < neighbour.g) {
                        neighbour.g = tentativeG;
                    }
                    else {
                        neighbour.g = tentativeG;
                        m_openSet.push_back(neighbour);
                    }

                }
                neighbour.h = hueristic(neighbour, m_end);
                neighbour.f = neighbour.g + neighbour.h;
                neighbour.previous = &current;
            }

        }

        std::cout << "Open set " << m_openSet.size() << std::endl;

    }
    //std::cout << "asdasd" << std::endl;


    return found;
} 


std::vector<std::vector<Node>> AI::generateNodes(std::vector<std::shared_ptr<TileMap>> TM) {

    // define dimensions of the grid
	const int rows = 25;
	const int cols = 25;
    // define dimensions of the grid

    // init the set of nodes (2D array) to max row count;
	std::vector<std::vector<Node>> temp(25); // default data is needed to index this
    for (int i = 0; i < 25; i++) {
        temp[i].resize(25);
    }
    // init the set of nodes (2D array) to max row count;

    // 2d int array of ints to determine valid tiles
    int tiles[rows][cols];
    // 2d int array of ints to determine valid tiles
    
    // set tiles to respective 1/0  1 = valid tile | 0 = invalid tile 
    for (int a = 0; a < TM.size(); a++) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (a == 0) {
                        switch (TM[a]->getMapValue(j, i)) {
                        case 104:

                            tiles[i][j] = 1;
                            break;
                        case 105:
                            tiles[i][j] = 1;
                            break;
                        case 103:
                            tiles[i][j] = 1;
                            break;
                        case 88:
                            tiles[i][j] = 1;
                            break;
                        case 87:
                            tiles[i][j] = 1;
                            break;
                        case 86:
                            tiles[i][j] = 1;
                            break;
                        case 89:
                            tiles[i][j] = 1;
                            break;
                        case 13:
                            tiles[i][j] = 1;
                            break;
                        case 33:
                            tiles[i][j] = 1;
                            break;
                        case 32:
                            tiles[i][j] = 1;
                            break;
                        default:
                            tiles[i][j] = 0;
                            break;
                        }
                    }
                    else if (TM[a]->getMapValue(j, i) != 0) {
                        tiles[i][j] = 1;
                    }
                }
            }

    }
    // set tiles to respective 1/0  1 = valid tile | 0 = invalid tile 


    // set node data 
    std::cout << "======= AI GRID =======\n" << std::endl;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            temp[i][j].valid = !tiles[i][j];
            temp[i][j].x = i;
            temp[i][j].y = j;
            std::cout << temp[i][j].valid;
        }
        std::cout << "\n";
    
    }
    // set node data 

    // add neighbour nodes to parent node 
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            addNeighbourNodes(temp[i][j].neighbour_nodes, temp[i][j]);
        }
    }
    // add neighbour nodes to parent node 


	return temp;
}

std::vector<std::vector<Node>> AI::generateNodes(std::vector<std::shared_ptr<TileMap>> TM, BaseEngine* engine) {

    // define dimensions of the grid
    const int rows = 25;
    const int cols = 25;
    // define dimensions of the grid

    // init the set of nodes (2D array) to max row count;
    std::vector<std::vector<Node>> temp(25); // default data is needed to index this
    for (int i = 0; i < 25; i++) {
        temp[i].resize(25);
    }
    // init the set of nodes (2D array) to max row count;

    // 2d int array of ints to determine valid tiles
    int tiles[rows][cols];
    // 2d int array of ints to determine valid tiles

    // set tiles to respective 1/0  1 = valid tile | 0 = invalid tile 
    for (int a = 0; a < TM.size(); a++) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (a == 0) {
                    switch (TM[a]->getMapValue(j, i)) {
                    case 104:

                        tiles[i][j] = 1;
                        break;
                    case 105:
                        tiles[i][j] = 1;
                        break;
                    case 103:
                        tiles[i][j] = 1;
                        break;
                    case 88:
                        tiles[i][j] = 1;
                        break;
                    case 87:
                        tiles[i][j] = 1;
                        break;
                    case 86:
                        tiles[i][j] = 1;
                        break;
                    case 89:
                        tiles[i][j] = 1;
                        break;
                    case 13:
                        tiles[i][j] = 1;
                        break;
                    case 33:
                        tiles[i][j] = 1;
                        break;
                    case 32:
                        tiles[i][j] = 1;
                        break;
                    default:
                        tiles[i][j] = 0;
                        break;
                    }
                }
                else if (TM[a]->getMapValue(j, i) != 0) {
                    tiles[i][j] = 1;
                }
            }
        }

    }
    // set tiles to respective 1/0  1 = valid tile | 0 = invalid tile 


    // set node data 
    std::cout << "======= AI GRID =======\n" << std::endl;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            temp[i][j].valid = !tiles[i][j];
            temp[i][j].x = i;
            temp[i][j].y = j;
            temp[i][j].neighbour_nodes.clear();
            std::cout << temp[i][j].valid;
        }
        std::cout << "\n";

    }
    // set node data 



    
    return temp;
}


//
//struct Node {
//
//    int f; // f(n) = g(n) + h(n) 
//    int g; // g(n) is the cost of the path from the start node to n
//    int h; // hueristic (estimates the cost of the cheapest path from n to the goal)
//    int x; // literal x position of node
//    int y; // literal y position of node
//    bool valid; // says if tile can be walked on or not 
//
//
//};


void AI::setFirstOpenNode(int x, int y) {

    // What tile we are actually on 
    int x_t = x / 32 + 1;
    int y_t = y / 32 + 1;

    

    m_openSet.push_back(Node{ 0,0,0,x_t,y_t });


}

void AI::setFirstOpenNode(int x, int y, BaseEngine* engine) {

    // What tile we are actually on 
    int x_t = x / 32 + 1;
    int y_t = y / 32 + 1;


    Node enemy = Node{ 0,0,0,x_t,y_t };

    m_openSet.push_back(enemy);
    



    m_start = enemy;
}

void AI::setPlayerNode(int x, int y) {

    int x_t = x / 32 + 1;
    int y_t = y / 32 + 1;

    Node player = Node{ 0,0,0,x_t,y_t };

    m_nodes[x_t][y_t] = player; // sets end node 

  
    m_end = player;
}

void AI::setPlayerNode(int x, int y, BaseEngine* engine) {
    
    int x_t = x / 32 + 1;
    int y_t = y / 32 + 1;

    Node player = Node{ 0,0,0,x_t,y_t, m_nodes[x_t][y_t].valid };

    m_nodes[x_t][y_t] = player; // sets end node 

    //engine->lockBackgroundForDrawing();
    //engine->drawBackgroundRectangle(x_t*32, y_t*32, x_t*32 + 32, y_t*32 + 32,0xFF0000);
    //engine->unlockBackgroundForDrawing();

    m_end = player;
    


    for (int i = 0; i < m_nodes.size(); i++) {
        for (size_t j = 0; j < m_nodes[i].size(); j++)
        {
           
            int color = (m_nodes[i][j].valid == 1) ? 0xFFFFFF : 0x000000;
            engine->lockBackgroundForDrawing();
            engine->drawBackgroundRectangle(j * 32, i * 32, j * 32 + 32, i * 32 + 32, color);
            engine->unlockBackgroundForDrawing();;

        }

    }

}

void AI::removeNode(Node node, std::vector<Node> nodes) {

    for (int i = nodes.size() -1 ; i >= 0; i--) {
   
        if (node == nodes[i]) {
            //std::cout << "nodes size before " << nodes.size() << std::endl;

            // remove node
            nodes.erase(nodes.begin() + i);

            //std::cout << "nodes size after " << nodes.size() << std::endl;
        }
        
    }
}


void AI::addNeighbourNodes(std::vector<Node>& nodes, Node self) { 
    
    //std::cout << "Self.x: " << self.x << " | Self.y: " << self.y << std::endl;
    
    // ONLY ALLOWS  NON-DIAGONALS AND NO SUBSCRIPT ERROR
    if (self.x < m_h-1) {nodes.push_back(m_nodes[self.x + 1][self.y]);}
    if (self.x > 0) { nodes.push_back(m_nodes[self.x - 1][self.y]); }
    if (self.y < m_w-1) { nodes.push_back(m_nodes[self.x][self.y + 1]); }
    if (self.y > 0) { nodes.push_back(m_nodes[self.x][self.y - 1]); }
 
    //std::cout << "adsasd" << std::endl;

}


int AI::hueristic(Node n, Node e) {
   
    return std::abs(n.x - e.x) + std::abs(n.y - e.y);
}