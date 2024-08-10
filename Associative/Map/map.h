#pragma once
#include <iostream>
#include <utility>  

template <typename K, typename V>
class MyMap {
private:
    struct Node {
        K key;
        V value;
        Node* left;
        Node* right;

        Node(K k, V v) : key(k), value(v), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, K key, V value);

    Node* find(Node* node, K key) const;

    Node* findMin(Node* node) const;

    Node* remove(Node* node, K key);

    void deleteAll(Node* node);

public:
    MyMap() : root(nullptr) {}

    ~MyMap();

    void insert(K key, V value);

    V& operator[](K key);

    void remove(K key);

    bool find(K key) const;
};