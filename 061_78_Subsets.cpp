// https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int i;
        int n = nums.size();
        vector<vector<int>> ans;
        int subsets = 1 << n; // 2 ^ n;
        for (i = 0; i <= subsets - 1; ++i) {
            vector<int> sub;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j))
                    sub.push_back(nums[j]);
            }
            ans.push_back(sub);
        }
        return ans;
    }

};