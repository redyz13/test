#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLUN 30
#define PERS 5

struct {
    char *nome;
    char *cognome;
    int anni;
} typedef Persona;

void leggi(char *str);
void *xmalloc(size_t bytes);
void elimina_persona(Persona *p);
void scrivi_persona(FILE *fp, Persona *p); // File in write mode
void stampa_pf(FILE *fp, Persona *p); // File in read mode
Persona *inserisci_persona(int *index);

int main() {
    Persona *lista[PERS];
    int index = 0;
    FILE *fp;

    fp = fopen("text.txt", "w");

    if(!fp) {
        fprintf(stderr, "Error...byee <3\n");
        return -1;
    }

    *lista = inserisci_persona(&index);

    scrivi_persona(fp, *lista);

    elimina_persona(*lista);

    fclose(fp);

    fp = fopen("text.txt", "r");

    if(!fp) {
        fprintf(stderr, "Error...byee <3\n");
        return -1;
    }

    printf("\n");

    stampa_pf(fp, *lista);

    fclose(fp);

    return 0;
}

void stampa_pf(FILE *fp, Persona *p) {
    char tmp[MAXLUN+1];
    int i;

    for(i = 0; i < 3; i++) {
        fgets(tmp, MAXLUN+1, fp);
        printf("%s", tmp);
    }
}

void scrivi_persona(FILE *fp, Persona *p) {
    fprintf(fp, "Nome persona: %s\n", p->nome);
    fprintf(fp, "Cognome persona: %s\n", p->cognome);
    fprintf(fp, "Età persona: %d\n", p->anni);
}

void elimina_persona(Persona *p) {
    free(p->nome);
    free(p->cognome);
    free(p);
}

Persona *inserisci_persona(int *index) {
    char nome[MAXLUN+1], cognome[MAXLUN+1];

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
