/**************/
/* CLIfe v1.0 */
/**************/

//Creator: XP710

#include <iostream>
#include <termios.h>
#include <unistd.h>
#include "engine.h"
using namespace std;

int main()
{
    //Disable ICanon and Echo
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    t.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);

    //Start the program with a splash screen
    cout << "\x1B[2J\x1B[H"; //Clears the screen
    cout << "Weclome to CLIfe v1.0!" << endl
         << "Copyright 2020 by XP710 GPLv3.0" << endl << endl
         << "Controls:" << endl
         << "Movement: hjkl" << endl
         << "Advance 1 frame: n" << endl
         << "Change state of space under cursor: u" << endl
         << "Clear the board: c" << endl << endl
         << "Press any key to continue..." << endl;
    getchar(); //Wait for any key to be pressed
    Engine game;

    while (game.isRunning()){
        game.dispBoard();
        game.takeTurn();
    }

    //Enables ICanon and Echo again
    t.c_lflag |= ICANON;
    t.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}
