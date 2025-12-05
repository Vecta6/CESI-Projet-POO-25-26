//
// Created by nathan on 03/12/2025.
//

#include "AliveState.h"

bool AliveState::isAlive() {
    return true;
}

char32_t AliveState::symbol() {
    return U'■';
}

int AliveState::value() {
    return 1;
}

bool AliveState::canBeModified() {
    return true;
}
