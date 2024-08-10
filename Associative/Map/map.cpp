#include "map.h"
#include <string>

template <typename K, typename V>
MyMap<K, V>::~MyMap()
{
    deleteAll(root);
}

template <typename K, typename V>
typename MyMap<K, V>::Node *MyMap<K, V>::insert(Node *node, K key, V value)
{
    if (!node)
        return new Node(key, value);

    if (key < node->key)
        node->left = insert(node->left, key, value);
    else if (key > node->key)
        node->right = insert(node->right, key, value);
    else
        node->value = value;

    return node;
}

template <typename K, typename V>
void MyMap<K, V>::insert(K key, V value)
{
    root = insert(root, key, value);
}

template <typename K, typename V>
typename MyMap<K, V>::Node *MyMap<K, V>::find(Node *node, K key) const
{
    if (!node || node->key == key)
        return node;

    if (key < node->key)
        return find(node->left, key);
    else
        return find(node->right, key);
}

template <typename K, typename V>
bool MyMap<K, V>::find(K key) const
{
    return find(root, key) != nullptr;
}

template <typename K, typename V>
V &MyMap<K, V>::operator[](K key)
{
    Node *node = find(root, key);
    if (node)
    {
        return node->value;
    }
    else
    {
        insert(key, V());
        return find(root, key)->value;
    }
}

template <typename K, typename V>
typename MyMap<K, V>::Node *MyMap<K, V>::findMin(Node *node) const
{
    while (node->left)
        node = node->left;
    return node;
}

template <typename K, typename V>
typename MyMap<K, V>::Node *MyMap<K, V>::remove(Node *node, K key)
{
    if (!node)
        return node;

    if (key < node->key)
        node->left = remove(node->left, key);
    else if (key > node->key)
        node->right = remove(node->right, key);
    else
    {
        if (!node->left)
        {
            Node *temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right)
        {
            Node *temp = node->left;
            delete node;
            return temp;
        }

        Node *temp = findMin(node->right);

        node->key = temp->key;
        node->value = temp->value;

        node->right = remove(node->right, temp->key);
    }
    return node;
}

template <typename K, typename V>
void MyMap<K, V>::remove(K key)
{
    root = remove(root, key);
}

template <typename K, typename V>
void MyMap<K, V>::deleteAll(Node *node)
{
    if (!node)
        return;
    deleteAll(node->left);
    deleteAll(node->right);
    delete node;
}

template class MyMap<int, std::string>;
template class MyMap<std::string, int>;