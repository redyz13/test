#include <iostream>

using std::cout;

class Checker {
private:
    char vocals[127] = {};
    int *arr = new int[50];
public:
    Checker() {
        vocals[65] = 'A'; vocals[69] = 'E'; vocals[73] = 'I';
        vocals[79] = 'O'; vocals[85] = 'U';
    }

    ~Checker() {
        delete[] arr;
    }

    bool isVocal(char c) const {
        c = toupper(c);

        return vocals[c] != 0 ? true : false;
    }

    void printIndex(unsigned i) const {
        cout << vocals[i];
    }
};

void func(const Checker& c) {
    Checker paolo;
    // c.printIndex(65);
}

int main() {
    Checker checker;
    char c;

    func(Checker());

    cout << "Inserisci un carattere: ";
    c = std::cin.get();

    checker.isVocal(c) ? cout << c << " è una vocale" << '\n'
        : cout << c << " non è una vocale" << '\n';
}
