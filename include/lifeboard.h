#ifndef LIFEBOARD_H
#define LIFEBOARD_H

#include <vector>
#include "space.h"

class LifeBoard {
private:
    //The board
    std::vector<std::vector<Space>> board;

public:
    LifeBoard();
    LifeBoard(int p_x, int p_y);
    ~LifeBoard() = default;

    void initBoard(int p_x, int p_y);

    //Accessing spaces
    int sizeX();
    int sizeY();
    Space boardSpace(int p_x, int p_y);
    bool spaceHasNeighbors(int p_x, int p_y, int p_neighbors); //Test space for p_neighbors neighbors

    //Controlling spaces
    void setSpaceLife(int p_x, int p_y, bool p_life);
    void setSpaceToLive(int p_x, int p_y, bool p_toLive);
    void setSpaceToDie(int p_x, int p_y, bool p_toDie);
};


#endif // LIFEBOARD_H
