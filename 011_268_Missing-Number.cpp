// https://leetcode.com/problems/missing-number/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;

        for (int num : nums) {
            actualSum += num;
        }

        return expectedSum - actualSum;
    }
};

int main() {
    // Test case
    vector<int> nums = {3, 0, 1};  // Expected missing number = 2

    Solution sol;
    int missing = sol.missingNumber(nums);

    cout << "Missing Number: " << missing << endl;

    return 0;
}
