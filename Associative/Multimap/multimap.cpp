#include "multimap.h"

template <typename K, typename V>
MyMultimap<K, V>::MyMultimap() : root(nullptr) {}

template <typename K, typename V>
MyMultimap<K, V>::~MyMultimap()
{
    deleteAll(root);
}

template <typename K, typename V>
typename MyMultimap<K, V>::Node *MyMultimap<K, V>::insert(Node *node, K key, V value)
{
    if (!node)
        return new Node(key, value);

    if (key < node->key)
        node->left = insert(node->left, key, value);
    else if (key > node->key)
        node->right = insert(node->right, key, value);
    else
        node->values.push_back(value);

    return node;
}

template <typename K, typename V>
void MyMultimap<K, V>::insert(K key, V value)
{
    root = insert(root, key, value);
}

template <typename K, typename V>
typename MyMultimap<K, V>::Node *MyMultimap<K, V>::find(Node *node, K key) const
{
    if (!node || node->key == key)
        return node;

    if (key < node->key)
        return find(node->left, key);
    else
        return find(node->right, key);
}

template <typename K, typename V>
std::list<V> MyMultimap<K, V>::find(K key) const
{
    Node *node = find(root, key);
    if (node)
    {
        return node->values;
    }
    else
    {
        return std::list<V>();
    }
}

template <typename K, typename V>
typename MyMultimap<K, V>::Node *MyMultimap<K, V>::findMin(Node *node) const
{
    while (node->left)
        node = node->left;
    return node;
}

template <typename K, typename V>
typename MyMultimap<K, V>::Node *MyMultimap<K, V>::remove(Node *node, K key, V value)
{
    if (!node)
        return node;

    if (key < node->key)
        node->left = remove(node->left, key, value);
    else if (key > node->key)
        node->right = remove(node->right, key, value);
    else
    {
        node->values.remove(value);
        if (node->values.empty())
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
            node->values = temp->values;
            node->right = remove(node->right, temp->key, *temp->values.begin());
        }
    }
    return node;
}

template <typename K, typename V>
void MyMultimap<K, V>::remove(K key, V value)
{
    root = remove(root, key, value);
}

template <typename K, typename V>
void MyMultimap<K, V>::removeAll(K key)
{
    Node *node = find(root, key);
    if (node)
    {
        while (!node->values.empty())
        {
            root = remove(root, key, node->values.front());
        }
    }
}

template <typename K, typename V>
void MyMultimap<K, V>::deleteAll(Node *node)
{
    if (!node)
        return;
    deleteAll(node->left);
    deleteAll(node->right);
    delete node;
}

template class MyMultimap<std::string, int>;
template class MyMultimap<int, std::string>;