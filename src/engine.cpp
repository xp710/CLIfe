#include "engine.h"

void Engine::toCheck(){
    /*
     * Look at every space on the board.
     * Check to see if toLive or toDie is true.
     * If either one is true, set it to alive or dead.
     * Set both toLive and toDie to false.
     */
    for (int y = 0; y < board.sizeY(); y++){
        for (int x = 0; x < board.sizeX(); x++){
            if (board.boardSpace(x, y).toLive()){
                board.setSpaceLife(x, y, true);
                board.setSpaceToLive(x, y, false);
            }else if (board.boardSpace(x, y).toDie()){
                board.setSpaceLife(x, y, false);
                board.setSpaceToLive(x, y, false);
            }
        }
    }
}

void Engine::setTos(){
    /*
     * Look at every space on the board and test its neighbors.
     * If it's alive and has more than 3 neighbors or less than 2 neighbors, mark it to die.
     * If it's dead and has exactly 3 neighbors, mark it to live.
     */
    for (int y = 0; y < board.sizeY(); y++){
        for (int x = 0; x < board.sizeX(); x++){
            if (board.boardSpace(x, y).isAlive()){
                if (!board.spaceHasNeighbors(x, y, 2)){
                    if (!board.spaceHasNeighbors(x, y, 3)){
                        board.setSpaceToDie(x, y, true);
                    }
                }
            }else{
                if (board.spaceHasNeighbors(x, y, 3)){
                    board.setSpaceToLive(x, y, true);
                }
            }
        }
    }
}

void Engine::edit(){
    /*
     * Take input from the player and update thing accordingly.
     */
    char input = getchar();
    if (input == 'h'){
        if (cursor.getX() - 1 >= 0)
            cursor.setX(cursor.getX() - 1);
    }else if (input == 'j'){
        if (cursor.getY() + 1 < board.sizeY())
            cursor.setY(cursor.getY() + 1);
    }else if (input == 'k'){
        if (cursor.getY() - 1 >= 0)
            cursor.setY(cursor.getY() - 1);
    }else if (input == 'l'){
        if (cursor.getX() + 1 < board.sizeX())
            cursor.setX(cursor.getX() + 1);
    }else if (input == 'u'){
        if (board.boardSpace(cursor.getX(), cursor.getY()).isAlive()){
            board.setSpaceLife(cursor.getX(), cursor.getY(), false);
        }else{
            board.setSpaceLife(cursor.getX(), cursor.getY(), true);
        }
    }else if (input == 'c'){ //Clear the board
        for (int y = 0; y < (int)board.sizeY(); y++){
            for (int x = 0; x < (int)board.sizeX(); x++){
                board.setSpaceLife(x, y, false);
            }
        }
    }else if (input == 'q'){ //Quit
        running = false;
    }else if (input == 'n'){ //Next frame
        setTos();
        toCheck();
    }
}

bool Engine::isRunning(){
    return running;
}

Engine::Engine(){
    board.setSpaceLife(1, 0, true);
    board.setSpaceLife(2, 1, true);
    board.setSpaceLife(0, 2, true);
    board.setSpaceLife(1, 2, true);
    board.setSpaceLife(2, 2, true);

    cursor.setX(0);
    cursor.setY(19);
 }

void Engine::takeTurn(){
	edit();
}

void Engine::dispBoard(){
    /*
     * Display the board
     * Wait for player input and quit the game if they hit q.
     */
    std::cout << "\x1B[2J\x1B[H";
    for (int y = 0; y < board.sizeY(); y++){
        for (int x = 0; x < board.sizeX(); x++){
            if (board.boardSpace(x, y).isAlive()){
		if ((cursor.getX() == x) && (cursor.getY() == y)){
			std::cout << "X ";
		}else{
			std::cout << "# ";
		}
            }else{
		if ((cursor.getX() == x) && (cursor.getY() == y)){
			std::cout << "_ ";
		}else{
			std::cout << ". ";
		}
            }
        }
        std::cout << std::endl;
    }
}
