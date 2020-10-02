#include "space.h"

//Accessors
bool Space::isAlive(){
    return alive;
}

bool Space::toLive(){
    return willLive;
}

bool Space::toDie(){
    return willDie;
}

//Constructor
Space::Space(bool p_alive)
    :willLive(false), willDie(false){
    alive = p_alive;
}

//Functions
void Space::setLife(bool p_alive){
    alive = p_alive;
}

void Space::setToLive(bool p_willLive){
    willLive = p_willLive;
}

void Space::setToDie(bool p_willDie){
    willDie = p_willDie;
}
