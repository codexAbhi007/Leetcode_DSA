// https://leetcode.com/problems/binary-subarrays-with-sum/description/

class Solution {
public:
    // Helper function to count number of subarrays with sum <= goal
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;

        int left = 0, sum = 0, count = 0;

        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];

            // Shrink window if sum exceeds goal
            while (sum > goal) {
                sum -= nums[left];
                ++left;
            }

            // Number of subarrays ending at right with sum <= goal
            count += right - left + 1;
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};
