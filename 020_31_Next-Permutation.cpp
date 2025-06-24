// https://leetcode.com/problems/next-permutation/description/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i ;
        int n = nums.size();
        int breakpoint_index = -1;
        for(i = n -1; i >= 1; --i){
            if(nums[i] > nums[i - 1]){
                breakpoint_index = i -1;
                break;
            }
        }
        if(breakpoint_index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for(i = n -1; i > breakpoint_index; --i){
            if(nums[i] > nums[breakpoint_index]){
                swap(nums[i], nums[breakpoint_index]);
                break;
            }
        }
        reverse(nums.begin() + breakpoint_index + 1, nums.end());
    }
};