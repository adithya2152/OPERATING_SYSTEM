#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    long lines;
    long words;
    long chars;
} CountStats;

CountStats count_file(FILE *fp) {
    CountStats stats = {0, 0, 0};
    int c;
    bool in_word = false;

    while ((c = fgetc(fp)) != EOF) {
        stats.chars++;
        
        if (c == '\n') {
            stats.lines++;
        }
        if (isspace(c)) {
            in_word = false;
        } else if (!in_word) {
            in_word = true;
            stats.words++;
        }
    }

    return stats;
}

void print_stats(const char *filename, CountStats stats) {
    printf("%8ld %8ld %8ld %s\n", 
           stats.lines, stats.words, stats.chars, 
           filename ? filename : "");
}

int main(int argc, char *argv[]) {
    CountStats total = {0, 0, 0};
    CountStats current;

    if (argc < 2) {
        current = count_file(stdin);
        print_stats(NULL, current);
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (!fp) {
            printf("Error: Cannot open file %s\n", argv[i]);
            continue;
        }

        current = count_file(fp);
        print_stats(argv[i], current);
        fclose(fp);

        total.lines += current.lines;
        total.words += current.words;
        total.chars += current.chars;
    }

    if (argc > 2) {
        print_stats("total", total);
    }

    return 0;
}
