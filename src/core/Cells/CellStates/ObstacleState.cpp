#pragma once

#include "ObstacleState.h"

    bool ObstacleState::isAlive(){
        if(value()==2){return false;}           //Dead obstacle
        else if(value()==3){return true;}       //Alive obstacle
    }

    char32_t ObstacleState::symbol(){
        if(value()==2){return U'‒';}            //Dead obstacle
        else if(value()==3){return U'⁄';}       //Alive obstacle
    }
    
    int ObstacleState::value(){return 0;}

    bool ObstacleState::canBeModified(){return false;}