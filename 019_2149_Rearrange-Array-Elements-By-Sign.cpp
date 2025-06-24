// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,0);
        int pos_index = 0;
        int neg_index = 1;

        int i;
        for(i = 0; i < n; ++i){
            if(nums[i] >= 0){
                result[pos_index] = nums[i];
                pos_index +=2;
            }
            else {
                result[neg_index] = nums[i];
                neg_index += 2;
            }
        }

        return result;
    }
};