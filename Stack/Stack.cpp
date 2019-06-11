#include <stdexcept>
#include "Stack.h"

void Stack::Push(int element) {
    elements_.push_back(element);
}

int Stack::Pop() {
    if (IsEmpty()) {
        throw std::out_of_range{"Cannot pop empty stack."};
    }
    else {
        int result{elements_.back()};
        elements_.pop_back();
        return result;
    }
}

bool Stack::IsEmpty() const {
    return elements_.empty();
}
