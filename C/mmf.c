#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Filename required as argument\n");
        exit(-1);
    }

    struct stat sb;
    int fd = open(argv[1], O_RDWR);

    if (fstat(fd, &sb) == -1) {
        fprintf(stderr, "Can't get file size\n");
        exit(-1);
    }

    printf("File size: %ld\n", sb.st_size);

    char *file = mmap((void *)0xFEEDBEEF, sb.st_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);

    printf("\nFile printed:\n");

    for (int i = 0; i < sb.st_size; i++) {
        file[i] = toupper(file[i]);
        putchar(file[i]);
    }
    
    munmap(file, sb.st_size);
    close(fd);

    return 0;
}
