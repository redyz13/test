#include <stdio.h>
#include "Element.h"

const int GetXElement(const Element *this) {
    return this->x;
}

void SetXElement(Element *this, int x) {
    this->x = x;
}

void initElement(Element *this) {
    this->GetX = &GetXElement;
    this->SetX = &SetXElement;
}