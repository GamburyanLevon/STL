#include "unorderedMap.h"

// Constructor
template <typename K, typename V>
MyUnorderedMap<K, V>::MyUnorderedMap(int bucketCount) : bucketCount(bucketCount)
{
    buckets.resize(bucketCount);
}

template <typename K, typename V>
int MyUnorderedMap<K, V>::hashFunction(const K &key) const
{
    return std::hash<K>()(key) % bucketCount;
}

// Insert a key-value pair
template <typename K, typename V>
void MyUnorderedMap<K, V>::insert(const K &key, const V &value)
{
    int index = hashFunction(key);
    for (auto &kv : buckets[index])
    {
        if (kv.first == key)
        {
            kv.second = value;
            return;
        }
    }
    buckets[index].emplace_back(key, value);
}

template <typename K, typename V>
bool MyUnorderedMap<K, V>::find(const K &key) const
{
    int index = hashFunction(key);
    for (const auto &kv : buckets[index])
    {
        if (kv.first == key)
        {
            return true;
        }
    }
    return false;
}

template <typename K, typename V>
V &MyUnorderedMap<K, V>::operator[](const K &key)
{
    int index = hashFunction(key);
    for (auto &kv : buckets[index])
    {
        if (kv.first == key)
        {
            return kv.second;
        }
    }
    buckets[index].emplace_back(key, V());
    return buckets[index].back().second;
}

template <typename K, typename V>
void MyUnorderedMap<K, V>::remove(const K &key)
{
    int index = hashFunction(key);
    buckets[index].remove_if([&key](const std::pair<K, V> &kv)
                             { return kv.first == key; });
}

template class MyUnorderedMap<std::string, int>;
