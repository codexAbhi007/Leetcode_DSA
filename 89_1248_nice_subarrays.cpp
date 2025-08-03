// https://leetcode.com/problems/count-number-of-nice-subarrays/description/

class Solution {
public:
 int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;

        int left = 0, sum = 0, count = 0;

        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right] % 2;

            // Shrink window if sum exceeds goal
            while (sum > goal) {
                sum -= nums[left] % 2;
                ++left;
            }

            // Number of subarrays ending at right with sum <= goal
            count += right - left + 1;
        }

        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};