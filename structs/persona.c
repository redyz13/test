#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#define MAX_LUN 40

persona *alloca_persona(persona *p) {
    p = malloc(sizeof(persona));

    if(!p) return NULL;

    return p;
}

persona build_persona(const char nome[], const char cognome[], int anni) {
    persona p;

    p.nome = malloc(sizeof(strlen(nome+1)));
    p.cognome= malloc(sizeof(strlen(cognome+1)));

    strcpy(p.nome, nome);
    strcpy(p.cognome, cognome);
    p.anni = anni;

    return p;
}

void print_persona(persona p) {
    printf("Nome: %s", p.nome);
    printf("\nCognome: %s ", p.cognome);
    printf("\nAnni: %d\n ", p.anni);
}
