#include <stdio.h>
#include "persona.h"

int main() {
    persona *fabio = NULL, *giovannino = NULL;

    printf("--- Fabbione ---\n\n");

    fabio = alloca_persona(fabio);
    *fabio = build_persona("Fabio", "Fabbione", 20);

    print_persona(*fabio);

    printf("\n--- Giovannino ---\n\n");

    giovannino = alloca_persona(giovannino);
    *giovannino = build_persona("Giovannino", "La Marca", 19);

    print_persona(*giovannino);

    return 0;
}