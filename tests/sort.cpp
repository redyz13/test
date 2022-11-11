#include <iostream>
#include <array>
#include <set>

template <size_t size>
void sort(std::array<int, size>& arr) {
    std::set<int> set;

    // std::sort(arr.begin(), arr.end(), [](int &a, int &b) {
    //     return a > b;
    // });

    for (int x : arr)
        set.insert(x);

    // std::cout << "[ ";
    // for (int x : set)
    //     std::cout << x << " ";
    // std::cout << "]\n";

    long sum = 0;

    for (int x : set) {
        sum += x;
    }

    std::cout << sum << '\n';
}

int main() {
    // std::array<int, 2000000> arr;
    // for (int i = 0; i < arr.size(); i++)
    //     arr[i] = i;
    // sort(arr);
    int x = 50;
    auto lambda = [&x]() { std::cout << x << '\n'; };
    lambda();
}