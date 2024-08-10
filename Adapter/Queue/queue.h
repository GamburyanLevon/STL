#pragma once
#include <iostream>

template <typename T>
class Queue
{
private:
    struct Node
    {
        T m_data;
        Node* m_next;
        Node* m_prev;
        Node(const T& value) : m_data(value), m_next(nullptr), m_prev(nullptr) {}
    };

    Node* m_front;
    Node* m_back;
    int m_size;

public:
    Queue();
    Queue(const Queue& other);
    Queue& operator=(const Queue& other);
    Queue(Queue&& other);
    Queue& operator=(Queue&& other);
    ~Queue();

    void enqueue(const T& value);
    void dequeue();
    T& front() const;
    T& back() const;
    bool empty() const;
    void clear();
    int size() const;

    void print() const;
};



