#include "DeadState.h"

bool DeadState::isAlive() {
    return false;
}

int DeadState::value() {
    return 0;
}

bool DeadState::canBeModified() {
    return true;
}
