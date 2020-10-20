#include "lifeboard.h"

void LifeBoard::initBoard(int p_x, int p_y){
    /*
     * Initialize the board by first making a 1d vector of Spaces of the x size.
     * Then, put y of those into board.
     */
    std::vector<Space> tmp(p_x, Space(false));
    board = std::vector<std::vector<Space>>(p_y, tmp);
}

LifeBoard::LifeBoard(int p_x, int p_y){
    initBoard(p_x, p_y);
}

int LifeBoard::sizeX(){
    /*
     * Return the size of the board's x axis.
     */
    return board[0].size();
}

int LifeBoard::sizeY(){
    /*
     * Return the size of the board's y axis.
     */
    return board.size();
}

Space LifeBoard::boardSpace(int p_x, int p_y){
    //Return the space at the given coords.
    return board[p_y][p_x];
}

bool LifeBoard::spaceHasNeighbors(int p_x, int p_y, int p_neighbors){
    /*
     * Look at each neighbor of the space of the given coord.
     * If it has exactly p_neighbors neighbors, return true,
     * else, return false.
     */

    int numberOfNeighbors = 0;

    //Make sure we can test 1 above the space and do so
    if (p_y - 1 >= 0){
        //Up left
        if (p_x - 1 >= 0){
            if (board[p_y - 1][p_x - 1].isAlive()){
                numberOfNeighbors++;
            }
        }
        //Directly above
        if (board[p_y - 1][p_x].isAlive()){
            numberOfNeighbors++;
        }
        //Up right{
        if (p_x + 1 < (int)board[0].size()){
            if (board[p_y - 1][p_x + 1].isAlive()){
                numberOfNeighbors++;
            }
        }
    }
    //Left
    if (p_x - 1 >= 0){
        if (board[p_y][p_x - 1].isAlive()){
            numberOfNeighbors++;
        }
    }
    //Right
    if (p_x + 1 < (int)board[0].size()){
        if (board[p_y][p_x + 1].isAlive()){
            numberOfNeighbors++;
        }
    }
    if (p_y + 1 < (int)board.size()){
        //Bottom left
        if (p_x - 1 >= 0){
            if (board[p_y + 1][p_x - 1].isAlive()){
                numberOfNeighbors++;
            }
        }
        //Directly below
        if (board[p_y + 1][p_x].isAlive()){
            numberOfNeighbors++;
        }
        //Bottom right
        if (p_x + 1 < (int)board[0].size()){
            if (board[p_y + 1][p_x + 1].isAlive()){
                numberOfNeighbors++;
            }
        }
    }
    if (numberOfNeighbors == p_neighbors){
        return true;
    }else{
        return false;
    }
}

void LifeBoard::setSpaceLife(int p_x, int p_y, bool p_life){
    /*
     * Sets the given space to alive or dead depending on the bool
     */
    board[p_y][p_x].setLife(p_life);
}

void LifeBoard::setSpaceToLive(int p_x, int p_y, bool p_toLive){
    board[p_y][p_x].setToLive(p_toLive);
}
