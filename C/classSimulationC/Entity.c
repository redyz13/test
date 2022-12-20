#include <stdio.h>
#include "Entity.h"

const int GetXEntity(const Entity *this) {
    return this->x;
}

void SetXEntity(Entity *this, int x) {
    this->x = x;
}

void PrintNameEntity(const Entity *this) {
    printf("Entity\n");
}

void initEntity(Entity *this) {
    this->GetX = &GetXEntity;
    this->PrintName = &PrintNameEntity;
    this->SetX = &SetXEntity;
}