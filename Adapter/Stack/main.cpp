#include "stack.h"
#include <iostream>


int main() {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.printStack();
    std::cout << "Top element: " << stack.top() << std::endl;
    stack.pop();
    stack.printStack();
    std::cout << "Top element: " << stack.top() << std::endl;

    return 0;
}