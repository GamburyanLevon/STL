#include "list.h"
#include <iostream>



int main() 
{
    List<int> list;
    
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.print();

    list.push_front(5);
    list.push_front(0);
    list.print();

    list.reverse();
    list.print();

    for (auto it = list.begin(); it != list.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    
    std::cout << list.find(2) << std::endl;


    return 0;
}
