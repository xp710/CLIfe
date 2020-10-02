#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include "lifeboard.h"
#include "cursor.h"

class Engine
{
private:
    //The board
    LifeBoard* board;
    
    //The cursor
    Cursor cursor;

    //Logic
    bool running = true;
    bool mode = false; //If it's true, that means it's edit mode, if false, that means it's view mode. 

    //Private functions
    void toCheck(); //Checks the spaces toLive and toDie functions and updates accordingly
    void setTos(); //Sets the toLive and toDie functions of every space according to their neighbors
    void edit(); //Takes input so the user can directly interact with the board.

public:
    //Accessor
    bool isRunning();

    Engine();
    Engine(int p_x, int p_y);
    ~Engine() = default;

    //Functions
    void takeTurn();
    void dispBoard();
};

#endif // ENGINE_H
