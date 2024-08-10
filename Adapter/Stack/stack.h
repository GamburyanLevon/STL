#pragma once
#include <vector>

template <typename T>
class Stack
{
private:
    std::vector<T> stack;

public:
    Stack() = default;
    void push(const T&);
    void pop();
    T& top();
    bool isEmpty();
    void printStack();
};