typedef struct Entity Entity;

struct Entity {
    int x;
    const int (*GetX)(const Entity *this);
    void (*SetX)(Entity *this, int x);
    void (*PrintName)(const Entity *this);
};

void initEntity(Entity *this);