#include "list.h"
#include <iostream>

template <typename T>
List<T>::List() : head(nullptr) {}


template <typename T>
void List<T>::insert(T data)
{
    Node<T> *newNode = new Node<T>(data);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node<T> *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


template <typename T>
void List<T>::push_front(T data)
{
    Node<T> *newNode = new Node<T>(data);
    newNode->next = head;
    head = newNode;
}

template <typename T>
void List<T>::pop_front()
{
    if (head == nullptr)
    {
        std::cout << "list is empty" << std::endl;
    }
    Node<T> *temp = head;
    head = head->next;
    T data = temp->data;
    delete temp;
}

template <typename T>
void List<T>::print() const
{
    Node<T> *temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}

template <typename T>
bool List<T>::hasLoop() const
{
    if (head == nullptr)
        return false;
    Node<T> *slow = head;
    Node<T> *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

template <typename T>
void List<T>::createLoop(int index)
{
    if (head == nullptr)
        return;
    Node<T> *temp = head;
    Node<T> *loopNode = nullptr;
    int count = 0;
    while (temp->next != nullptr)
    {
        if (count == index)
        {
            loopNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = loopNode;
}

template <typename T>
void List<T>::reverse()
{
    Node<T> *prev = nullptr;
    Node<T> *current = head;
    Node<T> *next = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

template <typename T>
T List<T>::find(int index)
{
    if (head == nullptr)
    {
        std::cout << "List is empty" << std::endl;
    }

    Node<T> *mainPtr = head;
    Node<T> *refPtr = head;

    for (int i = 0; i < index; ++i)
    {
        if (refPtr == nullptr)
        {
            std::cout << "out of range" << std::endl;
        }
        refPtr = refPtr->next;
    }

    while (refPtr != nullptr)
    {
        mainPtr = mainPtr->next;
        refPtr = refPtr->next;
    }

    return mainPtr->data;
}

template <typename T>
T &List<T>::back()
{
    Node<T> *current = head;
    while (current->next)
    {
        current = current->next;
    }
    return current->data;
}

template <typename T>
bool List<T>::empty() const
{
    return head == nullptr;
}

template <typename T>
void List<T>::pop_back()
{
    Node<T> *current = head;
    while (current->next && current->next->next)
    {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
}

template class List<int>;
template class List<double>;