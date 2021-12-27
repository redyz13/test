#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ebreo.h"

#define MAX_LUN 40
#define EBREI 30

void leggi_stringa(char *str, FILE *buffer) {
    int n;

    fgets(str, MAX_LUN+2, buffer);

    n = strlen(str);

    if(str[n-1] == '\n') str[n-1] = '\0';
}

void *xmalloc(size_t bytes) {
    void *p;

    p = malloc(bytes);

    if(!p) exit(-1);

    return p;
}

Ebreo **carica_ebrei(FILE *fp) {
    Ebreo **le = xmalloc(sizeof(Ebreo) * EBREI);
    char str[30];
    int i = 0;

    while(!feof(fp)) {
        le[i] = xmalloc(sizeof(Ebreo));

        fscanf(fp, "%d", &le[i]->id);

        fgets(str, 30, fp); // Clear Buffer ('\n') ti odio scanf

        leggi_stringa(str, fp);
        strcpy(le[i]->nome, str);

        leggi_stringa(str, fp);
        strcpy(le[i]->cognome, str);

        fscanf(fp, "%d", &le[i]->anni);

        fgets(str, 30, fp); // **

        fgets(str, 30, fp); // **

        i++;
    }

    rewind(fp);

    return le;
}