#include <iostream>
#include "unorderedMap.h"

int main() {
    MyUnorderedMap<std::string, int> myUnorderedMap;

    myUnorderedMap.insert("one", 1);
    myUnorderedMap.insert("two", 2);
    myUnorderedMap.insert("three", 3);

    std::cout << "Value for key 'one': " << myUnorderedMap["one"] << std::endl;
    std::cout << "Value for key 'two': " << myUnorderedMap["two"] << std::endl;

    if (myUnorderedMap.find("three")) {
        std::cout << "'three' is in the map with value: " << myUnorderedMap["three"] << std::endl;
    }

    myUnorderedMap.remove("two");

    if (!myUnorderedMap.find("two")) {
        std::cout << "'two' has been removed from the map.\n";
    }

    return 0;
}
