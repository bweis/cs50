#include <stdio.h>
#include <cs50.h>
#include <math.h>

int lenLongLong(long long n);

int sumDigits(int n);

int leadingTwoDigits(long long n);


int main(void) {
    long long cardNumber = get_long_long("Number: ");
    int leadingDigits = leadingTwoDigits(cardNumber);
    int length = lenLongLong(cardNumber);
    int sum = 0;

    for (int i = 0; i < length; ++i) {
        int digit = (int) (cardNumber % 10);
        cardNumber /= 10;
        if (i % 2 == 0) {
            sum += digit;
        } else {
            sum += sumDigits(digit * 2);
        }
    }

    if (sum % 10 != 0) {
        printf("INVALID\n");
    } else if (length == 15 && (leadingDigits == 34 || leadingDigits == 37)) {
        printf("AMEX\n");
    } else if (length == 16 && leadingDigits >= 51 && leadingDigits <= 55) {
        printf("MASTERCARD\n");
    } else if (leadingDigits / 10 == 4 && (length == 13 || length == 16)) {
        printf("VISA\n");
    } else {
        printf("INVALID\n");
    }

    return 0;
}

int lenLongLong(long long n) {
    int count = 0;
    while (n > 0) {
        n /= 10;
        count++;
    }
    return count;
}


int sumDigits(int n) {
    if (n < 10) {
        return n;
    }
    int ones = n % 10;
    int tens = n / 10;
    return ones + tens;
}

int leadingTwoDigits(long long n) {
    while (n > 99) {
        n /= 10;
    }
    return (int) n;
}