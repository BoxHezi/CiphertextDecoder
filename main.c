#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef enum boolean {
    FALSE = 0,
    TRUE
} Boolean;

void readRestOfLine();

int main() {
    char data[20 + 2];
    char tempChar;
    int len = 0;
    Boolean validInput = FALSE;
    FILE *fp;
    fp = fopen("plaintext.txt", "w");

    do {
        printf("Please enter cipher-text you want to decode: ");
        fgets(data, sizeof(data), stdin);
        if (data[strlen(data) - 1] != '\n') {
            printf("Too long, try again!\n");
            readRestOfLine();
        } else {
            data[strlen(data) - 1] = '\0';
            validInput = TRUE;
        }
    } while (!validInput);

    len = (int) strlen(data);

    for (int i = 0; i < len; i++) {
        data[i] = (char) toupper(data[i]);
    }

    for (int i = 0; i < 26; i++) {
        printf("Shift by %d: ", 26 - i);
        fprintf(fp, "Shift by %d: ", 26 - i);
        for (int j = 0; j < len; j++) {
            tempChar = (char) (data[j] + i);
            if (tempChar > 'Z') {
                tempChar = (char) (tempChar - 26);
            }
            printf("%c", tempChar);
            fprintf(fp, "%c", tempChar);
        }
        printf("\n");
        fprintf(fp, "\n");
    }

    fclose(fp);

    return EXIT_SUCCESS;
}

void readRestOfLine() {
    int ch;
    while (ch = getc(stdin), ch != EOF && ch != '\n') {}

    clearerr(stdin);
}