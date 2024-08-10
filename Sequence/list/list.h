#pragma once
#include "node.h"

template <typename T>
class List
{
private:
    Node<T> *head;

public:
    List();
    void insert(T data);
    void push_front(T data);
    void pop_back();
    void pop_front();
    void print() const;
    bool hasLoop() const;
    void createLoop(int);
    void reverse();
    bool empty() const;
    T &back();
    T find(int);
    class Iterator
    {
    private:
        Node<T> *current;

    public:
        Iterator(Node<T> *node) : current(node) {}

        T &operator*()
        {
            return current->data;
        }

        T* operator->() const {
            return &current->data;
        }

        Iterator &operator++()
        {
            if (current)
            {
                current = current->next;
            }
            return *this;
        }

        bool operator!=(const Iterator &other) const
        {
            return current != other.current;
        }
    };
    Iterator begin()
    {
        return Iterator(head);
    }

    Iterator end()
    {
        return Iterator(nullptr);
    }
};
