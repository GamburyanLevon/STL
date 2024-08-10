#include <iostream>
#include "vector.h"

int main() {
    Vector<int> vec1{1, 2, 3, 4, 5};
    
    std::cout << "vec1: ";
    for (int i = 0; i < vec1.length(); ++i) 
    {
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;

    Vector<int> vec2 = std::move(vec1);
    
    std::cout << "vec2: ";
    for (int i = 0; i < vec2.length(); ++i) 
    {
        std::cout << vec2[i] << " ";
    }
    std::cout << std::endl;

    vec1.push_back(6);
    vec1.push_back(7);
    
    std::cout << "vec1 after push_back: ";
    for (int i = 0; i < vec1.length(); ++i) 
    {
        std::cout << vec1[i] << " ";
    }
    std::cout << std::endl;

    vec2 = std::move(vec1);

    std::cout << "vec2 after move assignment: ";
    for (int i = 0; i < vec2.length(); ++i) 
    {
        std::cout << vec2[i] << " ";
    }
    std::cout << std::endl;


    return 0;


}
