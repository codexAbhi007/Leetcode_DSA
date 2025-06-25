// https://leetcode.com/problems/longest-consecutive-sequence/description/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i;
        int last = INT_MIN;
        int longest = 1;
        int curr_count = 0;
        for (i = 0; i < n; ++i) {
            if (nums[i] - 1 == last) {
                curr_count += 1;
                last = nums[i];
                
            } else {
                if (nums[i] != last) {
                    curr_count = 1;
                    last = nums[i];
                    
                }
                
            }
            longest = max(curr_count, longest);
        }
        return longest;
    }
};