#import <stdio.h>
#import <cs50.h>

int main(void) {
    int coinCount = 0;
    int coins[] = {25, 10, 5, 1};
    const int NUM_COINS = 4;
    double changeDue;
    do {
        changeDue = get_double("Change owed: ");
    } while (changeDue < 0);
    int cents = (int) (changeDue * 100);
    for (int i = 0; i < NUM_COINS; i++) {
        while (cents >= coins[i]) {
            cents -= coins[i];
            coinCount++;
        }
    }
    printf("%d\n", coinCount);
}