#include <iostream>
#include "Stack.h"

int main() {
    Stack<int, 10> s;

    for (int i = 0; i < 10; i++)
        s.push(i);

    std::cout << "Stack 1: ";
    while (!s.isEmpty()) {
        std::cout << s.top() << " ";
        s.pop();
    }

    std::cout << '\n';

    Stack<std::string, 10> v;

    for (int i = 0; i < 10; i++)
        v.push("a" + std::to_string(i));

    std::cout << "Stack 2: ";
    while (!v.isEmpty()) {
        std::cout << v.top() << " ";
        v.pop();
    }

    std::cout << '\n';
}