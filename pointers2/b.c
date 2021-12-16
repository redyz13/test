#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLUN 30
#define PERS 5

struct {
    char *nome;
    char *cognome;
    int anni;
    char codice_fiscale[16+1];
} typedef Persona;

void leggi(char *str);
void *xmalloc(size_t bytes);
void elimina_persona(Persona *p);
void elenca_persone(Persona **lista, int index);
void print_persona(Persona *p);
Persona *inserisci_persona(int *index);
int cerca_cf(Persona **lista, int index);
int cerca_nm(Persona **lista, int index);
int check_codice(char *str);
int crea_elenco(Persona **lista, Persona *elenco_con_cognomi, int index, int *cognomi);
int cerca_persona(Persona **lista, char *codice_fiscale, int index);
void elimina_elenco(Persona **lista, int *index);
void print_persona_np(Persona p);

int main() {
    Persona *lista[PERS];
    Persona elenco_con_cognomi[PERS];
    int index = 0, s;
    int found, cognomi;

    do {
        printf("Elenco persone\n\n1. Elenca persone\n2. Aggiungi persona"
                "\n3. Cerca per cf\n4. Cerca per nome e cognome\n5. Crea sottoelenco per cognome"
                "\n0. Esci\n");
        printf("\nSelezione: ");
        scanf("%d", &s);
        while(getchar() != '\n');
        printf("\n");

        switch(s) {
            case 1:
                printf("[Lista persone]\n\n");
                elenca_persone(lista, index);
                break;
            case 2:
                lista[index] = inserisci_persona(&index);
                printf("[Persona aggiunta]\n\n");
                break;
            case 3:
                found = cerca_cf(lista, index);

                if(found != -1) {
                    printf("[Persona trovata]\n\n");
                    print_persona(lista[found]);
                }
                else {
                    printf("[Persona non trovata]\n\n");
                }
                break;
            case 4:
                found = cerca_nm(lista, index);

                if(found != -1) {
                    printf("[Persona trovata]\n\n");
                    print_persona(lista[found]);
                }
                else {
                    printf("[Persona non trovata]\n\n");
                }

                break;
            case 5:
                found = crea_elenco(lista, elenco_con_cognomi, index, &cognomi);

                if(found != -1) {
                    printf("[Elenco creato]\n\n");

                    for(int i = 0; i < cognomi; i++) {
                        print_persona_np(elenco_con_cognomi[i]);
                    }

                    cognomi = 0;
                }
                else {
                    printf("[Nessun cognome trovato]\n\n");
                }

                break;
            case 0:
                elimina_elenco(lista, &index);
                return 0;
        }

    } while(1);

    return 0;
}

void elimina_persona(Persona *p) {
    free(p->nome);
    free(p->cognome);
    free(p);
}

Persona *inserisci_persona(int *index) {
    char nome[MAXLUN+1], cognome[MAXLUN+1];
    char codice_fiscale[16+1];

    Persona *p;

    p = xmalloc(sizeof(Persona));

    printf("Inserire il nome della persona: ");
    leggi(nome);
    
    p->nome = xmalloc(sizeof(strlen(nome) + 1));
    strcpy(p->nome, nome);

    printf("Inserire il cognome della persona: ");
    leggi(cognome);

    p->cognome = xmalloc(sizeof(strlen(cognome) + 1));
    strcpy(p->cognome, cognome);

    printf("Inserire l'età della persona: ");
    scanf("%d", &p->anni);

    while(getchar() != '\n');

    printf("Inserire il codice fiscale della persona: ");
    do {
        leggi(codice_fiscale);

        if(check_codice(codice_fiscale)) {
            break;
        }

        printf("\nFormato non corretto!\nReinserire: ");
    } while(check_codice(codice_fiscale) != 1);

    strcpy(p->codice_fiscale, codice_fiscale);

    printf("\n");

    (*index)++;

    return p;
}

void leggi(char *str) { 
    int len;

    fgets(str, MAXLUN + 1, stdin);

    len = strlen(str);
    
    if(str[len-1] == '\n')
        str[len-1] = '\0';
}

void *xmalloc(size_t bytes) {
    void *p;

    p = malloc(bytes);

    if(!p) {
        fprintf(stderr, "Error...byee <3\n");
        exit(-1);
    }

    return p;
}

void elenca_persone(Persona **lista, int index) {
    int i;

    for(i = 0; i < index; i++) {
        print_persona(lista[i]);
    }
}

void print_persona(Persona *p) {
    printf("Nome: %s", p->nome);
    printf("\nCognome: %s", p->cognome);
    printf("\nAnni: %d", p->anni);
    printf("\nCodice fiscale: %s\n\n", p->codice_fiscale);
}

void print_persona_np(Persona p) {
    printf("Nome: %s", p.nome);
    printf("\nCognome: %s", p.cognome);
    printf("\nAnni: %d", p.anni);
    printf("\nCodice fiscale: %s\n\n", p.codice_fiscale);
}

int cerca_cf(Persona **lista, int index) {
    char codice_fiscale[16+1];
    int i;

    printf("Inserire il codice fiscale della persona da cercare: ");
    leggi(codice_fiscale);
    printf("\n");

    for(i = 0; i < index; i++) {
        if(!(strcmp(lista[i]->codice_fiscale, codice_fiscale))) {
            return i;
        }
    }

    return -1;
}

int cerca_persona(Persona **lista, char *codice_fiscale, int index) {
    int i;

    for(i = 0; i < index; i++) {
        if(!(strcmp(lista[i]->codice_fiscale, codice_fiscale))) {
            return i;
        }
    }

    return -1;
}

int check_codice(char *str) {
    int c = 1;

    // Controllo lettere
    c = c && isalpha(str[0]);
    c = c && isalpha(str[1]);
    c = c && isalpha(str[2]);
    c = c && isalpha(str[3]);
    c = c && isalpha(str[4]);
    c = c && isalpha(str[5]);
    c = c && isalpha(str[8]);
    c = c && isalpha(str[11]);
    c = c && isalpha(str[15]);

    // Controllo caratteri numerici
    c = c && isdigit(str[6]);
    c = c && isdigit(str[7]);
    c = c && isdigit(str[9]);
    c = c && isdigit(str[10]);
    c = c && isdigit(str[12]);
    c = c && isdigit(str[13]);
    c = c && isdigit(str[14]);

    if(c) return 1;

    return 0;
}

int cerca_nm(Persona **lista, int index) {
    char nome[MAXLUN+1], cognome[MAXLUN+1];
    char nome_p[MAXLUN+1], cognome_p[MAXLUN+1];
    //char search[(MAXLUN+1)*2];
    //char tmp[(MAXLUN+1)*2];
    int i;

    printf("Inserire il nome della persona: ");
    leggi(nome);
    
    printf("Inserire il cognome della persona: ");
    leggi(cognome);

    //strcat(search, nome);
    //strcat(search, cognome);

    printf("\n");

    for(i = 0; i < index; i++) {
        //strcat(tmp, lista[i]->nome);
        //strcat(tmp, lista[i]->cognome);
        strcpy(nome_p, lista[i]->nome);
        strcpy(cognome_p, lista[i]->cognome);

        if(!(strcmp(nome_p, nome))) {
            if(!(strcmp(cognome_p, cognome))) {
                return i;
            }
        }
    }

    return -1;
}

int crea_elenco(Persona **lista, Persona *elenco_con_cognomi, int index, int *cognomi) {
    char cognome[MAXLUN+1];
    int i, found;

    printf("Inserire il cognome della persona: ");
    leggi(cognome);

    printf("\n");

    for(i = 0; i < index; i++) {
        found = cerca_persona(lista, lista[i]->codice_fiscale, index);

        if(found != -1) {
            elenco_con_cognomi[i] = *(lista[i]);
            (*cognomi)++;
        }
    }

    if((*cognomi) > 0)
        return 1;

    return -1;
}

void elimina_elenco(Persona **lista, int *index) {
    int i;

    for(i = 0; i < (*index); i++) {
       elimina_persona(lista[i]); 
    }

    *(index) = 0;
}
