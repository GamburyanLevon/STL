#include "vector.h"
#include "string"


template <typename T>
Vector<T>::Vector() : data(nullptr), size(0), cap(0) {}

template <typename T>
Vector<T>::Vector(const int& size) : data(nullptr), size(size), cap(2*size) {}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> init_list) : Vector() 
{
    for (const auto& item : init_list) 
    {
        push_back(item);
    }
}


template <typename T>
Vector<T>::Vector(const Vector& obj) : Vector()
{
    data = new T[obj.cap];
    for (int i = 0; i < obj.size; ++i) 
    {
        data[i] = obj.data[i];
    }
    size = obj.size;
    cap = obj.cap;
}

template <typename T>
Vector<T>::Vector(Vector&& obj)  
{
    data = obj.data;
    size = obj.size;
    cap = obj.cap;
    obj.data = nullptr;
    obj.size = 0;
    obj.cap = 0;
}

template <typename T>
Vector<T>::~Vector() 
{
    delete[] data;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& obj) 
{
    if (this != &obj) 
    {
        delete[] data;
        data = new T[obj.cap];
        for (size_t i = 0; i < obj.size; ++i) 
        {
            data[i] = obj.data[i];
        }
        size = obj.size;
        cap = obj.cap;
    }
    return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& obj) 
{
    if (this != &obj) 
    {
        delete[] data;
        data = obj.data;
        size = obj.size;
        cap = obj.cap;
        obj.data = nullptr;
        obj.size = 0;
        obj.cap = 0;
    }
    return *this;
}

template <typename T>
void Vector<T>::push_back(const T& value) 
{
    if (size == cap) 
    {
        resize();
    }
    data[size++] = value;
}


template <typename T>
void Vector<T>::pop_back() 
{
    --size;
}

template <typename T>
void Vector<T>::push_front(const T& value) 
{
    if (size == cap) 
    {
        resize();
    }
    for (int i = size; i > 0; --i) 
    {
        data[i] = std::move(data[i - 1]);
    }
    data[0] = value;
    ++size;
}

template <typename T>
void Vector<T>::pop_front() 
{
    for (int i = 1; i < size; ++i) 
    {
        data[i - 1] = std::move(data[i]);
    }
    --size;
}

template <typename T>
void Vector<T>::insert(const int& index, const T& value) 
{
    if (size == cap) 
    {
        resize();
    }
    for (int i = size; i > index; --i) 
    {
        data[i] = std::move(data[i - 1]);
    }
    data[index] = value;
    ++size;
}

template <typename T>
T& Vector<T>::operator[](const int& index) 
{
    return data[index];
}

template <typename T>
int Vector<T>::length() const 
{
    return size;
}

template <typename T>
void Vector<T>::resize() 
{
    cap = (cap == 0) ? 1 : cap * 2;
    T* new_data = new T[cap];
    for (int i = 0; i < size; ++i) 
    {
        new_data[i] = std::move(data[i]);
    }
    delete[] data;
    data = new_data;
}

template <typename T>
bool Vector<T>::empty() const
{
    return size == 0;
}

template <typename T>
T& Vector<T>::back()
{
    return data[size-1];
}

template <typename T>
void Vector<T>::reserve(int new_cap)
{
    if(new_cap <= cap)
        return;
    cap = new_cap;
}

template <typename T>
T& Vector<T>::at(int index) 
{
    if (index >= size) 
    {
        throw myexception("Index " + std::to_string(index) + " is out of range");
    }
    return data[index];
}

template <typename T>
const T& Vector<T>::at(int index) const 
{
    if (index >= size) 
    {
        throw myexception("Index " + std::to_string(index) + " is out of range");
    }
    return data[index];
}


template class Vector<int>;
template class Vector<double>;

