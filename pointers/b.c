#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp, *fpr;

    fp = fopen("mammt", "a");
    fpr = fopen("mammt", "r");

    if(!fp) exit(2);
    if(!fpr) exit(2);

    fprintf(fp, "%d", 10);

    fprintf(fp, "%c", '\n');

    fprintf(fp, "%d", 20);

    int x;

    fscanf(fpr, "%d", &x);
    printf("%d", x);

    return 0;
}
