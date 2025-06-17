// https://leetcode.com/problems/max-consecutive-ones/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0, currentCount = 0;
        
        for (int num : nums) {
            if (num == 1) {
                currentCount++;
                maxCount = max(maxCount, currentCount);
            } else {
                currentCount = 0;
            }
        }

        return maxCount;
    }
};

// Driver code (for testing)
int main() {
    Solution sol;
    vector<int> nums1 = {1, 1, 0, 1, 1, 1}; // Output: 3
    vector<int> nums2 = {1, 0, 1, 1, 0, 1}; // Output: 2

    cout << "Max consecutive 1s in nums1: " << sol.findMaxConsecutiveOnes(nums1) << endl;
    cout << "Max consecutive 1s in nums2: " << sol.findMaxConsecutiveOnes(nums2) << endl;

    return 0;
}
