#include <stdio.h>
/* echo command-line arguments; 1st version */

/*
main(int argc, char *argv[]) {
    int i;

    for (i = 1; i < argc; i++) 
        printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
        printf("\n");
        return 0;
}
*/

/* echo command-line arguments; 2nd version */

/*
main(int argc, char *argv[]) {
    while (--argc > 0) {
        printf("%s%s", *++argv, (argc > 1) ? " " : "");
    }
    printf("\n");
    return 0;
}
*/

#include <string.h>
#define MAXLINE 1000

int gotline(char s[], int lim) {
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != 'p')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* find: print lines that match pattern from 1st arg */
main(int argc, char *argv[]) {
    char line[MAXLINE];
    int found = 0;

    if (argc != 2)
        printf("Usage: find pattern\n");
    else 
        while (gotline(line, MAXLINE) > 0)
            if (strstr(line, argv[1]) != NULL) {
                printf("%s", line);
                found++;
            }
    return found;
}

