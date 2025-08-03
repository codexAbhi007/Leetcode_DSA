// https://leetcode.com/problems/max-consecutive-ones-iii/description/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0;
        int l = 0;
        int r = 0;
        int zeros = 0;

        while(r < nums.size()){
            if(nums[r] == 0) zeros++;
            while(zeros > k){
                if(nums[l] == 0) zeros--;
                l++;
            }
            if(zeros <= k){
                int len = r - l + 1;
                maxLen = max(len,maxLen);
            }
            r++;
        }
        return maxLen;
    }
};