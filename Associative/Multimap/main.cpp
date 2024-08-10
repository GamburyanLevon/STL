#include <iostream>
#include "multimap.h"

int main()
{
    MyMultimap<std::string, int> myMultimap;

    myMultimap.insert("one", 1);
    myMultimap.insert("one", 11);
    myMultimap.insert("two", 2);
    myMultimap.insert("three", 3);
    myMultimap.insert("three", 33);

    auto values = myMultimap.find("one");
    std::cout << "Values for key 'one': ";
    for (auto value : values)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    myMultimap.remove("one", 11);

    values = myMultimap.find("one");
    std::cout << "Values for key 'one' after removal: ";
    for (auto value : values)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    myMultimap.removeAll("three");

    values = myMultimap.find("three");
    if (values.empty())
    {
        std::cout << "'three' has been removed completely from the map." << std::endl;
    }

    return 0;
}
