#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LUN 40

typedef struct {
    char *nome;
    char *cognome;
    int anni;
    int id;
} ebreo;

void leggi(char str[]);
ebreo *alloca_ebreo(ebreo *e);
ebreo *censisci_ebrei(ebreo *ebreo);
//void elenca_ebrei();

int main() {
    int s, index = 0;
    ebreo *ebreo[30];

    do {
        printf("Soluzione totale\n1. Elenca ebrei\n2. Censisci ebrei\n0. Esci\n");
        printf("\nSelezione: ");
        scanf("%d", &s);
        printf("\n");

        switch(s) {
            case 1:
                //elenca_ebrei();
                break;
            case 2:
                ebreo[index] = censisci_ebrei(ebreo[index]);
                break;
            case 0:
                exit(0);
        }

    }while(1938);

    return 0;
}

void leggi(char str[]) {
    int n;
    
    fgets(str, MAX_LUN+2, stdin);

    n = strlen(str);

    if(str[n-1] == '\n') str[n-1] = '\0';
}

ebreo *alloca_ebreo(ebreo *e) {
    e = malloc(sizeof(ebreo));

    if(!e) return NULL;

    return e;
}

ebreo *censisci_ebrei(ebreo *ebreo) {
    ebreo = alloca_ebreo(ebreo);
    char nome[MAX_LUN + 1], cognome[MAX_LUN + 1];
    int anni, id;

    printf("Inserire il nome dell'ebreo: ");
    leggi(nome);
    printf("\nInserire il cognome dell'ebreo: ");
    leggi(cognome);
    printf("\nInserire l'età dell'ebreo: ");
    scanf("%d", &anni);
    printf("\nCon quale numero vuoi timbrarlo?: ");
    scanf("%d", &id);
    printf("\n");

    ebreo->nome = malloc(strlen(nome) + 1); 
    strcpy(ebreo->nome, nome);
    ebreo->cognome = malloc(strlen(cognome) + 1); 
    strcpy(ebreo->cognome, cognome);
    ebreo->anni = anni;
    ebreo->id = id;

    return ebreo;
}