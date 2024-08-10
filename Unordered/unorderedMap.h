#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <functional>

template <typename K, typename V>
class MyUnorderedMap
{
private:
    static const int default_size = 16;
    std::vector<std::list<std::pair<K, V>>> buckets;
    int bucketCount;

    int hashFunction(const K &key) const;

public:
    MyUnorderedMap(int bucketCount = default_size);

    void insert(const K &key, const V &value);
    bool find(const K &key) const;
    V &operator[](const K &key);
    void remove(const K &key);
};
