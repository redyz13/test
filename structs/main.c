#include <stdio.h>
#include "persona.h"

int main() {
    persona fabio, giovannino;
    persona *fp, *gp;
    
    printf("--- Fabbione ---\n\n");

    fp = &fabio;
    fp = alloca_persona(fp);
    fabio = build_persona("Fabio", "Fabbione", 20);

    print_persona(fabio);

    printf("\n--- Giovannino ---\n\n");

    gp = &giovannino;
    gp = alloca_persona(gp);
    giovannino = build_persona("Giovannino", "La Marca", 19);

    print_persona(giovannino);

    return 0;
}
