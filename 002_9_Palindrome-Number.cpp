#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    // Step 1: Negative numbers are not palindromes
    if (x < 0) return false;

    // Step 2: Numbers ending in 0 (but not 0 itself) can't be palindromes
    if (x % 10 == 0 && x != 0) return false;

    int reversedHalf = 0;

    // Step 3: Reverse half the digits
    while (x > reversedHalf) {
        reversedHalf = reversedHalf * 10 + x % 10;
        x /= 10;
    }

    // Step 4: Check palindrome
    return (x == reversedHalf || x == reversedHalf / 10);
}

int main() {
    int x;

    printf("Enter a number: ");
    scanf("%d", &x);

    if (isPalindrome(x)) {
        printf("%d is a palindrome.\n", x);
    } else {
        printf("%d is not a palindrome.\n", x);
    }

    return 0;
}
