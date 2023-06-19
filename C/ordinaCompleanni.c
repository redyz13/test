#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30
#define MONTHSIZE 10
#define NAMESIZE 50

char *months[] = {
    "gennaio", "febbraio", "marzo", "aprile", "maggio", "giugno", "luglio",
    "agosto", "settembre", "ottobre", "novembre", "dicembre"
};

typedef struct Birthday {
    int dayAndMonth;
    char name[NAMESIZE];
} Birthday;

int getMonthNumber(char *month) {
    for (int i = 0; i < 12; i++)
        if (!(strcmp(month, months[i])))
            return i;
    return -1;
}

char *getMonth(int i) {
    return months[i];
}

int buildBirthdays(Birthday *birthdays, char *filename) {
    FILE *file = fopen("f", "r");
    int dayAndMonth, day, month;
    char monthStr[MONTHSIZE];
    char name[NAMESIZE];
    int i = 0;

    while ((fscanf(file, "%d %s %s", &day, monthStr, name)) == 3) {
        month = getMonthNumber(monthStr);
        dayAndMonth = 100 * month + day;
        Birthday birthday;
        birthday.dayAndMonth = dayAndMonth;
        strcpy(birthday.name, name);
        birthdays[i++] = birthday;
    }

    fclose(file);

    return i;
}

int compare(const void *b1, const void *b2) {
    return ((Birthday *)b1)->dayAndMonth - ((Birthday *)b2)->dayAndMonth;
}

int main(int argc, char **argv) {
    Birthday birthdays[SIZE];

    if (argc < 2) {
        fprintf(stderr, "Usage: <%s filename>\n", *argv);
    }

    int size = buildBirthdays(birthdays, argv[1]);

    qsort(birthdays, size, sizeof(struct Birthday), compare);

    printf("Giorni ordinati e stampati su file:\n\n");
    for (int i = 0; i < size; i++)
        printf("%d %s %s\n", birthdays[i].dayAndMonth % 100,
            getMonth(birthdays[i].dayAndMonth / 100), birthdays[i].name);
    
    FILE *file = fopen(argv[1], "w");

    for (int i = 0; i < size; i++)
        fprintf(file, "%d %s %s\n", birthdays[i].dayAndMonth % 100,
            getMonth(birthdays[i].dayAndMonth / 100), birthdays[i].name);

    putchar('\n');

    return 0;
}