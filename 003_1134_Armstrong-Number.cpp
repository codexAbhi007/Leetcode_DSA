// 1134. Armstrong Number
// The k-digit number N is an Armstrong number if and only if the k-th power of each digit sums to N.

// Given a positive integer N, return true if and only if it is an Armstrong number.

// Example 1:

// Input: 153
// Output: true
// Explanation:
// 153 is a 3-digit number, and 153 = 1^3 + 5^3 + 3^3.
// Example 2:

// Input: 123
// Output: false
// Explanation:
// 123 is a 3-digit number, and 123 != 1^3 + 2^3 + 3^3 = 36.

// Note:

// 1 <= N <= 10^8
// Difficulty:
// Easy

#include <iostream>
#include <cmath>

class Solution{
    public:
        bool isArmstrong(int N){
            int original = N;
            int numDigits = 0;
            int temp = N;

            //count no of digits
            while(temp > 0){
                numDigits++;
                temp /= 10;
            }

            int sum = 0;
            temp = N;

            while(temp > 0){
                int digit = temp % 10;
                sum += std::pow(digit, numDigits);
                temp /= 10;
            }

            return sum == original;
        }
};

int main(){
    Solution sol;
    int test1 = 153;
    int test2 = 123;
    int test3 = 9474;

    std::cout << sol.isArmstrong(test1) << std::endl;
    std::cout << sol.isArmstrong(test2) << std::endl;
    std::cout << sol.isArmstrong(test3) << std::endl;

    return 0;
}