#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LUN 40
#define EBREI 30

typedef struct {
    char *nome;
    char *cognome;
    int anni;
    int id;
} ebreo;

ebreo *build_ebreo(const char nome[], const char cognome[], int anni, int id);
void ebrei_default(ebreo *ebreo[], int *index);
void leggi(char str[]);
ebreo *alloca_ebreo(ebreo *e);
ebreo *censisci_ebrei(ebreo *ebreo);
void elenca_ebrei(ebreo *ebreo[], int index);
void print_ebreo(ebreo *ebreo); 
int metti_nel_forno(ebreo *ebreo[], int *index);
void shifta_ebrei(ebreo *ebreo[], int i, int index);

int main() {
    int s, index = 0;
    ebreo *ebreo[EBREI];
    ebrei_default(ebreo, &index);

    do {
        printf("Soluzione totale\n1. Elenca ebrei\n2. Censisci ebrei\n3. Metti nel forno\n0. Esci\n");
        printf("\nSelezione: ");
        scanf("%d", &s);
        while(getchar() != '\n'); // Usare ogni volta che si usa una scanf prima di fgets
        printf("\n");

        switch(s) {
            case 1:
                printf("[Ebrei Censiti]\n\n");
                elenca_ebrei(ebreo, index);
                break;
            case 2:
                ebreo[index] = censisci_ebrei(ebreo[index]);
                index++;
                printf("[Ebreo Censito]\n\n");
                break;
            case 3:
                if(metti_nel_forno(ebreo, &index))
                    printf("[Ebreo Eliminato]\n\n");
                else
                    printf("[Ebreo non schedato]\n\n");
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
    printf("Inserire il cognome dell'ebreo: ");
    leggi(cognome);
    printf("Inserire l'età dell'ebreo: ");
    scanf("%d", &anni);
    printf("Con quale numero vuoi timbrarlo?: ");
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

void elenca_ebrei(ebreo *ebreo[], int index) {
    int i;

    for(i = 0; i <= index - 1; i++)
        print_ebreo(ebreo[i]);
}

void print_ebreo(ebreo *ebreo) {
    printf("Nome: %s", ebreo->nome);
    printf("\nCognome: %s", ebreo->cognome);
    printf("\nAnni: %d", ebreo->anni);
    printf("\nId: %d\n\n", ebreo->id);
}

void ebrei_default(ebreo *ebreo[], int *index) {
    ebreo[0] = build_ebreo("Angelo", "De Luca", 19, 669);   
    ebreo[1] = build_ebreo("Vittorio Maria", "Borrello", 23, 880); 
    ebreo[2] = build_ebreo("Pierpaolo", "Pastore", 23, 890); 
    ebreo[3] = build_ebreo("Luca", "Casillo", 19, 190); 
    ebreo[4] = build_ebreo("Rosalia", "Fortino", 22, 290); 
    ebreo[5] = build_ebreo("Frank", "Lo Schiavo", 34, 790); 
    *index = 6;
}

ebreo *build_ebreo(const char nome[], const char cognome[], int anni, int id) {
    ebreo *e = NULL;
    e = alloca_ebreo(e);

    e->nome = malloc(strlen(nome) + 1); 
    strcpy(e->nome, nome);
    e->cognome = malloc(strlen(cognome) + 1); 
    strcpy(e->cognome, cognome);
    e->anni = anni;
    e->id = id;

    return e;
}

int metti_nel_forno(ebreo *ebreo[], int *index) {
    int id, i;

    printf("Inserisci l'id dell'ebreo: ");
    scanf("%d", &id);
    printf("\n");

    for(i = 0; i <= *index - 1; i++) {
        if(ebreo[i]->id == id) {
            shifta_ebrei(ebreo, i, *index);
            (*index)--;
            return 1;
        }
    }

    return 0;
}

void shifta_ebrei(ebreo *ebreo[], int i, int index) {
    int j;

    for(j = i; j < index - 1; j++) {
        ebreo[j] = ebreo[j+1];
    }

    free(ebreo[index]);
}