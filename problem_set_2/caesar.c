#include <stdio.h>
#include <string.h>
#include <cs50.h>

char rotate(char c, int rot);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./caesar k");
        return 1;
    }
    int rotation = atoi(argv[1]);
    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); ++i) {
        printf("%c", rotate(plaintext[i], rotation));
    }
    printf("\n");
    return 0;
}

char rotate(char c, int rot) {
    if (c >= 'a' && c <= 'z') {
        return (char) (((c - 'a' + rot) % 26) + 'a');
    } else if (c >= 'A' && c <= 'Z') {
        return (char) (((c - 'A' + rot) % 26) + 'A');
    } else {
        return c;
    }
}