#include "AI.h"

void AI::AIProc(std::shared_ptr<LevelLoader> LL) {



}


std::vector<std::vector<Node>> AI::generateNodes(std::vector<std::shared_ptr<TileMap>> TM) {

	const int rows = 25;
	const int cols = 25;

	std::vector<std::vector<Node>> temp(25);
    for (int i = 0; i < 25; i++) {
        temp[i].resize(25);
    }
    int tiles[rows][cols];

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


    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            temp[i][j].valid = !tiles[i][j];
            std::cout << temp[i][j].valid;
        }
        std::cout << "\n";
    
    }


	return temp;
}