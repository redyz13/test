#include <iostream>

class A {
    public:
        A(int x) : x(x) {

        }
    protected:
        int x,y;
    
    public:
        virtual void mao() const {
            std::cout << "mao";
        }
        void printX() const {
            std::cout << x;
        }
};

class B : public virtual A {
    private:
        int y;
    public:
        void mao() const override {
            std::cout << "mao mao";
        }

        B(int y) : y(y), A(20) {
        }
};

class C : public virtual A, public B {
    public:
        C() : A(30), B(50) {

        }
};

int main() {
    A a(10);
    B b(50);
    C c;

    a.mao();
    b.mao();
    c.mao();

    std::cout << '\n';

    a.printX();
    b.printX();
    c.printX();
}