#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>

#define NUM_CHARS 52
#define MAX_PASSWORD_LEN 5

bool crack(string str, int pos, int size, string hash);

void crackNChars(int n, string hash);

bool crackCheck(string str, string hash);

const char ALPHANUM[NUM_CHARS] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    string hashedPassword = argv[1];
    crackNChars(MAX_PASSWORD_LEN, hashedPassword);
    return 0;
}

void crackNChars(int n, string hash) {
    for (int i = 1; i <= n; ++i) {
        int size = i;
        char str[size + 1];
        memset(str, '\0', (size + 1) * sizeof(char));
        if (crack(str, 0, size, hash)) {
            return;
        }
    }
}

bool crack(string str, int pos, int size, string hash) {
    for (int i = 0; i < NUM_CHARS; i++) {
        str[pos] = ALPHANUM[i];
        if (pos + 1 < size) {
            if (crack(str, pos + 1, size, hash)) {
                return true;
            }
        } else if (strlen(str) == size) {
            if (crackCheck(str, hash)) {
                return true;
            }
        }
    }
    return false;
}

bool crackCheck(string str, string hash) {
    char salt[3];
    strncpy(salt, hash, 2);
    salt[2] = '\0';

    string result = crypt(str, salt);
    if (strcmp(result, hash) == 0) {
        printf("%s\n", str);
        return true;
    }
    return false;
}