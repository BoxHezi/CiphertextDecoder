#include <stdio.h>
#include <mem.h>

typedef enum boolean {
    FALSE = 0,
    TRUE
} Boolean;

int main(int argc, char ** args) {
    char data[20];

    printf("Please enter cipher-text you want to decode: ");
    fgets(data, sizeof(data), stdin);
    printf("%s\n", data);
    /*printf("%d\n", argc);

    for(int i = 0; i < argc; i++) {
        printf("%s", args[i]);
    }*/

    printf("Hello, World!\n");
    return 0;
}