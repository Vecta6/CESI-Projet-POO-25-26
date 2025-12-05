#include "ObstacleAlive.h"

    bool ObstacleAlive::isAlive(){return true;}

    char32_t ObstacleAlive::symbol(){return U'⁄';}
    
    int ObstacleAlive::value(){return 3;}

    bool ObstacleAlive::canBeModified(){return false;}