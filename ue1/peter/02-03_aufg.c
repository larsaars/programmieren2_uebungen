#include <stdio.h>

int wc(FILE *f);

int main(int argc, char **argv) {
    if (argc == 1) {
        // Sets stdout from line buffered to unbuffered
        // which prints every character as soon as typed
        // instead of line by line (ref: man setvbuf)
        setvbuf(stdout, NULL, _IOFBF, sizeof(stdout));
        while(1) {
            printf("%c", fgetc(stdin));
        }
    } else {
        char *path = argv[1];
        int lc = wc(fopen(path, "r"));
        printf("%d %s\n", lc, path);
    }
    
    return 0;
}

/**
 * returns number of line breaks in referred file stream
 */
int wc(FILE *f) {
    int line_count = 0;
    while (!feof(f)) if (fgetc(f) == '\n') line_count++;
    return line_count;
}

