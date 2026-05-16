#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "compare.h"
#include "secret.h"


const size_t BUF_MAX = 1024;


int repl() {
    char buf[BUF_MAX];

    while (1) {
        printf(">>> ");

        if (fgets(buf, BUF_MAX, stdin)) {
            buf[strcspn(buf, "\n")] = '\0';
        }
        else {
            fprintf(stderr, "Something went wrong...\n");
            return -1;
        }

        if (strcmp((char*)buf, "q") == 0) break;

        const char* secretString = getSecretString();
        size_t inputLen = strlen(buf);
        if (inputLen != strlen(secretString)) {
            printf("Wrong input length!\n\n");
            continue;
        }

        int diffs[BUF_MAX];

        compare(diffs, buf, secretString);
        for (size_t i = 0; i < inputLen; i++) {
            printf("%d", diffs[i]);
            if (i + 1 < inputLen) {
                printf(" ");
            }
        }
        printf("\n\n");
    }
    return 0;
}


int main() {
    printf("Enter a string with a length of 17 bytes. (Type `q` to quit.)\n");
    return repl();
}
