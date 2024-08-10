#include "node.h"

template <typename T>
Node<T>::Node(T data) : data(data), next(nullptr) {}

template class Node<int>;
template class Node<double>;