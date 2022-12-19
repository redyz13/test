typedef struct Element Element;

struct Element {
    int x;
    const int (*GetX)(const Element *this);
    void (*SetX)(Element *this, int x);
};

void initElement(Element *this);