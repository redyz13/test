#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    int i, flag = 1;

    printf("Argc: %d", argc);

    for(i = 0; i < argc; i++) {
        if(!(strcmp(argv[i], "-mammt"))) {
            printf("\nSi nu figl e bucchin senza cor\n");
            flag = 0;
        }
    }

    if(flag) {
        printf("\nStrunz e scriver -mammt\n");
    }
}
