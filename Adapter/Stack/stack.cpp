#include "stack.h"
#include <iostream>

template <typename T>
void Stack<T>::push(const T& value)
{
    stack.push_back(value);
}
template <typename T>
void Stack<T>::pop()
{
    if (!stack.empty())
    {
        stack.pop_back();
    }
    else
    {
        std::cerr << "Stack is empty. Cannot pop.\n";
    }
}
template <typename T>
T& Stack<T>::top()
{
    if (!stack.empty())
    {
        return stack.back();
    }
    else
    {
        std::cerr << "Stack is empty. No top element.\n";
    }
}
template <typename T>
bool Stack<T>::isEmpty()
{
    return stack.empty();
}
template <typename T>
void Stack<T>::printStack()
{
    for (auto it = stack.rbegin(); it != stack.rend(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template class Stack<int>;
template class Stack<double>;