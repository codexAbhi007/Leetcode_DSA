// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }

        return count <= 1;
    }
};

int main() {
    Solution sol;

    // Test cases
    vector<int> nums1 = {3, 4, 5, 1, 2}; // true
    vector<int> nums2 = {2, 1, 3, 4};    // false
    vector<int> nums3 = {1, 2, 3};       // true

    cout << boolalpha; // Print "true" or "false" instead of 1/0
    cout << "Test 1: " << sol.check(nums1) << endl;
    cout << "Test 2: " << sol.check(nums2) << endl;
    cout << "Test 3: " << sol.check(nums3) << endl;

    return 0;
}
