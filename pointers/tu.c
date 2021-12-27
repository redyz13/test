#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLUN 50

void leggi(char *str) {
    int lun;

    fgets(str, MAXLUN+2, stdin);

    lun = strlen(str);

    if(str[lun-1] == '\n')
        str[lun-1] = '\0';
}

char *alloca_stringa() {
    char *allstr;
    int lun;

    allstr = malloc(MAXLUN+1);

    leggi(allstr);

    lun = strlen(allstr);

    allstr = realloc(allstr, lun+1);

    return allstr;
}

int main() {
    int *da;
    int i;

    da = malloc(sizeof(int) * 10);

    for(i = 0; i < 10; i++) {
        da[i] = i;
    }

    for(i = 0; i < 10; i++) {
        printf("%d\n", da[i]);
    }

    da = realloc(da, sizeof(int) * 5);
    printf("\n");

    for(i = 0; i < 15; i++) {
        printf("%d\n", da[i]);
    }

    free(da);

    return 0;
}
