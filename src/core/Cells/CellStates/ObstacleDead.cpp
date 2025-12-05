#pragma once

#include "ObstacleDead.h"

    bool ObstacleDead::isAlive(){return false;}

    char32_t ObstacleDead::symbol(){return U'‒';}
    
    int ObstacleDead::value(){return 2;}

    bool ObstacleDead::canBeModified(){return false;}