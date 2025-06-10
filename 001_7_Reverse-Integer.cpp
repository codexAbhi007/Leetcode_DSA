#include <stdio.h>
#include <limits.h> // For INT_MAX and INT_MIN

int reverse(int x) {
    long reversed = 0;

    while (x != 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x /= 10;
    }

    // Overflow check
    if (reversed < INT_MIN || reversed > INT_MAX) {
        return 0;
    }

    return (int)reversed;
}

int main() {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    int result = reverse(x);
    printf("Reversed number: %d\n", result);

    return 0;
}
