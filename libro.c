#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Libro {
	char autore[26];
	char titolo[53];
	char editore[26];
	int anno;
};

typedef struct Libro* libro;

libro creaLibro(char *A, char *T, char *E, int anno) {
	libro L;
	
	L = malloc(sizeof(struct Libro));
	
	if(!L) return NULL;
	
	strcpy(L->autore, A);
	strcpy(L->titolo, T);
	strcpy(L->editore, E);
	L->anno = anno;
	
	return L;
}

char *autore(libro L) {
	char *aut;
	
	aut = calloc(26, sizeof(char));
	
	if(aut)
		strcpy(aut, L->autore);
	
	return aut;
}

char *titolo(libro L) {
	char *tit;
	
	tit = calloc(53, sizeof(char));
	
	if(tit)
		strcpy(tit, L->titolo);
	
	return tit;
}

char *editore(libro L) {
	char *ed;
	
	ed = calloc(26, sizeof(char));
	
	if(ed)
		strcpy(ed, L->editore);
	
	return ed;
}

int anno(libro L) {
	return L->anno;
}

int main(void) {
    libro l;
    char *aut;

    l = creaLibro("Ngulett", "Le cronache di Tucci", "Rocco", 1945);
    aut = autore(l);

    puts(aut);

    return 0;
}
