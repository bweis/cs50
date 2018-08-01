#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

char rotate(char c, int rot);

int getNthKey(string str, int n);

int isValidKeyword(string keyword);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./caesar k");
        return 1;
    }
    string keyword = argv[1];
    if (!isValidKeyword(keyword)) {
        printf("Usage: ./caesar k");
        return 1;
    }

    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");
    int nonAlphaCharCount = 0;  // fix for not applying rotation to non alpha chars
    for (int i = 0; i < strlen(plaintext); ++i) {
        if (!isalpha(plaintext[i])) {
            nonAlphaCharCount++;
        }
        int rotation = getNthKey(keyword, i - nonAlphaCharCount);
        printf("%c", rotate(plaintext[i], rotation));
    }
    printf("\n");
    return 0;
}

int isValidKeyword(string keyword) {
    for (int i = 0; i < strlen(keyword); ++i) {
        if (!isalpha(keyword[i])) {
            return 0;
        }
    }
    return 1;
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

int getNthKey(string str, int n) {
    char c = str[n % strlen(str)];
    int i = tolower(c) - 'a';
    return i;
}