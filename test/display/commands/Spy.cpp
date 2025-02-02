
#include "Spy.h"

void Spy::set_caught() {
    caught_ = true;
}

[[nodiscard]] bool Spy::was_caught() const {
    return caught_;
}