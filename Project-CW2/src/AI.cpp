#include "AI.h"
#include <algorithm>
#include <cstdlib>
#include <queue>


bool operator==(const Node& lhs, const Node& rhs) // check equivalence between nodes
{

    return (
        //lhs.f == rhs.f          &&
        //lhs.g == rhs.g          &&
        //lhs.h == rhs.h          &&
        lhs.x == rhs.x          &&
        lhs.y == rhs.y         /* &&*/
        //lhs.valid == rhs.valid  &&
        //lhs.neighbour_nodes == rhs.neighbour_nodes
        );
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

	return temp;
}


void AI::setFirstNode(int x, int y) {

    // What tile we are actually on 
    int x_t = x / 32 + 1;
    int y_t = y / 32 + 2; //  + 1

    if (x_t > 24) {
        x_t = 24;
    }
    if (y_t > 24) {
        y_t = 24;
    }

    Node self = m_nodes[x_t][y_t];

    m_start = self;

}

void AI::setPlayerNode(int x, int y) {

    // What tile we are actually on 
    int x_t = x / 32 + 1;
    int y_t = y / 32 + 1;

    if (x_t > 24) {
        x_t = 24;
    }
    if (y_t > 24) {
        y_t = 24;
    }

    Node enemy = m_nodes[x_t][y_t];

    m_end = enemy;
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
    Node neighbour;
    Node nNeighbour;

    // ONLY ALLOWS  NON-DIAGONALS AND NO SUBSCRIPT ERROR
    if (self.x < m_h-1) {
    
        neighbour = m_nodes[self.x + 1][self.y];
        nNeighbour = Node{
            neighbour.x,
            neighbour.y,
            INT_MAX,
            false,
            neighbour.valid
            

        };
        nodes.push_back(nNeighbour);
    }
    if (self.x > 0) { 
     
        nNeighbour = Node{
            neighbour.x,
            neighbour.y,
            INT_MAX,
            false,
            neighbour.valid

        };
        neighbour = m_nodes[self.x - 1][self.y];


        nodes.push_back(nNeighbour);
    }
    if (self.y < m_w-1) {
      
        nNeighbour = Node{
            neighbour.x,
            neighbour.y,
            INT_MAX,
            false,
            neighbour.valid

        };
        neighbour = m_nodes[self.x][self.y + 1];


        nodes.push_back(nNeighbour);
    }
    if (self.y > 0) { 
    
        nNeighbour = Node{
            neighbour.x,
            neighbour.y,
            INT_MAX,
            false,
            neighbour.valid

        };
        neighbour = m_nodes[self.x][self.y - 1];

        nodes.push_back(nNeighbour);
    }
 


}


std::vector<std::pair<int, int>> getPath(std::vector<leeNode> path) {
    
    std::vector<std::pair<int, int>> _path;

    for (int i = 0; i < path.size(); i++) {
        _path.push_back(std::make_pair(path[i].x, path[i].y));
    }

    return _path;

}



std::vector<std::pair<int, int>> AI::pathing(Node start, Node end) {

    int dl[] = { -1, 0, 1, 0 }; // these arrays will help you travel in the 4 directions more easily
    int dc[] = { 0, 1, 0, -1 };

    bool visited[25][25] = { false };
    int  distances[25][25] = { 0 };

    std::vector<std::pair<int, int>> uninit(1,std::make_pair<int,int>(-100,-100));

    std::queue<leeNode> queue; 

    visited[start.x][start.y] = true;
    
    queue.push(leeNode{ start.x,start.y,0 });
    std::vector<leeNode> steps;
    std::vector<leeNode> steps2;

    while (!(queue.empty())) 
    {
        int px, py;
        leeNode current = queue.front();
        queue.pop();
        px = current.x;
        py = current.y;
        

        if (px == end.x && py == end.y) {

            for (int i = 0; i < steps.size(); i++) {

                int sx = steps[i].x;
                int sy = steps[i].y;

                if (std::abs(sx - current.x) <= 1 && std::abs(sy - current.y) <= 1 && steps[i].distance ==  current.distance - 1) {
                    steps2.push_back(steps[i]);
                    current = steps[i];
                   
                    if (steps[i].distance == 1) {
                        
                        break;
                    }
                    i = 0;
                }
              


            }

            return getPath(steps2);
        }

        for (int i = 0; i < 4; i++) {
            int row = px + dl[i];
            int col = py + dc[i];
        
            if (
                row >= 0 && row < m_h
                && col >= 0 && col < m_w 
                && m_nodes[col][row].valid
                && visited[row][col] == false) {


                visited[row][col] = true;
                distances[row][col] = current.distance + 1;


                queue.push(leeNode{ row,col,current.distance + 1 });
                steps.push_back(current);


            }

        }


    }

    return uninit;

}