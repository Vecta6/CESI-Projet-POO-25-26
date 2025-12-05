#include "DeadState.h"

bool DeadState::isAlive() {
    return false;
}

char32_t DeadState::symbol() {
    return U'⋅';
}

int DeadState::value() {
    return 0;
}

bool DeadState::canBeModified() {
    return true;
}
