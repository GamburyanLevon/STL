#include <iostream>
#include "queue.h"

int main()
{
    Queue<int> queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Front element: " << queue.front() << std::endl;
    std::cout << "Back element: " << queue.back() << std::endl;

    queue.dequeue();
    std::cout << "Queue after dequeue operation: ";
    queue.print();

    std::cout << "Front element: " << queue.front() << std::endl;
    std::cout << "Back element: " << queue.back() << std::endl;

    queue.clear();
    std::cout << "Queue after clear operation: ";
    queue.print();

    if (queue.empty())
    {
        std::cout << "Queue is empty" << std::endl;
    }
    queue.enqueue(40);
    queue.enqueue(50);
    Queue<int> queueMove = std::move(queue);
    std::cout << "Moved queue: ";
    queueMove.print();

    return 0;
}