#include <iostream>

template<typename T>
using Predicate = bool(*)(T);

template<typename T>
void func(Predicate<T> x) {
    std::cout << "Mao";
}

int main() {
    func<int>([](int x) {
        return x % 2 == 0;
    });
    
    return 0;
}
