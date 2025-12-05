#include "AliveState.h"

bool AliveState::isAlive() {
    return true;
}

int AliveState::value() {
    return 1;
}

bool AliveState::canBeModified() {
    return true;
}
