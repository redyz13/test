#pragma once

#include <iostream>

template<typename T, size_t N>
class Stack {
private:
    T s[N];
    size_t size = 0;
public:
    Stack() {}

    bool isEmpty() const { return size == 0; }

    int getSize() const { return size; }

    bool push(T x) {
        if (size >= N)
            return false;
        s[size++] = x;
        return true;
    }

    bool pop() {
        if (size <= 0)
            return false;
        size--;
        return true;
    }

    T top() const {
        try {
            if (size <= 0)
                throw "Error calling top: size is <= 0";
        }
        catch (const char *msg) {
            std::cout << msg << '\n';
        }
        return s[size - 1];
    }
};