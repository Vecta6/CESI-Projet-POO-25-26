#include "CellState.h"

//AliveState

bool AliveState::isAlive(){return true;}
char AliveState::symbol(){return '■';}

//DeadState

bool DeadState::isAlive(){return false;}
char DeadState::symbol(){return '⋅';}