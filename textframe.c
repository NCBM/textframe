#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "textframe.h"

int print_frame(char *frame[], tf_ull len) {
    if (len == 0) {
        fprintf(stderr, "textframe.c: print_frame(char *frame[], tf_uint128 len): no content to print according to 'len'.");
        return 2;
    } else if (0 < len && len <= ULLONG_MAX) {
        tf_ull i = 0;
        while (1) {
            printf("%s", frame[i]);
            i >= len ? i = 0 : i++;
        }
        return 0;
    } else {
        fprintf(stderr, "textframe.c: print_frame(char *frame[], tf_ull len): an uncaught error maybe happened.");
        return 3;
    }
}

int fprint_frame(FILE *fob) {
    char c;
    while (!feof(fob)) {
        c = fgetc(fob);
        if (c != '\n') {
            putchar(c);
        } else {
            for (int i = 0; i < 25000; i++) {}
            printf("\r");
        }
    }
    printf("%s", "\0");
    printf("\r");
    return 0;
}

int main(int argc, char *argv[]) {
    FILE *f = fopen("test.fr", "r");
    fclose(f);
    // printf("\r        Please wait...\r");
    while (1) {
        freopen("test.fr", "r", f);
        fprint_frame(f);
        fclose(f);
    }
    return 0;
}


