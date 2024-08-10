#pragma once
#include <iostream>
#include <list>
#include <utility>

template <typename K, typename V>
class MyMultimap {
private:
    struct Node {
        K key;
        std::list<V> values;
        Node* left;
        Node* right;

        Node(K k, V v) : key(k), left(nullptr), right(nullptr) {
            values.push_back(v);
        }
    };

    Node* root;

    Node* insert(Node* node, K key, V value);
    Node* find(Node* node, K key) const;
    Node* findMin(Node* node) const;
    Node* remove(Node* node, K key, V value);
    void deleteAll(Node* node);

public:
    MyMultimap();
    ~MyMultimap();

    void insert(K key, V value);
    std::list<V> find(K key) const;
    void remove(K key, V value);
    void removeAll(K key);
};
