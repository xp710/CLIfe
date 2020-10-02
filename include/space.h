#ifndef SPACE_H
#define SPACE_H

//The object which represents spaces on the board, alive or dead.

class Space
{
private:
    //logic stuff
    bool alive; //True if the space is alive and false if it's dead.
    bool willLive; //If the space is dead, this is marked to say it needs to be born.
    bool willDie; //If the space is alive, this is marked to say it needs to die.

public:
    Space(bool p_alive);
    ~Space() = default;

    //Accessors
    bool isAlive();
    bool toLive();
    bool toDie();

    //Functions
    void setLife(bool p_alive); //Use this to set a space to either alive or dead.
    void setToLive(bool p_willLive); //Use this to set a space to willLive or !willLive.
    void setToDie(bool p_willDie); //Use this to set a space to willDie or !willDie.
};

#endif // SPACE_H
