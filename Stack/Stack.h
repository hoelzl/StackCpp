#ifndef STACK_STACK
#define STACK_STACK

#include <vector>

class Stack {
public:
    void Push(int element);
    int Pop();
    bool IsEmpty() const;

private:
    std::vector<int> elements_;
};

#endif // STACK_STACK
