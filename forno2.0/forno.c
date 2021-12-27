#include <stdio.h>
#include <stdlib.h>
#include "ebreo.h"

int main() {
    int s;

    Ebreo **lista_ebrei;
    FILE *fp;

    fp = fopen("lista_ebrei.txt", "r");

    if(!fp) {
        fprintf(stderr, "Error... bye <3\n");
        exit(-1);
    }

    lista_ebrei = carica_ebrei(fp);

    do {
        printf("Soluzione finale\n\n1. Elenca ebrei\n2. Censisci ebrei\n3. Metti nel forno"
               "\n4. Cerca ebreo\n0. Esci\n");
        printf("\nSelezione: ");
        scanf("%d", &s);
        while(getchar() != '\n');
        printf("\n");

        switch(s) {
            case 1:
                printf("[Ebrei censiti]\n\n");
                for(int i = 0; i < 2; i++) {
                   printf("Id: %d", lista_ebrei[i]->id);
                   printf("\nNome: %s", lista_ebrei[i]->nome);
                   printf("\nCognome: %s", lista_ebrei[i]->cognome);
                   printf("\nAnni: %d\n\n", lista_ebrei[i]->anni);
                }
                break;
            case 0:
                exit(0);
        }

    } while(1938);

    return 0;
}
