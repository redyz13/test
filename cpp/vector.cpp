#include <iostream>

struct Vector2D {
    int x, y;
    int *s;

    Vector2D(int x, int y)
    : x(x), y(y) {
        s = new int[2];
    }
    ~Vector2D() {
        delete[] s;
    }
    Vector2D operator+(Vector2D& other) const {
        return Vector2D(this->x + other.x, this->y + other.y);
    }
};

std::ostream& operator<<(std::ostream& stream, Vector2D& v) {
    stream << '(' << v.x << ',' << v.y << ')' << std::endl;
    return stream;
}

int main() {
    Vector2D v1(5, 10), v2(15, 20);
    Vector2D sum = v1 + v2;

    std::cout << v1 << v2;
    std::cout << sum;
}
