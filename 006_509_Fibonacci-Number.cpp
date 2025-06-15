#include <iostream>
using namespace std;

class Solution {
public:
    // Recursive Fibonacci (Exponential time)
    int fibRecursive(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return fibRecursive(n - 1) + fibRecursive(n - 2);
    }

    // Iterative Fibonacci (Linear time)
    int fibIterative(int n) {
        if (n == 0) return 0;
        int a = 0, b = 1;
        for (int i = 2; i <= n; i++) {
            int temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }
};

int main() {
    Solution sol;
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Fibonacci of " << n << " (Recursive): " << sol.fibRecursive(n) << endl;
    cout << "Fibonacci of " << n << " (Iterative): " << sol.fibIterative(n) << endl;

    return 0;
}
