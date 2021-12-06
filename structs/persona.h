#ifndef __PERSONA_H_
#define __PERSONA_H_

typedef struct {
    char *nome;
    char *cognome;
    int anni;
} persona;

persona *alloca_persona(persona *p);
persona build_persona(const char nome[], const char cognome[], int anni);
void print_persona(persona p);

#endif
