#include <iostream>
#include <string>
#include "map.h"

int main()
{
    MyMap<std::string, int> myMap;

    myMap.insert("one", 1);
    myMap.insert("two", 2);
    myMap.insert("three", 3);

    std::cout << "Value for key 'one': " << myMap["one"] << std::endl;
    std::cout << "Value for key 'two': " << myMap["two"] << std::endl;

    if (myMap.find("three"))
    {
        std::cout << "'three' is in the map with value: " << myMap["three"] << std::endl;
    }

    myMap.remove("two");

    if (!myMap.find("two"))
    {
        std::cout << "'two' has been removed from the map.\n";
    }

    return 0;
}
