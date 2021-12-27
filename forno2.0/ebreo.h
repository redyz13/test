#ifndef __EBREO_H_
#define __EBREO_H_

#include <stdio.h>

typedef struct {
    char nome[30];
    char cognome[30];
    int anni;
    int id;
} Ebreo;

void leggi_stringa(char *str, FILE *buffer);

void *xmalloc(size_t bytes);

Ebreo **carica_ebrei(FILE *fp);

#endif
