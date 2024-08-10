#pragma once
#include <initializer_list>
#include "exeption.h"

template <typename T>
class Vector
{
public:
    Vector();
    Vector(std::initializer_list<T>);
    Vector(Vector &&);
    Vector(const Vector &);
    Vector(const int &);
    ~Vector();
    Vector &operator=(const Vector &);
    Vector &operator=(Vector &&);
    void push_back(const T &value);
    void pop_back();
    void push_front(const T &value);
    void pop_front();
    void insert(const int &, const T &);
    T &operator[](const int &);
    int length() const;
    bool empty() const;
    T &back();
    void reserve(int);
    T& at(int );
    const T& at(int ) const;

private:
    void resize();

    T *data;
    int size;
    int cap;
};
